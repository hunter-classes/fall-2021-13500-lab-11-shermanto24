#include <iostream>
#include "profile.h"

//parameterized constructor
Profile::Profile(std::string usrn, std::string dspn)
{
  username = usrn;
  displayname = dspn;
}

//default constructor
Profile::Profile()
{
  username = "";
  displayname = "";
}

std::string Profile::getUsername()
{
  return username;
}

std::string Profile::getFullName()
{
  return displayname + " (@" + username + ")";
}

void Profile::setDisplayName(std::string dspn)
{
  displayname = dspn;
}
