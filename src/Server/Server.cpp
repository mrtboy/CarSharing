#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include "User.h"
#include "ManageUser.h"
#include "Car.h"

using namespace boost::archive;

using namespace std;

stringstream ss;

void save()
{
	text_oarchive oa{ ss };
	User a{ "Id","Name",23,"Address","Email","other" };
	oa << a;
}

void load()
{
	text_iarchive ia{ ss };
	User a;
	ia >> a;
	std::cout << a.getAddress() << '\n';
	std::cout << a.getAge() << '\n';
}

int main()
{
	save();
	load();

	return 0;

}