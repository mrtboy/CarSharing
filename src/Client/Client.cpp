#include "Client.h"
#include "boost\serialization\map.hpp"


Client::Client(boost::asio::io_service& io_service,
	const std::string& host, const std::string& service)
	: connection_(io_service)
{

	// Resolve the host name into an IP address.
	boost::asio::ip::tcp::resolver resolver(io_service);
	boost::asio::ip::tcp::resolver::query query(host, service);
	boost::asio::ip::tcp::resolver::iterator endpoint_iterator =
		resolver.resolve(query);

	// Start an asynchronous connect operation.
	boost::asio::async_connect(connection_.socket(), endpoint_iterator,
		boost::bind(&Client::handle_connect, this,
			boost::asio::placeholders::error));
}


/// Handle completion of a connect operation.
void Client::handle_connect(const boost::system::error_code& e)
{
	if (!e)
	{
		int input = 0;
		cin >> input;
		if (input == 1) {
			User user{ "1","1",1,"1","1","1" };
			user_ = user;
			connection_.async_write(user_,
				boost::bind(&Client::handle_read, this,
					boost::asio::placeholders::error));
			input = 0;
		}
		else if (input == 2) {
			test_ = "testing";
			connection_.async_write(test_,
				boost::bind(&Client::handle_connect, this,
					boost::asio::placeholders::error));
			input = 0;
		}
		
	}
	else
	{
		std::cerr << e.message() << std::endl;
	}
}

/// Handle completion of a read operation.
void Client::handle_read(const boost::system::error_code& e)
{ 
	if (!e)
	{
		cout << "Read in Client" << endl;
		manageUser_.insert(user_);
		Client::handle_connect(e);

		connection_.async_read(users_,
			boost::bind(&Client::handle_read, this,
				boost::asio::placeholders::error));
		
	}
	else
	{
		// An error occurred.
		std::cerr << e.message() << std::endl;
	}
}
void Client::handle_read_Customers(const boost::system::error_code& e) {

	if (!e)
	{
		for (std::size_t i = 0; i < users_.size(); ++i) {
			cout << users_[i].getUserString() << endl;
		}
		Client::handle_connect(e);
	}
	else
	{
		// An error occurred.
		std::cerr << e.message() << std::endl;
	}
}
void Client::handle_write(const boost::system::error_code& e)
{
	
}

int main(int argc, char* argv[])
{
	try
	{
		// Check command line arguments.
		if (argc != 3)
		{
			std::cerr << "Usage: client <host> <port>" << std::endl;
			return 1;
		}

		boost::asio::io_service io_service;
		Client ClientConnection(io_service, argv[1], argv[2]);
		io_service.run();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}