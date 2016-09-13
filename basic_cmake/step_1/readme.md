# Setp 1: Adding version number.

The same steps as the previous example are still true.

The goal is to add a version number to our tutorial without hard coding it.

This is done prepering a minimal `TutorialConfig.h.in`

```
// the configured options and settings for Tutorial
#define Tutorial_VERSION_MAJOR @Tutorial_VERSION_MAJOR@
#define Tutorial_VERSION_MINOR @Tutorial_VERSION_MINOR@
```
And the version number will be specified in the `CMakeLists.txt`
```
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)
```
