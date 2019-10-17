# CDT-test
[![Build Status](https://img.shields.io/travis/com/acgetchell/CDT-test.svg?label=Linux/MacOS)](https://travis-ci.com/acgetchell/CDT-test)
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

You will also need to install `yasm` so that `vcpkg` can install [mpir], which is required for [CGAL].

MacOS using [homebrew]:

```bash
brew install yasm
```
Linux using [apt]:
```bash
sudo apt-get install yasm
```

At minimum, we need to install prerequisites [date], [catch2], [eigen3], [boost], and [CGAL] (which
installs [mpir] and [mpfr]):

```bash
./vcpkg install date
./vcpkg install catch2
./vcpkg install docopt
./vcpkg install ms-gsl
./vcpkg install eigen3
./vcpkg install boost
./vcpkg install cgal

```

This builds from source, so it will take awhile. To use these successfully, you'll need to set the
`CMAKE_TOOLCHAIN_FILE` option in your IDE or whatever invokes [CMake] to wherever you've installed
[vcpkg], (e.g. your home directory):

```bash
-DCMAKE_TOOLCHAIN_FILE=$HOME/vcpkg/scripts/buildsystems/vcpkg.cmake
```

N.B.

- As of 2018-11-29, the [vcpkg] formula for [date] is [broken][1].

- As of 2019-10-16 the [vcpkg] formula for [tbb] doesn't [build][2].

- As of 2019-10-16 [vcpkg] doesn't [build][3] on macOS 10.14 (but does on 10.15).


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
