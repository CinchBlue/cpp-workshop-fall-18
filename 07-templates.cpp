#include <iostream>

// Have you ever heard of copy-and-paste?
//
// And this phrase:
//
//  If it looks like a duck,
//  walks like a duck,
//  talks like a duck,
//  quacks like a duck,
//    it might as well be a duck.
//
// Lookup: Duck Typing.

// In C++, you can play "copy-and-paste" to make "generic" code that "just
// works" with more than one type.
//
// Creating "holes" that are "filled in later" can be accomplished using
// templates.

template <typename T>
T add(T lhs, T rhs) {
  return lhs + rhs;
}

void using_add() {
  std::cout << add<int>(1, 2) << std::endl;
  std::cout << add<float>(3.14, 2.12) << std::endl;

  // BUT HOW DOES IT WORK WITH int AND float AT THE SAME TIME?!

  // Because it basically copy-pasted the type into the T's.
}

template <typename Left, typename Right>
class Pair {
  Left left;
  Right right;
public:
  Pair(Left l, Right r) :
      left(l),
      right(r) {}

  Left& first() { return left; }
  Right& second() { return right; }
};

int main() {
  Pair<int, int> point2d(1, 2);
  std::cout << point2d.first() << ", " << point2d.second() << std::endl;
}
