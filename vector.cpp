#include<iostream>
using namespace std;

class vector
{
	int size;
	int* coord;
public:
	vector();
	void modify();
	void display();
	void multiply();
};
vector::vector()   //accept co-ordinates
{
	cout << "\n Enter Number of Co-ordinates : ";
	cin >> size;
	coord = new int[size];
	cout << "\n Enter " << size << " Co-ordinates : \n";
	for (int i = 0; i < size; i++)
	{
		cout << " ";
		cin >> coord[i];
	}
}
void vector::modify()   //Modify Co-ordinates
{
	int pos;
	cout << "enter position to make changes :";
	cin >> pos;
	cout << "Enter new Value :";
	cin >> coord[pos - 1];
}
void vector::multiply()   //Multiplying Co-ordinates
{
	int num;
	cout << endl << "\n Enter Number to Multiply : ";
	cin >> num;
	for (int i = 0; i < size; i++)
	{
		coord[i] = coord[i] * num;
	}
}
void vector::display()  //Displaying the vector
{
	cout << "\n Vector : (";
	for (int i = 0; i < size; i++)
	{
		cout << coord[i];
		if (i != size - 1)
			cout << ",";
	}
	cout << ")\n";
}
int main()
{
	int s;
	vector v;;
	do
	{
		cout << "select the option \n1-Display\t\t2-Modify\n3-Multiply\t\t4-Exit\n";
		cin >> s;
		switch (s)
		{
		case 1:
			v.display();
			break;
		case 2:
			v.modify();
			v.display();
			break;
		case 3:
			v.multiply();
			v.display();
			break;
		}
	} while (s != 4);
	return 0;
}
