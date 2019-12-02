#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char ch;
	fstream f;
	f.open("first.txt", ios::out);
	if (!f)
	{
		cout << "Enter the opening file" << endl;
		return 0;
	}
	cout << "file name first.txt created !!!" << endl;
	f << "SY_B.TECH_COMPUTER_DIVISION_A ,_BATCH A-1,_VIIT,PUNE " << endl;
	f.close();
	f.open("first.txt", ios::in);
	if (!f)
	{
		cout << "Error opening file" << endl;
		return 0;
	}
	while (!f.eof())
	{
		f >> ch;
		cout << ch;
	}
	f.close();;
	return 0;
}
