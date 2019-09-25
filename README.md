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

N.B. As of 2018-11-29, the `vcpkg` formula for [date] is [broken][1]. It installs, but doesn't seem to link. I can't tell, because of the next issue.

As of 2019-09-24, the formula for [mpfr] is [fixed][2], which also fixes the formula install for [cgal].

However, there is an [issue](https://github.com/microsoft/vcpkg/issues/8328) with actually using the library; `find_package()` misses targets:

```bash
CMake Error at /Users/adam/vcpkg/scripts/buildsystems/vcpkg.cmake:166 (_add_executable):
  Target "cdt-opt" links to target "CGAL::" but the target was not found.
  Perhaps a find_package() call is missing for an IMPORTED target, or an
  ALIAS target is missing?
Call Stack (most recent call first):
  CMakeLists.txt:71 (add_executable)


CMake Error at /Users/adam/vcpkg/scripts/buildsystems/vcpkg.cmake:166 (_add_executable):
  Target "cdt-opt" links to target "CGAL::Qt5_moc_and_resources" but the
  target was not found.  Perhaps a find_package() call is missing for an
  IMPORTED target, or an ALIAS target is missing?
Call Stack (most recent call first):
  CMakeLists.txt:71 (add_executable)
```
This is after I did a `git pull`, `./bootstrap-vcpkg.sh`, and `./vcpkg update` on 2019-09-25 to ensure up-to-date ports and binaries.

You can use [homebrew] to successfully install [CGAL], but HomeBrew 2.0 does not support options anymore, and the
default CGAL package does not install with Qt support. Hence, the demos cannot be run if CGAL is install with `brew install cgal`.


[CDT-plusplus]:https://github.com/acgetchell/CDT-plusplus
[vcpkg]:https://github.com/Microsoft/vcpkg
[CMake]:https:://cmake.org
[Ninja]:https://ninja-build.org
[CGAL]: https://www.cgal.org/
[date]: https://github.com/HowardHinnant/date
[eigen3]: https://eigen.tuxfamily.org/dox/
[CLion]: https://www.jetbrains.com/clion/
[boost]: https://www.boost.org/
[1]: https://github.com/Microsoft/vcpkg/issues/4864
[2]: https://github.com/Microsoft/vcpkg/issues/5910
[catch2]: https://github.com/catchorg/Catch2
[homebrew]: https://brew.sh
[mpfr]: http://mpfr.org