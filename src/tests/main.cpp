#define BOOST_TEST_MAIN

#include "main.h"

BOOST_AUTO_TEST_SUITE(adder_test_suite);
BOOST_AUTO_TEST_CASE(check_constructor)
{
	User user{ "Reza","test",31,"test","test","test" };
	ManageUser manageUser;
	manageUser.insert(user);
	BOOST_CHECK_EQUAL(manageUser.userExist("test"), false);
}
BOOST_AUTO_TEST_SUITE_END();