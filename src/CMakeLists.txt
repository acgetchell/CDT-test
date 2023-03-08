add_executable(initialize ${PROJECT_SOURCE_DIR}/src/initialize.cpp)

# On macOS and Linux docopt builds an intermediate object, thus different targets than Windows See
# https://github.com/microsoft/vcpkg/issues/8666
if(WIN32)
  target_link_libraries(
    initialize
    PRIVATE project_options
            project_warnings
            date::date-tz
            docopt
            fmt::fmt-header-only
            Eigen3::Eigen
            spdlog::spdlog_header_only
            TBB::tbb
            CGAL::CGAL)
else()
  target_link_libraries(
    initialize
    PRIVATE project_options
            project_warnings
            date::date-tz
            docopt_s
            fmt::fmt-header-only
            Eigen3::Eigen
            spdlog::spdlog_header_only
            TBB::tbb
            CGAL::CGAL)
endif()
target_compile_features(initialize PRIVATE cxx_std_20)

#
# Tests    ##
#

add_test(NAME initialize COMMAND $<TARGET_FILE:initialize> --s -n640 -t4 -o)
set_tests_properties(initialize PROPERTIES PASS_REGULAR_EXPRESSION "Writing to file S3-4")
