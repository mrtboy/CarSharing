#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/binary_object.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>

#include <map>
#include <boost/serialization/map.hpp>
#include <boost/serialization/split_member.hpp>


struct values
{
	std::string name;
	std::string sex;
	values() :name("dummy"), sex("dummy") {};

	BOOST_SERIALIZATION_SPLIT_MEMBER();

	template<class Archive>
	void save(Archive & ar, const unsigned int version) const
	{
		// note, version is always the latest when saving
		ar & BOOST_SERIALIZATION_NVP(name);
		ar & BOOST_SERIALIZATION_NVP(sex);
	}
	template<class Archive>
	void load(Archive & ar, const unsigned int version)
	{
		ar & BOOST_SERIALIZATION_NVP(name);
		ar & BOOST_SERIALIZATION_NVP(sex);
	}
};
class Myclass
{
public:

	Myclass()
	{
		values val1;
		e_group.insert(std::make_pair(1, val1));
		e_group.insert(std::make_pair(2, val1));
		p_group.insert(std::make_pair(1, e_group));
		p_group.insert(std::make_pair(2, e_group));
	}

	BOOST_SERIALIZATION_SPLIT_MEMBER();

	template<class Archive>
	void save(Archive & ar, const unsigned int version) const
	{
		// note, version is always the latest when saving
		ar & BOOST_SERIALIZATION_NVP(e_group);
		ar & BOOST_SERIALIZATION_NVP(p_group);
	}
	template<class Archive>
	void load(Archive & ar, const unsigned int version)
	{
		ar & BOOST_SERIALIZATION_NVP(e_group);
		ar & BOOST_SERIALIZATION_NVP(p_group);
	}

	typedef   std::map<int, values> groups;
	typedef   std::map<int, groups> Pgroups;
	groups  e_group;
	Pgroups p_group;
};

template<class Archive, class Object>
std::string serialise_to_string(Object const& assetlist)
{
	auto os = std::ostringstream(std::ios::binary);
	Archive arch{ os, boost::archive::no_header };
	arch << BOOST_SERIALIZATION_NVP(assetlist);
	return os.str();
};


std::ostream& dump(std::ostream& os, std::string const& s)
{
	const char *sep = "";
	for (uint8_t ch : s) {
		std::cout << sep << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(ch);
		sep = " ";
	}
	return os;
}

template<class Archive, class Object>
void deserialise_to_obj(std::string const &s1, Object &outObj)
{
	std::stringstream is(s1, std::ios_base::binary | std::ios_base::out | std::ios_base::in);
	Archive arch{ is, boost::archive::no_header };
	arch >> BOOST_SERIALIZATION_NVP(outObj);
};


int main() {

	Myclass obj;
	std::string  s1 = serialise_to_string<boost::archive::binary_oarchive>(obj);
	dump(std::cout, s1) << std::endl << std::endl;

	auto s2 = serialise_to_string<boost::archive::xml_oarchive>(obj);

	//Save xml to a file
	std::ofstream ofs("output.xml");
	ofs << s2 << std::endl << std::endl;

	//Deserialize the binary data to object
	Myclass outObj;
	deserialise_to_obj<boost::archive::binary_iarchive>(s1, outObj);

	//Print the object 
	for (auto &i : outObj.p_group) {
		std::cout << "\n" << i.first << "\n";
		for (auto &j : i.second) {
			std::cout << "\t" << j.first << "\t" << j.second.name << "\t" << j.second.sex << "\n";
		}
	}
}