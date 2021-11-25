#include <iostream>
#include "profile.h"
#include "network.h"

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

  //task B
  std::cout << "\nTask B\n" << '\n';
  Network nw;
  std::cout << "Valid new user: nw.addUser(\"mario123\", \"Mario\") = " << nw.addUser("mario123", "Mario") << '\n';
  std::cout << "\nInvalid new users\n" << '\n';
  std::cout << "Same username: nw.addUser(\"mario123\", \"Mario2\") = " << nw.addUser("mario123", "Mario2") << '\n';
  std::cout << "Bad characters: nw.addUser(\"mario-2\", \"Mario2\") = " << nw.addUser("mario-2", "Mario2") << '\n';

  std::cout << "\nMore valid new users\n" << '\n';

  for (int i = 1; i < 20; i++)
    std::cout << "nw.addUser(\"mario" << i << "\", \"Mario" << i << "\") = "
              << nw.addUser("mario" + std::to_string(i), "Mario" + std::to_string(i)) << '\n';

  std::cout << "\nProfiles is full: nw.addUser(\"yoshi\", \"Yoshi\") = " << nw.addUser("yoshi", "Yoshi") << '\n';
}
