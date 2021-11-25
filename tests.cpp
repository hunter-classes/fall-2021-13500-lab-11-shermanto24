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

//----------------- task B -----------------

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

//----------------- task C -----------------

Network nw2;

TEST_CASE("follow: true cases")
{
  //adding users
  nw2.addUser("mario", "Mario");
  nw2.addUser("luigi", "Luigi");
  nw2.addUser("yoshi", "Yoshi");

  //checking if follow returns true
  CHECK( nw2.follow("mario", "luigi") );
  CHECK( nw2.follow("luigi", "mario") );
  CHECK( nw2.follow("luigi", "yoshi") );
  CHECK( nw2.follow("yoshi", "mario") );

  //checking if the cells are true
  CHECK( nw2.isFollowing("mario", "luigi") );
  CHECK( nw2.isFollowing("luigi", "mario") );
  CHECK( nw2.isFollowing("luigi", "yoshi") );
  CHECK( nw2.isFollowing("yoshi", "mario") );
}

TEST_CASE("follow: false cases")
{
  //checking if follow returns false
  CHECK( !nw2.follow("mario", "Nonexistent") );
  CHECK( !nw2.follow("Nonexistent", "luigi") );
  CHECK( !nw2.follow("impostor1", "impostor2") );

  //invalid user(s)
  //cells for these pairs of users do not exist,
  //so isFollowing returns false
  CHECK( !nw2.isFollowing("mario", "Nonexistent") );
  CHECK( !nw2.isFollowing("Nonexistent", "luigi") );
  CHECK( !nw2.isFollowing("impostor1", "impostor2") );

  //checking that the cells that should be false are false
  CHECK( !nw2.isFollowing("mario", "mario") );
  CHECK( !nw2.isFollowing("mario", "yoshi") );
  CHECK( !nw2.isFollowing("luigi", "luigi") );
  CHECK( !nw2.isFollowing("yoshi", "luigi") );
  CHECK( !nw2.isFollowing("yoshi", "yoshi") );
}
