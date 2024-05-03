//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "board.h"
using namespace std;

class checkers_piece {
  std::string color{};
public:
  checkers_piece() = default;
  explicit checkers_piece(std::string color): color(std::move(color)) {}
  friend ostream& operator <<(ostream& os, const checkers_piece& cp) {
    os << cp.color;
    return os;
  }
  bool operator==(const checkers_piece& other) const { return color == other.color; }
};

static void test_1_2() {
  utec::board<checkers_piece, 5, 5> b1(checkers_piece{});
  std::cout << b1.rows() << " " << b1.cols() << std::endl;
  b1(1,1) = checkers_piece{"b"};
  b1(3,3) = checkers_piece{"w"};
  std::cout << b1;
}

TEST_CASE("Question #1.2") {
    execute_test("test_1_2.in", test_1_2);
}