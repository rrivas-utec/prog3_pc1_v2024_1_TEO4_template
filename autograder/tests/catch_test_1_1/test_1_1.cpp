//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "board.h"
#include <string>
using namespace std;

static void test_1_1() {
  utec::board<int, 5, 5> b1(-1);
  std::cout << b1.rows() << " " << b1.cols() << std::endl;
  std::cout << b1;
}

TEST_CASE("Question #1.1") {
  execute_test("test_1_1.in", test_1_1);
}
