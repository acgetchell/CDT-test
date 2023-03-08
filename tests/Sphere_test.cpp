/// Causal Dynamical Triangulations in C++ using CGAL
///
/// Copyright © 2014-2019 Adam Getchell
///
/// Tests that 2-spheres and 3-spheres are correctly constructed
/// in 3D and 4D respectively.

/// @file Sphere_test.cpp
/// @brief Tests for spheres
/// @author Adam Getchell

#include <doctest/doctest.h>

#include <Sphere_d.hpp>

SCENARIO("Construct a higher-dimensional 3-sphere" *
         doctest::test_suite("sphere"))
{
  GIVEN("Number of points and dimensionality 4.")
  {
    std::vector<Kd::Point_d> points;
    auto constexpr number_of_points{50};
    auto constexpr dim{4};
    auto constexpr radius{1.0};
    WHEN("A 3-sphere is constructed.")
    {
      make_d_sphere(number_of_points, dim, radius, points);
      THEN("We have the correct number of points.")
      {
        REQUIRE(points.size() == number_of_points);
        fmt::print("3-sphere has {} points.\n", number_of_points);
      }
    }
  }
}
