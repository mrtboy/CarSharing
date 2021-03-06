// Server.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <vector>
#include "Connection.h" // Must come before boost/serialization headers.
#include <boost/serialization/vector.hpp>
#include "User.h"
#include "Car.h"
#include "ManageUser.h"
#include "ManageCar.h"

using namespace std;

template<typename T>
struct Wrapper
{
	typedef std::map<FUNCTIONTYPE, T> map_Type;
};
/// Serves stock quote information to any client that connects to it.
class Server
{
public:
	/// Constructor opens the acceptor and starts waiting for the first incoming
	/// connection.
	Server(boost::asio::io_service& io_service, unsigned short port);
	/// Handle completion of a accept operation.
	void handle_accept(const boost::system::error_code& e, connection_ptr conn);

	void handle_read(const boost::system::error_code& e, connection_ptr conn);
	/// Handle completion of a write operation.
	void handle_write(const boost::system::error_code& e, connection_ptr conn);
	void handle_Show_All_Cars(const boost::system::error_code& e, connection_ptr conn);
	void ShowAllCars(const boost::system::error_code & e, connection_ptr conn);
	void handle_Show_Available_Cars(const boost::system::error_code& e, connection_ptr conn);
	void handle_Rent_Car(const boost::system::error_code& e, connection_ptr conn);
	void handle_Return_Car(const boost::system::error_code& e, connection_ptr conn);
	void handle_Add_New_Car(const boost::system::error_code& e, connection_ptr conn);
	void Add_New_Car(const boost::system::error_code& e, connection_ptr conn);
	void handle_Find_Car(const boost::system::error_code& e, connection_ptr conn);
	void handle_Get_User_Info(const boost::system::error_code& e, connection_ptr conn);

private:
	/// The acceptor object used to accept incoming socket connections.
	boost::asio::ip::tcp::acceptor acceptor_;

	/// The data to be sent to each client.
	std::vector<User> users_;
	Car car_;
	int carID_;
	int findID_;
	User user_;
	vector<Car> cars_;
	ManageUser manageUser;
	ManageCar manageCar_;
	Wrapper<User>::map_Type userWrapper;
	Wrapper<Car>::map_Type carWrappr;
	Wrapper<string>::map_Type messageWrapper;
	vector<string> container_;
	string test_;
	FUNCTIONTYPE functionType_;
	bool login = false;
};

// TODO: Reference additional headers your program requires here.
