#include <iostream>
#include <string>

int main() {
  // For things from the standard library, they lie in the namespace "std".
  //
  // Thus, if you want to use the "string" class from <string>, you'll need to
  // actually type "std::string"
  std::string s;
  std::cout << "Enter a sentence with no whitespace." << std::endl;

  // There is also a "console-in" stream that is used for input.
  std::cin >> s;
  // The actual way it reads input depends on the type you're trying to
  // read into. So, the behavior changes based on what type you use it with!

  std::cout << "Here's what you typed: " << std::endl;
  std::cout << s << std::endl;

  // This will clear the input stream. So, no leftover characters like
  // newlinse will remain.
  std::cin.clear();

  std::cout << "Type in one character: " << std::endl;

  char c;
  // You can also do input character-wise by calling the .get() method on the
  // std::cin object.
  c = std::cin.get();
  std::cout << "You input: " << c << std::endl;

  // Alternatively, you can also call .peek() which will give you the next
  // character without consuming it:
  std::cout << "Next character: " << std::endl;
  c = std::cin.peek();
  std::cout << "Peeking the next character: " << c <<  std::endl;
  std::cout << "And again as a raw number: " << std::cin.peek() << std::endl;
  std::cout << "Once more, but cast to a char: "
            // This is called performing a static_cast.
            // This asks the compiler to convert the value to the following
            // type.
            << static_cast<char>(std::cin.peek()) << std::endl;



}