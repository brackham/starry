/**
\file interface.cpp
\brief Defines the entry point for the C++ API.

*/

// Enable debug mode?
#ifdef STARRY_DEBUG
#   undef NDEBUG
#endif

// Includes
#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>
#include <pybind11/embed.h>
#include "utils.h"
#include "ops.h"
namespace py = pybind11;

// Multiprecision?
#if STARRY_NDIGITS > 16
    using Scalar = Multi;
#else
    using Scalar = double;
#endif

// Register the Python module
PYBIND11_MODULE(
    _c_ops, 
    m
) {

    // Import some useful stuff
    using namespace starry::utils;

    // Declare the Ops class
    py::class_<starry::Ops<Scalar>> Ops(m, "Ops");

    // Constructor
    Ops.def(py::init<int, int, int>());

    // Total number of map coeffs
    Ops.def_property_readonly(
        "N", [] (
            starry::Ops<Scalar>& ops
        ) {
            return ops.N;
    });

    // Occultation solution in emitted light
    Ops.def(
        "sT", [](
            starry::Ops<Scalar>& ops,
            const Vector<double>& b,
            const double& r
        )
    {
        size_t npts = size_t(b.size());
        Matrix<Scalar, RowMajor> sT(npts, ops.N);
        for (size_t n = 0; n < npts; ++n) {
            ops.G.compute(b(n), r);
            sT.row(n) = ops.G.sT;
        }
        return sT;
    });

    // Gradient of occultation solution in emitted light
    Ops.def(
        "sT", [](
            starry::Ops<Scalar>& ops,
            const Vector<double>& b,
            const Scalar& r,
            const Matrix<double, RowMajor>& bsT
        )
    {
        size_t npts = size_t(b.size());
        Vector<Scalar> bb(npts);
        Scalar br = 0.0;
        for (size_t n = 0; n < npts; ++n) {
            ops.G.template compute<true>(b(n), r);
            bb(n) = ops.G.dsTdb.dot(bsT.row(n));
            br += ops.G.dsTdr.dot(bsT.row(n));
        }
        return py::make_tuple(bb, br);
    });

    // Change of basis matrix: Ylm to poly
    Ops.def(
        "A1", [](
            starry::Ops<Scalar>& ops
        )
    {
        return ops.B.A1;
    });

    // Change of basis matrix: poly to Ylm
    Ops.def(
        "A1Inv", [](
            starry::Ops<Scalar>& ops
        )
    {
        return ops.B.A1Inv;
    });

    // Change of basis matrix: Ylm to greens
    Ops.def(
        "A", [](
            starry::Ops<Scalar>& ops
        )
    {
        return ops.B.A;
    });

    // Rotation solution in emitted light
    Ops.def(
        "rT", [](
            starry::Ops<Scalar>& ops
        )
    {
        return ops.B.rT;
    });

    // Rotation solution in emitted light dotted into Ylm space
    Ops.def(
        "rTA1", [](
            starry::Ops<Scalar>& ops
        )
    {
        return ops.B.rTA1;
    });

    // Zhat rotation operator
    Ops.def(
        "dotRz", [](
            starry::Ops<Scalar>& ops,
            const Matrix<double>& M,
            const Vector<double>& theta
        )
    {
        ops.W.dotRz(M, theta);
        return ops.W.dotRz_result;
    });

    // Gradient of zhat rotation matrix
    Ops.def(
        "dotRz", [](
            starry::Ops<Scalar>& ops,
            const Matrix<double>& M,
            const Vector<double>& theta,
            const Matrix<double>& bMRz
        )
    {
        ops.W.dotRz(M, theta, bMRz);
        return py::make_tuple(ops.W.dotRz_bM, ops.W.dotRz_btheta);
    });

}