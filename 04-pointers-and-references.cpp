#include <iostream>

int main() {
  // In C++, all variables have types.
  int x = 1;
  // In C++, all named variables can have addresses.
  //
  // You can use a pointer type to hold the address of a variable of a
  // certain type.
  int* px = &x;

  // You can also take the address of a pointer because int* is also a type.
  int** ppx = &px;

  // ...Yup.
  int*** pppx = &ppx;

  std::cout << "x: " << x << std::endl;
  // You can get the original value back by "dereferencing it."
  std::cout << "*px: " << *px << std::endl;
  std::cout << "px: " << px << std::endl;
  std::cout << "ppx: " << ppx << std::endl;
  std::cout << "pppx: " << ppx << std::endl;
  std::cout << "address of pppx: " << &pppx << std::endl;

  // But forsooth! Pointers can sometimes have invalid values.
  int* p = nullptr;
  // The NULL and nullptr values represent "null" values. This is bad,
  // because accidentally using a null value means bad things:
  //std::cout << *p << std::endl;
  // Yeah, how do you even get the value at the address of nothing?
  // So comment the line above.

  ///////////////////////////////////////////////////////////////////////////
  //                            ENTER REFERENCES.                          //
  ///////////////////////////////////////////////////////////////////////////

  // Instead of taking the address of stuff, references just create a sort of
  // "alias" to a variable.
  //
  // Another name for int& is "int lvalue."
  int& rx = x;

  // But here's the thing! You cannot bind references to values -- only
  // variables.
  // This will not compile.
  // int& not_rx = 1;

  // Instead, "values" have the type "rvalue".
  int&& rvalue_x = 1;

  // Notice: if you look at the statement:
  //
  //   int x = 1;
  //
  // the x is the "lvalue",
  // and the 1 is the "rvalue"
  //
  // So, variables belong on the left.
  // And, values belong on the right.
  //
  // This is why they're called lvalues and rvalues.


  //////////////////////////////////////////////////////////////////////
  //////////              Dynamic Allocation                  //////////
  //////////////////////////////////////////////////////////////////////

  // In C++, you can also use dynamic allocation.
  //
  // This means you can ask for more memory on the fly to be able to create
  // new objects on the fly.

  // You use the new keyword, like in Java.
  int* dym_x = new int(1);

  std::cout << "dym_x: " << *dym_x << std::endl;

  // Make sure you return the memory you borrow using delete!
  delete dym_x;

}
