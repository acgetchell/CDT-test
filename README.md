# CDT-test
[![macOS](https://github.com/acgetchell/CDT-test/actions/workflows/macos.yml/badge.svg)](https://github.com/acgetchell/CDT-test/actions/workflows/macos.yml)
[![Linux GCC](https://github.com/acgetchell/CDT-test/actions/workflows/linux-gcc.yml/badge.svg)](https://github.com/acgetchell/CDT-test/actions/workflows/linux-gcc.yml)
[![Linux Clang](https://github.com/acgetchell/CDT-test/actions/workflows/linux-clang.yml/badge.svg)](https://github.com/acgetchell/CDT-test/actions/workflows/linux-clang.yml)
[![Windows Build status](https://img.shields.io/appveyor/ci/acgetchell/cdt-test.svg?label=Windows)](https://ci.appveyor.com/project/acgetchell/cdt-test)

## Setup

This project is a clean build of [CDT-plusplus] using [vcpkg]. To get started:

```bash
git clone https://github.com/acgetchell/CDT-test.git
```

Next, install [vcpkg]:

```bash
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
```

Compile via script:

```bash
cd scripts
./fast-build.sh
```

Or, if you want to build with tests:

```bash
./build.sh
```


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
[mpir]: http://mpir.org/
[mpfr]: https://www.mpfr.org/
[apt]: https://wiki.debian.org/Apt
[tbb]: https://github.com/intel/tbb
[2]: https://github.com/microsoft/vcpkg/issues/8626
[3]: https://github.com/microsoft/vcpkg/issues/8627
[docopt]: https://github.com/docopt/docopt.cpp
[ms-gsl]: https://github.com/microsoft/GSL