# CDT-test

[![Windows Build status](https://img.shields.io/appveyor/ci/acgetchell/cdt-test.svg?label=Windows)](https://ci.appveyor.com/project/acgetchell/cdt-test)

## Setup

This project is a test case of [CDT-plusplus] using [vcpkg]. To get started:

```bash
git clone https://github.com/Microsft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
sudo ./vcpkg integrate install

```

Note that this helpfully installs up to date versions of [CMake] and [Ninja].

Now, we need to install prerequisites [curl], [date], [boost], [eigen3], [tbb], and [CGAL] :

```bash
./vcpkg install curl
./vcpkg install date
./vcpkg install boost
./vcpkg install eigen3
./vcpkg install tbb
./vcpkg install cgal

```

This builds from source, so it may take awhile. To use these successfully, you'll need to set the `CMAKE_TOOLCHAIN_FILE` option in your IDE or whatever invokes `CMake` to wherever you've installed `vcpkg`, for example:

```bash
-DCMAKE_TOOLCHAIN_FILE=/Users/adam/vcpkg/scripts/buildsystems/vcpkg.cmake
```

(I set it in [CLion].)


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
