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
		connection_.async_read(user_,
			boost::bind(&Client::handle_read, this,
				boost::asio::placeholders::error));
		
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
		cout << "Welcome "<<user_.getName() << endl;



		connection_.async_write(test_,
			boost::bind(&Client::handle_write, this,
				boost::asio::placeholders::error));
	}
	else
	{
		// An error occurred.
		std::cerr << e.message() << std::endl;
	}
}

void Client::handle_Show_All_Cars(const boost::system::error_code& e) {
	
	connection_.async_read(test_,
		boost::bind(&Client::Show_All_Cars, this,
			boost::asio::placeholders::error));
}

void Client::Show_All_Cars(const boost::system::error_code& e) {
	cout << test_ << endl;
	handle_write(e);
}

void Client::handle_Show_Available_Cars(const boost::system::error_code& e) {
	connection_.async_read(test_,
		boost::bind(&Client::read_Available_Cars, this,
			boost::asio::placeholders::error));
	
}

void Client::read_Available_Cars(const boost::system::error_code& e) {
	cout << test_ << endl;
	handle_write(e);
}

void Client::handle_Rent_Car(const boost::system::error_code& e) {
	connection_.async_read(test_,
		boost::bind(&Client::handle_write, this,
			boost::asio::placeholders::error));
	cout << test_ << endl;
}

void Client::handle_Return_Car(const boost::system::error_code& e) {
	connection_.async_read(test_,
		boost::bind(&Client::handle_write, this,
			boost::asio::placeholders::error));
	cout << test_ << endl;
}
void Client::handle_Add_New_Car(const boost::system::error_code& e) {
	connection_.async_read(test_,
		boost::bind(&Client::handle_write, this,
			boost::asio::placeholders::error));
	cout << test_ << endl;
}
void Client::handle_Find_Car(const boost::system::error_code& e) {
	connection_.async_read(test_,
		boost::bind(&Client::handle_write, this,
			boost::asio::placeholders::error));
	cout << test_ << endl;
}

void Client::handle_write(const boost::system::error_code& e)
{
	functionType_ = mainMenu.carManagementMenu();
	cout << "write" << endl;
	switch (functionType_)
	{
	case SHOWALLCARS:
		connection_.async_write(SHOWALLCARS,
			boost::bind(&Client::handle_Show_All_Cars, this,
				boost::asio::placeholders::error));
	case SHOWAVAILABLECARS:
		connection_.async_write(SHOWAVAILABLECARS,
			boost::bind(&Client::handle_Show_Available_Cars, this,
				boost::asio::placeholders::error));
		break;
	case RENT:
		connection_.async_write(RENT,
			boost::bind(&Client::handle_Rent_Car, this,
				boost::asio::placeholders::error));
		break;
	case RETURN:
		connection_.async_write(RETURN,
			boost::bind(&Client::handle_Return_Car, this,
				boost::asio::placeholders::error));
		break;
	case ADDNEWCAR:
		connection_.async_write(ADDNEWCAR,
			boost::bind(&Client::handle_Add_New_Car, this,
				boost::asio::placeholders::error));
		break;
	case FINDCARBYID:
		connection_.async_write(FINDCARBYID,
			boost::bind(&Client::handle_Find_Car, this,
				boost::asio::placeholders::error));
		break;
	default:
		break;
	}
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