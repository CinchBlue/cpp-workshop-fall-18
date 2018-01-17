#include <iostream>
#include <string>

// In C++, classes exist.
//
// Like Java, you can control privacy of class members.
// However, it's just with a private: public: protected:
// and it extends until the end of the class or the next privacy access setting.
class BasicPoint {
public:
  double x;
  double y;
  double z;
};

// Here's how you create a class that has a default constructor.
void using_BasicPoint() {
  BasicPoint b;
  // You can also explicitly use this syntax to call the constructor.
  BasicPoint b1();
  b.x = 1;
  b.y = 2;
  b.z = 3;

  // There's also a new uniform syntax that can be used that uses braces:
  BasicPoint b2 {1, 2, 3};
};

class Point {
  float x, y, z;
public:
  // This is known as a constructor. This is the first function that is
  // called when you create an object, and you can use it to initialize
  // variables.
  Point(float f1, float f2, float f3) : // <- This colon starts the initialization list
    // Then, you can put a list of constructor calls for the member variables,
    // separated by commas
    x(f1),
    y(f2),
    z(f3) {
    // This is the body of the constructor, like any other regular function.
    // As in Java, constructors do not return anything.
  }

  // C++ also has destructors, or functions when variables "die."
  //
  // This is very important.
  ~Point() {

  }

  float get_x() {
    return x;
  }

  // You can also mark types with "const" which means that they cannot be
  // assigned to or modified in the course of the function.
  const float get_y() {
    return y;
  }

  // Specifically for member functions on classes, you can also put a
  // "const" after the parameter list in the () in order to mark that
  // "this" object won't be modified, and you can treat the current object
  // as "const" for the course of the function.
  const float get_z() const {
    return z;
  }

  void set_x(float f) { x = f; }
  void set_y(float f) { y = f; }
  void set_z(float f) { z = f; }

};

int main() {
  // Note that this will fail. This is because we defined a specific
  // constructor, which means we can only use the constructors in the class.
  //Point p;
  Point p(1, 2, 3);
  std::cout << p.get_x() << " "
            << p.get_y() << " "
            << p.get_z() << std::endl;
}


