#include<iostream>
#include<exception>
using namespace std;

class City_Exception :public exception {
public:
	const char* what() const throw() {
		return "City is not Chennai or Bangalore or Pune or Mumbai\n";
	}
};

class Wheel_Exception :public exception {
public:
	const char* what() const throw() {
		return "The Vehicle is not a 4-Wheeler\n";
	}
};

int main()
{
	string city;
	int wheels;

	try {
		cout << "Enter City: ";
		cin >> city;
		if (city != "Pune" && city != "Mumbai" && city != "Chennai" && city != "Bangelore")
		{
			City_Exception ce;
			throw ce;
		}

		else
		{
			cout << "City: " << city << endl;
		}
	}

	catch (exception & e) {
		cout << e.what() << endl;
	}

	try {
		cout << "Enter Wheels: ";
		cin >> wheels;
		if (wheels != 4) {
			Wheel_Exception we;
			throw we;
		}
		else {
			cout << "Vehicle is a 4-Wheeler" << endl;
		}

	}

	catch (exception & e) {
		cout << e.what() << endl;
	}

}