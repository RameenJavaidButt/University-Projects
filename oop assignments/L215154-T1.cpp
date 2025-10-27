#include <iostream>
#include<math.h>
#include<cmath>
using namespace std;
class VectorType {
    friend ostream& operator<<(ostream&, const VectorType&);
    friend istream& operator>>(istream&, VectorType&);
private:
    
    double* x;
    double* y;
    double* z;
public:
    VectorType();
    VectorType(double*, double*, double*);
    VectorType(const VectorType& obj);
    ~VectorType();
    VectorType& operator = (const VectorType& t);
    double operator*(const VectorType& s)const;
    VectorType operator+(const VectorType& q)const;
    double length();
    double angle(VectorType&);
    VectorType operator-(const VectorType&)const;
    VectorType operator++();
    VectorType operator--();
    VectorType operator++(int);
    VectorType operator--(int);
    friend bool operator==(VectorType&, const VectorType&);
    friend bool operator!=(VectorType&, const VectorType&);
    

};
istream& operator>>(istream& obj, VectorType& ob) {
    obj >> *ob.x;
    obj >> *ob.y;
    obj >> *ob.z;
    return obj;
}
ostream& operator<<(ostream& obj,const VectorType& ob) {
    
    obj << *ob.x << "i" << " " << *ob.y << "j" << " " << *ob.z << "k" << endl;
    
    return obj;
}
bool operator==(VectorType& obj, const VectorType& ob) {
    if (*obj.x == *ob.x && *obj.y == *ob.y && *obj.z == *obj.z) {
        return true;
    }
    return false;

}
bool operator!=(VectorType& obj, const VectorType& ob) {
    if (*obj.x != *ob.x && *obj.y != *ob.y && *obj.z != *obj.z) {
        return true;
    }
    return false;
}
VectorType VectorType::operator-(const VectorType &obj)const {
    VectorType temp;
    *temp.x = *x - (*obj.x);
    *temp.y = *y - *obj.y;
    *temp.z = *z - *obj.z;
    return temp;
}
VectorType VectorType::operator--(int w) {
    VectorType temp;
    temp = *this;
    (*x)--;
    (*y)--;
    (*z)--;
    return temp;

}
VectorType VectorType::operator++(int w) {
    VectorType temp;
    temp = *this;
    (*x)++;
    (*y)++;
    (*z)++;
    return temp;

}
VectorType VectorType::operator--() {
    VectorType temp;
    *temp.x = --(*x);
    *temp.y = --(*y);
    *temp.z = --(*z);
    return temp;
}
VectorType VectorType::operator++() {
    VectorType temp;
    *temp.x = ++(*x);
    *temp.y = ++(*y);
    *temp.z = ++(*z);
    return temp;
}
double VectorType::angle(VectorType& ob) {
    double theta;
    theta = ((*this) * ob) / (length() * ob.length());
    return acos(theta);
}
double VectorType::length() {
    double len;
    len = sqrt(pow(*x, 2) + pow(*y, 2) + pow(*z, 2));
    return len;
}
VectorType VectorType::operator+(const VectorType& q)const {
    VectorType temp;
    *temp.x = *x + *q.x;
    *temp.y = *y + *q.y;
    *temp.z = *z + *q.z;
    return temp;
}
double VectorType::operator*(const VectorType& s)const
{
    //* operator
    double tree=0;
    tree = (*s.x) * (*x) +
        (*s.y) * (*y) +
        (*s.z) * (*z);
    return tree;
}
VectorType& VectorType::operator = (const VectorType& t)
{
    //assignment operator
    *x = *t.x;
    *y = *t.y;
    *z = *t.z;
    return *this;
}
VectorType::VectorType(double* a, double* b, double* c)
{
    x = new double;
    y = new double;
    z = new double;
    //parametrized constructor
    *x = *a;
    *y = *b;
    *z = *c;
}
VectorType::~VectorType()
{
    //destructor
    delete x;
    *x = 0;
    delete y;
    *y = 0;
    delete z;
    *z = 0;
}
VectorType::VectorType(const VectorType& obj)
{
    //copy constructor
    x = new double;
    y = new double;
    z = new double;
    *x = *obj.x;
    *y = *obj.y;
    *z = *obj.z;

}
VectorType::VectorType()
{
    x = new double;
    y = new double;
    z = new double;
    *x = 0;
    *y = 0;
    *z = 0;
}

int main()
{

    double* t, * f, * m;
    t = new double;
    f = new double;
    m = new double;
    *t = 9;
    *f = 8;
    *m = 7;
    VectorType v1(t, f, m);
    cout << "U = ";
   
    cout << v1;
    ++v1;
    cout << "PRE INCREMENT = ";
    
    cout << v1;
    --v1;
    cout << "PRE DECREEMENT = ";
    
    cout << v1;
    v1++;
    cout << "POST INCREMENT = ";
    
    cout << v1;

    v1--;
    cout << "POST DECREEMENT = ";
    
    cout << v1;
    cout << endl << endl;
    double* tt, * ff, * mm;
    tt = new double;
    ff = new double;
    mm = new double;
    *tt = 3;
    *ff = 4;
    *mm = 6;
    VectorType u(tt, ff, mm);
    cout << "V = ";
   
    cout << u;
   ++u;
    cout << "PRE INCREMENT = ";
    
    cout << u;
    --u;
    cout << "PRE DECREEMENT = ";
    
    cout << u;
    u++;
    cout << "POST INCREMENT = ";
        cout << u;
    u--;
    cout << "POST DECREEMENT = ";
    
    cout << u;

    cout << endl;
    cout << "COPY CONSTRUCTOR CALLED.V IS COPIED TO V3 " << endl;
    VectorType v3;
    v3 = (u);
   
     cout<<v3;
    //using overload assignment operator
     cout << endl;
    cout << "OVERLOADED ASSIGNMENT " << endl;
    u = v1;
    
    cout << u;
    cout << endl;
    VectorType j,sub;
    double k;
    cout << endl;
    cout << "DOT PRODUCT OF VECTORS " << endl;
    k = u * v3;
    cout << k;
    cout << endl << endl;
    j = u + v3;
    cout << "ADDTION OF VECTORS " << endl;
   
    cout << j;
    cout << endl;
    sub = u - v3;
    cout << "SUBTRACTION OF VECTORS " << endl;
    //sub.print();
    cout << sub;
    cout << endl;
    double leng;
    leng = v3.length();
    cout << "LENGHT OF VECTOR V = " << leng;
    cout << endl;
    double lengt;
    lengt = u.length();
    cout << "LENGHT OF VECTOR U = " << lengt;
    cout << endl << endl;
    VectorType vector1, vector2;
    cout << "ENTER THE VECTOR = ";
    cin >> vector1;
    cout << endl;
    cout << "ENTER THE VECTOR = ";
    cin >> vector2;
    cout << "LENGTH OF ENTERED VECTOR 1 = " << vector1.length();
    cout << endl;
    cout << "LENGTH OF ENTERED VECTOR 2 = " << vector2.length();
    cout << endl;
    cout << "THE ANGLE BETWEEN THE VECTORS = ";
    double thetta;
    thetta = vector1.angle(vector2);
    cout << thetta;
    cout << endl << endl;
    if (vector1 == vector2) {
        cout << "EQUAL " << endl;
    }
    else  {
        cout << "NOT EQUAL " << endl;
    }
    return 0;
}

