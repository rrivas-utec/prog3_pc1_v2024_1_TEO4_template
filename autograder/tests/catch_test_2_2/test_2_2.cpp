//
// Created by rudri on 9/12/2020.
//
#include <deque>
#include "catch.hpp"
#include "redirect_io.h"
#include "counter.h"
using namespace std;

static void test_2_2() {
  deque d1 = {1, 3, 4, 1, 2, 4, 2, 1, 4, 5, 1};
  std::cout << utec::counter(d1, 4);
}

TEST_CASE("Question #2.2") {
    execute_test("test_2_2.in", test_2_2);
}