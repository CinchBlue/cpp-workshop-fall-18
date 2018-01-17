#include <iostream>

// Polymorphism is when you can have one function/call, but different
// behavior based on the underlying type.

// In C++, two major ways to do it are through pointers, templates, and
// references.

// In C++, member functions can have their functionality "overrided" by
// derived/child classes with inheritance.
//
// This is by using the virutal keyword.
class IWizard {
public:
  // The = 0; means that the function is "pure." This means that the class
  // can never be created... but you can still have pointers and rvalue
  // references to them.
  virtual void cast_spell() = 0;
};

class FireWizard {
public:
  virtual void cast_spell() override {
    std::cout << "BLAZE!" << std::endl;
  }
};

class IceWizard {
public:
  virtual void cast_spell() override {
    std::cout << "FREEZE!" << std::endl;
  }
};

int main() {

  IWizard* fire_wiz = new FireWizard();
  fire_wiz->cast_spell();

  IWizard* ice_wiz = new IceWizard();
  ice_wiz->cast_spell();

  // Now, you must be wondering... aren't they both IWizard?
  // No, they're still technically FireWizard and IceWizard beneath.
  //
  // But, because they both inherit from IWizard, you can consider them
  // IWizard, and use the IWizard* to call the IWizard method.
  //
  // But, the "virtual" keyword will lookup what type it is FOR REAL and then
  // call the FOR REAL correct method.
  //
  // ISN'T THAT FOR REAL?!

  // You can also get the original pointers back by using dynamic_cast.
  FireWizard* fire = dynamic_cast<FireWizard>(fire_wiz);
  FireWizard* ice = dynamic_cast<IceWizard>(fire_wiz);

  delete fire_wiz;
  delete ice_wiz;
}
