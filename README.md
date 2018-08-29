#CDT-test

##Setup

This project is a test case of [CDT-plusplus] using [vcpkg]. To get started:

```bash
git clone https://github.com/Microsft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
sudo ./vcpkg integrate install

```

Note that this helpfully installs up to date versions of [CMake] and [Ninja].

Now, we need to install prerequisites [eigen3], [CGAL], [curl], and [date]:

```bash
./vcpkg install curl
./vcpkg install date
./vcpkg install

```

This is building from source, so it may take awhile.


[CDT-plusplus]:https://github.com/acgetchell/CDT-plusplus
[vcpkg]:https://github.com/Microsoft/vcpkg
[CMake]:https:://cmake.org
[Ninja]:https://ninja-build.org
[CGAL]: https://www.cgal.org/
[curl]: https://curl.haxx.se/libcurl/
[date]: https://github.com/HowardHinnant/date
[eigen3]: https://eigen.tuxfamily.org/dox/
