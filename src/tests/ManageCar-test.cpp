#include <boost/test/unit_test.hpp>

#include "ManageCar.h"
#include "Car.h"
#include "../lib/ManageCar.h"
#include "../lib/Car.h"

BOOST_AUTO_TEST_CASE(check_constructor)
{
	Car car{ "Reza",3500,"Kiel",123456,"VW",2018,"Diesel",5,5,"?","6","Diesel",true };
	ManageCar manageCar;
	manageCar.insert(car);
	

	BOOST_CHECK_EQUAL(manageCar.reserveCar(123456), true);
}