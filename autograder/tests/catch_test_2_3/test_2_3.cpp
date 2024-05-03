//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "board.h"
#include "counter.h"

using namespace std;

static void test_2_3() {
  int arr[] = {5, 2, 3, 2, 1, 2, 1, 2, 4, 2, 6, 4, 2};
  std::cout << utec::counter(arr, 2) << std::endl;
}

TEST_CASE("Question #2.3") {
    execute_test("test_2_3.in", test_2_3);
}