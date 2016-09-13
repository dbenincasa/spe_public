# Setp 2: link a library.

Now we have our own library to evaluate the square root of a number.

Prepare the library:

 - Prepare a `MathFuncs` directory.
 - Locate the provided file `mysqrt.cpp`.
 - Prepare the corresponding header file `MathFuncs.h`.
 - We need to tell cmake that MathFuncs contains a library. This is done adding a minimal `CMakeList.txr` to the `MathFuncs` directory. `add_library(MathFuncs mysqrt.cpp`.

Tell `cmake` that you want to use it:
```shell
include_directories ("${PROJECT_SOURCE_DIR}/MathFuncs")
add_subdirectory (MathFuncs)

# add the executable
add_executable (Tutorial main.cpp)
target_link_libraries (Tutorial MathFuncs)
```

Now use it:
- `#include "MathFuncs.h"`
- `double outputValue = sqrt(inputValue);` -> `double outputValue = mysqrt(inputValue);`

