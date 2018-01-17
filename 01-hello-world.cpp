#include <iostream>

// This is how you make a comment.

/*
 * This is how you make a block comment
 */

/**
 * This is how you make a documentation block comment.
 * More on this later.
 */

// All C++ programs start in the main() function.
//
// All C++ programs must return an int back to the OS/execution
// environemnt.
int main() {
  // Unlike in Java or C, in C++, you can define new "overloads" of
  // the in-built operators like +, /, -, *.
  //
  // In C++, the << and >> operators have been overloaded for output and
  // input, respectively.
  std::cout << "Hello World" << std::endl;

  // Here is a more raw syntax, essentially.
  std::endl(operator<<(std::cout, std::string("Hello world")));
}
