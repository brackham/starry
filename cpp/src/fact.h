/**
Tabulated factorials for integers and half-integers.

*/

#ifndef _STARRY_FACT_H_
#define _STARRY_FACT_H_

#include <cmath>
#include <iostream>

namespace fact {

#define STARRY_MAX_FACT 170
#define STARRY_MAX_HALF_FACT 341

    // Table of n! for nonnegative integer n
    //
    // Mathematica:
    //      Table[{StringPadRight[ToString[n],4],
    //             StringPadRight[ToString[FortranForm[
    //                  SetPrecision[Factorial[n],25]]],30]},{n,0,170}]
    //
    static struct {int n; double f;} fact_table[] = {
        {0  ,  1.                            },
        {1  ,  1.                            },
        {2  ,  2.                            },
        {3  ,  6.                            },
        {4  ,  24.                           },
        {5  ,  120.                          },
        {6  ,  720.                          },
        {7  ,  5040.                         },
        {8  ,  40320.                        },
        {9  ,  362880.                       },
        {10 ,  3.6288e6                      },
        {11 ,  3.99168e7                     },
        {12 ,  4.790016e8                    },
        {13 ,  6.2270208e9                   },
        {14 ,  8.71782912e10                 },
        {15 ,  1.307674368e12                },
        {16 ,  2.0922789888e13               },
        {17 ,  3.55687428096e14              },
        {18 ,  6.402373705728e15             },
        {19 ,  1.21645100408832e17           },
        {20 ,  2.43290200817664e18           },
        {21 ,  5.109094217170944e19          },
        {22 ,  1.12400072777760768e21        },
        {23 ,  2.585201673888497664e22       },
        {24 ,  6.2044840173323943936e23      },
        {25 ,  1.5511210043330985984e25      },
        {26 ,  4.03291461126605635584e26     },
        {27 ,  1.0888869450418352160768e28   },
        {28 ,  3.04888344611713860501504e29  },
        {29 ,  8.841761993739701954543616e30 },
        {30 ,  2.652528598121910586363085e32 },
        {31 ,  8.222838654177922817725563e33 },
        {32 ,  2.63130836933693530167218e35  },
        {33 ,  8.683317618811886495518194e36 },
        {34 ,  2.952327990396041408476186e38 },
        {35 ,  1.033314796638614492966665e40 },
        {36 ,  3.719933267899012174679994e41 },
        {37 ,  1.376375309122634504631598e43 },
        {38 ,  5.230226174666011117600072e44 },
        {39 ,  2.039788208119744335864028e46 },
        {40 ,  8.159152832478977343456113e47 },
        {41 ,  3.345252661316380710817006e49 },
        {42 ,  1.405006117752879898543143e51 },
        {43 ,  6.041526306337383563735513e52 },
        {44 ,  2.658271574788448768043626e54 },
        {45 ,  1.196222208654801945619632e56 },
        {46 ,  5.502622159812088949850305e57 },
        {47 ,  2.586232415111681806429644e59 },
        {48 ,  1.241391559253607267086229e61 },
        {49 ,  6.082818640342675608722522e62 },
        {50 ,  3.041409320171337804361261e64 },
        {51 ,  1.551118753287382280224243e66 },
        {52 ,  8.065817517094387857166064e67 },
        {53 ,  4.274883284060025564298014e69 },
        {54 ,  2.308436973392413804720927e71 },
        {55 ,  1.26964033536582759259651e73  },
        {56 ,  7.109985878048634518540456e74 },
        {57 ,  4.05269195048772167556806e76  },
        {58 ,  2.350561331282878571829475e78 },
        {59 ,  1.38683118545689835737939e80  },
        {60 ,  8.320987112741390144276341e81 },
        {61 ,  5.075802138772247988008568e83 },
        {62 ,  3.146997326038793752565312e85 },
        {63 ,  1.982608315404440064116147e87 },
        {64 ,  1.268869321858841641034334e89 },
        {65 ,  8.24765059208247066672317e90  },
        {66 ,  5.443449390774430640037292e92 },
        {67 ,  3.647111091818868528824986e94 },
        {68 ,  2.48003554243683059960099e96  },
        {69 ,  1.711224524281413113724683e98 },
        {70 ,  1.197857166996989179607278e100},
        {71 ,  8.504785885678623175211676e101},
        {72 ,  6.123445837688608686152407e103},
        {73 ,  4.470115461512684340891257e105},
        {74 ,  3.30788544151938641225953e107 },
        {75 ,  2.480914081139539809194648e109},
        {76 ,  1.885494701666050254987932e111},
        {77 ,  1.451830920282858696340708e113},
        {78 ,  1.132428117820629783145752e115},
        {79 ,  8.946182130782975286851442e116},
        {80 ,  7.156945704626380229481153e118},
        {81 ,  5.797126020747367985879734e120},
        {82 ,  4.753643337012841748421382e122},
        {83 ,  3.945523969720658651189747e124},
        {84 ,  3.314240134565353266999388e126},
        {85 ,  2.817104114380550276949479e128},
        {86 ,  2.422709538367273238176552e130},
        {87 ,  2.107757298379527717213601e132},
        {88 ,  1.854826422573984391147968e134},
        {89 ,  1.650795516090846108121692e136},
        {90 ,  1.485715964481761497309523e138},
        {91 ,  1.352001527678402962551666e140},
        {92 ,  1.243841405464130725547532e142},
        {93 ,  1.156772507081641574759205e144},
        {94 ,  1.087366156656743080273653e146},
        {95 ,  1.03299784882390592625997e148 },
        {96 ,  9.916779348709496892095714e149},
        {97 ,  9.619275968248211985332843e151},
        {98 ,  9.426890448883247745626186e153},
        {99 ,  9.332621544394415268169924e155},
        {100,  9.332621544394415268169924e157},
        {101,  9.425947759838359420851623e159},
        {102,  9.614466715035126609268656e161},
        {103,  9.902900716486180407546715e163},
        {104,  1.029901674514562762384858e166},
        {105,  1.081396758240290900504101e168},
        {106,  1.146280563734708354534347e170},
        {107,  1.226520203196137939351752e172},
        {108,  1.324641819451828974499892e174},
        {109,  1.443859583202493582204882e176},
        {110,  1.58824554152274294042537e178 },
        {111,  1.762952551090244663872161e180},
        {112,  1.97450685722107402353682e182 },
        {113,  2.231192748659813646596607e184},
        {114,  2.543559733472187557120132e186},
        {115,  2.925093693493015690688152e188},
        {116,  3.393108684451898201198256e190},
        {117,  3.96993716080872089540196e192 },
        {118,  4.684525849754290656574312e194},
        {119,  5.574585761207605881323432e196},
        {120,  6.689502913449127057588118e198},
        {121,  8.094298525273443739681623e200},
        {122,  9.87504420083360136241158e202 },
        {123,  1.214630436702532967576624e205},
        {124,  1.506141741511140879795014e207},
        {125,  1.882677176888926099743768e209},
        {126,  2.372173242880046885677147e211},
        {127,  3.012660018457659544809977e213},
        {128,  3.856204823625804217356771e215},
        {129,  4.974504222477287440390234e217},
        {130,  6.466855489220473672507304e219},
        {131,  8.471580690878820510984569e221},
        {132,  1.118248651196004307449963e224},
        {133,  1.487270706090685728908451e226},
        {134,  1.992942746161518876737324e228},
        {135,  2.690472707318050483595388e230},
        {136,  3.659042881952548657689727e232},
        {137,  5.012888748274991661034926e234},
        {138,  6.917786472619488492228198e236},
        {139,  9.615723196941089004197196e238},
        {140,  1.346201247571752460587607e241},
        {141,  1.898143759076170969428526e243},
        {142,  2.695364137888162776588508e245},
        {143,  3.854370717180072770521566e247},
        {144,  5.550293832739304789551055e249},
        {145,  8.047926057471991944849029e251},
        {146,  1.174997204390910823947958e254},
        {147,  1.727245890454638911203499e256},
        {148,  2.556323917872865588581178e258},
        {149,  3.808922637630569726985955e260},
        {150,  5.713383956445854590478933e262},
        {151,  8.627209774233240431623189e264},
        {152,  1.311335885683452545606725e267},
        {153,  2.006343905095682394778289e269},
        {154,  3.089769613847350887958565e271},
        {155,  4.789142901463393876335775e273},
        {156,  7.471062926282894447083809e275},
        {157,  1.172956879426414428192158e278},
        {158,  1.85327186949373479654361e280 },
        {159,  2.94670227249503832650434e282 },
        {160,  4.714723635992061322406943e284},
        {161,  7.590705053947218729075179e286},
        {162,  1.229694218739449434110179e289},
        {163,  2.004401576545302577599592e291},
        {164,  3.28721858553429622726333e293 },
        {165,  5.423910666131588774984495e295},
        {166,  9.003691705778437366474262e297},
        {167,  1.503616514864999040201202e300},
        {168,  2.526075744973198387538019e302},
        {169,  4.269068009004705274939252e304},
        {170,  7.257415615307998967396728e306}
    };

    // Table of (n / 2)! for odd n
    //
    // Mathematica:
    //      Table[{StringPadRight[ToString[n],4],
    //             StringPadRight[ToString[FortranForm[
    //                  SetPrecision[Factorial[n/2.],25]]],33]},{n,-341,341,2}]
    //
    static struct {int n; double f;} half_fact_table[] = {
        {-341,   5.648220884223258302751563e-306  },
        {-339,   -9.573734398758691626495438e-304 },
        {-337,   1.613174246190873678763457e-301  },
        {-335,   -2.702066862369875682438955e-299 },
        {-333,   4.498941325845179240367467e-297  },
        {-331,   -7.445747894274180505561967e-295 },
        {-329,   1.224825528608186508481267e-292  },
        {-327,   -2.002589739274137506478583e-290 },
        {-325,   3.254208326320831153037262e-288  },
        {-323,   -5.255546447008042972440442e-286 },
        {-321,   8.435152047447189069876869e-284  },
        {-319,   -1.345406751567836931205851e-281 },
        {-317,   2.132469701235085504149247e-279  },
        {-315,   -3.358639779445133337926535e-277 },
        {-313,   5.256271254832167930025176e-275  },
        {-311,   -8.173501801262896093685259e-273 },
        {-309,   1.262806028295134501645689e-270  },
        {-307,   -1.938407253433282310401723e-268 },
        {-305,   2.956071061485346092913969e-266  },
        {-303,   -4.478447658150595683117813e-264 },
        {-301,   6.740063725517600664670372e-262  },
        {-299,   -1.007639526964678697890431e-259 },
        {-297,   1.496344697542484001478583e-257  },
        {-295,   -2.207108428875399604071035e-255 },
        {-293,   3.233413848302257805714455e-253  },
        {-291,   -4.704617149279798215154178e-251 },
        {-289,   6.798171780708947545838963e-249  },
        {-287,   -9.755376505317351835755373e-247 },
        {-285,   1.390141152007910349639894e-244  },
        {-283,   -1.967049730091193027670282e-242 },
        {-281,   2.76370487077782012730677e-240   },
        {-279,   -3.855368294735538482445717e-238 },
        {-277,   5.339685088208354934685093e-236  },
        {-275,   -7.342066996286476630251334e-234 },
        {-273,   1.002192144993158069917549e-231  },
        {-271,   -1.357970356465642655571972e-229 },
        {-269,   1.826470129446300460200847e-227  },
        {-267,   -2.438337622810822407788123e-225 },
        {-265,   3.23079735022441864185803e-223   },
        {-263,   -4.248498515545340610245927e-221 },
        {-261,   5.544290562786242859703507e-219  },
        {-259,   -7.179856278808245162708776e-217 },
        {-257,   9.226115318268965001588949e-215  },
        {-255,   -1.176329703079211292310618e-212 },
        {-253,   1.488057074395329261931509e-210  },
        {-251,   -1.867511628366077045683961e-208 },
        {-249,   2.325051977315885161375243e-206  },
        {-247,   -2.871439191984952477636035e-204 },
        {-245,   3.517513010181584456759003e-202  },
        {-243,   -4.273778307371052788768926e-200 },
        {-241,   5.149902860381823346022332e-198  },
        {-239,   -6.154133918156128262981544e-196 },
        {-237,   7.292648693015065859062661e-194  },
        {-235,   -8.568862214292868506342309e-192 },
        {-233,   9.982724479650325450402021e-190  },
        {-231,   -1.153004677399743186686719e-187 },
        {-229,   1.32019035562262528241359e-185   },
        {-227,   -1.498416053631705526732367e-183 },
        {-225,   1.685718060335619165579182e-181  },
        {-223,   -1.879575637274228554723903e-179 },
        {-221,   2.076931079187949771200717e-177  },
        {-219,   -2.274239531710976436216637e-175 },
        {-217,   2.467549891906398818625391e-173  },
        {-215,   -2.652616133799474372530455e-171 },
        {-213,   2.825036182496245167921318e-169  },
        {-211,   -2.980413172533546762690521e-167 },
        {-209,   3.114531765297561463615559e-165  },
        {-207,   -3.223540377083161035223113e-163 },
        {-205,   3.304128886510081924090079e-161  },
        {-203,   -3.353690819807807582505163e-159 },
        {-201,   3.370459273906888121078096e-157  },
        {-199,   -3.353606977537328234348968e-155 },
        {-197,   3.303302872874071861971359e-153  },
        {-195,   -3.220720301052419627557364e-151 },
        {-193,   3.10799509051548603637549e-149   },
        {-191,   -2.968135311442299473216426e-147 },
        {-189,   2.804887869312893585797852e-145  },
        {-187,   -2.622570157807618012031648e-143 },
        {-185,   2.425877395971948697571819e-141  },
        {-183,   -2.219677817314298366796864e-139 },
        {-181,   2.008808424669588851275868e-137  },
        {-179,   -1.797883540079342349725074e-135 },
        {-177,   1.591126932970221495738444e-133  },
        {-175,   -1.392236066348803341330776e-131 },
        {-173,   1.204284197391773930430296e-129  },
        {-171,   -1.029662988769939595105295e-127 },
        {-169,   8.700652255106339044326175e-126  },
        {-167,   -7.265044633013580262115327e-124 },
        {-165,   5.993661822236589124996108e-122  },
        {-163,   -4.884834385122833379149212e-120 },
        {-161,   3.932291680023602434995258e-118  },
        {-159,   -3.126171885618868584070501e-116 },
        {-157,   2.454044930210605860345039e-114  },
        {-155,   -1.901884820913334818751417e-112 },
        {-153,   1.454941887998695190306604e-110  },
        {-151,   -1.098481125439025542004769e-108 },
        {-149,   8.183684384520632420745202e-107  },
        {-147,   -6.015008022622747176284238e-105 },
        {-145,   4.360880816401374800873939e-103  },
        {-143,   -3.118029783727024950368159e-101 },
        {-141,   2.198210997527553088080637e-99   },
        {-139,   -1.527756643281665444129869e-97  },
        {-137,   1.046513300647911884509894e-95   },
        {-135,   -7.063964779373463509583421e-94  },
        {-133,   4.697536578283427226570095e-92   },
        {-131,   -3.076886458775545139234902e-90  },
        {-129,   1.984591765910315943397587e-88   },
        {-127,   -1.260215771353010159066841e-86  },
        {-125,   7.876348570956253183723686e-85   },
        {-123,   -4.84395437113804515365775e-83   },
        {-121,   2.930592394538565125925152e-81   },
        {-119,   -1.743702474750413908905207e-79  },
        {-117,   1.020065947729006846911187e-77   },
        {-115,   -5.865379199441918578613421e-76  },
        {-113,   3.31393924768469058737456e-74    },
        {-111,   -1.839236282464997854390058e-72  },
        {-109,   1.002383773943416468730384e-70   },
        {-107,   -5.362753190597289239300844e-69  },
        {-105,   2.815445425063558201031797e-67   },
        {-103,   -1.449954393907755702605656e-65  },
        {-101,   7.322269689234132689631519e-64   },
        {-99 ,   -3.624523496170893623530563e-62  },
        {-97 ,   1.757893895642883277869795e-60   },
        {-95 ,   -8.349996004303695542245786e-59  },
        {-93 ,   3.882748142001216631926661e-57   },
        {-91 ,   -1.766650404610554730615412e-55  },
        {-89 ,   7.861594300516968352013645e-54   },
        {-87 ,   -3.419793520724879222040726e-52  },
        {-85 ,   1.453412246308074311059972e-50   },
        {-83 ,   -6.031660822178508011076176e-49  },
        {-81 ,   2.442822632982295053208519e-47   },
        {-79 ,   -9.649149400280068693224558e-46  },
        {-77 ,   3.714922519107826407997609e-44   },
        {-75 ,   -1.393095944665434611761988e-42  },
        {-73 ,   5.084800198028836946271644e-41   },
        {-71 ,   -1.805104070300237217884316e-39  },
        {-69 ,   6.227609042535819135797642e-38   },
        {-67 ,   -2.086249029249499901195106e-36  },
        {-65 ,   6.780309345060872724424901e-35   },
        {-63 ,   -2.135797443694174865429608e-33  },
        {-61 ,   6.514182203267231851364915e-32   },
        {-59 ,   -1.921683749963834146066281e-30  },
        {-57 ,   5.476798687396924128334895e-29   },
        {-55 ,   -1.506119639034154309053106e-27  },
        {-53 ,   3.991217043440508685814666e-26   },
        {-51 ,   -1.017760346077329608697947e-24  },
        {-49 ,   2.493512847889458983127261e-23   },
        {-47 ,   -5.859755192540226244666681e-22  },
        {-45 ,   1.318444918321550740480794e-20   },
        {-43 ,   -2.834656574391334588562521e-19  },
        {-41 ,   5.811045977502235497293055e-18   },
        {-39 ,   -1.133153965612936599899486e-16  },
        {-37 ,   2.09633483638393241399121e-15    },
        {-35 ,   -3.668585963671881211725029e-14  },
        {-33 ,   6.053166840058602453178924e-13   },
        {-31 ,   -9.382408602090834913143487e-12  },
        {-29 ,   1.360449247303170408093016e-10   },
        {-27 ,   -1.836606483859280386967696e-9   },
        {-25 ,   2.29575810482410127987096e-8     },
        {-23 ,   -2.640121820547716058261297e-7   },
        {-21 ,   2.772127911575102152341938e-6    },
        {-19 ,   -0.00002633521515996347574120433 },
        {-17 ,   0.0002238493288596894845079305   },
        {-15 ,   -0.00167886996644767117446706    },
        {-13 ,   0.01091265478190986577822219     },
        {-11 ,   -0.06001960130050425223924293    },
        {-9  ,   0.2700882058522691142599115      },
        {-7  ,   -0.9453087204829418999096902     },
        {-5  ,   2.363271801207354805285377       },
        {-3  ,   -3.544907701811032207928065      },
        {-1  ,   1.772453850905516103964032       },
        {1   ,   0.8862269254527580519820162      },
        {3   ,   1.329340388179137022461873       },
        {5   ,   3.323350970447842556154683       },
        {7   ,   11.63172839656744983471981       },
        {9   ,   52.34277778455351892716862       },
        {11  ,   287.8852778150443896265642       },
        {13  ,   1871.254305797788447307539       },
        {15  ,   14034.40729348341301374603       },
        {17  ,   119292.4619946090097073466       },
        {19  ,   1.133278388948785606771708e6     },
        {21  ,   1.189942308396224863827229e7     },
        {23  ,   1.368433654655658602714539e8     },
        {25  ,   1.710542068319573163986206e9     },
        {27  ,   2.309231792231423950195313e10    },
        {29  ,   3.348386098735564575195312e11    },
        {31  ,   5.1899984530401259765625e12      },
        {33  ,   8.5634974475162078125e13         },
        {35  ,   1.49861205331533575e15           },
        {37  ,   2.772432298633372e16             },
        {39  ,   5.40624298233507392e17           },
        {41  ,   1.1082798113786906624e19         },
        {43  ,   2.38280159446418456576e20        },
        {45  ,   5.36130358754441428992e21        },
        {47  ,   1.25990634307293762551808e23     },
        {49  ,   3.086770540528697685835776e24    },
        {51  ,   7.871264878348179259942502e25    },
        {53  ,   2.085885192762267873251951e27    },
        {55  ,   5.736184280096232899359434e28    },
        {57  ,   1.634812519827426706170927e30    },
        {59  ,   4.822696933490906841026896e31    },
        {61  ,   1.470922564714727171981155e33    },
        {63  ,   4.633406078851391384374172e34    },
        {65  ,   1.50585697562670228754364e36     },
        {67  ,   5.044620868349450877626368e37    },
        {69  ,   1.740394199580560699174458e39    },
        {71  ,   6.178399408510990270507308e40    },
        {73  ,   2.255115784106512246626208e42    },
        {75  ,   8.456684190399417582410175e43    },
        {77  ,   3.255823413303776398101457e45    },
        {79  ,   1.286050248254991864228539e47    },
        {81  ,   5.208503505432716015722694e48    },
        {83  ,   2.161528954754577350971607e50    },
        {85  ,   9.186498057706951041634962e51    },
        {87  ,   3.996126655102524287971527e53    },
        {89  ,   1.778276361520623116738498e55    },
        {91  ,   8.091157444918834350871191e56    },
        {93  ,   3.762388211887258199647047e58    },
        {95  ,   1.787134400646447321471542e60    },
        {97  ,   8.667601843135271257515402e61    },
        {99  ,   4.290462912352008712330199e63    },
        {101 ,   2.16668377073772795352967e65     },
        {103 ,   1.115842141929947815247055e67    },
        {105 ,   5.858171245132187650312521e68    },
        {107 ,   3.134121616145726843765616e70    },
        {109 ,   1.708096280799408437724191e72    },
        {111 ,   9.479934358436688533371595e73    },
        {113 ,   5.356162912516739548054562e75    },
        {115 ,   3.079793674697194033149048e77    },
        {117 ,   1.801679299697884212687598e79    },
        {119 ,   1.071999183320221192652968e81    },
        {121 ,   6.485595059087443348811231e82    },
        {123 ,   3.98864096133873640406052e84     },
        {125 ,   2.492900600836691139014036e86    },
        {127 ,   1.582991881531247990839146e88    },
        {129 ,   1.021029763587700890348086e90    },
        {131 ,   6.687744951499224581007056e91    },
        {133 ,   4.447350392747054444005714e93    },
        {135 ,   3.001961515104286436577283e95    },
        {137 ,   2.056343637846379701033752e97    },
        {139 ,   1.429158828303248505869314e99    },
        {141 ,   1.007556973953790301056319e101   },
        {143 ,   7.20403236376969944115119e102    },
        {145 ,   5.222923463732891720377904e104   },
        {147 ,   3.838848745843728358315932e106   },
        {149 ,   2.859942315653539693261418e108   },
        {151 ,   2.159256448318443244223775e110   },
        {153 ,   1.651831182963602660520161e112   },
        {155 ,   1.28016916679686956512473e114    },
        {157 ,   1.004932795935458235426204e116   },
        {159 ,   7.989215727687161609772341e117   },
        {161 ,   6.431318660787708383916995e119   },
        {163 ,   5.241524708541995993543483e121   },
        {165 ,   4.324257884547425460256152e123   },
        {167 ,   3.610755333596995162033308e125   },
        {169 ,   3.051088256889582607758282e127   },
        {171 ,   2.608680459640524657104009e129   },
        {173 ,   2.256508597589164457223068e131   },
        {175 ,   1.974445022890319720958762e133   },
        {177 ,   1.747383845257936909640358e135   },
        {179 ,   1.563908541505905932819866e137   },
        {181 ,   1.415337230062949639342732e139   },
        {183 ,   1.295033565507578675820611e141   },
        {185 ,   1.197906048094461687414591e143   },
        {187 ,   1.120042154968348810904977e145   },
        {189 ,   1.058439836445059618394271e147   },
        {191 ,   1.0108100438050354561916e149     },
        {193 ,   9.754316922718280406577346e150   },
        {195 ,   9.510458999650912760860895e152   },
        {197 ,   9.367802114655591517858755e154   },
        {199 ,   9.320963104082245205332179e156   },
        {201 ,   9.367567919602771500107894e158   },
        {203 ,   9.508081438397021927342993e160   },
        {205 ,   9.745783474356481311059046e162   },
        {207 ,   1.008688589595953748155197e165   },
        {209 ,   1.054079576127773273852382e167   },
        {211 ,   1.112053952814803936549075e169   },
        {213 ,   1.184337459747684307589784e171   },
        {215 ,   1.273162769228806665563077e173   },
        {217 ,   1.381381604613249030477733e175   },
        {219 ,   1.512612857051621962540887e177   },
        {221 ,   1.67143720704198363089001e179    },
        {223 ,   1.863652485851825142968424e181   },
        {225 ,   2.096609046583241459563444e183   },
        {227 ,   2.379651267872019842524052e185   },
        {229 ,   2.724700701713296239640386e187   },
        {231 ,   3.147029310479213612064425e189   },
        {233 ,   3.666289146707966065695506e191   },
        {235 ,   4.307889747381943581614149e193   },
        {237 ,   5.104849350647640550636806e195   },
        {239 ,   6.100294974023781547457899e197   },
        {241 ,   7.350855443698236315851655e199   },
        {243 ,   8.931289364094250646582316e201   },
        {245 ,   1.09408294710155095541895e204    },
        {247 ,   1.351192439670337511454292e206   },
        {249 ,   1.682234587389656496938689e208   },
        {251 ,   2.111204407173950103194152e210   },
        {253 ,   2.670673575075274751454751e212   },
        {255 ,   3.405108808220737958643626e214   },
        {257 ,   4.375564818563823902302154e216   },
        {259 ,   5.666356440040199907425296e218   },
        {261 ,   7.394595154251890339563226e220   },
        {263 ,   9.723892627841764761798807e222   },
        {265 ,   1.288415773189065378911623e225   },
        {267 ,   1.720035057207410048588329e227   },
        {269 ,   2.313447151943980606203356e229   },
        {271 ,   3.134720890883893680709591e231   },
        {273 ,   4.27889401605674597310385e233    },
        {275 ,   5.883479272078017523377313e235   },
        {277 ,   8.148618791827496244719338e237   },
        {279 ,   1.136732321460076725495384e240   },
        {281 ,   1.597108911651230999426634e242   },
        {283 ,   2.259909109986492022908647e244   },
        {285 ,   3.220370481731186206130486e246   },
        {287 ,   4.621231641284257109813772e248   },
        {289 ,   6.677679721655396933516677e250   },
        {291 ,   9.71602399500862981886628e252    },
        {293 ,   1.423397515268675050398239e255   },
        {295 ,   2.099511335021519885275777e257   },
        {297 ,   3.117774332506824245462319e259   },
        {299 ,   4.661072627096764694690952e261   },
        {301 ,   7.01491430378162459212595e263    },
        {303 ,   1.062759517022986450996809e266   },
        {305 ,   1.620708263459829927614864e268   },
        {307 ,   2.48778718441116065962921e270    },
        {309 ,   3.843631199915295741245644e272   },
        {311 ,   5.976846515867460083820123e274   },
        {313 ,   9.353764797333527037165304e276   },
        {315 ,   1.473217955579975375387065e279   },
        {317 ,   2.335050459594330613155076e281   },
        {319 ,   3.724405483052985774114877e283   },
        {321 ,   5.977670800299531909228718e285   },
        {323 ,   9.653938342483561771791138e287   },
        {325 ,   1.568764980653751287491638e290   },
        {327 ,   2.564930743368566519361964e292   },
        {329 ,   4.219311072841580243440584e294   },
        {331 ,   6.982959825553198918359215e296   },
        {333 ,   1.162662810954436182395427e299   },
        {335 ,   1.947460208348797528722468e301   },
        {337 ,   3.281470451067793253415487e303   },
        {339 ,   5.562092414560065367747007e305   },
        {341 ,   9.483367566825812901350953e307   }
    };

    // Factorial of n
    double factorial(int n) {
        if ((n < 0) || (n > STARRY_MAX_FACT)) {
            // TODO: Better error handling
            std::cout << "ERROR: Factorial argument out of bounds." << std::endl;
            return NAN;
        } else {
            return fact_table[n].f;
        }
    }

    // Factorial of (n / 2)
    double half_factorial(int n) {
        if ((n < -STARRY_MAX_HALF_FACT) || (n > STARRY_MAX_HALF_FACT)) {
            // TODO: Better error handling
            std::cout << "ERROR: Half factorial argument out of bounds." << std::endl;
            return NAN;
        } else if (n % 2 == 0) {
            if (n < 0)
                return INFINITY;
            else
                return fact_table[n / 2].f;
        } else {
            return half_fact_table[(n + STARRY_MAX_HALF_FACT) / 2].f;
        }
    }

    // Gamma function
    #define gamma(n)           factorial(n - 1)

    // Gamma of n + 1/2
    #define gamma_sup(n)       half_factorial(2 * (n) - 1)

}; // namespace fact

#endif
