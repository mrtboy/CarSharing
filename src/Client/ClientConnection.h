#ifndef CLIENTCONNECTION_H
#define CLIENTCONNECTION_H

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

using namespace std;

class ClientConnection
{
public:
	/// Constructor starts the asynchronous connect operation.
	ClientConnection::ClientConnection(boost::asio::io_service& io_service,
		const std::string& host, const std::string& service);

	/// Handle completion of a connect operation.
	void handle_connect(const boost::system::error_code& e);
	/// Handle completion of a read operation.
	void handle_read(const boost::system::error_code& e);
	void handle_write(const boost::system::error_code& e);

private:
	/// The connection to the server.
	Connection connection_;

	/// The data received from the server.
	//std::vector<User> user_;
	//std::vector<Car> car_;
	ManageUser manageUser_;
	std::vector<string> menu_;
	char option_ = ' ';
	User user_;

};

#endif