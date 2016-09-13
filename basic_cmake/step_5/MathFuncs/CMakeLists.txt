add_library(MathFuncs mysqrt.cpp)

install (TARGETS MathFuncs DESTINATION bin)
install (FILES MathFuncs.h DESTINATION include)
