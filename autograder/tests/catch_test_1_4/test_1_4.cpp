//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "board.h"
using namespace std;

static void test_1_4() {
  utec::board<char, 5, 5> b1(char{}); // char{} es el valor vacío
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
  b1 = std::move(b2); // uso asignación move: b1 ahora tiene los valores de b2
  std::cout << b1;
  std::cout << b2.rows() << " " << b2.cols() << std::endl;
  std::cout << b2;
  utec::board<char, 5, 5> b3 = b1; // uso constructor copia: b3 es un clone de b1
  b2 = b3; // uso asignación copia: b2 es un clone de b3
  b2(0,0) = 'w';
  b2(1,1) = 'w';
  std::cout << b2;
  std::cout << b3;
}

TEST_CASE("Question #1.4") {
    execute_test("test_1_4.in", test_1_4);
}