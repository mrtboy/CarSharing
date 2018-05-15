//#include <boost/asio.hpp>
//#include <boost/bind.hpp>
//#include <iostream>
//#include <vector>
//#include "Connection.h" // Must come before boost/serialization headers.
//#include <boost/serialization/vector.hpp>
//#include "User.h"
//#include "Car.h"
//#include "ManageUser.h"
//#include "MainMenu.h"
//
//using namespace std;
//
///// Downloads stock quote information from a server.
//class ClientConnection
//{
//public:
//	/// Constructor starts the asynchronous connect operation.
//	ClientConnection(boost::asio::io_service& io_service,
//		const std::string& host, const std::string& service)
//		: connection_(io_service)
//	{
//		// Resolve the host name into an IP address.
//		boost::asio::ip::tcp::resolver resolver(io_service);
//		boost::asio::ip::tcp::resolver::query query(host, service);
//		boost::asio::ip::tcp::resolver::iterator endpoint_iterator =
//			resolver.resolve(query);
//
//		// Start an asynchronous connect operation.
//		boost::asio::async_connect(connection_.socket(), endpoint_iterator,
//			boost::bind(&ClientConnection::handle_connect, this,
//				boost::asio::placeholders::error));
//		
//		//Car car{ "Reza",20,"Kiel",1, "CLA", 2018,"AMG",4,4,"Automatic","Benzin", "Limo", true };
//		//car_.push_back(car);
//	}
//
//	/// Handle completion of a connect operation.
//	void handle_connect(const boost::system::error_code& e)
//	{
//		if (!e)
//		{
//			// Successfully established connection. Start operation to read the list
//			// of stocks. The connection::async_read() function will automatically
//			// decode the data that is read from the underlying socket.
//
//			connection_.async_write(car_,
//				boost::bind(&ClientConnection::handle_write, this,
//					boost::asio::placeholders::error));
//
//			connection_.async_read(ManageUser::users,
//				boost::bind(&ClientConnection::handle_read, this,
//					boost::asio::placeholders::error));
//		}
//		else
//		{
//			// An error occurred. Log it and return. Since we are not starting a new
//			// operation the io_service will run out of work to do and the client will
//			// exit.
//			std::cerr << e.message() << std::endl;
//		}
//	}
//
//	/// Handle completion of a read operation.
//	void handle_read(const boost::system::error_code& e)
//	{
//		if (!e)
//		{
//			// Print out the data that was received.
//
//			for (std::size_t i = 0; i < user_.size(); ++i) {
//				cout << "id: " << user_[i].getId() << endl;
//				cout << "name: " << user_[i].getName() << endl;
//			}
//		}
//		else
//		{
//			// An error occurred.
//			std::cerr << e.message() << std::endl;
//		}
//
//		// Since we are not starting a new operation the io_service will run out of
//		// work to do and the client will exit.
//	}
//
//	void handle_write(const boost::system::error_code& e)
//	{
//		// Nothing to do. The socket will be closed automatically when the last
//		// reference to the connection object goes away.
//	}
//
//private:
//	/// The connection to the server.
//	Connection connection_;
//
//	/// The data received from the server.
//	std::vector<User> user_;
//	std::vector<Car> car_;
//};
