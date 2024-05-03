//
// Created by rudri on 9/12/2020.
//
#include <utility>
#include "catch.hpp"
#include "redirect_io.h"
#include "board.h"
using namespace std;

static void test_1_3() {
  utec::board<char, 5, 5> b1(char{});
  std::cout << b1.rows() << " " << b1.cols() << std::endl;
  b1(1,1) = 'b';
  b1(3,3) = 'w';
  std::cout << b1;
  
  utec::board<char, 5, 5> b2(char{});
  b2(0,0) = 'w';
  b2(3,0) = 'w';
  b2(3,3) = 'w';
  b2(0,3) = 'w';
  std::cout << b2;
  std::swap(b1, b2);
  std::cout << b1;
  std::cout << b2;
}

TEST_CASE("Question #1.3") {
    execute_test("test_1_3.in", test_1_3);
}