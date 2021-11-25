#include <iostream>
#include "network.h"

//----------------- task B -----------------

//default constructor: makes empty network
Network::Network()
{
  numUsers = 0;
  for (int i = 0; i < MAX_USERS; i++)
    for (int j = 0; j < MAX_USERS; j++)
      following[i][j] = false;
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

//----------------- task C -----------------

bool Network::follow(std::string usrn1, std::string usrn2)
{
  int id1 = findID(usrn1);
  int id2 = findID(usrn2);

  //one or both of the usernames DO NOT exist in the network
  if (id1 == -1 || id2 == -1)
    return false;
  else
  {
    following[id1][id2] = true;
    return true;
  }
}

//helper method for testing if follow worked
bool Network::isFollowing(std::string usrn1, std::string usrn2)
{
  if (findID(usrn1) == -1 || findID(usrn2) == -1)
    return false;
    
  return following[findID(usrn1)][findID(usrn2)];
}

void Network::printDot()
{
  std::string result = "digraph {\n";

  //printing all the usernames
  for (int i = 0; i < MAX_USERS; i++)
    if (profiles[i].getUsername() != "")
      result += "\"@" + profiles[i].getUsername() + "\"\n";

  result += "\n";

  //printing who's following who
  for (int row = 0; row < MAX_USERS; row++)
  {
    for (int col = 0; col < MAX_USERS; col++)
    {
      if (following[row][col])
      {
        result += "\"@" + profiles[row].getUsername()
                + "\" -> \"@" + profiles[col].getUsername() + "\"\n";
      }
    }
  }

  result += "}";
  std::cout << result << '\n';
}
