//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "board.h"
#include "counter.h"
using namespace std;

static void test_2_4() {
  utec::board<char, 5, 5> b2(char{});
  b2(0,0) = 'w';
  b2(3,0) = 'w';
  b2(3,3) = 'w';
  b2(0,3) = 'w';
  b2(2,2) = 'b';
  b2(2,3) = 'b';
  b2(3,2) = 'b';
  std::cout << utec::counter(b2, char{});
}

TEST_CASE("Question #2.4") {
    execute_test("test_2_4.in", test_2_4);
}