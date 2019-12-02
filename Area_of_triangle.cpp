#include<iostream>
using namespace std;
class Shape
{
public:
	double length, width;
	void get_data() //accept length and width
	{
		cout << "Enter the length::";
		cin >> length;
		cout << "Enter the width::";
		cin >> width;
	}
	void display()  //display length and width
	{
		cout << "length::" << length;
		cout << "\t width::" << width << endl;
	}
};
class rectangle :public Shape //inheritance base class shape
{
public:
	double result;
	void cal()    //calculate  area of rectangle
	{
		get_data();
		display();
		result = (length * width);
	}
	void display_area() //display area of rectangle
	{
		cout << "area of rectangle::" << result << endl;
	}
};
class triangle :public Shape //inheritance  of shape class
{
public:
	double result;

	void cal() //calculate area of triangle
	{
		get_data();
		display();
		result = (length * width) / 2;
	}
	void display_area()  //display area of triangle
	{
		cout << "area of triangle::" << result << endl;
	}
};
int main()
{
	int ch;
	char rep = 'n';
	rectangle r;
	triangle t;
	do
	{
		cout << "1.Area of rectangle 2.Area of triangle" << endl;
		cout << "Enter the choice::";
		cin >> ch;
		switch (ch)  // switch case used for multiple operation
		{
		case 1:
			r.cal();
			r.display_area();
			break;
		case 2:
			t.cal();
			t.display_area();
			break;
		default:
			cout << "Enter the valid choice::" << endl;
			break;
		}
		cout << "do you want repeat process (Y/N)::";
		cin >> rep;
	} while (rep == 'Y' || rep == 'y');
	return 0;
}