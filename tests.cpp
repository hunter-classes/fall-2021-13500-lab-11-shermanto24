#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "profile.h"
#include "network.h"

//----------------- task A -----------------

Profile pr1;
Profile pr2("username", "First Last");

TEST_CASE("Profile: getUsername() tests")
{
  CHECK( pr1.getUsername() == "" );
  CHECK( pr2.getUsername() == "username" );
}

TEST_CASE("Profile: getFullName() tests")
{
  CHECK( pr1.getFullName() == " (@)" );
  CHECK( pr2.getFullName() == "First Last (@username)" );
}

TEST_CASE("Profile: setDisplayName(name) tests")
{
  pr1.setDisplayName("New Dspn");
  CHECK( pr1.getFullName() == "New Dspn (@)" );

  pr2.setDisplayName("Random Name");
  CHECK( pr2.getFullName() == "Random Name (@username)" );
}

//----------------- task A -----------------

Network nw;

TEST_CASE("addUser: true cases")
{
  CHECK( nw.addUser("lowercase", "Lowercase") );
  CHECK( nw.addUser("UPPERCASE", "Uppercase") );
  CHECK( nw.addUser("mixedCase", "Mixed Case") );
  CHECK( nw.addUser("letsAndNums123", "Letters and numbers") );
  CHECK( nw.addUser("123456", "Only numbers") );
}

TEST_CASE("addUser: false cases")
{
  CHECK( !nw.addUser("", "Empty") );
  CHECK( !nw.addUser("Invalid Username", "Not alphanumeric") );
  CHECK( !nw.addUser("ALSO-INVALID", "Not alphanumeric") );
  CHECK( !nw.addUser("123456", "Duplicate") );

  for (int i = 5; i < 20; i++)
    nw.addUser("user" + std::to_string(i), "dspn" + std::to_string(i));

  CHECK( !nw.addUser("whatAboutMe", "Network full") );
}

TEST_CASE("publicFindID: users that exist within the network")
{
  CHECK( nw.publicFindID("letsAndNums123") == 3 );
  CHECK( nw.publicFindID("user12") == 12 );
}

TEST_CASE("publicFindID: users that DO NOT exist within the network")
{
  CHECK( nw.publicFindID("") == -1 );
  CHECK( nw.publicFindID("UPPERCASE2") == -1 );
  CHECK( nw.publicFindID("user_15") == -1 );
}
