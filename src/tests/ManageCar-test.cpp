#include <boost/test/unit_test.hpp>

#include "ManageCar.h"
#include "Car.h"
#include "../lib/ManageCar.h"
#include "../lib/Car.h"

BOOST_AUTO_TEST_CASE(check_constructor)
{
	Car car{ "Reza",3500,"Kiel",1,"VW",2018,"Diesel",5,5,"?","6","Diesel",true };
	ManageCar manageCar;
	manageCar.insert(car);
	
	// Seems to work.
	BOOST_CHECK_EQUAL(manageCar.reserveCar(1), true);
}