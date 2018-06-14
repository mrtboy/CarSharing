#define BOOST_TEST_MAIN

#include "main.h"

BOOST_AUTO_TEST_CASE(CheckUserAdded)
{
	User user{ "Id","test",31,"test","test","test"};
	ManageUser manageUser;
	manageUser.insert(user);
	BOOST_CHECK_EQUAL(manageUser.userExist("Id"), true);
}


BOOST_AUTO_TEST_CASE(testManageCar)
{
	Car car1{ "User1",3500,"Kiel",1,"VW",2018,"Diesel",5,5,"?","6","Diesel",true };
	
	ManageCar manageCar;

	manageCar.insert(car1);


	std::string expected_value1 = "User1";
	int expected_value2 = 3500;
	std::string expected_value3 = "Kiel";
	int expected_value4 = 1;
	std::string expected_value5 = "VW";
	int expected_value6 = 2018;
	std::string expected_value7 = "Diesel";
	int expected_value8 = 5;
	int expected_value9 = 5;
	std::string expected_value10 = "?";
	std::string expected_value11 = "6";
	std::string expected_value12 = "Diesel";
	bool expected_value13 = true;


	BOOST_CHECK(expected_value1 == car1.getOwner());
	BOOST_CHECK(expected_value2 == car1.getPrice());
	BOOST_CHECK(expected_value3 == car1.getLocation());
	BOOST_CHECK(expected_value4 == car1.getID());
	BOOST_CHECK(expected_value5 == car1.getModel());
	BOOST_CHECK(expected_value6 == car1.getYear());
	BOOST_CHECK(expected_value7 == car1.getEngine());
	BOOST_CHECK(expected_value8 == car1.getNoOfDoors());
	BOOST_CHECK(expected_value9 == car1.getSeats());
	BOOST_CHECK(expected_value10 == car1.getTransmission());
	BOOST_CHECK(expected_value11 == car1.getConsumption());
	BOOST_CHECK(expected_value12 == car1.getType());
	BOOST_CHECK(expected_value13 == car1.getIsAvailable());
	BOOST_REQUIRE(manageCar.reserveCar(expected_value4) == true);
	BOOST_REQUIRE(manageCar.insert(car1) == true);
	

	

}
