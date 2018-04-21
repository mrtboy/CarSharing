#include <iostream>
#include <string>
#include <memory>
#include <boost/asio/io_service.hpp>

#include "chatserver.hpp"

int main()
{

	
  try
  {

	  
    boost::asio::io_service io_service;

    chatserver srv(io_service);
	
    io_service.run();
	
  }
  catch (std::exception const &e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}

