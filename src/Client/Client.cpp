#include <iostream>
#include <string>
#include <memory>
//#include <boost\asio.hpp>
//#include <boost\bind.hpp>
//#include <boost\asio\buffer.hpp>
//#include <boost\asio\io_service.hpp>
//#include <boost\asio\ip\tcp.hpp>
//#include <boost\archive\binary_oarchive.hpp>
//#include <boost\archive\binary_iarchive.hpp>
//#include <boost\serialization\string.hpp>
#include "User.h"
//#include <boost\serialization\vector.hpp>
#include "MainMenu.h"
#include "Connection.h"
#include "Car.h"

//using namespace boost::archive;
//using namespace boost::asio;
//std::stringstream stringStream;
using namespace std;

int main()
{
	User user{ "ass","ss",2,"ss","dd","Ff" };
	shared_ptr<Connection> cc = make_shared<Connection>();
	cc->connectToServer(user);

	Car car{"",22,"22",22,"ed",23,"ewe",3,4,"eee","232","2323",true};
	cc->connectToServer(car);
	
	return 0;
}