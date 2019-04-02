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

For MacOS, you may need to install gcc6 or greater:

```bash
brew install gcc
```

Now, we need to install prerequisites [curl], [date], [gsl], [catch2], [eigen3], [tbb], and [CGAL] (which installs [boost]):

```bash
./vcpkg install curl
./vcpkg install date
./vcpkg install gsl
./vcpkg install catch2
./vcpkg install eigen3
./vcpkg install tbb
./vcpkg install cgal

```

This builds from source, so it will take awhile. To use these successfully, you'll need to set the `CMAKE_TOOLCHAIN_FILE` option in your IDE or whatever invokes `CMake` to wherever you've installed `vcpkg`, for example:

```bash
-DCMAKE_TOOLCHAIN_FILE=/Users/adam/vcpkg/scripts/buildsystems/vcpkg.cmake
```

N.B. As of 2018-11-29, the `vcpkg` formula for [date] is [broken][1].
The formula for [cgal] is broken on MacOS and Linux as it relies on the formula for [mpir], which [doesn't build][2] on those platforms.
You can use [homebrew] to successfully install [CGAL], but HomeBrew 2.0 does not support options anymore, and the
default CGAL package does not install with Qt support. Hence, the demos cannot be run.


[CDT-plusplus]:https://github.com/acgetchell/CDT-plusplus
[vcpkg]:https://github.com/Microsoft/vcpkg
[CMake]:https:://cmake.org
[Ninja]:https://ninja-build.org
[CGAL]: https://www.cgal.org/
[curl]: https://curl.haxx.se/libcurl/
[date]: https://github.com/HowardHinnant/date
[eigen3]: https://eigen.tuxfamily.org/dox/
[tbb]: https://www.threadingbuildingblocks.org/
[CLion]: https://www.jetbrains.com/clion/
[boost]: https://www.boost.org/
[1]: https://github.com/Microsoft/vcpkg/issues/4864
[gsl]: https://github.com/Microsoft/GSL
[2]: https://github.com/Microsoft/vcpkg/issues/3772
[catch2]: https://github.com/catchorg/Catch2
[homebrew]: https://brew.sh
[mpir]: http://mpir.org