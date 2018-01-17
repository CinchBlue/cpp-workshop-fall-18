#include <iostream>

// In C++, classes can inherit variables and functions from other others.
class FireStaff {
private:
  int times;
public:
  FireStaff() : times(0) {}

  void fireball() {
    times++;
    std::cout << "Fire! You've called it " << times << " times!" << std::endl;
  }
};

class WaterStaff {
public:
  void water_gun() {
    std::cout << "Squirt!" << std::endl;
  }
};

// This is how you inherit from both classes.
// Also, you can also force public functions in the parent classes to have
// tighter access restrictions.
class Wizard : public FireStaff, private WaterStaff {
public:
  // Notice, I can only use WaterStaff.water_gun() in this method.
  //
  // I can't directly call water_gun() on this class though. It's private!
  void cast_spells() {
    fireball();
    water_gun();
  }
};

int main() {
  Wizard w;

  w.cast_spells();
  w.cast_spells();
  w.cast_spells();
}
