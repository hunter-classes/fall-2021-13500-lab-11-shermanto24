#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "profile.h"

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
