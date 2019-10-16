# CDT-test

[![Windows Build status](https://img.shields.io/appveyor/ci/acgetchell/cdt-test.svg?label=Windows)](https://ci.appveyor.com/project/acgetchell/cdt-test)

## Setup

This project is a test case of [CDT-plusplus] using [vcpkg]. To get started:

```bash
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
./vcpkg integrate install

```

Note that this helpfully installs up to date versions of [CMake] and [Ninja].

For MacOS, you may need to install gcc with [homebrew]:

```bash
brew install gcc
```

You will also need to install `yasm` so that `vcpkg` can install `mpir`, which is required for [CGAL]:

```bash
brew install yasm
```

At minimum, we need to install prerequisites [date], [catch2], [eigen3], [boost], and [CGAL]:

```bash
./vcpkg install date
./vcpkg install catch2
./vcpkg install eigen3
./vcpkg install boost
./vcpkg install cgal

```

This builds from source, so it will take awhile. To use these successfully, you'll need to set the `CMAKE_TOOLCHAIN_FILE` option in your IDE or whatever invokes `CMake` to wherever you've installed `vcpkg`, for example:

```bash
-DCMAKE_TOOLCHAIN_FILE=/Users/adam/vcpkg/scripts/buildsystems/vcpkg.cmake
```

N.B. As of 2018-11-29, the `vcpkg` formula for [date] is [broken][1]. It installs, but doesn't seem to link.


[CDT-plusplus]:https://github.com/acgetchell/CDT-plusplus
[vcpkg]:https://github.com/Microsoft/vcpkg
[CMake]:https:://cmake.org
[Ninja]:https://ninja-build.org
[homebrew]: https://brew.sh
[CGAL]: https://www.cgal.org/
[date]: https://github.com/HowardHinnant/date
[eigen3]: https://eigen.tuxfamily.org/dox/
[CLion]: https://www.jetbrains.com/clion/
[boost]: https://www.boost.org/
[1]: https://github.com/Microsoft/vcpkg/issues/4864
[catch2]: https://github.com/catchorg/Catch2