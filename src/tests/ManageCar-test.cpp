#include <boost/test/unit_test.hpp>

#include "ManageCar.h"
#include "Car.h"
#include "../lib/ManageCar.h"
#include "../lib/Car.h"
#include <boost/asio/basic_socket_iostream.hpp>


BOOST_AUTO_TEST_CASE(check_constructor)
{
	
	Car car1{ "Reza",3500,"Kiel",1,"VW",2018,"Diesel",5,5,"?","6","Diesel",true };
	Car car2{ "Reza",3500,"Kiel",1,"VW",2018,"Diesel",5,5,"?","6","Diesel",true };
	ManageCar manageCar;
	manageCar.insert(car1);
	manageCar.insert(car2);

	

}




	
	

	
