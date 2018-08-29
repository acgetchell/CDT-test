cmake_minimum_required(VERSION 3.11)

project(CDT-test VERSION 0.1.0 LANGUAGES CXX)

#Set mimumum Boost
set(BOOST_MIN_VERSION "1.64.0")
#Compile commands for ClangTidy et. al
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

###############
##  OPTIONS  ##
###############

#Turn on / off TBB
set(TBB_ON FALSE)

#Threads
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)

#Compiler flags
if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS  "-frounding-math")
endif()

#Turn off CGAL Triangulation Assertions and Postconditions
add_definitions(-DCGAL_TRIANGULATION_NO_ASSERTIONS -DCGAL_TRIANGULATION_NO_POSTCONDITIONS)

#Disable CLion generation of RelWithDebInfo and MinSizeRel to avoid conflicts
#with CGAL_SetupFlags.cmake
set(CMAKE_CONFIGURATION_TYPES "Release" "Debug" CACHE STRING "" FORCE)

#Extra warnings
add_compile_options(-Wall -Wno-comment)

#Easier navigation in an IDE when projects are organized in folders.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

###############
##  Project  ##
###############

#Vcpkg
set(CMAKE_TOOLCHAIN_FILE "${PROJECT_SOURCE_DIR}/../vcpkg/scripts/buildsystems/vcpkg.cmake")

#Boost
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREAD ON)
find_package(Boost ${BOOST_MIN_VERSION} REQUIRED)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
else()
    message(FATAL_ERROR "Boost >= ${BOOST_MIN_VERSION} required.\n")
endif ()

#CGAL
find_package(CGAL QUIET COMPONENTS Core )
if(CGAL_FOUND)
    #Don't let CGAL override flags
    set(CGAL_DONT_OVERRIDE_CMAKE_FLAGS TRUE CACHE BOOL "Force CGAL to maintain CMAKE flags")
    set(CGAL_DO_NOT_WARN_ABOUT_CMAKE_BUILD_TYPE TRUE)
    include(${CGAL_USE_FILE})
    include(CGAL_CreateSingleSourceCGALProgram)
    #TBB
    find_package(TBB)
    if(TBB_FOUND AND TBB_ON)
        include(${TBB_USE_FILE})
        list(APPEND CGAL_3RD_PARTY_LIBRARIES ${TBB_LIBRARIES})
        MESSAGE(${TBB_LIBRARIES})
    endif()
else()
    message(FATAL_ERROR "Notice: This program requires the CGAL library, and will not be compiled.")
endif()

#Eigen
find_package(Eigen3 REQUIRED)

#Curl
find_package(CURL)
if(CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIR})
else()
    message(FATAL_ERROR "Notice: This program requires the Curl library, and will not be compiled.")
endif()

#Date
find_package(unofficial-date CONFIG REQUIRED)


include_directories(BEFORE ${PROJECT_SOURCE_DIR}/include)
add_executable(cdt-opt ${PROJECT_SOURCE_DIR}/src/cdt-opt.cpp)
target_link_libraries(cdt-opt PRIVATE ${CGAL_LIBRARIES} ${CGAL_3RD_PARTY_LIBRARIES} Eigen3::Eigen unofficial::date::tz unofficial::date::date)
target_compile_features(cdt-opt PRIVATE cxx_std_17)