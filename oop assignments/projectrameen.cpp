#include<iostream>
#include<cstring>
using namespace std;
class name {
private:
	char* fname;
	char* lname;
public:
	~name();
	name();
	name(char*fn, char*ln);
	name(name& obj, name& ob);
	friend ostream& operator<<(ostream& out, const name& n);
};
ostream& operator<<(ostream& out, const name& n) {
	out << n.fname << endl;
	out << n.lname << endl;
	return out;
}
name::name(name& obj, name& ob) {
	int len = strlen(obj.fname);
	int len1 = strlen(ob.lname);
	fname = new char[len + 1];
	lname = new char[len1 + 1];
	for (int i = 0; i < len+1; i++) {
		fname[i] = obj.fname[i];
		if (i == len + 1) {
			fname[i] = '\0';
		}
	}
	for (int i = 0; i < len + 1; i++) {
		lname[i] = ob.lname[i];
		if (i == len + 1) {
			lname[i] = '\0';
		}
	}
}
name::~name() {
	delete[]fname;
	fname = 0;
	delete[]lname;
	lname = 0;
}
name::name(char* b,char *a) {
	int len = strlen(b);
	fname = new char[len + 1];
	for (int i = 0; i < len; i++) {
		fname[i] = b[i];
	}
	int len1 = strlen(a);
	lname = new char[len + 1];
	for (int i = 0; i < len; i++) {
		lname[i] = a[i];
	}
}
name::name() {
	{

		fname = new char[1];
		fname = nullptr;

		lname = new char[1];
		lname = nullptr;
	}
}
class date {
private:
	int day;
	int month;
	int year;
public:
	date();
	~date();
	date(int, int, int);
	friend ostream& operator<< (ostream& obj, const date ob);
	void set(int, int, int);

};
void date::set(int a, int b, int c) {
	day = a;
	month = b;
	year = c;
}
date::date() {
	day = 0;
	month = 0;
	year = 0;
}
date::~date() {
	day = 0;
	month = 0;
	year = 0;
}
date::date(int a, int b, int c) 
{day = a;
	month = b;
	year = c;
}
ostream& operator << (ostream & obj, const date ob) {
	obj << ob.day << endl;
	obj << ob.month << endl;
	obj << ob.year << endl;
	return obj;
}