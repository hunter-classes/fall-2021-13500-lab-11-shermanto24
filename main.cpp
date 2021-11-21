#include <iostream>
#include "profile.h"

int main()
{
  //task A
  std::cout << "Task A\n" << '\n';

  //default constructor
  std::cout << "Testing the default constructor\n" << '\n';
  Profile pr1;
  std::cout << "pr1.getUsername() = " << pr1.getUsername() << '\n';
  std::cout << "pr1.getFullName() = " << pr1.getFullName() << '\n';
  pr1.setDisplayName("Not Empty Anymore");
  std::cout << "After calling pr1.setDisplayName(\"Not Empty Anymore\")" << '\n';
  std::cout << "pr1.getFullName() = " << pr1.getFullName() << '\n';

  //parameterized constructor
  std::cout << "\nTesting the parameterized constructor\n" << '\n';
  Profile pr2 ("username", "First Last");
  std::cout << "pr2.getUsername() = " << pr2.getUsername() << '\n';
  std::cout << "pr2.getFullName() = " << pr2.getFullName() << '\n';
  pr2.setDisplayName("New Name");
  std::cout << "After calling pr2.setDisplayName(\"New Name\")" << '\n';
  std::cout << "pr2.getFullName() = " << pr2.getFullName() << '\n';
}
