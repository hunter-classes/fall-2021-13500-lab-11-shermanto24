#include <iostream>
#include "network.h"

//default constructor: makes empty network
Network::Network()
{
  numUsers = 0;
}

int Network::findID(std::string usrn)
{
  for (int i = 0; i < MAX_USERS; i++)
  {
    std::string curr_user = profiles[i].getUsername();
    if (curr_user == usrn)
      return i;
  }
  return -1;
}

//helper method for testing findID
int Network::publicFindID(std::string usrn)
{
  return findID(usrn);
}

bool Network::addUser(std::string usrn, std::string dspn)
{
  if (usrn == "") //empty username
    return false;
  else if (findID(usrn) != -1) //there is a user with the same username
    return false;
  else if (numUsers == MAX_USERS) //profiles is full
    return false;
  else
  {
    for (int i = 0; i < usrn.length(); i++)
    {
      //checking if any char is NOT alphanumeric
      char curr = usrn[i];
      if ( !((curr >= 48 && curr <= 57) || (curr >= 65 && curr <= 90) || (curr >= 97 && curr <= 122)) )
        return false;
    }

    //adding the new user to profiles
    Profile new_user(usrn, dspn);
    profiles[numUsers] = new_user;
    numUsers++;
    return true;
  }
}
