# -*- coding: utf-8 -*-
from inspect import getmro
import theano
import theano.tensor as tt
import numpy as np
from theano.ifelse import ifelse
import logging
logger = logging.getLogger(__name__)
logger.addHandler(logging.StreamHandler())


__all__ = ["logger",
           "STARRY_ORTHOGRAPHIC_PROJECTION",
           "STARRY_RECTANGULAR_PROJECTION",
           "autocompile",
           "get_projection",
           "is_theano",
           "to_tensor",
           "to_array",
           "vectorize",
           "atleast_2d",
           "cross",
           "RAxisAngle",
           "VectorRAxisAngle"]


# Constants
STARRY_ORTHOGRAPHIC_PROJECTION = 0
STARRY_RECTANGULAR_PROJECTION = 1


class CompileLogMessage:
    """
    Log a brief message saying what method is currently
    being compiled and print `Done` when finished.

    """
    def __init__(self, name):
        self.name = name

    def __enter__(self):
        logger.handlers[0].terminator = ""
        logger.info("Compiling `{0}`... ".format(self.name))

    def __exit__(self, type, value, traceback):
        logger.handlers[0].terminator = "\n"
        logger.info("Done.")


class autocompile(object):
    """
    A decorator used to automatically compile methods into Theano functions
    if the user disables lazy evaluation.

    """
    def __init__(self, name, *args):
        """
        Initialize the decorator.

        Arguments:
            name (str): The name of the decorated method
            *args (tuple): Theano types corresponding to each of the
                arguments of the method.
        """
        self.args = args
        self.name = name
        self.compiled_name = "_compiled_{0}".format(name)

    def __call__(self, func):
        """
        Wrap the method `func` and return a compiled version if `lazy==False`.
        
        """
        def wrapper(instance, *args, force_compile=False):
            """
            The magic happens in here.

            """
            if (not instance.lazy) or (force_compile):
                # Compile the function if needed & cache it
                if not hasattr(instance, self.compiled_name):
                    with CompileLogMessage(self.name):
                        compiled_func = theano.function(
                            [*self.args], 
                            func(instance, *self.args), 
                            on_unused_input='ignore'
                        )
                        setattr(instance, self.compiled_name, compiled_func)
                # Return the compiled version
                return getattr(instance, self.compiled_name)(*args)
            else:
                # Just return the function as is
                return func(instance, *args)

        # Store the function info
        wrapper.args = self.args
        wrapper.func = func
        return wrapper


def get_projection(projection):
    """

    """
    if projection.lower().startswith("rect"):
        projection = STARRY_RECTANGULAR_PROJECTION
    elif projection.lower().startswith("ortho"):
        projection = STARRY_ORTHOGRAPHIC_PROJECTION
    else:
        raise ValueError("Unknown map projection.")
    return projection


def is_theano(*objs):
    """
    Return ``True`` if any of ``objs`` is a ``Theano`` object.

    """
    for obj in objs:
        for c in getmro(type(obj)):
            if c is theano.gof.graph.Node:
                return True
    return False


def to_tensor(*args):
    """
    Convert all ``args`` to tensor variables.

    """
    if len(args) == 1:
        return tt.as_tensor_variable(args[0]).astype(tt.config.floatX)
    else:
        return [tt.as_tensor_variable(arg).astype(tt.config.floatX) for arg in args]


def to_array(*args):
    """
    Convert all ``args`` to numpy arrays.

    """
    if len(args) == 1:
        return np.array(args[0], dtype=tt.config.floatX)
    else:
        return [np.array(arg, dtype=tt.config.floatX) for arg in args]


def vectorize(*args):
    """
    Vectorize all ``args`` so that they have the same length
    along the first axis.

    TODO: Add error catching if the dimensions don't agree.
    
    """
    if is_theano(*args):
        args = [arg * tt.ones(1) for arg in args]
        size = tt.max([arg.shape[0] for arg in args])
        args = [tt.repeat(arg, size // arg.shape[0], 0) for arg in args]
    else:
        args = [np.atleast_1d(arg) for arg in args]
        size = np.max([arg.shape[0] for arg in args])
        args = tuple([arg * np.ones((size,) + tuple(np.ones(len(arg.shape) - 1, dtype=int))) for arg in args])
    if len(args) == 1:
        return args[0]
    else:
        return args


def atleast_2d(arg):
    if is_theano(arg):
        return arg * tt.ones((1, 1))
    else:
        return np.atleast_2d(arg)


def cross(x, y):
    """
    Cross product of two 3-vectors.

    Based on ``https://github.com/Theano/Theano/pull/3008``
    """
    eijk = np.zeros((3, 3, 3))
    eijk[0, 1, 2] = eijk[1, 2, 0] = eijk[2, 0, 1] = 1
    eijk[0, 2, 1] = eijk[2, 1, 0] = eijk[1, 0, 2] = -1
    result = tt.as_tensor_variable(
        tt.dot(tt.dot(eijk, y), x)
    )
    return result


def RAxisAngle(axis=[0, 1, 0], theta=0):
    """
    
    """
    axis = tt.as_tensor_variable(axis)
    axis /= axis.norm(2)
    cost = tt.cos(theta)
    sint = tt.sin(theta)

    return tt.reshape(tt.as_tensor_variable([
        cost + axis[0] * axis[0] * (1 - cost),
        axis[0] * axis[1] * (1 - cost) - axis[2] * sint,
        axis[0] * axis[2] * (1 - cost) + axis[1] * sint,
        axis[1] * axis[0] * (1 - cost) + axis[2] * sint,
        cost + axis[1] * axis[1] * (1 - cost),
        axis[1] * axis[2] * (1 - cost) - axis[0] * sint,
        axis[2] * axis[0] * (1 - cost) - axis[1] * sint,
        axis[2] * axis[1] * (1 - cost) + axis[0] * sint,
        cost + axis[2] * axis[2] * (1 - cost)
    ]), [3, 3])


def VectorRAxisAngle(axis=[0, 1, 0], theta=0):
    """

    """
    fn = lambda theta, axis: RAxisAngle(axis=axis, theta=theta)
    R, _ = theano.scan(fn=fn, sequences=[theta], non_sequences=[axis])
    return R