#include "Server.h"
#include <boost/foreach.hpp>

Server::Server(boost::asio::io_service& io_service, unsigned short port)
	: acceptor_(io_service,
		boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
{
	User user1{ "1", "Reza", 32, "Mohammadreza@gmail.com", "Kiel", "017856556" };
	User user2{ "2", "Ali", 20, "Ali@gmail.com", "Koln", "017432432" };
	User user3{ "3", "Jack", 43, "Jack@gmail.com", "Essen", "01765464" };
	User user4{ "4", "Muller", 33, "Muller@gmail.com", "Berlin", "0142325" };
	User user5{ "5", "Peter", 23, "Peter@gmail.com", "Kiel", "015455346" };

	manageUser.insert(user1);
	manageUser.insert(user2);
	manageUser.insert(user3);
	manageUser.insert(user4);
	manageUser.insert(user5);

	// Start an accept operation for a new connection.
	connection_ptr new_conn(new Connection(acceptor_.get_io_service()));
	acceptor_.async_accept(new_conn->socket(),
		boost::bind(&Server::handle_accept, this,
			boost::asio::placeholders::error, new_conn));
}

/// Handle completion of a accept operation.
void Server::handle_accept(const boost::system::error_code& e, connection_ptr conn)
{

	if (!e)
	{
		login = false;
		int numberUsers = manageUser.users.size();
		int randomUser = rand() % numberUsers;
		user_ = manageUser.users[randomUser];
		conn->async_write(user_,
			boost::bind(&Server::handle_write, this,
				boost::asio::placeholders::error, conn));
		
	}

	// Start an accept operation for a new connection.
	connection_ptr new_conn(new Connection(acceptor_.get_io_service()));
	acceptor_.async_accept(new_conn->socket(),
		boost::bind(&Server::handle_accept, this,
			boost::asio::placeholders::error, new_conn));
}


void Server::handle_Show_All_Cars(const boost::system::error_code& e, connection_ptr conn) {
	test_ = "handle_Show_All_Cars";
	cout << test_ << endl;
	conn->async_write(test_,
		boost::bind(&Server::handle_write, this,
			boost::asio::placeholders::error, conn));
}
void Server::handle_Show_Available_Cars(const boost::system::error_code& e, connection_ptr conn) {
	test_ = "handle_Show_Available_Cars";
	cout << test_ << endl;
	conn->async_write(test_,
		boost::bind(&Server::handle_write, this,
			boost::asio::placeholders::error, conn));
}

void Server::handle_Rent_Car(const boost::system::error_code& e, connection_ptr conn) {
	test_ = "handle_Rent_Car";
	cout << test_ << endl;
	conn->async_write(test_,
		boost::bind(&Server::handle_write, this,
			boost::asio::placeholders::error, conn));
}

void Server::handle_Return_Car(const boost::system::error_code& e, connection_ptr conn) {
	test_ = "handle_Return_Car";
	cout << test_ << endl;
	conn->async_write(test_,
		boost::bind(&Server::handle_write, this,
			boost::asio::placeholders::error, conn));
}

void Server::handle_Add_New_Car(const boost::system::error_code& e, connection_ptr conn) {
	test_ = "handle_Add_New_Car";
	cout << test_ << endl;
	conn->async_write(test_,
		boost::bind(&Server::handle_write, this,
			boost::asio::placeholders::error, conn));
}
void Server::handle_Find_Car(const boost::system::error_code& e, connection_ptr conn) {
	test_ = "handle_Find_Car";
	cout << test_ << endl;
	conn->async_write(test_,
		boost::bind(&Server::handle_write, this,
			boost::asio::placeholders::error, conn));
}

void Server::handle_read(const boost::system::error_code& e, connection_ptr conn)
{
	if (!e)
	{
		switch (functionType_)
		{
		case SHOWALLCARS:
			cout << "in" << endl;
			conn->async_write(test_,
				boost::bind(&Server::handle_Show_All_Cars, this,
					boost::asio::placeholders::error, conn));
			break;
		case SHOWAVAILABLECARS:
			conn->async_write(test_,
				boost::bind(&Server::handle_Show_Available_Cars, this,
					boost::asio::placeholders::error, conn));
			break;
		case RENT:
			conn->async_write(test_,
				boost::bind(&Server::handle_Rent_Car, this,
					boost::asio::placeholders::error, conn));
			break;
		case RETURN:
			conn->async_write(test_,
				boost::bind(&Server::handle_Return_Car, this,
					boost::asio::placeholders::error, conn));
			break;
		case ADDNEWCAR:
			conn->async_write(test_,
				boost::bind(&Server::handle_Add_New_Car, this,
					boost::asio::placeholders::error, conn));
			break;
		case FINDCARBYID:
			conn->async_write(test_,
				boost::bind(&Server::handle_Find_Car, this,
					boost::asio::placeholders::error, conn));
			break;
		default:
			break;
		}
	}
	else
	{
		// An error occurred.
		std::cerr << e.message() << std::endl;
	}
}

/// Handle completion of a write operation.
void Server::handle_write(const boost::system::error_code& e, connection_ptr conn)
{
	
	if (!login) {
		login = true;
		cout << "User " + user_.getUserString() << " loged in" << endl;
		conn->async_read(functionType_,
			boost::bind(&Server::handle_read, this,
				boost::asio::placeholders::error, conn));
	}
	else {
		conn->async_read(functionType_,
			boost::bind(&Server::handle_read, this,
				boost::asio::placeholders::error, conn));
	}

}

int main(int argc, char* argv[])
{
	try
	{
		// Check command line arguments.
		if (argc != 2)
		{
			std::cerr << "Usage: server <port>" << std::endl;
			return 1;
		}
		unsigned short port = boost::lexical_cast<unsigned short>(argv[1]);

		boost::asio::io_service io_service;
		Server server(io_service, port);
		io_service.run();

	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}