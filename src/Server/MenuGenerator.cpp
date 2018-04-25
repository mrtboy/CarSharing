#include "MenuGenerator.h"

#include <iostream>

using namespace std;

string MenuGenerator::MenuItemSelected(int item) {
	switch (item)
	{
	case 0:
		return "Quite";
		break;
	case 1:
		return "Add New Car";
		break;
	case 2:
		return "Rent Car";
		break;
	case 3: 
		return "Available Cars";
		break;
	case 4:
		return "Return Car";
		break;
	case 9: 
		return "Show Main Menu";
		break;
	default:
		return "Select other number";
		break;
	}
}

