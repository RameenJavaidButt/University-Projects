#include<iostream>
#include<cstring>
#include<fstream>
#include <string>
using namespace std;
class name {
	friend ostream& operator<<(ostream& out, const name& n);
	friend istream& operator >> (istream& in, name& n);
	friend ofstream& operator<<(ofstream& objout, name& n);//fromfiles
	friend ifstream& operator >> (ifstream& objin, name& n);
private:
	char* fname;
	char* lname;
public:
	~name();
	name();
	name& operator=(const name& obj) {
		if (fname != nullptr) {
			delete fname;
			fname = nullptr;
		}
		if (lname != nullptr)
		{
			delete lname;
			lname = nullptr;
		}
		fname = new char[strlen(obj.fname) + 1];
		lname = new char[strlen(obj.lname) + 1];
		for (int i = 0; i < strlen(obj.fname) + 1; i++) {
			fname[i] = obj.fname[i];
		}
		for (int i = 0; i < strlen(obj.lname) + 1; i++) {
			fname[i] = obj.fname[i];
		}
		return*this;
	}
	name(char* firstname, char* lname);
	name(const name& obj);

	char* getfname();
	char* getlname();
	void setname(char*, char*);
};
void name::setname(char* a, char* b) {    //setter
	int len = strlen(a);
	int len1 = strlen(b);
	if (fname != nullptr) {
		delete fname;
		fname = nullptr;
		fname = new char[len + 1];
		for (int i = 0; i < len + 1; i++) {
			fname[i] = a[i];
		}

	}
	else {
		fname = new char[len + 1];
		for (int i = 0; i < len + 1; i++) {
			fname[i] = a[i];
		}
	}
	if (lname != nullptr) {
		delete lname;
		lname = nullptr;
		lname = new char[len1 + 1];
		for (int i = 0; i < len1 + 1; i++) {
			lname[i] = b[i];
		}
	}
	else {
		lname = new char[len1 + 1];
		for (int i = 0; i < len1 + 1; i++) {
			lname[i] = b[i];
		}
	}
}
char* name::getfname() {
	return fname;               //getter
}
char* name::getlname() {
	return lname;
}
istream& operator >> (istream& in, name& n) {
	if (n.fname != nullptr)
	{
		delete n.fname;
	}
	if (n.lname != nullptr)          ///conditons to check if names are empty
	{
		delete n.lname;
	}

	n.fname = new char[50];
	n.lname = new char[50];
	in.ignore();
	cout << "Enter First Name: ";
	in.getline(n.fname, 50);
	cout << "Enter Last Name: ";
	in.getline(n.lname, 50);
	return in;
}
ofstream& operator<<(ofstream& objout, name& n) {
	//fromfiles
	objout << n.fname << " " << n.lname << endl;
	return objout;
}
ifstream& operator >> (ifstream& objin, name& n) {
	if (n.fname != nullptr)
		delete n.fname;
	if (n.lname != nullptr)
		delete n.lname;
	n.fname = new char[50];
	n.lname = new char[50];
	objin >> n.fname;
	objin >> n.lname;

	return objin;
}
ostream& operator<<(ostream& out, const name& n) {
	out << n.fname << " ";
	out << n.lname << endl;
	return out;
}
name::name(const name& obj) {   //copy
	if (obj.fname != nullptr && obj.lname != nullptr) {
		int len = strlen(obj.fname);
		int len1 = strlen(obj.lname);
		fname = new char[len + 1];
		lname = new char[len1 + 1];
		for (int i = 0; i < len + 1; i++) {
			fname[i] = obj.fname[i];
			if (i == len + 1) {
				fname[i] = '\0';
			}
		}
		for (int i = 0; i < len1 + 1; i++) {
			lname[i] = obj.lname[i];
			if (i == len1 + 1) {
				lname[i] = '\0';
			}
		}
	}
	else if (obj.fname != nullptr && obj.lname == nullptr)
	{
		fname = new char[strlen(obj.fname) + 1];
		for (int i = 0; i < strlen(obj.fname) + 1; i++) {
			fname[i] = obj.fname[i];
			if (i == (strlen(obj.fname)) + 1) {
				fname[i] = '\0';
			}
		}
		lname = nullptr;
	}
	else if (obj.fname == nullptr && obj.lname != nullptr) {
		fname = nullptr;
		lname = new char[strlen(obj.lname) + 1];
		for (int i = 0; i < strlen(obj.lname) + 1; i++) {
			lname[i] = obj.lname[i];
			if (i == strlen(obj.lname) + 1) {
				lname[i] = '\0';
			}
		}
	}
	else {
		fname = nullptr;
		lname = nullptr;
	}
}
name::~name() {            //destructor
	delete[]fname;
	fname = 0;
	delete[]lname;
	lname = 0;
}
name::name(char* firstname, char* lastname) {     //overloaded
	int len = strlen(firstname);
	fname = new char[len + 1];
	for (int i = 0; i < len + 1; i++) {
		fname[i] = firstname[i];
	}
	int len1 = strlen(lastname);
	lname = new char[len1 + 1];
	for (int i = 0; i < len1 + 1; i++) {
		lname[i] = lastname[i];
	}
}
name::name() {        //default
	{

		fname = new char[1];
		fname = nullptr;

		lname = new char[1];
		lname = nullptr;
	}
}
/////////////////class date
class date {
	friend ostream& operator<< (ostream& obj, const date ob);
	friend istream& operator >> (istream& in, date& d);
	friend ofstream& operator <<(ofstream& objout, date& d);
	friend ifstream& operator >> (ifstream& objin, date& d);
private:
	int day;
	int month;
	int year;
public:
	date();
	~date();
	date(int, int, int);
	date(const date& obj) {
		this->day = obj.day;
		this->month = obj.month;
		this->year = obj.year;
	}
	date& operator=(const date& d) {
		day = d.day;
		month = d.month;
		year = d.year;
		return *this;
	}
	bool operator==(const date&);
	void set(int, int, int);
	int getday();
	int getmonth();
	int getyear();

};
bool date::operator==(const date& obj) {
	if (this->day == obj.day && this->month == obj.month && this->year == obj.year)
		return true;
	return false;
}
int date::getday() {
	return day;
}
int date::getmonth() {
	return month;
}
int date::getyear() {
	return year;
}
void date::set(int aa, int bb, int cc) {
	day = aa;
	month = bb;
	year = cc;
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
date::date(int aa, int bb, int cc)
{
	day = aa;
	month = bb;
	year = cc;
}
ofstream& operator <<(ofstream& objout, date& d) {
	objout << d.day << ' ' << d.month << ' ' << d.year << endl;
	return objout;
}
istream& operator >> (istream& in, date& d) {

	cout << "Enter the date: ";
	in >> d.day;

	cout << "Enter the Month: ";
	in >> d.month;

	cout << "Enter the Year: ";
	in >> d.year;
	return in;
}
ifstream& operator >> (ifstream& objin, date& d) {
	objin >> d.day;
	objin >> d.month;
	objin >> d.year;
	return objin;
}
ostream& operator << (ostream& obj, const date ob) {
	obj << ob.day << "/" << ob.month << "/" << ob.year << endl;;
	return obj;
}

///////////////////////////////////////////////class time
class mtime {
	friend ostream& operator<< (ostream& obj, const mtime ob);
	friend istream& operator>>(istream& obj, mtime ob);
	friend ofstream& operator << (ofstream& objout, mtime& ob);
	friend ifstream& operator >> (ifstream& objin, mtime& ob);
private:
	int hour;
	int min;
	int sec;
public:
	mtime();
	~mtime();
	mtime(int, int, int);
	mtime(const mtime& obj) {
		this->hour = obj.hour;
		this->min = obj.min;          //copy
		this->sec = obj.sec;
	}
	void settime(int, int, int);
	void operator=(const mtime& obj)
	{
		this->hour = obj.hour;
		this->min = obj.min;          //copy
		this->sec = obj.sec;
	}
	int gethour();
	int getmin();
	int getsec();
};
int mtime::gethour() {
	return hour;
}
int mtime::getmin() {
	return min;
}
int mtime::getsec() {
	return sec;
}
void mtime::settime(int a, int b, int c) {
	hour = a;
	min = b;           //overloaded
	sec = c;
}
mtime::mtime() {
	hour = 0;
	min = 0;
	sec = 0;
}
mtime::~mtime() {
	hour = 0;
	min = 0;
	sec = 0;
}
mtime::mtime(int a, int b, int c)
{
	hour = a;
	min = b;
	sec = c;

}
istream& operator>>(istream& obj, mtime ob) {
	cout << "Enter the hour: ";
	obj >> ob.hour;

	cout << "Enter the minute: ";
	obj >> ob.min;

	cout << "Enter the second: ";
	obj >> ob.sec;
	return obj;
}
ofstream& operator << (ofstream& objout, mtime& ob) { ///takingfromfile
	objout << ob.hour << ' ' << ob.min << ' ' << ob.sec << endl;
	return objout;
}
ifstream& operator >> (ifstream& objin, mtime& ob) {///writinginfile
	objin >> ob.hour >> ob.min >> ob.sec;
	return objin;
}
ostream& operator << (ostream& obj, const mtime ob) {
	obj << ob.hour << ":" << ob.min << ":" << ob.sec << endl;;
	return obj;
}
/////////////////service class
class service {
	friend ostream& operator<<(ostream&, const service&);
	friend istream& operator>>(istream& in, service& obj);
	friend ifstream& operator>>(ifstream& filein, service& obj);
	friend ofstream& operator<<(ofstream& fileout, service& obj);
private:
	char* source;
	char* destination;
	date bookingdate;
	mtime bookingtime;
	bool status;  //false for pending true if complete
	float fuelrate;
	int cid;        //ids(customer,vehicle,river)
	int vid;
	int did;
	float distance;//in km
public:
	service();
	service(char*, char*, float, float, int, int, int, int, int, int, int, int, int, bool);
	service(service&);
	~service();
	service& operator=(const service& s)
	{
		this->distance = s.distance;
		this->fuelrate = s.fuelrate;
		this->status = s.status;
		this->vid = s.vid;
		this->did = s.did;
		this->cid = s.cid;
		if (this->source != nullptr && s.source != nullptr)
		{
			delete this->source;
			this->source = new char[strlen(s.source) + 1];

			for (int i = 0; i < strlen(s.source) + 1; i++) {
				source[i] = s.source[i];
				if (i == strlen(s.source) + 1) {
					source[i] = '\0';
				}
			}
		}
		else if (this->source != nullptr && s.source == nullptr)
		{
			delete this->source;
			this->source = nullptr;
		}
		else if (this->source == nullptr && s.source != nullptr)
		{
			this->source = new char[strlen(s.source) + 1];
			for (int i = 0; i < strlen(s.source) + 1; i++) {
				source[i] = s.source[i];
				if (i == strlen(s.source) + 1) {
					source[i] = '\0';
				}
			}
		}
		if (this->destination != nullptr && s.destination != nullptr)
		{
			delete this->destination;
			this->destination = new char[strlen(s.destination) + 1];
			for (int i = 0; i < strlen(s.destination) + 1; i++) {
				destination[i] = s.destination[i];
				if (i == strlen(s.destination) + 1) {
					destination[i] = '\0';
				}
			}
		}
		else if (this->destination != nullptr && s.destination == nullptr)
		{
			delete this->destination;
			this->destination = nullptr;
		}
		else if (this->destination == nullptr && s.destination != nullptr)
		{
			this->destination = new char[strlen(s.destination) + 1];
			for (int i = 0; i < strlen(s.destination) + 1; i++) {
				destination[i] = s.destination[i];
				if (i == strlen(s.destination) + 1) {
					destination[i] = '\0';
				}
			}
		}
		this->bookingdate = s.bookingdate;
		this->bookingtime = s.bookingtime;
		return *this;
	}
	void setservice(int, float, int, int, int, int, int, int, int, int, int);
	void setsource(char* csource) {
		if (source != nullptr) {
			delete source;
			int len = strlen(csource);   //setter
			source = new char[len + 1];

			for (int i = 0; i < len + 1; i++) {
				source[i] = csource[i];
				if (i == len + 1) {
					source[i] = '\0';
				}
			}
		}
		else {
			int len = strlen(csource);   //setter
			source = new char[len + 1];

			for (int i = 0; i < len + 1; i++) {
				source[i] = csource[i];
				if (i == len + 1) {
					source[i] = '\0';
				}
			}
		}
	}
	void setdestination(char* cdestination) {
		if (destination != nullptr) {
			delete destination;
			int len1 = strlen(cdestination);
			destination = new char[len1 + 1];
			for (int i = 0; i < len1 + 1; i++) {
				destination[i] = cdestination[i];
				if (i == len1 + 1) {
					destination[i] = '\0';
				}
			}
		}
		else {
			int len1 = strlen(cdestination);
			destination = new char[len1 + 1];
			for (int i = 0; i < len1 + 1; i++) {
				destination[i] = cdestination[i];
				if (i == len1 + 1) {
					destination[i] = '\0';
				}
			}
		}
	}
	char* getsource();
	char* getdestination();
	bool getstatus();
	float getfuelrate();
	int getcid();
	int getvid();
	int getdid();
	int getday();
	int getmonth();
	void setstatus(bool);
	int getyear();
	date getdate();
	int getsec();
	int getmin();
	int gethour();
	float getdis();


};
int service::getday() {
	return bookingdate.getday();
}
int service::getmonth() {
	return bookingdate.getmonth();
}
int service::getyear() {
	return bookingdate.getyear();
}
date service::getdate() {
	return bookingdate;
}
int service::getsec() {
	return bookingtime.getsec();
}
int service::getmin() {
	return bookingtime.getmin();
}
int service::gethour() {
	return bookingtime.gethour();
}
float service::getdis() {
	return distance;
}
char* service::getsource() {
	return source;
}
char* service::getdestination() {
	return destination;
}
bool service::getstatus() {
	return status;
}
float service::getfuelrate() {
	return fuelrate;
}
int service::getcid() {
	return cid;
}
int service::getvid() {
	return vid;
}
int service::getdid() {
	return did;
}

void service::setstatus(bool cstatus)
{
	status = cstatus;
}
void service::setservice(int d, float cfuelrate, int ccid, int cvid, int cdid, int hour, int min, int sec, int day, int month, int year)
{



	fuelrate = cfuelrate;
	cid = ccid;        //ids
	vid = cvid;
	did = cdid;
	distance = d;
	bookingtime.settime(hour, min, sec);
	bookingdate.set(day, month, year);

}

service::service(char* csource, char* cdestination, float dis, float cfuelrate, int ccid, int cvid, int cdid, int day, int month, int year, int hour, int min, int sec, bool cstatus) :bookingdate(day, month, year), bookingtime(hour, min, sec) {
	int len = strlen(csource);   //overloaded
	source = new char[len + 1];
	for (int i = 0; i < len + 1; i++) {
		source[i] = csource[i];
		if (i == len + 1) {
			source[i] = '\0';
		}
	}
	int len1 = strlen(cdestination);
	destination = new char[len1 + 1];
	for (int i = 0; i < len1 + 1; i++) {
		destination[i] = cdestination[i];
		if (i == len1 + 1) {
			destination[i] = '\0';
		}
	}
	this->status = cstatus;
	fuelrate = cfuelrate;
	cid = ccid;        //ids
	vid = cvid;
	did = cdid;
	distance = dis;
}
service::service(service& o) :bookingdate(o.bookingdate), bookingtime(o.bookingtime) {    ///copy
	int len = strlen(o.source);
	distance = o.distance;
	source = new char[len + 1];
	for (int i = 0; i < len + 1; i++) {
		source[i] = o.source[i];
		if (i == len + 1) {
			source[i] = '\0';
		}
	}
	int len1 = strlen(o.destination);
	destination = new char[len1 + 1];
	for (int i = 0; i < len1 + 1; i++) {
		destination[i] = o.destination[i];
		if (i == len1 + 1) {
			destination[i] = '\0';
		}
	}
	this->status = o.status;
	fuelrate = o.fuelrate;
	cid = o.cid;
	vid = o.vid;
	did = o.did;
}
service::~service() {     //destructor
	delete[]source;
	source = nullptr;
	delete[]destination;
	destination = nullptr;

	status = 0;
	fuelrate = 0;
	cid = 0;        //ids
	vid = 0;
	did = 0;
}
service::service() :bookingdate(), bookingtime() {             ///default
	source = new char[1];
	source = nullptr;
	destination = new char[1];
	destination = nullptr;
	distance = 0;
	status = 0;
	fuelrate = 0;
	cid = 0;        //ids
	vid = 0;
	did = 0;
}
istream& operator>>(istream& in, service& obj) {
	cout << "Enter Source: ";
	char* temp = new char[1000];
	in.ignore();
	in.getline(temp, 1000);
	obj.setsource(temp);
	delete []temp;
	char* temb = new char[1000];
	cout << "Enter Destination: ";
	in.getline(temb, 1000);
	obj.setdestination(temb);
	delete[] temb;
	cout << "Enter Booking Date" << endl;
	in >> obj.bookingdate;
	cout << "Enter Booking Time" << endl;
	in >> obj.bookingtime;
	cout << "Enter Distance: ";
	in >> obj.distance;
	cout << "Enter Status: (0 if Pending, 1 if Complete, 2 if Canceled): ";
	in >> obj.status;
	cout << "Fuel Rate: ";
	in >> obj.fuelrate;
	cout << "Enter Customer ID: ";
	in >> obj.cid;
	cout << "Enter Driver ID: ";
	in >> obj.did;
	cout << "Enter Vehicle ID: ";
	in >> obj.vid;
	return in;
}
ifstream& operator>>(ifstream& filein, service& obj) {
	obj.source = new char[50];
	filein.ignore();
	filein.getline(obj.source, 50, '\n');
	obj.destination = new char[50];
	filein.getline(obj.destination, 50, '\n');
	filein >> obj.bookingdate;
	filein >> obj.bookingtime;
	filein >> obj.distance;
	filein >> obj.status;
	filein >> obj.fuelrate;
	filein >> obj.cid;
	filein >> obj.did;
	filein >> obj.vid;
	return filein;
}
ofstream& operator<<(ofstream& fileout, service& obj) {
	fileout << obj.source << endl;
	fileout << obj.destination << endl;
	fileout << obj.bookingdate;
	fileout << obj.bookingtime;
	fileout << obj.distance << endl;
	fileout << obj.status << endl;
	fileout << obj.fuelrate << endl;
	fileout << obj.cid << endl;
	fileout << obj.did << endl;
	fileout << obj.vid;
	return fileout;
}
ostream& operator<<(ostream& obj, const service& o) {
	cout << "SOURCE = ";
	obj << o.source << endl;
	cout << "DESTINATION = ";
	obj << o.destination << endl;
	cout << "BOOKING TIME = ";
	obj << o.bookingtime;
	cout << "BOOKING DATE = ";
	obj << o.bookingdate << endl;
	cout << "Distance = ";
	obj << o.distance << endl;
	if (o.status == 0) {
		cout << "STATUS : PENDING  ";
	}
	else if (o.status == 1) {
		cout << "STATUS : COMPLETED  ";
	}
	else if (o.status == 2) {
		cout << "STATUS : CANCELLED  ";
	}
	cout << "FUELRATE = ";
	obj << o.fuelrate << " RUPPEES " << endl;
	cout << "CUSTOMER ID = ";
	obj << o.cid << endl;
	cout << "DRIVER ID = ";
	obj << o.did << endl;
	cout << "VEHICLE ID = ";
	obj << o.vid << endl;
	
	
	return obj;
}
/////////////////class ride
class ride :public service {
	friend ostream& operator<<(ostream&, const ride&);
	friend istream& operator>>(istream& in, ride& obj);
	friend ofstream& operator<<(ofstream& fileout, ride& ob);
	friend ifstream& operator>>(ifstream& filein, ride& ob);
private:
	int noofpassangers;       //false for pending.true for complete
	char* ridetype; //intercity,intracity
	float driverranking;            //0-5 scale
	float vehicleranking;          //0-5 scale
public:
	ride();
	~ride();
	ride(int, char*, float, float);
	ride(ride& ob);
	void setride(int, char*);
	int getno();
	void setvrank(float drirank) {
		driverranking = drirank;
	}
	void setdrank(float vrank) {
		vehicleranking = vrank;
	}
	char* ridetypr();
	float drirank();
	float vehrank();
};
istream& operator>>(istream& in, ride& obj) {
	in >> (service&)obj;
	cout << "Enter number of passengers: ";
	in >> obj.noofpassangers;

	int choice;
	cout << "Enter 1 to travel intercity and 2 for intracity: ";
	in >> choice;
	obj.ridetype = new char[10];
	if (choice == 1) {
		string s = "intercity";
		int len = s.length();
		for (int i = 0; i <= len; i++)
		{
			obj.ridetype[i] = s[i];
			if (i == len)
			{
				obj.ridetype[i] = '\0';
			}
		}


	}
	if (choice == 2) {
		string s = "intracity";
		int len = s.length();
		for (int i = 0; i <= len; i++)
		{
			obj.ridetype[i] = s[i];
			if (i == len)
			{
				obj.ridetype[i] = '\0';
			}
		}
	}

	obj.driverranking = -1; //intializing from -1
	obj.vehicleranking = -1;
	return in;
}

ofstream& operator<<(ofstream& fileout, ride& ob) {
	fileout << (service&)ob;
	fileout << ob.noofpassangers;
	fileout << ob.ridetype;
	fileout << ob.driverranking;
	fileout << ob.vehicleranking;
	return fileout;
}
ifstream& operator>>(ifstream& filein, ride& ob) {
	filein >> (service&)ob;
	filein >> ob.noofpassangers;
	filein >> ob.ridetype;
	filein >> ob.driverranking;
	filein >> ob.vehicleranking;
	return filein;
}

ostream& operator<<(ostream& obj, const ride& o) {
	obj << (const service&)o;
	cout << "SERVICE FROM RIDE TYPE : " << endl;
	cout << "No of Passangers: ";
	obj << o.noofpassangers << endl;
	cout << "Ride Type: ";
	obj << o.ridetype << endl;
	if (o.driverranking > 0) {
		cout << "Driver Ranking: ";
		obj << o.driverranking << endl;
	}
	else {
		cout << "No rank " << endl;
	}
	if (o.vehicleranking > 0) {
		cout << "Vehicle Ranking: ";
		obj << o.vehicleranking << endl;
	}
	else {
		cout << "No rank " << endl;
	}
	return obj;
}
int ride::getno() {
	return noofpassangers;
}
char* ride::ridetypr() {
	return ridetype;
}
float ride::drirank() {
	return driverranking;
}
float ride::vehrank() {
	return vehicleranking;
}
void ride::setride(int noofpass, char* ritype) {
	noofpassangers = noofpass;
	int len = strlen(ritype);
	if (ridetype != nullptr) {
		delete ridetype;
		ridetype = new char[len + 1];
		for (int i = 0; i < len; i++) {
			ridetype[i] = ritype[i];
			if (ridetype[i] == len + 1) {
				ridetype[i] = '\0';
			}
		}
	}
	else {
		ridetype = new char[len + 1];
		for (int i = 0; i < len; i++) {
			ridetype[i] = ritype[i];
			if (ridetype[i] == len + 1) {
				ridetype[i] = '\0';
			}
		}
	}
}
ride::ride() {
	noofpassangers = 0;
	driverranking = -1;
	vehicleranking = -1;
	ridetype = new char[1];
	ridetype = 0;
}
ride::~ride() {
	noofpassangers = 0;
	driverranking = 0;
	vehicleranking = 0;
	delete[]ridetype;
	ridetype = 0;
}
ride::ride(int noofpass, char* ritype, float drivrank, float vehirank) {
	noofpassangers = noofpass;
	driverranking = drivrank;
	vehicleranking = vehirank;
	int len = strlen(ritype);
	ridetype = new char[len + 1];
	for (int i = 0; i < len + 1; i++) {
		ridetype[i] = ritype[i];
		if (ridetype[i] == len + 1) {
			ridetype[i] = '\0';
		}
	}
}
ride::ride(ride& obj) {
	noofpassangers = obj.noofpassangers;
	driverranking = obj.driverranking;
	vehicleranking = obj.vehicleranking;
	int len = strlen(obj.ridetype);
	ridetype = new char[len + 1];
	for (int i = 0; i < len + 1; i++) {
		ridetype[i] = obj.ridetype[i];
		if (ridetype[i] == len + 1) {
			ridetype[i] = '\0';
		}
	}
}
////////////class delivery
class delivery :public service {
	friend ifstream& operator>>(ifstream& filein, delivery& r);
	friend ofstream& operator<<(ofstream& fileout, delivery& o);
	friend istream& operator>>(istream& in, delivery& obj);
	friend ostream& operator<<(ostream&, const delivery&);
private:
	float goodsweight; //in kg
	char* goodstype;    //types of goods food,furniture
public:
	delivery();
	~delivery();
	delivery(float, char*);
	delivery(delivery& obj);
	void setdelivery(float);
	void setgoodstype(char* goodtype) {
		int len = strlen(goodtype);
		if (goodstype != nullptr) {

			delete goodstype;
			goodstype = new char[len + 1];
			for (int i = 0; i < len + 1; i++) {
				goodstype[i] = goodtype[i];
				if (goodstype[i] == len + 1) {
					goodstype[i] = '\0';
				}
			}
		}
		else {
			goodstype = new char[len + 1];
			for (int i = 0; i < len + 1; i++){
				goodstype[i] = goodtype[i];
			if (goodstype[i] == len + 1) 
				goodstype[i] = '\0';
			}
		}

	}
	char* getgoodstype();
	float getgoodsweight();
};
char* delivery::getgoodstype() {
	return  goodstype;
}
float delivery::getgoodsweight() {
	return goodsweight;
}
void delivery::setdelivery(float gooweight) {
	goodsweight = gooweight;

}
ifstream& operator>>(ifstream& filein, delivery& r) {
	filein >> (service&)r;
	filein >> r.goodsweight;
	filein >> r.goodstype;
	
	return filein;
}
ofstream& operator<<(ofstream& fileout, delivery& o) {
	fileout << (service&)o;
	fileout << o.goodsweight;
	fileout << o.goodstype;
	
	return fileout;
}
istream& operator>>(istream& in, delivery& obj) {
	in >> (service&)obj;
	cout << "Enter Weight: ";
	in >> obj.goodsweight;
	in.ignore();
	char* buffer = new char[100];
	cout << "Enter Good Type: ";
	in.getline(buffer, 100);
	obj.setgoodstype(buffer);
	delete[] buffer;
	return in;
}
ostream& operator<<(ostream& obj, const delivery& o) {
	obj << (const service&)o;
	cout << "SERVICE FROM DELIVERY TYPE " << endl;
	cout << "Goods Weight: ";
	obj << o.goodsweight << endl;
	cout << "Goods Type: ";
	obj << o.goodstype << endl;
	
	return obj;
}
delivery::delivery() {
	goodsweight = 0;
	goodstype = new char[1];

	goodstype = 0;
}
delivery::~delivery() {
	goodsweight = 0;
	delete[]goodstype;

	goodstype = 0;
}

delivery::delivery(float aweight, char* bgoods) {
	goodsweight = aweight;
	int len = strlen(bgoods);
	if (goodstype != nullptr) {

		delete goodstype;
		goodstype = new char[len + 1];

		for (int i = 0; i < len; i++) {
			goodstype[i] = bgoods[i];
			if (goodstype[i] == len + 1) {
				goodstype[i] = '\0';
			}
		}
	}
	else {
		goodstype = new char[len + 1];

		for (int i = 0; i < len; i++) {
			goodstype[i] = bgoods[i];
			if (goodstype[i] == len + 1) {
				goodstype[i] = '\0';
			}
		}
	}
}

delivery::delivery(delivery& obj)
{
	goodsweight = obj.goodsweight;
	int len = strlen(obj.goodstype);
	goodstype = new char[len + 1];
	if (goodstype != nullptr) {

		delete goodstype;
		for (int i = 0; i < len + 1; i++) {
			goodstype[i] = obj.goodstype[i];
			if (goodstype[i] == len + 1) {
				goodstype[i] = '\0';
			}
		}
	}
	else {
		for (int i = 0; i < len + 1; i++) {
			goodstype[i] = obj.goodstype[i];
			if (goodstype[i] == len + 1) {
				goodstype[i] = '\0';
			}
		}
	}
}
////////////////////class person
class person {
	friend istream& operator >>(istream&, person&);
	friend ofstream& operator <<(ofstream& fielout, person& p);
	friend ifstream& operator >> (ifstream& filein, person& p);
	friend ostream& operator<<(ostream&, const person&);
private:
	name pname;
	date dob;
	int age;
	int nid;
public:
	person();
	~person();
	person(int, int, char*, char*, int, int, int);
	person(person&);
	int getage();//getter
	int getnid();
	char* getfname();
	char* getlname();
	int getday();
	int getmonth();
	int getyear();
	void setperson(int, int);//setter
	void set(int, int, int);
	void setname(char*, char*);
	virtual void file(ofstream& fileout) {
		fileout << pname << endl;
		fileout << dob << endl;
		fileout << age << endl;
		fileout << nid << endl;

	}
};
char* person::getfname() {
	return pname.getfname();
}
char* person::getlname() {
	return pname.getlname();
}
int person::getday() {
	return dob.getday();
}
int person::getmonth() {
	return dob.getmonth();
}
int person::getyear() {
	return dob.getyear();
}
void person::set(int day, int month, int year) {
	dob.set(day, month, year);
}
void person::setname(char* firstname, char* lastname) {
	pname.setname(firstname, lastname);

}
void person::setperson(int agee, int nidd) {
	age = agee;
	nid = nidd;

};//setter
int person::getage() {
	return age;
}//getter
int person::getnid() {
	return nid;
}
istream& operator>>(istream& obj, person& per) {
	obj >> per.pname;
	obj >> per.dob;
	cout << "Enter age: ";
	obj >> per.age;
	cout << "Enter Nid: ";
	obj >> per.nid;
	return obj;
}
ofstream& operator <<(ofstream& fileout, person& p) {
	p.file(fileout);
	return fileout;
}
ifstream& operator >> (ifstream& filein, person& per) {
	filein >> per.pname;
	filein >> per.dob;
	filein >> per.age;
	filein >> per.nid;
	return filein;
}
ostream& operator<<(ostream& ob, const person& obj)
{
	cout << "Name: ";
	ob << obj.pname << endl;
	cout << "Date of Birth: ";
	ob << obj.dob;
	cout << "Age: ";
	ob << obj.age << endl;
	cout << "Id: ";
	ob << obj.nid << endl;
	return ob;
}
person::person() :pname(), dob() {
	age = 0;
	nid = 0;
}
person::~person() {
	age;
	nid;
}
person::person(int x, int y, char* firstname, char* lastname, int day, int month, int year) {
	dob.set(day, month, year);//composition
	pname.setname(firstname, lastname);
	age = x;
	nid = y;
}
person::person(person& o) :pname(o.pname), dob(o.dob) {

	age = o.age;
	nid = o.nid;
}
////////////////////////class customer
class customer :public person {
	friend ostream& operator<<(ostream&, const customer&);
	friend ifstream& operator >> (ifstream& filein, customer& cus);
	friend ofstream& operator << (ofstream& fileout, customer& cus);
	friend istream& operator >> (istream&, customer&);
private:
	int cid;
	service** bookinghistory;
	int bookcount;
public:
	void setcid(int ccid) {
		cid = ccid;
	}
	void setbbokcount(int bookc) {
		bookcount = bookc;
	}
	service** getbookinghistory() {
		return bookinghistory;
	}
	int getcustid() {
		return cid;
	}
	int getbookcount() {
		return bookcount;
	}
	void settingservice(service& history) {
		bookcount++;
		service** buffer = new service * [bookcount];
		for (int i = 0; i < bookcount-1; i++) {
			buffer[i] = new service;
			*(buffer[i]) = *(bookinghistory[i]);
			delete bookinghistory[i];
		}
		*(buffer[bookcount - 1]) = history;
		delete bookinghistory;
		bookinghistory = buffer;
	}
	customer() {
		cid = 0;
		bookcount = 0;
		bookinghistory = 0;
	}
	~customer() {
		for (int i = 0; i < bookcount; i++) {
			delete bookinghistory[i];
		}
		delete bookinghistory;
		bookinghistory = 0;
	}
	customer(customer& obj) :person(obj) { //person is called here as it contains name,dob
		cid = obj.cid;
		bookcount = obj.bookcount;

		bookinghistory = new service * [bookcount ];
		for (int i = 0; i < bookcount; i++) {
			bookinghistory[i] = new service;

			*(bookinghistory[i]) = *(obj.bookinghistory[i]);
		}
	}
	customer(int ccid, char* firstname, char* lastname, int day, int month, int year, int id, int age) :person(age, id, firstname, lastname, day, month, year)//overriding
	{
		this->cid = ccid;

	}
	virtual void file(ofstream& fileout) { //we made it virtual and defined it as its is virtual in its base class
		//so it must have a definiion here
		person::file(fileout);
		fileout << cid << endl;
		fileout << bookcount << endl;
		for (int i = 0; i < bookcount; i++) {
			fileout << *(bookinghistory[i]) << endl;
		}

	}

};
ostream& operator<<(ostream& ob, const customer& obj)
{
	ob << (person&)obj;
	cout << "Customer ID: ";
	ob << obj.cid << endl;
	cout << "Booking History: " << endl;
	if (obj.bookcount > 0) {
		for (int i = 0; i < obj.bookcount; i++) {
			ob << *(obj.bookinghistory[i]) << endl;            //use
		}
	}///make array
	return ob;
}
ifstream& operator >> (ifstream& filein, customer& cus) {
	filein >> (person&)cus;
	filein >> cus.cid;
	filein >> cus.bookcount;
	if ( cus.bookcount > 0) {


		cus.bookinghistory = new service * [cus.bookcount];
		for (int i = 0; i < cus.bookcount; i++) {
			cus.bookinghistory[i] = new service;
			filein >> *(cus.bookinghistory[i]);
		}
	}
	if (cus.bookinghistory != nullptr) {
		for (int i = 0; i < cus.bookcount; i++) {
			delete cus.bookinghistory[i];
		}
		delete[]cus.bookinghistory;
		cus.bookinghistory = nullptr;
	}
	return filein;
}
ofstream& operator << (ofstream& fileout, customer& cus) {
	cus.file(fileout);
	return fileout;


}
istream& operator >> (istream& obj, customer& ob) {
	obj >> (person&)ob;
	cout << "Enter the Customer iD: ";
	obj >> ob.cid;
	cout << "Booking History: " << endl;
	cout << "Enter the booking count:   ";
	obj >> ob.bookcount;
	if (ob.bookinghistory != NULL) {
		for (int i = 0; i < ob.bookcount; i++) {       //condition to make sure array is empty
			delete ob.bookinghistory[i];
		}
		delete[]ob.bookinghistory;
		ob.bookinghistory = 0;
	}
	cout << endl;
	cout << "Enter The Details:  " << endl;
	if (ob.bookcount > 0) {
		ob.bookinghistory = new service * [ob.bookcount];
		for (int i = 0; i < ob.bookcount; i++) {
			ob.bookinghistory[i] = new service;
			obj >> *(ob.bookinghistory[i]);
		}
	}
	return obj;


}

///////////////////////////////////////////////class driver
class driver :public person {
	friend ostream& operator<<(ostream&, const driver&);
	friend istream& operator >> (istream&, driver&);
	friend ofstream& operator << (ofstream& fileout, driver& dri);
	friend ifstream& operator >> (ifstream& filein, driver& dri);
private:
	int did;
	char** liscencelist;
	int noofliscence;
	float overallranking;
	float salary;
	int experience;
	int status;
	int rows; //forcountservices
	service** servicehistory;
public:
	driver();
	~driver();
	driver(driver&);
	driver(int, float, float, int, int, char*, char*, int, int, int, int, int);
	void setdriver(int, int, float, float, int, int);
	void string_copy(char*& a, char* s)
	{
		int len = strlen(s);
		for (int i = 0; i <= len; i++)
		{
			a[i] = s[i];
			if (i == len)
			{
				a[i] = '\0';
			}
		}

	}
	void addlis(char* lisc) {
		noofliscence++;
		char** buffer = new char* [noofliscence];
		for (int i = 0; i < noofliscence; i++) {
			buffer[i] = new char[strlen(liscencelist[i]) + 1];
			for (int j = 0; j < strlen(liscencelist[i])+1; j++) {
				buffer[i][j] = liscencelist[j];
				delete[]liscencelist[i];
			}


		}
		buffer[noofliscence - 1] = new char[strlen(lisc) + 1];
		for (int i = 0; i < strlen(lisc) + 1; i++) {
			buffer[noofliscence - 1] = lisc;
			
		}
		delete[]liscencelist;
		liscencelist = buffer;
		










	}
	void setservicehistory(service& s1) { 
		rows++;
		service** buffer = new service * [rows];
		for (int i = 0; i < rows - 1; i++) {
			buffer[i] = new service;
			*(buffer[i]) = *(servicehistory[i]);
			delete servicehistory[i];
		}
		*(buffer[rows - 1]) = s1;
		delete[] servicehistory;
		servicehistory = buffer;
	}
	int getdid();
	int getnoofliscence();
	int getexperience();
	int getstatus();
	float getsalary();
	float getoverallranking();
	char** getlist();
	service** getservicehistory() {
		return servicehistory;
	}
	virtual void file(ofstream& fileout) {
		person::file(fileout);
		fileout << did << endl;
		fileout << overallranking << endl;
		fileout << salary << endl;
		fileout << experience << endl;
		fileout << status << endl;
		fileout << noofliscence;
		for (int i = 0; i < noofliscence; i++) {
			fileout << liscencelist[i] << endl;
		}
		for (int i = 0; i < rows; i++) {
			fileout << *(servicehistory[i]) << endl;

		}
	}
};
istream& operator >> (istream& ob, driver& obj) {
	ob >> (person&)obj;
	cout << "Enter Driver's id:  ";
	ob >> obj.did;
	cout << "Enter ranking:  ";
	ob >> obj.overallranking;
	cout << "Enter salary:  ";
	ob >> obj.salary;
	cout << "Enter experience:  ";
	ob >> obj.experience;
	cout << "Enter status:  ";
	cout << "1-Free " << endl << "2-Booked " << endl << "3-Cancelled ";
	ob >> obj.status;
	cout << "Number of liscences:  ";
	ob >> obj.noofliscence;
	cout << "Enter the liscence list: " << endl;
	char* buffer;
	buffer = new char[100];
	if (obj.noofliscence > 0) {
		obj.liscencelist = new char* [obj.noofliscence];
	}
	for (int i = 0; i < obj.noofliscence; i++) {
		if (obj.liscencelist == nullptr && obj.noofliscence > 0) {
			cout << i + 1 << ": " << endl;
			ob.getline(buffer, 100, '\n');
			obj.liscencelist[i] = new char[strlen(buffer) + 1];
			for (int j = 0; j < strlen(buffer) + 1; j++) {
				obj.liscencelist[i][j] = buffer[j];
			}
		}
		else {
			for (int i = 0; i < obj.noofliscence; i++) {
				delete obj.liscencelist[i];
			}
			delete obj.liscencelist;
			obj.liscencelist = 0;
		}
	}
	cout << "Enter the no of servicehistory: ";
	ob >> obj.rows;
	if (obj.rows > 0) {
		obj.servicehistory = new service * [obj.rows];
	}
	cout << "Enter the service list: " << endl;
	for (int i = 0; i < obj.rows; i++) {
		if (obj.rows > 0 && obj.servicehistory == nullptr) {
			obj.servicehistory[i] = new service;
			cout << i + 1 << ": " << endl;
			ob >> *(obj.servicehistory[i]);
		}
		else {
			for (int i = 0; i < obj.rows; i++) {
				delete obj.servicehistory[i];
			}
			delete[] obj.servicehistory;
			obj.servicehistory = 0;
		}
	}
	return ob;
}
ofstream& operator << (ofstream& fileout, driver& dri) {
	dri.file(fileout);
	return fileout;
}
ifstream& operator >> (ifstream& filein, driver& dri) {
	filein >> (person&)dri;
	filein >> dri.did;
	filein >> dri.overallranking;
	filein >> dri.salary;
	filein >> dri.experience;
	filein >> dri.status;
	filein >> dri.noofliscence;
	if (dri.noofliscence > 0) {
		dri.liscencelist = new char* [dri.noofliscence];
	}
	for (int i = 0; i < dri.noofliscence; i++) {
		if (dri.liscencelist == nullptr && dri.noofliscence > 0) {

			dri.liscencelist[i] = new char[150];
			filein.getline(dri.liscencelist[i], 100);
		}
		else {
			for (int i = 0; i < dri.noofliscence; i++) {
				delete dri.liscencelist[i];
			}
			delete[] dri.liscencelist;
			dri.liscencelist = 0;
		}
	}
	filein.ignore();
	filein >> dri.rows;
	if (dri.rows > 0) {
		dri.servicehistory = new service * [dri.rows];
	}
	for (int i = 0; i < dri.rows; i++) {
		if (dri.rows > 0 && dri.servicehistory == nullptr) {
			dri.servicehistory[i] = new service;
			filein >> *(dri.servicehistory[i]);
		}
		else {
			for (int i = 0; i < dri.rows; i++) {
				delete dri.servicehistory[i];
			}
			delete[] dri.servicehistory;
			dri.servicehistory = 0;
		}
	}
	return filein;
}
ostream& operator<<(ostream& ob, const driver& obj)
{
	ob << (person&)obj;
	cout << "Driver's id: ";
	ob << obj.did << endl;
	cout << "Ranking: ";
	ob << obj.overallranking << endl;
	cout << "Salary: ";
	ob << obj.salary << endl;
	cout << "Experience: ";
	ob << obj.experience << endl;
	cout << "Status: ";
	ob << obj.status << endl;
	if (obj.status == 1) {
		cout << "Driver is Available " << endl;
	}
	if (obj.status == 2) {
		cout << "Driver is Booked " << endl;
	}
	if (obj.status == 3) {
		cout << "The Ride got Cancelled " << endl;
	}
	cout << "Number of Liscenses: ";
	ob << obj.noofliscence << endl;
	cout << "Liscence List: " << endl;
	for (int i = 0; i < obj.noofliscence; i++) {
		ob << obj.liscencelist[i] << endl;
	}
	cout << "Service History: " << endl;
	for (int i = 0; i < obj.rows; i++) {
		ob << *(obj.servicehistory[i]) << endl;///* is used for pointing
	}
	return ob;
}

void driver::setdriver(int nooflis, int id, float sal, float rank, int exp, int stat) {

	did = id;
	noofliscence = nooflis;
	overallranking = rank;
	salary = sal;
	experience = exp;
	status = stat;
}

int driver::getdid() {
	return did;
}
int driver::getnoofliscence() {
	return noofliscence;
}
int driver::getexperience() {
	return experience;
}
int driver::getstatus() {
	return status;
}
float driver::getsalary() {
	return salary;
};
float driver::getoverallranking() {
	return overallranking;
};
char** driver::getlist() {
	return liscencelist;
};
driver::driver() :person() {
	did = 0;
	rows = 0;//count
	liscencelist = new char* [1];
	liscencelist = 0;
	servicehistory = new service * [1];
	servicehistory = 0;
	noofliscence = 0;
	overallranking = 0.0;
	salary = 0.0;
	experience = 0;
	status = 0;
}
driver::~driver() {
	did = 0;
	//delete **char
	for (int i = 0; i < noofliscence; i++) {
		delete liscencelist[i];
	}
	delete[]liscencelist;
	liscencelist = 0;
	for (int i = 0; i < rows; i++) {
		delete servicehistory[i];
	}
	delete servicehistory;
	servicehistory = 0;
	liscencelist = 0;
	noofliscence = 0;
	overallranking = 0.0;
	salary = 0.0;
	experience = 0;
	status = 0;
}
driver::driver(driver& obj) {
	did = obj.did;
	rows = obj.rows;//for service array

	noofliscence = obj.noofliscence;

	liscencelist = new char* [obj.noofliscence];
	for (int i = 0; i < noofliscence; i++) {
		liscencelist[i] = new char[strlen(obj.liscencelist[i])];//measuring the size of each liscence for colums/length
		liscencelist[i] = obj.liscencelist[i];//copying
	}
	overallranking = obj.overallranking;
	salary = obj.salary;
	experience = obj.experience;
	status = obj.status;
	servicehistory = new service * [obj.rows];
	for (int i = 0; i < rows; i++)
	{
		servicehistory[i] = new service;
		*(servicehistory[i]) = *(obj.servicehistory[i]);
	}
}

driver::driver(int ddid, float sal, float rank, int exp, int stat, char* firstname, char* lastname, int day, int month, int year, int id, int age) :person(age, id, firstname, lastname, day, month, year)//overriding 
{
	did = ddid;
	rows = 0;
	liscencelist = new char* [1];
	liscencelist = 0;
	noofliscence = 0;
	servicehistory = new service * [1];
	servicehistory = 0;
	overallranking = rank;
	salary = sal;
	experience = exp;
	status = stat;
}





///////////////class feature
//make = operator if needed
class feature {
	friend ostream& operator<<(ostream&, const feature&);
	friend istream& operator>>(istream&, feature&);
	friend ifstream& operator>>(ifstream&, feature&);
	friend ofstream& operator<<(ofstream&, feature&);
private:
	int fid;
	char* description;
	float cost;
public:
	feature();
	~feature();
	feature(feature&);
	feature(int, char*, float);
	void setfeature(int, char*, float);
	int getfid();
	char* getdecrip();
	float getcost();
	feature& operator=(const feature& o) {
		fid = o.fid;
		cost = o.cost;
		if (description != nullptr && o.description == nullptr) {
			delete description;
			description = nullptr;
		}
		else if (description != nullptr && o.description != nullptr) {
			delete description;
			description = new char[strlen(o.description) + 1];
			for (int i = 0; i < strlen(o.description) + 1; i++) {
				description[i] = o.description[i];
			}

		}
		else if (description == nullptr && o.description != nullptr) {
			description = new char[strlen(o.description) + 1];
			for (int i = 0; i < strlen(o.description) + 1; i++) {
				description[i] = o.description[i];
			}
		}
		return *this;
	}

};
int feature::getfid() {
	return fid;
}
char* feature::getdecrip() {
	return description;
}
float feature::getcost() {
	return cost;
}
feature::feature(feature& o) {
	fid = o.fid;
	int len = strlen(o.description);
	description = new char[len + 1];
	if (description != nullptr) {
		for (int i = 0; i < len + 1; i++) {
			description[i] = o.description[i];
			if (i == len + 1) {
				description[i] = '\0';
			}
		}
	}
	else {
		delete[]description;
		description = 0;
	}
	cost = o.cost;
}
feature::~feature() {
	fid = 0;
	delete[]description;
	description = nullptr;
	cost = 0.0;
}
feature::feature() {
	fid = 0;
	description = new char[1];
	description = nullptr;
	cost = 0.0;
}
feature::feature(int cfid, char* cdesrip, float ccost) {
	fid = cfid;
	int len = strlen(cdesrip);
	description = new char[len + 1];
	for (int i = 0; i < len + 1; i++) {
		description[i] = cdesrip[i];
		if (description[i] == len + 1) {
			description[i] = '\0';

		}
	}
	cost = ccost;
}
void feature::setfeature(int cfid, char* cdesrip, float ccost) {
	fid = cfid;
	int len = strlen(cdesrip);
	description = new char[len + 1];
	if (description == nullptr) {
		for (int i = 0; i < len + 1; i++) {
			description[i] = cdesrip[i];
			if (description[i] == len + 1) {
				description[i] = '\0';
			}
		}
	}
	else {
		delete[] description;
		description = nullptr;
	}
	cost = ccost;
}
ostream& operator<<(ostream& obj, const feature& o) {
	cout << "The feature id: ";
	obj << o.fid << endl;
	cout << "The description: ";
	obj << o.description << endl;
	cout << "The cost: ";
	obj << o.cost << endl;
	return obj;
};
istream& operator>>(istream& obj, feature& ob) {
	cout << "Enter the feature id: ";
	obj >> ob.fid;
	obj.ignore();
	cout << "Enter the description: " << endl;
	char* buffer = new char[500];
	obj.getline(buffer, 500);
	if (ob.description == nullptr) {
		ob.description = new char[strlen(buffer) + 1];
		for (int i = 0; i < strlen(buffer) + 1; i++) {
			ob.description[i] = buffer[i];
		}
	}
	else {
		delete[]ob.description;
		ob.description = 0;
	}
	cout << "Enter the cost: ";
	obj >> ob.cost;
	return obj;
}
ifstream& operator>>(ifstream& filein, feature& f) {

	filein >> f.fid;
	filein.ignore();

	char* buffer = new char[500];
	filein.getline(buffer, 500);
	if (f.description == nullptr) {
		f.description = new char[strlen(buffer) + 1];
		for (int i = 0; i < strlen(buffer) + 1; i++) {
			f.description[i] = buffer[i];
		}
	}
	else {
		delete[]f.description;
		f.description = 0;
	}
	filein >> f.cost;
	return filein;
}
ofstream& operator<<(ofstream& fileout, feature& f) {

	fileout << f.fid << endl;

	fileout << f.description << endl;

	fileout << f.cost << endl;
	return fileout;
}
//////////////class vehicle
class vehicle {
	friend ostream& operator<<(ostream&, const vehicle&);
	friend istream& operator>>(istream& in, vehicle& obj);
	friend ifstream& operator>>(ifstream&, vehicle&); //forfile
	friend ofstream& operator<<(ofstream&, vehicle&);
private:

	int vid;
	int registrationno;
	char* liscensetype;
	bool status; //false for free ,true if booked
	float averagemileage;
	char* vehicletype;
	char* fueltype;
	float overallranking;
	date manufacturingdate;
	feature* list;
	service** servicehistory;
	int featurescount;
	int servicescount;
public:
	vehicle();
	vehicle(float, date, int, int, char*, bool, char*, float, char*);
	~vehicle();
	vehicle(vehicle&);
	void setvehicle(int, int, bool, float);
	void setmileage(float mil) {
		averagemileage = mil;
	}
	int getvidd();
	void setdate(date&);
	void setlisecencetype(char* vlistype) {
		if (vlistype != nullptr && liscensetype == nullptr) {
			int len = strlen(vlistype);

			liscensetype = new char[len + 1];
			for (int i = 0; i < len + 1; i++) {
				liscensetype[i] = vlistype[i];
				if (liscensetype[i] == len + 1) {
					liscensetype[i] = '\0';
				}
			}
		}
		else if (vlistype != nullptr && liscensetype != nullptr) {
			delete[]liscensetype;
			liscensetype = new char[strlen(vlistype) + 1];
			for (int i = 0; i < strlen(vlistype) + 1; i++) {
				liscensetype[i] = vlistype[i];
				if (liscensetype[i] == strlen(vlistype) + 1) {
					liscensetype[i] = '\0';
				}
			}
		}
		else if (liscensetype != nullptr && vlistype == nullptr)
		{
			delete liscensetype;
			liscensetype = 0;
		}


	}
	void setfueltype(char* vfueltype) {

		if (vfueltype != nullptr && fueltype == nullptr) {
			int len = strlen(vfueltype);

			fueltype = new char[len + 1];
			for (int i = 0; i < len + 1; i++) {
				fueltype[i] = vfueltype[i];
				if (fueltype[i] == len + 1) {
					fueltype[i] = '\0';
				}
			}
		}
		else if (vfueltype != nullptr && fueltype != nullptr) {
			delete[]fueltype;
			fueltype = new char[strlen(vfueltype) + 1];
			for (int i = 0; i < strlen(vfueltype) + 1; i++) {
				fueltype[i] = vfueltype[i];
				if (fueltype[i] == strlen(vfueltype) + 1) {
					fueltype[i] = '\0';
				}
			}
		}
		else if (fueltype != nullptr && vfueltype == nullptr)
		{
			delete fueltype;
			fueltype = 0;
		}

	}
	void setvehicletype(char* vvehicletype) {

		if (vvehicletype != nullptr && vehicletype == nullptr) {
			int len = strlen(vvehicletype);

			vehicletype = new char[len + 1];
			for (int i = 0; i < len + 1; i++) {
				vehicletype[i] = vvehicletype[i];
				if (vehicletype[i] == len + 1) {
					vehicletype[i] = '\0';
				}
			}
		}
		else if (vvehicletype != nullptr && fueltype != nullptr) {
			delete[]vehicletype;
			vehicletype = new char[strlen(vvehicletype) + 1];
			for (int i = 0; i < strlen(vvehicletype) + 1; i++) {
				vehicletype[i] = vvehicletype[i];
				if (vehicletype[i] == strlen(vvehicletype) + 1) {
					vehicletype[i] = '\0';
				}
			}
		}
		else if (vehicletype != nullptr && vvehicletype == nullptr)
		{
			delete vehicletype;
			vehicletype = 0;
		}
	}
	int getregistration();
	char* getliscensetype();
	float getmileage();
	bool getvehistatus();
	char* getfueltype();
	char* getvehicletype();
	float getoverallrankingvehi();  //vehicle
	void addfeature(feature&);
	void addservice(service&);
	vehicle& operator=(const vehicle&);
};
vehicle& vehicle::operator=(const vehicle& obj) {
	if (obj.vehicletype != nullptr && vehicletype == nullptr) {
		int len = strlen(obj.vehicletype);

		vehicletype = new char[len + 1];
		for (int i = 0; i < len + 1; i++) {
			vehicletype[i] = obj.vehicletype[i];
			if (vehicletype[i] == len + 1) {
				vehicletype[i] = '\0';
			}
		}
	}
	else if (obj.vehicletype != nullptr && vehicletype != nullptr) {
		delete[]vehicletype;
		vehicletype = new char[strlen(obj.vehicletype) + 1];
		for (int i = 0; i < strlen(obj.vehicletype) + 1; i++) {
			vehicletype[i] = obj.vehicletype[i];
			if (vehicletype[i] == strlen(obj.vehicletype) + 1) {
				vehicletype[i] = '\0';
			}
		}
	}
	else if (vehicletype != nullptr && obj.vehicletype == nullptr)
	{
		delete vehicletype;
		vehicletype = 0;
	}

	if (obj.fueltype != nullptr && fueltype == nullptr) {
		int len = strlen(obj.fueltype);

		fueltype = new char[len + 1];
		for (int i = 0; i < len + 1; i++) {
			fueltype[i] = obj.fueltype[i];
			if (fueltype[i] == len + 1) {
				fueltype[i] = '\0';
			}
		}
	}
	else if (obj.fueltype != nullptr && fueltype != nullptr) {
		delete[]fueltype;
		fueltype = new char[strlen(obj.fueltype) + 1];
		for (int i = 0; i < strlen(obj.fueltype) + 1; i++) {
			fueltype[i] = obj.fueltype[i];
			if (fueltype[i] == strlen(obj.fueltype) + 1) {
				fueltype[i] = '\0';
			}
		}
	}
	else if (fueltype != nullptr && obj.fueltype == nullptr)
	{
		delete fueltype;
		fueltype = 0;
	}
	if (obj.liscensetype != nullptr && liscensetype == nullptr) {
		int len = strlen(obj.liscensetype);

		liscensetype = new char[len + 1];
		for (int i = 0; i < len + 1; i++) {
			liscensetype[i] = obj.liscensetype[i];
			if (liscensetype[i] == len + 1) {
				liscensetype[i] = '\0';
			}
		}
	}
	else if (obj.liscensetype != nullptr && liscensetype != nullptr) {
		delete[]liscensetype;
		liscensetype = new char[strlen(obj.liscensetype) + 1];
		for (int i = 0; i < strlen(obj.liscensetype) + 1; i++) {
			liscensetype[i] = obj.liscensetype[i];
			if (liscensetype[i] == strlen(obj.liscensetype) + 1) {
				liscensetype[i] = '\0';
			}
		}
	}
	else if (liscensetype != nullptr && obj.liscensetype == nullptr)
	{
		delete liscensetype;
		liscensetype = 0;
	}

	averagemileage = obj.averagemileage;
	status = obj.status;
	manufacturingdate = obj.manufacturingdate;
	vid = obj.vid;
	registrationno = obj.registrationno;
	featurescount = obj.featurescount;
	servicescount = obj.servicescount;
	overallranking = obj.overallranking;

	if (servicescount > 0) {
		servicehistory = new service * [servicescount];
		for (int i = 0; i < servicescount; i++) {
			servicehistory[i] = new service;
			*(servicehistory[i]) = *(obj.servicehistory[i]);
		}
	}
	if (featurescount > 0) {
		list = new feature[featurescount];
		for (int i = 0; i < featurescount; i++) {
			list[i] = obj.list[i];
		}
	}
	return *this;
}


void vehicle::addfeature(feature& fea) {  
	featurescount++;
	feature* buffer = new feature[featurescount];
	for (int i = 0; i < featurescount; i++) {
		(buffer[i]) = (list[i]);

	}
	(buffer[featurescount - 1]) = fea;
	delete list;
	list = buffer;
}
void vehicle::addservice(service& serv) {  
	servicescount++;
	service** buffer = new service * [servicescount];
	for (int i = 0; i < servicescount; i++) {
		buffer[i] = new service;
		*(buffer[i]) = *(servicehistory[i]);
		delete servicehistory[i];
	}
	*(buffer[servicescount - 1]) = serv;
	delete servicehistory;
	servicehistory = buffer;

}

char* vehicle::getvehicletype() {
	return vehicletype;
}
float vehicle::getmileage() {
	return averagemileage;

}
void vehicle::setdate(date& obj) {
	manufacturingdate = obj;
}
vehicle::vehicle() :manufacturingdate() {
	vid = 0;
	registrationno = 0;
	list = 0;
	servicehistory = 0;
	liscensetype = new char[1];
	liscensetype = 0;
	averagemileage = 0;
	status = NULL;
	featurescount = 0;
	servicescount = 0;
	vehicletype = new char[1];
	vehicletype = 0;
	fueltype = new char[1];
	fueltype = 0;

	overallranking = 0;
}
vehicle ::~vehicle() {
	vid = 0;
	delete[]liscensetype;
	liscensetype = 0;
	delete[]list;
	list = 0;
	delete[]vehicletype;
	vehicletype = 0;
	status = 0;
	for (int i = 0; i < servicescount; i++) {
		delete servicehistory[i];
	}
	delete[] servicehistory;
	servicehistory = 0;
	delete[]fueltype;
	fueltype = 0;
	overallranking = 0;
}
vehicle::vehicle(vehicle& o) : manufacturingdate(o.manufacturingdate) {
	vid = o.vid;
	registrationno = o.registrationno;
	int len = strlen(o.liscensetype);
	liscensetype = new char[len + 1];
	for (int i = 0; i < len + 1; i++) {
		liscensetype[i] = o.liscensetype[i];
		if (liscensetype[i] == len + 1) {
			liscensetype[i] = '\0';
		}
	}
	vehicletype = new char[strlen(o.vehicletype)+1];
	for (int i = 0; i < strlen(o.vehicletype) + 1; i++) {
		vehicletype[i] = o.vehicletype[i];
		if (vehicletype[i] == strlen(vehicletype) + 1) {
			vehicletype[i] = '\0';
		}
	}
	status = o.status;
	averagemileage = o.averagemileage;
	featurescount = o.featurescount;
	list = new feature[featurescount];
	for (int i = 0; i < featurescount; i++) {
		list[i] = o.list[i];
	}
	servicescount = o.servicescount;
	servicehistory = new service * [servicescount];
	for (int i = 0; i < servicescount; i++) {
		servicehistory[i] = new service;
		*(servicehistory[i]) = *(o.servicehistory[i]);
	}
	int len1 = strlen(o.fueltype);
	fueltype = new char[len1 + 1];
	for (int i = 0; i < len1 + 1; i++) {
		fueltype[i] = o.fueltype[i];
	}
	overallranking = o.overallranking;
}

void vehicle::setvehicle(int vvid, int vregno, bool vstat, float vrank) {
	vid = vvid;
	registrationno = vregno;
	status = vstat;
	overallranking = vrank;
}
vehicle::vehicle(float avgm, date mafd, int vvid, int vregno, char* vlistype, bool vstat, char* vfueltype, float vrank, char* vvehicletype) {
	vid = vvid;
	registrationno = vregno;
	int len = strlen(vlistype);
	liscensetype = new char[len + 1];
	for (int i = 0; i < len + 1; i++) {
		liscensetype[i] = vlistype[i];
	}
	averagemileage = avgm;
	status = vstat;
	manufacturingdate = mafd;
	featurescount = 0;
	servicescount = 0;
	vehicletype = new char[strlen(vvehicletype) + 1];
	for (int i = 0; i < strlen(vvehicletype) + 1; i++) {
		vehicletype[i] = vvehicletype[i];
	}
	int len1 = strlen(vfueltype);
	fueltype = new char[len1 + 1];
	for (int i = 0; i < len1 + 1; i++) {
		fueltype[i] = vfueltype[i];
	}
	overallranking = vrank;

}
int vehicle::getvidd() {
	return vid;
}
int vehicle::getregistration() {
	return registrationno;
}
char* vehicle::getliscensetype() {
	return liscensetype;

}
bool vehicle::getvehistatus() {
	return status;
}
char* vehicle::getfueltype() {
	return fueltype;
}
float vehicle::getoverallrankingvehi() {
	return overallranking;
}
ostream& operator<<(ostream& obj, const vehicle& o) {
	cout << "Vehicle id:  ";
	obj << o.vid << endl;
	cout << "Registration number:  ";
	obj << o.registrationno << endl;
	cout << "Liscence type:  ";
	obj << o.liscensetype << endl;
	cout << "Status: " << endl;
	cout << "1-Free " << endl << "2-Booked " << endl << "3-Cancelled " << endl;
	obj << o.status << endl;
	cout << "Fuel type: ";
	obj << o.fueltype << endl;
	cout << "Over ranking:  ";
	obj << o.overallranking << endl;
	cout << "Manufacturing date:  ";
	obj << o.manufacturingdate << endl;
	cout << "Features list:  ";
	for (int i = 0; i < o.featurescount; i++) {
		obj << o.list[i] << endl;
	}
	cout << "Service list:  ";
	for (int i = 0; i < o.servicescount; i++) {
		obj << *(o.servicehistory[i]) << endl;
	}
	return obj;
};
istream& operator>>(istream& in, vehicle& v) {
	cout << "Enter vehicle id:  ";
	in >> v.vid;
	cout << "Enter average mileage:  ";
	in >> v.averagemileage;
	cout << "Enter registration no:  ";
	in >> v.registrationno;
	cout << "Enter liscence type:  ";
	char* t = new char[1500];
	in.getline(t, 1500, '\n');
	v.setlisecencetype(t);
	cout << "Enter status:  " << endl;
	cout << "1-Free " << endl << "2-Booked " << endl << "3-Cancelled" << endl;
	in >> v.status;
	char* buffer = new char[1000];
	cout << "Enter fuel Type:  ";
	in.getline(buffer, 1000, '\n');
	v.setfueltype(buffer);
	cout << "Enter overall ranking:  ";
	in >> v.overallranking;
	cout << "Enter the manufacturing date:  ";
	in >> v.manufacturingdate;
	cout << "Enter the no of features list:  ";
	in >> v.featurescount;
	cout << "Enter the details:  ";
	if (v.featurescount > 0 && v.list == nullptr) {
		v.list = new feature[v.featurescount];
		for (int i = 0; i < v.featurescount; i++) {
			in >> v.list[i];
		}
	}
	else {
		delete v.list;
		v.list = new feature[v.featurescount];
		for (int i = 0; i < v.featurescount; i++) {
			in >> v.list[i];
		}
	}
	cout << "Enter vehicletype " << endl;
	char* p = new char[100];
	in.ignore();
	in.getline(p, 100, '\n');
	v.setvehicletype(p);
	cout << "Enter the no of services:  ";
	in >> v.servicescount;
	cout << "Enter the details:  ";
	if (v.servicehistory == nullptr && v.servicescount > 0) {
		v.servicehistory = new service * [v.servicescount];
		for (int i = 0; i < v.servicescount; i++) {
			v.servicehistory[i] = new service;
			in >> *(v.servicehistory[i]);
		}
	}
	else {
		for (int i = 0; i < v.servicescount; i++) {
			delete[]v.servicehistory[i];
		}
		delete[] v.servicehistory;
	}
	return in;
}
ifstream& operator>>(ifstream& filein, vehicle& v) {
	filein >> v.vid;
	filein >> v.averagemileage;
	filein >> v.registrationno;
	filein. ignore();
	v.liscensetype = new char[100];
	filein.getline(v.liscensetype, 100, '\n');
	filein >> v.status;

	v.fueltype = new char[1000];
	filein.ignore();
	filein.getline(v.fueltype, 1000, '\n');
	filein >> v.overallranking;
	filein >> v.manufacturingdate;
	filein >> v.featurescount;
	v.list = new feature[v.featurescount];
	for (int i = 0; i < v.featurescount; i++) {
		filein >> v.list[i];
	}
	v.vehicletype = new char[1000];
	filein.ignore();
	filein.getline(v.vehicletype, 1000, '\n');
	filein >> v.servicescount;
	v.servicehistory = new service * [v.servicescount];
	for (int i = 0; i < v.servicescount; i++) {
		v.servicehistory[i] = new service;
		filein >> *(v.servicehistory[i]);
	}
	return filein;
}
ofstream& operator<<(ofstream& fileout, vehicle& v) {

	fileout << v.vid << endl;
	fileout << v.averagemileage << endl;
	fileout << v.registrationno << endl;
	fileout << v.liscensetype << endl;
	fileout << v.status << endl;
	fileout << v.fueltype << endl;
	fileout << v.overallranking << endl;
	fileout << v.manufacturingdate << endl;
	fileout << v.featurescount << endl;
	for (int i = 0; i < v.featurescount; i++) {
		fileout << v.list[i] << endl;
	}
	fileout << v.servicescount << endl;
	for (int i = 0; i < v.servicescount; i++) {
		fileout << *(v.servicehistory[i]) << endl;
	}
	return fileout;
}



























class transportsystem {
private:
	vehicle v;   //creating objects of classes
	driver d;
	customer c;
	date date;
	service* servicepointer;  //creating dynamic arrays
	ofstream outputfile;
	ofstream ouputservice;
	ofstream outputcustomer;  //creating objects for ofstream/ifstream of classes
	ofstream outputdriver;
	ofstream outputvehicle;
	ifstream inputservice;
	ifstream inputfile;
	ifstream inputcustomer;
	ifstream inputvehicle;
	ifstream inputdriver;
	int vehiclec;
	int customerc;
	int driverc;
	int servicec;
public:
	transportsystem() {

		//opening file file1 uding istream object
		inputfile.open("file1.txt");
		inputfile >> vehiclec;
		inputfile >> customerc;
		inputfile >> driverc;
		inputfile >> servicec;
		inputfile.close();//closing the file

	}
	~transportsystem() {
		for (int i = 0; i < servicec; i++) {
			delete servicepointer;
		}
		delete[]servicepointer;
	}
	//1st function
	//adding a customer
	void addingacust() {
		cin >> c;
		outputcustomer.open("customerfile.txt",ios::app);
		outputcustomer << c;
		customerc++;
		outputcustomer.close();
		customerc++; //adding to customer
		//opening file to see if customer is added

		outputfile.open("file1.txt");
		outputfile << vehiclec;
		outputfile << customerc;
		outputfile << driverc;
		outputfile << servicec;
		outputfile.close();
	
		cout << "Added " << endl;
	}
	//2nd function
	//adding a driver
	void addingadriver() {
		cin >> d;
		outputdriver.open("driverfile.txt",ios::app);
		outputdriver << d;
		outputdriver.close();
		//opening file to see if customer is added
		driverc++; //adding to customer
		outputfile.open("file1.txt");
		outputfile << vehiclec;
		outputfile << customerc;
		outputfile << driverc;
		outputfile << servicec;
		outputfile.close();

		cout << " Added " << endl;

	}
	//3rd function
	//removing a driver
	void count() {
		inputfile.open("file1.txt");
		inputfile >> vehiclec;
		inputfile >> customerc;
		inputfile >> driverc;
		inputfile >> servicec;
		inputfile.close();
	}
	void removingadriver() {
		cout << "Enter the details of driver: " << endl;
		char* firname;
		firname = new char[150];
		char* lasname;
		lasname = new char[150];
		cout << "Enter the first name of driver:  ";
		cin.getline(firname, 150);
		cout << "Enter the last name of driver:  ";
		cin.getline(lasname, 150);
		if (driverc < 0 || driverc == 0) {
			cout << "Such driver does not exist" << endl;
			driverc--;
			outputfile.open("file1.txt");
			outputfile << vehiclec;
			outputfile << customerc;
			outputfile << driverc;
		outputfile << servicec;
			outputfile.close();
			cout << "Driver removed " << endl;

		}
		else if (driverc > 0) {
			inputdriver.open("driverfile.txt");
			driver* dritemp = new driver[driverc];
			for (int i = 0; i < driverc; i++) {
				inputdriver >> dritemp[i];
			}
			inputdriver.close();

			//now openig the output file
			outputdriver.open("driverfile.txt");
			for (int i = 0; i < driverc; i++) {
				if ((strcmp(dritemp[i].getfname(), firname) != 0) && (strcmp(dritemp[i].getlname(), lasname) != 0))
				{
					outputdriver << dritemp[i];
				}
				delete[]dritemp;
				dritemp = 0;
			}
		}
		
	}
	//3rd function
	//adding vehicle
	void addingavehicle() {
		cin >> v;
		outputcustomer.open("vehiclefile.txt",ios::app);
		outputcustomer << v;
		outputcustomer.close();
		vehiclec++;
		outputfile.open("file1.txt");
		outputfile << vehiclec;
		outputfile << customerc;
		outputfile << driverc;
		outputfile << servicec;
		outputfile.close();
		cout << " Added " << endl;
	}
	//removign a vehicle
	void removingavehicle() {
		//for a vehicle we need id,regno
		int giveid;
		int givereg;
		cin.ignore();
		cout << "Enter the id: ";
		cin >> giveid;
		cout << "Enter the registration no:  ";
		cin >> givereg;

		if (vehiclec < 0 || vehiclec == 0) {
			cout << "Such vehicle does not exist" << endl;
			vehiclec--;
			outputfile.open("file1.txt");
			outputfile << vehiclec;
			outputfile << customerc;
			outputfile << driverc;
			outputfile << servicec;
			outputfile.close();
			cout << "Vehicle removed " << endl;

		}
		else if (vehiclec > 0) {
			inputvehicle.open("vehiclefile.txt");
			vehicle* dritemp = new vehicle[vehiclec];  ///object created to point to vehicles functionc(getter)
			for (int i = 0; i < vehiclec; i++) {
				inputvehicle >> dritemp[i];
			}
			inputvehicle.close();

			//now openig the output file
			outputvehicle.open("driverfile.txt");
			for (int i = 0; i < driverc; i++) {
				if (dritemp->getvidd() != giveid && dritemp->getregistration() != givereg) {
					outputdriver << dritemp[i];
				}
				delete[]dritemp;
				dritemp = 0;
			}
		}
		
	}

	void listcust() {
		cout << "List of customers:  " << endl;
		inputcustomer.open("customerfile.txt");
		if (customerc < 0 || customerc == 0) {
			cout << "File does not exixt " << endl;
		}
		else {

			customer* c1 = new customer[customerc];
			for (int i = 0; i < customerc; i++) {
				inputcustomer >> c1[i];
				cout << c1[i] << endl;
			}
			delete []c1;
			c1 = 0;
		}
		inputcustomer.close();
	}

	void listdriver() {
		cout << "List of drivers:  " << endl;
		inputdriver.open("driverfile.txt");
		if (driverc < 0 || driverc == 0) {
			cout << "File does not exixt " << endl;
		}
		else {

			driver* d1 = new driver[driverc];
			for (int i = 0; i < driverc; i++) {
				inputdriver >> d1[i];
				cout << d1[i] << endl;
			}
			delete []d1;
			d1 = 0;
		}
		inputdriver.close();
	}


	void listvehicles() {
		cout << "List of vehicles:  " << endl;
		inputvehicle.open("vehiclefile.txt");
		if (vehiclec < 0 || vehiclec == 0) {
			cout << "File does not exixt " << endl;
		}
		else {

			vehicle* v1 = new vehicle[vehiclec];
			for (int i = 0; i < vehiclec; i++) {
				inputvehicle >> v1[i];
				cout << v1[i] << endl;
			}
			delete []v1;
			v1 = 0;
		}
		inputvehicle.close();
	}
	// history with particular id so we take a pointer to point to getvivd func
	void historyvehicle() {
		cout << "Enter the id of vehicle:  ";
		int tempv;
		cin >> tempv;

		inputvehicle.open("vehiclefile.txt");
		if (vehiclec < 0 || vehiclec == 0) {
			cout << "Not found " << endl;
		}
		else {
			int count = 0;
			vehicle* v2 = new vehicle[vehiclec];
			for (int i = 0; i < vehiclec; i++) {
				inputvehicle >> v2[i];
				if (v2[i].getvidd() == tempv) {
					cout << v2[i];
					count++;
				}

			}
			if (count == 0) {
				cout << "Not found " << endl;
			}
			delete []v2;
			v2 = 0;
		}
		inputvehicle.close();
	}
	//history with id
	void historydriver() {
		cout << "Enter the id of driver:  ";
		int tempd;
		cin >> tempd;

		inputdriver.open("driverfile.txt");
		if (driverc < 0 || driverc == 0) {
			cout << "Not found " << endl;
		}
		else {
			int count = 0;
			driver* v3 = new driver[driverc];
			for (int i = 0; i < driverc; i++) {
				inputdriver >> v3[i];
				if (v3[i].getdid() == tempd) {
					cout << v3[i];
					count++;
				}

			}
			if (count == 0) {
				cout << "Not found " << endl;
			}
			delete []v3;
			v3 = 0;
		}
		inputdriver.close();


	}
	//history with id
	void historycustomers() {
		cout << "Enter the id of customer:  ";
		int tempc;
		cin >> tempc;

		inputcustomer.open("customerfile.txt");
		if (customerc < 0 || customerc == 0) {
			cout << "Not found " << endl;
		}
		else {
			int count = 0;
			customer* c3 = new customer[customerc];
			for (int i = 0; i < customerc; i++) {
				inputcustomer >> c3[i];
				if (c3[i].getcustid() == tempc) {
					cout << c3[i];
					count++;
				}

			}
			if (count == 0) {
				cout << "Not found " << endl;
			}
			delete []c3;
			c3 = 0;
		}
		inputcustomer.close();

	}

	void driverwithrank() {
		cout << "Drivers with ranking > 4.5";
		inputdriver.open("driverfile.txt");
		if (driverc < 0 || driverc == 0) {
			cout << "Does not exixt " << endl;
		}
		else if (driverc > 0) {
			int counter = 0;
			driver* d4 = new driver[driverc];
			for (int i = 0; i < driverc; i++) {
				inputdriver >> d4[i];
				if (d4[i].getoverallranking() >= 4.5) {
					counter++;
					cout << d4[i];
				}
			}
			if (counter == 0) {
				cout << "Such drivers do not exist " << endl;
			}
			delete []d4;
			d4 = 0;
		}
		inputdriver.close();



	}
	void driverwithmultipleliscenses() {
		cout << "Drivers with multiple liscenses";
		inputdriver.open("driverfile.txt");
		if (driverc < 0 || driverc == 0) {
			cout << "Does not exixt " << endl;
		}
		else if (driverc > 0) {
			int counter = 0;
			driver* d5 = new driver[driverc];
			for (int i = 0; i < driverc; i++) {
				inputdriver >> d5[i];
				if (d5[i].getnoofliscence() > 1) {
					counter++;
					cout << d5[i];
				}
			}
			if (counter == 0) {
				cout << "Such drivers do not exist " << endl;
			}
			delete []d5;
			d5 = 0;
		}
		inputdriver.close();
	}

	void updatedsalary() {
		float salary;

		cout << "Salaries:  " << endl;;
		inputdriver.open("driverfile.txt");
		if (driverc < 0 || driverc == 0) {
			cout << "Does not exixt " << endl;
		}
		else if (driverc > 0) {
			int counter;
			driver* d6 = new driver[driverc];
			for (int i = 0; i < driverc; i++) {
				inputdriver >> d6[i];
				salary = d6[i].getsalary();
				cout << i + 1 << " - " << salary << endl;
			}
			delete []d6;
			d6 = 0;
		}
		inputdriver.close();

	}


	void servicerequest() {
		int choice1 = 0;
		cout << "Enter choice: " << endl;
		cout << "1-ride " << endl;
		cout << "2-delivery " << endl;
		if (choice1 == 1) {
			ride r;
			servicepointer = &r;
		}
		if (choice1 == 2) {
			delivery del;
			servicepointer = &del;
		}
		cout << "Enter you request: ";
		cin >> *(servicepointer);
		ouputservice.open("servicefile.txt", ios::app);
		ouputservice << choice1 << " ";
		ouputservice << *servicepointer;
		ouputservice.close();
		servicec++;
		//opening file1 
		outputfile.open("file1.txt");
		outputfile << vehiclec;
		outputfile << customerc;
		outputfile << driverc;
		outputfile << servicec;
		outputfile.close();
		delete servicepointer;
		servicepointer = 0;

	}

	void cancelaservice() {
		int* b = new int[servicec];
		int cusid, drivid;
		cout << "Enter the customer id: ";
		cin >> cusid;
		cout << "Enter the driver id: ";
		cin >> drivid;
		service** s = new service * [servicec];
		inputservice.open("servicefile.txt");
		for (int i = 0; i < servicec; i++) {
			inputservice >> b[i];
			if (b[i] == 1) {
				s[i] = new ride;

			}
			if (b[i] == 2) {
				s[i] = new delivery;
			}
			inputservice >> *(s[i]);
			if (s[i]->getcid() == cusid && s[i]->getdid() == drivid) {
				s[i]->setstatus(2);//cancelled
			}
		}
		inputservice.close();
		//for printing
		ouputservice.open("servicefile.txt");
		for (int i = 0; i < servicec; i++) {
			ouputservice << b[i] << endl;
		}
		for (int i = 0; i < servicec; i++) {
			ouputservice << *(s[i]) << endl;
		}
		//closing the files
		ouputservice.close();
		delete []b;
		for (int i = 0; i < servicec; i++) {
			delete[]s[i];
		}
		delete[]s;

	}
	void completeaservice() {

		int* b = new int[servicec];
		int cusid, drivid;
		cout << "Enter the customer id: ";
		cin >> cusid;
		cout << "Enter the driver id: ";
		cin >> drivid;
		service** s = new service * [servicec];
		inputservice.open("servicefile.txt");
		for (int i = 0; i < servicec; i++) {
			inputservice >> b[i];
			if (b[i] == 1) {
				s[i] = new ride;

			}
			if (b[i] == 2) {
				s[i] = new delivery;
			}
			inputservice >> *(s[i]);
			if (s[i]->getcid() == cusid && s[i]->getdid() == drivid) {
				s[i]->setstatus(1);
				if (b[i] == 2) {
					int vrank, drank;
					cout << "Enter vehicle ranking:  ";
					cin >> vrank;
					//dynamic_cast<ride*>(s[i])->setdrank(vrank);
					cout << "Enter driver ranking:  ";
					cin >> vrank;
					//dynamic_cast<ride*>(s[i])->setvrank(vrank);

				}
			}
		}
		inputservice.close();
		ouputservice.open("service.txt");
		for (int i = 0; i < servicec; i++) {
			ouputservice << b[i] << endl;
			ouputservice << *(s[i]) << endl;
		}
		ouputservice.close();
		delete []b;
		for (int i = 0; i < servicec; i++) {
			delete[]s[i];
		}
		delete []s;







	}
	void customerswithsamevehicle() {
		cout << "Customers having same vehicle:  " << endl;
		cout << "Enter the vegicle id:  ";
		int vehicleid;
		cin >> vehicleid;
		inputcustomer.open("customerfile.txt");
		if (customerc < 0 || customerc == 0) {
			cout << "Not found " << endl;
		}
		else {
			customer* cus = new customer[customerc];
			for (int i = 0; i < customerc; i++) {
				inputcustomer >> cus[i];
				//making 2d arrya to point to service
				service** s = cus[i].getbookinghistory();
				for (int k = 0; k < cus[i].getbookcount(); k++) {
					if (s[k]->getvid() == vehicleid) {
						cout << cus[i];
					}
				}
			}
			delete[]cus;
			cus = 0;
		}

	}


	void serviceinsamedate() {
		cout << "Services on the same date:  " << endl;
		cout << "Enter the booking date: ";
		int dt;
		cin >> dt;
		inputcustomer.open("customerfile.txt");
		if (customerc == 0 || customerc < 0) {
			cout << "Not found " << endl;
		}
		else {
			customer* t = new customer[customerc];
			for (int i = 0; i < customerc; i++) {

				inputcustomer >> t[i];
				service** s1 = t[i].getbookinghistory();
				for (int k = 0; k < t[i].getbookcount(); k++) {
					if (s1[k]->getdate() == date) {
						cout << *(s1[k]) << endl;
					}
				}

			}
			delete []t;
			t = 0;
			inputcustomer.close();
		}
	}


	void pendingservicesdate() {
		int* b = new int[servicec];
		cout << "Pending services: " << endl;
		cout << "Enter the driver id: ";
		int driverid;
		cin >> driverid;
		inputservice.open("servicefile.txt");
		service** s = new service * [servicec];
		for (int i = 0; i < servicec; i++) {
			inputservice >> b[i];
			if (b[i] == 1) {
				s[i] = new ride;

			}
			if (b[i] == 2) {
				s[i] = new delivery;
			}
			inputservice >> *(s[i]);
			if (s[i]->getstatus() == 0 && s[i]->getdid() == driverid) {
				cout << *(s[i]);
			}
		}
		inputservice.close();
		//for printing
		ouputservice.open("servicefile.txt");
		for (int i = 0; i < servicec; i++) {
			ouputservice << b[i] << endl;
		}

		//closing the files
		ouputservice.close();
		delete []b;
		for (int i = 0; i < servicec; i++) {
			delete[]s[i];
		}
		delete[]s;

	}


	void pendingservicesparticluardriver(int id) {
		int index = 0;
		for (index = 0; index < servicec; index++)
		{
			if (((servicepointer + index)->getdid() == id) && ((servicepointer + index)->getstatus() == false))
			{
				cout << (servicepointer + index);
			}
		}
	}



	void cancelledservices(int id) {

		for (int i = 0; i < customerc; i++)
		{
			if (c.getcustid() == id)
			{
				cout << "the following customer cancelled the request" << endl;
				cout << c.getcustid() << " " << c.getfname() << " " << c.getlname() << " " << c.getnid() << " " << c.getyear() << endl;











			}
		}
	}




};



























void menu() {
	cout << "------------------ Welcome to Transport Management System ------------------" << endl;
	cout << "**--------------------------------------MENU-------------------------------------**" << endl << endl << endl;
	cout << "1. Add a new Customer" << endl;
	cout << "2. Add  a Driver" << endl;
	cout << "2.1. Remove a Driver." << endl;;
	cout << "3. Add a Vehicle" << endl;
	cout << "3.1. Remove a Vehicle." << endl;
	cout << "4. Print List of All Customers" << endl;
	cout << "5. Print List of All drivers" << endl;
	cout << "6. Print complete list of vehicles with details by their category." << endl;
	cout << "7. Print complete details and service history of a particular vehicle, (Provide vehicle ID)" << endl;
	cout << "8. Print complete history of a particular customer, (Provide customer ID)" << endl;
	cout << "9. Print complete history of a driver including services. (Provide driver ID)" << endl;
	cout << "10. Print list of all drivers who have ranking above 4.5." << endl;
	cout << "11. Print list of all drivers(multiplt liscenses)." << endl;
	cout << "12. Print updated salary of all drivers based on their updated ranking." << endl;
	cout << "13. Add a Service request(ride or delivery) for a customer" << endl;
	cout << "14. Cancel a Service. " << endl;
	cout << "15. Complete a service(Provide service ID)" << endl;
	cout << "16. Print details of all Customers " << endl;
	cout << "17. Print the List of all Drivers who completed delivery services on same days." << endl;
	cout << "18. Print details of all pending services on a particular date." << endl;
	cout << "19. Print details of all pending services of a particular driver." << endl;
	cout << "20. Print details of all canceled services by a customer" << endl;
	cout << endl << endl << endl;
}
int main() {
	menu();
	transportsystem x;
	float choice;
	bool flag = false;
	while (!flag)
	{
		// created the update count function
		x.count();
		cout << "ENTER YOUR CHOICE = ";
		cin >> choice;
		if (choice == 1) {
			x.addingacust();
		}
		if (choice == 2) {
			x.addingadriver();
		}
		if (choice == 2.1) {
			x.removingadriver();
		}
		if (choice == 3) {

			x.addingavehicle();
		}
		if (choice == 3.1) {
			x.removingavehicle();
		}
		if (choice == 4)
		{
			x.listcust();
		}
		if (choice == 5) {


			x.listdriver();
		}
		if (choice == 6) {

			x.listvehicles();
		}
		if (choice == 7) {

			x.historyvehicle();
		}
		if (choice == 8) {

			x.historycustomers();
		}
		if (choice == 9) {

			x.historydriver();
		}
		if (choice == 10) {

			x.driverwithrank();
		}
		if (choice == 11) {

			x.driverwithmultipleliscenses();
		}
		if (choice == 12) {

			x.updatedsalary();
		}
		if (choice == 13) {

			x.servicerequest();
		}
		if (choice == 14) {

			x.cancelaservice();
		}
		if (choice == 15) {

			x.completeaservice();
		}
		if (choice == 16) {
			x.customerswithsamevehicle();
		}
		if (choice == 17) {

			x.serviceinsamedate();

		}
		if (choice == 18) {
			x.pendingservicesdate();
		}
		if (choice == 19)
		{
			int id = 0;
			cout << "enter the id" << endl;
			cin >> id;
			x.pendingservicesparticluardriver(id);
		}
		if (choice == 20)
		{
			int id;
			cout << "enter the customer id whose cancelled request you want to see" << endl;
			cin >> id;

			x.cancelledservices(id);
		}
	}




	system("pause");
	return 0;
}