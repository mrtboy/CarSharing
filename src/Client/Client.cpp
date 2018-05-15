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
	User user{ "1","ss",2,"ss","dd","Ff" };
	User user2{ "2","sdf",2,"ss","sdf","Ff" };
	User user3{ "3","sfsds",2,"sdf","dd","Ff" };
	shared_ptr<Connection> cc = make_shared<Connection>();
	shared_ptr<Connection> cc1 = make_shared<Connection>();
	cc->connectToServer(user);
	cc1->connectToServer(user2);
	cc->connectToServer(user3);

	//Car car{"",22,"22",22,"ed",23,"ewe",3,4,"eee","232","2323",true};
	//cc->connectToServer(car);


	
	return 0;
}