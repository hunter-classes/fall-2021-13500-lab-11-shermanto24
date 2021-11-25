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
  std::cout << "\n\n\nTask B\n" << '\n';
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



  //task C
  std::cout << "\n\n\nTask C\n" << '\n';
  Network nw2;

  //adding three users
  nw2.addUser("mario", "Mario");
  nw2.addUser("luigi", "Luigi");
  nw2.addUser("yoshi", "Yoshi");
  std::cout << "@mario, @luigi, and @yoshi were added to the network" << '\n';

  //making them follow each other
  nw2.follow("mario", "luigi");
  nw2.follow("mario", "yoshi");
  std::cout << "@mario follows @luigi and @yoshi" << '\n';
  nw2.follow("luigi", "mario");
  nw2.follow("luigi", "yoshi");
  std::cout << "@luigi follows @mario and @yoshi" << '\n';
  nw2.follow("yoshi", "mario");
  nw2.follow("yoshi", "luigi");
  std::cout << "@yoshi follows @mario and @luigi" << '\n';

  //adding a user who does not follow anyone
  nw2.addUser("wario", "Wario");
  std::cout << "\n@wario was added to the network" << '\n';
  std::cout << "@wario does not follow anyone\n" << '\n';

  //adding clone users who follow @mario
  for (int i = 2; i < 6; i++)
  {
    std::string usrn = "mario" + std::to_string(i);
    std::string dspn = "Mario " + std::to_string(i);
    nw2.addUser(usrn, dspn);
    nw2.follow(usrn, "mario");
    std::cout << "@" << usrn << " was added to the network" << '\n';
  }
  std::cout << "All the mario clones follow @mario" << '\n';

  //making @mario2 follow @luigi
  nw2.follow("mario2", "luigi");
  std::cout << "\n@mario2 follows @luigi\n" << '\n';

  //printing the network
  std::cout << "Output of nw2.printDot():\n" << '\n';
  nw2.printDot();
}
