#ifndef CLIENT_H
#define CLIENT_H

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <vector>
#include "Connection.h" // Must come before boost/serialization headers.
#include <boost/serialization/vector.hpp>
#include "User.h"
#include "MainMenu.h"
#include "Car.h"
#include "ManageUser.h"
#include "Container.h"

using namespace std;

template<typename T>
struct Wrapper
{
	typedef std::map<FUNCTIONTYPE, T> map_Type;
};
/// Downloads stock quote information from a server.
class Client
{
public:
	/// Constructor starts the asynchronous connect operation.
	Client::Client(boost::asio::io_service& io_service,
		const std::string& host, const std::string& service);
	

	/// Handle completion of a connect operation.
	void handle_connect(const boost::system::error_code& e);

	/// Handle completion of a read operation.
	void handle_read(const boost::system::error_code& e);

	void handle_write(const boost::system::error_code& e);
	void handle_Show_All_Cars(const boost::system::error_code& e);
	void handle_Show_Available_Cars(const boost::system::error_code& e);
	void handle_Rent_Car(const boost::system::error_code& e);
	void handle_Return_Car(const boost::system::error_code& e);
	void handle_Add_New_Car(const boost::system::error_code& e);
	void handle_Find_Car(const boost::system::error_code& e);
	void handle_Get_User_Info(const boost::system::error_code& e);
	
private:

	void read_Available_Cars(const boost::system::error_code& e);
	void Show_All_Cars(const boost::system::error_code& e);
	void rent_Car(const boost::system::error_code& e);
	void return_Car(const boost::system::error_code& e);
	void add_New_Car(const boost::system::error_code& e);
	void find_Car(const boost::system::error_code& e);
	void get_User_Info(const boost::system::error_code& e);

	/// The connection to the server.
	Connection connection_;

	/// The data received from the server.
	std::vector<User> users_;
	//std::vector<Car> car_;
	ManageUser manageUser_;
	std::vector<string> menu_;
	char option_ = ' ';
	User user_;
	MainMenu mainMenu;
	Wrapper<User>::map_Type userWrapper;
	Wrapper<Car>::map_Type carWrappr;
	Wrapper<string>::map_Type messageWrapper;
	vector<string> container_;
	
	string test_;
	FUNCTIONTYPE functionType_;
};

#endif
