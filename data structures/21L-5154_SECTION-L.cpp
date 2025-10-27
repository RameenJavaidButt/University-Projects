//IFRA JAVAID
//21L-5152
//ASSIGNMENT 3
#include<iostream>
#include<string.h>
using namespace std;
void quest2()
{
	int a[10];
	int a1[20];
	int t;
	int n1;
	int n2;

	cout << "Enter size= ";
	cin >> n1;
	cout << "Enter elements for first array:" << endl;

	for (int i = 0; i < n1; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n1; i++)
	{
		for (int j = i + 1; j < n1; j++)
		{
			if (a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;

			}
		}
	}
	int b[10];
	cout << "Enter size=  ";
	cin >> n2;
	cout << "Enter elements for secong array:" << endl;
	for (int i = 0; i < n2; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i < n2; i++)
	{
		for (int j = i + 1; j < n2; j++)
		{
			if (b[i] > b[j])
			{
				int temp = b[i];
				b[i] = b[j];
				b[j] = temp;

			}
		}
	}

	t = 0;
	for (int i = 0; i < n1; i++)
	{
		a1[t] = a[i];
		t++;
	}
	for (int i = 0; i < n2; i++)
	{
		int count = 1;
		for (int j = 0; j < n1; j++)
		{
			if (b[i] == a[j])
			{
				count = 0;
				break;
			}
		}
		if (count)
		{
			a1[t] = b[i];
			t++;
		}
	}
	cout << "The union=" << endl;
	for (int i = 0; i < t; i++)
	{
		for (int j = i + 1; j < t; j++)
		{
			if (a1[i] > a1[j])
			{
				int temp = a1[i];
				a1[i] = a1[j];
				a1[j] = temp;

			}


		}
		cout << a1[i] << "  ";
	}


	cout << endl;

	int i = 0, j = 0;
	int c = 0;
	int r[10];

	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < n2; j++)
		{
			if (a[i] == b[j])
			{
				r[c] = a[i];
				c++;

			}
			else {
				continue;
			}
		}
	}
	cout << "Intersection=   " << endl;
	for (int k = 0; k < c; k++)
	{
		cout << r[k] << " ";
	}
}
void update(int arr[], int size)
{

	int n;
	int newvalue;

	int c = 0;

	cout << "Enter number to be updated=  ";
	cin >> n;
	cout << "Enter newvalue=  ";
	cin >> newvalue;

	for (int i = 0; i < size; i++)
	{
		if (n == arr[i])
		{
			arr[i] = newvalue;
			c++;
			break;
		}
	}
	if (c == 0)
	{
		cout << "Number not found";
	}

	else
	{
		for (int i = 0; i < size; i++)
		{

			cout << arr[i] << " " << endl;
		}
		cout << "UPDATED";
	}
}
void deletion(int arr[], int size)
{

	int num;
	int c = 0;
	cout << "Enter number to deleted= ";
	cin >> num;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == num)
		{
			for (int j = i; j < (size + 1); j++)
			{
				arr[j] = arr[j + 1];
				c++;
				i--;

			}
			size--;
		}
	}
	if (c == 0)
	{
		cout << "Element not found";
	}
	else
	{
		cout << "Deleted" << endl;
		cout << "New array" << "  ";
		for (int i = 0; i < size; i++)
		{

			cout << arr[i] << " ";
		}
	}
	cout << endl;

}
void insertion(int arr[], int size)
{
	int p;
	int pos = 0;
	cout << "Enter value to be inserted= ";
	cin >> p;

	for (int i = 0; i < size; i++)
	{
		if (pos < arr[i])
		{
			pos = i;
			break;
		}
		else
		{
			pos = i + 1;
		}
	}
	for (int i = size + 1; i >= pos; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[pos] = p;
	cout << "Inserted " << endl;
	cout << "New array= " << endl;
	for (int i = 0; i <= size; i++)
	{
		for (int j = i + 1; j <= size; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;

			}
		}
		cout << arr[i] << "  ";
	}

}

void quest1()
{

	int s;
	int a[20];
	int choice;
	cout << "Enter 1 for INSERTION" << endl;
	cout << "Enter 2 for DELETION" << endl;
	cout << "Enter 3 for UPDATE" << endl;
	cin >> choice;
	cout << "Enter size= ";
	cin >> s;

	if (s > 20)
	{
		cout << "ARRAY IS FULL";
	}
	else {
		cout << "Enter elements= ";
		for (int i = 0; i < s; i++)
		{
			cin >> a[i];
		}
		if (choice == 1)
		{

			insertion(a, s);

		}
		if (choice == 2)
		{

			deletion(a, s);

		}
		if (choice == 3)
		{

			update(a, s);

		}
	}
}

int main()
{
	int choice;
	cout << "Enter choice  =  ";
	cin >> choice;
	if (choice == 2)
	{
		quest2();
	}
	if (choice == 1)
	{
		quest1();
	}
	system("pause");
	return 0;
}