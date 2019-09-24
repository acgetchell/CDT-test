cmake_minimum_required(VERSION 3.11)

project(CDT-test VERSION 0.1.0 LANGUAGES CXX)

# Set mimumum Boost
set(BOOST_MIN_VERSION "1.70.0")
# Compile commands for ClangTidy et. al
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

#
# OPTIONS  ##
#

# Turn on / off TBB
set(TBB_ON FALSE)

# Threads
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)

# Compiler flags
if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "-frounding-math")
endif()

# Turn off CGAL Triangulation Assertions and Postconditions
add_definitions(-DCGAL_TRIANGULATION_NO_ASSERTIONS
                -DCGAL_TRIANGULATION_NO_POSTCONDITIONS)

# Disable CLion generation of RelWithDebInfo and MinSizeRel to avoid conflicts
# with CGAL_SetupFlags.cmake
set(CMAKE_CONFIGURATION_TYPES "Release" "Debug" CACHE STRING "" FORCE)

# Extra warnings
add_compile_options(-Wall -Wno-comment)

# Easier navigation in an IDE when projects are organized in folders.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#
# Project  ##
#

# Date
find_package(date CONFIG REQUIRED)

# Catch
find_package(Catch2 CONFIG REQUIRED)

find_package(BOOST REQUIRED)

find_package(Eigen3 CONFIG REQUIRED)

# find_package(TBB CONFIG REQUIRED)

# CGAL
find_package(CGAL CONFIG REQUIRED)
# Don't let CGAL override flags
set(CGAL_DONT_OVERRIDE_CMAKE_FLAGS TRUE
    CACHE BOOL "Force CGAL to maintain CMAKE flags")
set(CGAL_DO_NOT_WARN_ABOUT_CMAKE_BUILD_TYPE TRUE)

include_directories(BEFORE ${PROJECT_SOURCE_DIR}/include)
add_executable(cdt-opt ${PROJECT_SOURCE_DIR}/src/cdt-opt.cpp)
target_link_libraries(cdt-opt
                      PRIVATE date::tz
                              date::date
                              Catch2::Catch2
                              Eigen3::Eigen
                              ${cgal_lib}
                              CGAL::${cgal_lib}
                              CGAL_Qt5_moc_and_resources
                              CGAL::Qt5_moc_and_resources)
target_compile_features(cdt-opt PRIVATE cxx_std_17)

# Tests
enable_testing()

# CTest basic testing
add_test(NAME CDT-Opt COMMAND $<TARGET_FILE:cdt-opt>)
set_tests_properties(CDT-Opt
                     PROPERTIES PASS_REGULAR_EXPRESSION
                                "64000 simplices on 16 timeslices desired.")
