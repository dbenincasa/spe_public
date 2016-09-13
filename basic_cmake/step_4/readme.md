# Setp 4: Installing.

To install the library `MathFuncs` change related `CMakeLists.txt`:
````
add_library(MathFuncs mysqrt.cpp)

install (TARGETS MathFuncs DESTINATION bin)
install (FILES MathFuncs.h DESTINATION include)
````
To install your application:
```
# add the executable
add_executable (Tutorial tutorial.cxx)
target_link_libraries (Tutorial  ${EXTRA_LIBS})

# add the install targets
install (TARGETS Tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" 
  DESTINATION include)
```
Run:
```
cmake -DCMAKE_INSTALL_PREFIX=/Users/nicola/mhpc_tmp/basic_cmake/step_4/build ../
```
Then classical `make`, `make install`.