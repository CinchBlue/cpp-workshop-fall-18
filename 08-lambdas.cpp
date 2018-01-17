#include <iostream>
#include <functional>

int main() {
  // You can make function literals that can be placed into variables using
  // this syntax.
  auto hello_world = []() {
    std::cout << "Hello world" << std::endl;
  };
  hello_world();

  // Unfortunately, lambdas (the thing above), regular functions, and objects
  // that overload operator() are all different.
  //
  // But, there IS a class that can use all 3!
  std::function<void(void)> f = hello_world;
  f();

  // Lambdas can also capture variables.
  auto capture_hello_world = [&hello_world]() {
    hello_world();
  };
  capture_hello_world();

  // You can return lambdas:
  auto generate_adder = []() {
    return [](int x, int y) {
      return x + y;
    };
  };
  std::cout << (generate_adder())(1, 2) << std::endl;

  // In fact, lambdas can capture themselves...
  std::function<int(int)> factorial;
  factorial = [&factorial](int n) {
    if (n <= 1) { return 1; }
    return n * factorial(n-1);
  };
  std::cout << factorial(5) << std::endl;
}
