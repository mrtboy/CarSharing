#include <boost/test/unit_test.hpp>

#include "ManageUser.h"
#include "User.h"

BOOST_AUTO_TEST_CASE(check_constructor)
{
	User user{ "Reza","test",31,"test","test","test" };
	ManageUser manageUser;
	manageUser.insert(user);
	BOOST_CHECK_EQUAL(manageUser.userExist("test"), true);
}

