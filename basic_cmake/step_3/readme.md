# Setp 3: Make `mysqrt` optional.

This is useful when working with working with third party software.

We need to specify whether we want to use it or not at the very beginning:
```
# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# should we use our own math functions
option(USE_MYMATH "Use tutorial provided math implementation" ON)
```
And then add the conditional instruction:
```
# add the MathFunctions library?
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory (MathFunctions)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

# add the executable
add_executable (Tutorial tutorial.cxx)
target_link_libraries (Tutorial  ${EXTRA_LIBS})
```
Notice that we added the extravariable `EXTRA_LIBS`.

Modify the ``main.cpp``. Include the library if necessary.
```
#ifdef USE_MYMATH
#include "MathFuncs.h"
#endif
```
And use it if required:
```c++
  #ifdef USE_MYMATH
    fprintf(stdout, "mysqrt\n");
    double outputValue = mysqrt(inputValue);
  #else
    fprintf(stdout, "sqrt\n");
    double outputValue = sqrt(inputValue);
  #endif
```