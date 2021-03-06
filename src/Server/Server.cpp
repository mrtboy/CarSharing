#include "Server.h"
#include <boost/foreach.hpp>
#include "ManageCar.h"

Server::Server(boost::asio::io_service& io_service, unsigned short port)
	: acceptor_(io_service,
		boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
{
	User user1{ "1", "Reza", 32, "017856556", "Kiel", "Mohammadreza@gmail.com" };
	User user2{ "2", "Ali", 20, "017432432", "Koln", "Ali@gmail.com" };
	User user3{ "3", "Jack", 43, "01765464", "Essen", "Jack@gmail.com" };
	User user4{ "4", "Muller", 33, "0142325", "Berlin", "Muller@gmail.com" };
	User user5{ "5", "Peter", 23, "015455346", "Kiel", "Peter@gmail.com" };

	manageUser.insert(user1);
	manageUser.insert(user2);
	manageUser.insert(user3);
	manageUser.insert(user4);
	manageUser.insert(user5);


	Car car1{ "Reza1",3500,"Kiel",1,"VW",2018,"Diesel",5,5,"?","6","Diesel",true };
	Car car2{ "Reza2",5000,"Kiel",2,"VW",2018,"Diesel",5,5,"?","6","Benzin",true };

	ManageCar manageCar;
	manageCar.insert(car1);
	manageCar.insert(car2);

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

//Rent car for user
void Server::handle_Rent_Car(const boost::system::error_code& e, connection_ptr conn) {
	test_ = "handle_Rent_Car";
	cout << test_ << endl;
	manageCar_.reserveCar(carID_);
	handle_write(e, conn);
}

//Return Car
void Server::handle_Return_Car(const boost::system::error_code& e, connection_ptr conn) {
	test_ = "handle_Return_Car";
	manageCar_.returnCar(carID_);
	handle_write(e, conn);
}

//Add new Car
void Server::handle_Add_New_Car(const boost::system::error_code& e, connection_ptr conn) {
	test_ = "handle_Add_New_Car";
	cout << test_ << endl;

	conn->async_read(car_,
		boost::bind(&Server::Add_New_Car, this,
			boost::asio::placeholders::error, conn));
}

void Server::Add_New_Car(const boost::system::error_code& e, connection_ptr conn) {
	ManageCar manageCar;
	manageCar.insert(car_);
	cout << car_.getModel() << endl;
	handle_write(e, conn);
}

/*
//Find Car
void Server::handle_Find_Car(const boost::system::error_code& e, connection_ptr conn) {
	test_ = "handle_Find_Car";
	manageCar_.getCarByID(findID_);
	handle_write(e, conn);
}
*/

void Server::handle_read(const boost::system::error_code& e, connection_ptr conn)
{
	if (!e)
	{
		switch (functionType_)
		{
		case SHOWALLCARS:
			cout << "SHOWALLCARS" << endl;
			conn->async_write(manageCar_.cars,
				boost::bind(&Server::handle_write, this,
					boost::asio::placeholders::error, conn));
			break;
		case SHOWAVAILABLECARS:
			cout << "SHOWAVAILABLECARS" << endl;
			conn->async_write(manageCar_.getAllAvailableCars(),
				boost::bind(&Server::handle_write, this,
					boost::asio::placeholders::error, conn));
			break;
		//case SHOWRESERVEDCARS:
		//	cout << "SHOWRESERVEDCARS" << endl;
		//	conn->async_write(manageCar_.getAllReservedCars(),
		//		boost::bind(&Server::handle_write, this,
		//			boost::asio::placeholders::error, conn));
		//	break;
		case RENT:
			cout << "RENT" << endl;
			conn->async_read(carID_,
				boost::bind(&Server::handle_Rent_Car, this,
					boost::asio::placeholders::error, conn));
			break;
		case RETURN:
			cout << "RETURN" << endl;
			conn->async_write(carID_,
				boost::bind(&Server::handle_Return_Car, this,
					boost::asio::placeholders::error, conn));
			break;
		case ADDNEWCAR:
			cout << "ADDNEWCAR" << endl;
			conn->async_write(test_,
				boost::bind(&Server::handle_Add_New_Car, this,
					boost::asio::placeholders::error, conn));
			break;
		case FINDCARBYID:
			cout << "FINDCARBYID" << endl;
			conn->async_write(manageCar_.getCarByID(findID_),
				boost::bind(&Server::handle_write, this,
					boost::asio::placeholders::error, conn));
			break;
		case GETUSERINFO:
			cout << "GETUSERINFO" << endl;
			conn->async_write(user_,
				boost::bind(&Server::handle_write, this,
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