#include <iostream>
#include <fstream>
using namespace std;
template<class t>
class myvector {

	char* a;
	t size;
	t capacity;

	void doublearray() {
		char* temp = new char[2 * capacity];
		for (int i = 0; i < size; i++) {
			temp[i] = a[i];
		}
		delete[]a;
		a = temp;
		delete[]temp;
	}
public:
	friend ostream& operator<<(ostream& out, myvector<t>& v) {
		out << "Array" << endl;
		for (int i = 0; i < v.size; i++) {
			out << v.a[i] << " ";
		}
		return out;
		cout << endl;
	}
	friend istream& operator>>(istream& in, myvector<t>& v) {
		cout << "Enter the capacity = ";
		in >> v.capacity;
		v.setcapacity(v.capacity);
		cout << endl;
		cout << "Enter the size = ";
		in >> v.size;
		v.setsize(v.size);
		cout << endl;
		cout << "Enter the elements = " << endl;
		v.a = new char[v.capacity];
		for (int i = 0; i < v.size; i++) {
			in >> v.a[i];
		}
		return in;
		cout << endl;
	}
	void operator+(char n) {
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
	char* operator+(myvector& v) {
		char* temp;
		temp = new char[size + v.size];
		for (int i = 0; i < size; i++) {
			temp[i] = a[i];
		}

		for (int i = 0; i < v.size; i++) {
			temp[size + i] = v.a[i];

		}
		return temp;

	}
	void setsize(t size) {
		this->size = size;
	}
	void setcapacity(t capacity) {
		this->capacity = capacity;
	}
	void setarray(char* a1) {
		for (int i = 0; i < size; i++) {
			a[i] = a1[i];
		}
	}
	char* getarray() {
		return a;
	}
	t getsize() {
		return size;
	}
	t getcapacity() {
		return capacity;
	}
	myvector() {   //default
		size = 0;
		capacity = 2;
		a = new char[capacity];
		for (int i = 0; i < capacity; i++) {
			a[i] = 0;
		}
	}
	myvector(t c) {  //para
		capacity = c;
		a = new char[capacity];
		for (int i = 0; i < capacity; i++) {
			a[i] = 0;
		}
	}
	~myvector() {  //des
		delete[]a;
	}
	char* operator=(myvector& v) {
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
		a = new char[v.capacity];
		for (int i = 0; i < v.size; i++) {
			a[i] = v.a[i];
		}
	}
	bool operator[](t n) {
		char e = 'l';
		if (n >= 0 && n <= capacity) {


			a[n] = e;
			return true;
		}
		else {
			return false;
		}
	}

};


int main() {
	myvector<int> v;
	myvector <int>v1(2);
	myvector<int> v3(v1);
	cout <<"Initial capacity = "<< v1.getcapacity();
	cout << endl;
	cin >> v;
	cout << v;
	myvector<int> v5;
	char* arr;
	char b[2] = { 'a','b' };
	v5.setsize(2);
	v5.setcapacity(2);
	v5.setarray(&b[0]);

	myvector<int> v6;
	char b1[2] = { 'k','o' };
	v6.setsize(2);
	v6.setcapacity(2);
	v6.setarray(&b1[0]);
	arr = v6 + v5;
	cout << endl;
	int s1 = v6.getsize() + v5.getsize();
	cout << "Merged two arrays containing 1,2 and 11,22 " << endl;
	for (int i = 0; i < s1; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	char j;
	cout << "Enter the element to add = ";
	cin >> j;

	v + j;
	cout << "Added" << endl;
	cout << v;
	cout << endl << endl;
	-v;
	cout << "Deleted the last element " << endl;
	cout << v;
	cout << endl;
	int i;
	cout << endl;
	cout << "Enter the index to check whether number can be added or not : ";
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

