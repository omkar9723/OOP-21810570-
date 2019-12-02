#include<iostream>
using namespace std;
struct student
{
	unsigned int roll_no, m1, m2, m3;
	string name;
};
void sort_record(struct student s[50], int n)
{
	int hold, j, pass;
	int switched = 1;
	string temp;
	for (pass = 0; pass < n - 1 && switched == 1;pass++)
	{
		switched = 0;
		for (j = 0;j < n - pass - 1;j++)
		{
			if (s[j].roll_no > s[j + 1].roll_no)
			{
				switched = 1;
				hold = s[j].roll_no;
				s[j].roll_no = s[j + 1].roll_no;
				s[j + 1].roll_no = hold;

				temp = s[j].name;
				s[j].name = s[j + 1].name;
				s[j + 1].name = temp;

				hold = s[j].m1;
				s[j].m1 = s[j + 1].m1;
				s[j + 1].m1 = hold;

				hold = s[j].m2;
				s[j].m2 = s[j + 1].m2;
				s[j + 1].m2 = hold;

				hold = s[j].m3;
				s[j].m3 = s[j + 1].m3;
				s[j + 1].m3 = hold;

			}
		}
	}
}
int  search(struct student s[50], int n)
{
	int high, low, mid, key, found = 0;
	cout << "SEARCH: \n Enter roll number :- ";
	cin >> key;
	low = 0;
	high = n - 1;
	while (low < high)
	{
		mid = (low + high) / 2;
		if (key < s[mid].roll_no)
		{
			high = mid - 1;
		}
		else if (key > s[mid].roll_no)
		{
			low = mid + 1;
		}

		else if (key = s[mid].roll_no)
		{
			return (mid);
			found = 1;
			break;
		}
	}
	if (found == 0)
	{
		cout << "ROLL NUMBER NOT FOUND IN DATABASE" << endl;
	}
}
int main()
{
	student s[50];
	int sh, n, i, pos, mo, x, hold;
	string temp;
	cout << "       WELCOME       " << endl;
	do
	{
		cout << "Enter option:" << endl;
		cout << "\n\n\n1-ADD DATA \t\t 2-DISPLAY DATA\n3-SEARCH RECORD \t 4-MODIFY RECORD \n5-DELETE RECORD \t 6-SORT RECORD \n7-EXIT" << endl;
		cin >> sh;
		switch (sh)
		{
		case 1://add data
		{
			cout << "enter number of students" << endl;
			cin >> n;
			for (i = 0;i < n;i++)
			{
				cout << "enter roll number ,name, marks [m1,m2,m3] of student" << endl;
				cin >> s[i].roll_no >> s[i].name >> s[i].m1 >> s[i].m2 >> s[i].m3;
				cout << endl;
			}
		}
		break;
		case 2://display data
			for (i = 0;i < n;i++)
			{
				cout << endl;
				cout << "Roll number: " << s[i].roll_no << "\t" << "Name: " << s[i].name << "\t" << "m1: " << s[i].m1 << "\t" << "m2: " << s[i].m2 << "\t" << "m3: " << s[i].m3 << endl;
			}
			break;
		case 3://search with roll
			sort_record(s, n);
			pos = search(s, n);
			cout << endl;
			cout << "Roll number : " << s[pos].roll_no << "\t" << "Name: " << s[pos].name << "\t" << "m1: " << s[pos].m1 << "\t" << "m2: " << s[pos].m2 << "\t" << "m3: " << s[pos].m3 << endl;
			break;
		case 4://modify record

			cout << "enter number of students to add" << endl;
			cin >> x;
			for (i = n;i < n + x;i++)
			{
				cout << "enter roll number ,name, marks [m1,m2,m3] of student" << endl;
				cin >> s[i].roll_no >> s[i].name >> s[i].m1 >> s[i].m2 >> s[i].m3;
				cout << endl;
			}
			n = n + x;
			break;
		case 5://delete record
			sort_record(s, n);
			pos = search(s, n);
			for (i = pos;i < n;i++)
			{
				hold = s[pos].roll_no;
				s[pos].roll_no = s[pos + 1].roll_no;
				s[pos + 1].roll_no = hold;

				temp = s[pos].name;
				s[pos].name = s[pos + 1].name;
				s[pos + 1].name = temp;

				hold = s[pos].m1;
				s[pos].m1 = s[pos + 1].m1;
				s[pos + 1].m1 = hold;

				hold = s[pos].m2;
				s[pos].m2 = s[pos + 1].m2;
				s[pos + 1].m2 = hold;

				hold = s[pos].m3;
				s[pos].m3 = s[pos + 1].m3;
				s[pos + 1].m3 = hold;
			}
			n = n - 1;
			break;
		case 6://sort record
			sort_record(s, n);
			cout << "sorted list is :" << endl << endl;
			for (i = 0;i < n;i++)
			{
				cout << endl;
				cout << "Roll number: " << s[i].roll_no << "\t" << "Name: " << s[i].name << "\t" << "m1: " << s[i].m1 << "\t" << "m2: " << s[i].m2 << "\t" << "m3: " << s[i].m3 << endl;
			}
			break;
		}
	} while (sh != 7);
	return 0;
}
