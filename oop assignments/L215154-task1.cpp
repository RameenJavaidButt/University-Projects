#include <iostream>
#include <fstream>
using namespace std;
class myvector {

	int* a;
	int size;
	int capacity;

	void doublearray() {
		int* temp = new int[2 * capacity];
		for (int i = 0; i < size; i++) {
			temp[i] = a[i];
		}
		delete[]a;
		a = temp;
		delete[]temp;
	}
public:
	friend ostream& operator<<(ostream& out, myvector& v);
	friend istream& operator>>(istream& in, myvector& v);
	void operator+(int n) {
		if (getsize() < getcapacity()) {
			a[size] = n;
			size++;
		}
		else {
			doublearray();
			a[size] = n;
			size++;
		}
	}
	void operator-() {
		a[size - 1] = 0;
		size--;
	}
	int* operator+(myvector& v) {
		int* temp;
		temp = new int[size + v.size];
		for (int i = 0; i < size; i++) {
			temp[i] = a[i];
		}

		for (int i = 0; i < v.size; i++) {
			temp[size + i] = v.a[i];

		}
		return temp;

	}
	void setsize(int size) {
		this->size = size;
	}
	void setcapacity(int capacity) {
		this->capacity = capacity;
	}
	void setarray(int* a1) {
		for (int i = 0; i < size; i++) {
			a[i] = a1[i];
		}
	}
	int* getarray() {
		return a;
	}
	int getsize() {
		return size;
	}
	int getcapacity() {
		return capacity;
	}
	myvector() {   //default
		size = 0;
		capacity = 2;
		a = new int[capacity];
		for (int i = 0; i < capacity; i++) {
			a[i] = 0;
		}
	}
	myvector(int c) {  //para
		capacity = c;
		a = new int[capacity];
		for (int i = 0; i < capacity; i++) {
			a[i] = 0;
		}
	}
	~myvector() {  //des
		delete[]a;
	}
	int* operator=(myvector& v) {
		int j = 0;
		for (int i = 0; i < v.size; i++) {
			if (a[i] != v.a[i]) {
				a[j] = v.a[i];
				j++;
			}
		}
		return a;
	}
	myvector(myvector& v) {  //copy
		capacity = v.capacity;
		size = v.size;
		a = new int[v.capacity];
		for (int i = 0; i < v.size; i++) {
			a[i] = v.a[i];
		}
	}
	bool operator[](int n) {
		int e = 98;
		if (n >= 0 && n <= capacity) {


			a[n] = e;
			return true;
		}
		else {
			return false;
		}
	}

};
ostream& operator<<(ostream& out, myvector& v) {
	out << "Array" << endl;
	for (int i = 0; i < v.size; i++) {
		out << v.a[i] << " ";
	}
	return out;
	cout << endl;
}
istream& operator>>(istream& in, myvector& v) {
	cout << "Enter the capacity = ";
	in >> v.capacity;
	v.setcapacity(v.capacity);
	cout << endl;
	cout << "Enter the size = ";
	in >> v.size;
	v.setsize(v.size);
	cout << endl;
	cout << "Enter the elements = " << endl;
	v.a = new int[v.capacity];
	for (int i = 0; i < v.size; i++) {
		in >> v.a[i];
	}
	return in;
	cout << endl;
}

int main() {
	myvector v;
	myvector v1(2);
	myvector v3(v1);
	cout <<"Initial capacity = "<< v1.getcapacity();
	cout << endl;
	cin >> v;
	cout << v;
	myvector v5;
	int* arr;
	int b[2] = { 11,22 };
	v5.setsize(2);
	v5.setcapacity(2);
	v5.setarray(&b[0]);

	myvector v6;
	int b1[2] = { 1,2 };
	v6.setsize(2);
	v6.setcapacity(2);
	v6.setarray(&b1[0]);
	arr = v6 + v5;
	cout << endl;
	int s1 = v6.getsize() + v5.getsize();
	for (int i = 0; i < s1; i++) {
		cout << arr[i] << " ";
	}
	int j;
	cout << "Enter the element to add = ";
	cin >> j;

	v + j;
	cout << "Added" << endl;
	cout << v;
	cout << endl << endl;
	-v;
	cout << "Deleted" << endl;
	cout << v;
	cout << endl;
	int i;
	cout << endl;
	cout << "Enter the index to check : ";
	cin >> i;
	if (v[i]) {
		cout << "Can get added " << endl;
		cout << v;
	}
	else {
		cout << "Out of bound" << endl;
	}


	system("pause");
	return 0;
}
