//
// Created by rudri on 9/12/2020.
//
#include <vector>
#include "catch.hpp"
#include "redirect_io.h"
#include "counter.h"
using namespace std;

static void test_2_1() {
  vector v1 = {1, 3, 4, 1, 2, 1, 2, 1, 4, 5, 1};
  std::cout << utec::counter(v1, 1);
}

TEST_CASE("Question #2.1") {
    execute_test("test_2_1.in", test_2_1);
}