cmake_minimum_required(VERSION 3.11)

add_executable(CDT_test ${PROJECT_SOURCE_DIR}/tests/main.cpp
    Tetrahedron_test.cpp
    Utilities_test.cpp
    Foliated_triangulation_test.cpp)

target_link_libraries(CDT_test
    #date::tz date::date
    Catch2::Catch2 CGAL::CGAL)

# Activate C++17
target_compile_features(CDT_test PRIVATE cxx_std_17)

# Run unit tests
add_test(NAME CDT-unit-tests COMMAND $<TARGET_FILE:CDT_test>)