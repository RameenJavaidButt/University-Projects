#include <iostream>
#include<cstring>
using namespace std;
class roman {
private:
    char* a;
    int size;
    int convertedvalue;
public:
    roman();
    roman(char*);
    roman(const roman& o) {
        size = o.size;
        a = new char[size];
        for (int i = 0; i < size; i++) {
            a[i] = o.a[i];
        }
        convertedvalue = o.convertedvalue;
    }
    void input();
     ~roman();
    void printname();
    void printnumber();
    void value();
    roman operator+(const roman&)const;
    roman operator-(const roman&)const;
    roman operator*(const roman&)const;
    roman operator/(const roman&)const;
    bool operator==(const roman&) const;
    bool operator!=(const roman&) const;
    bool operator<(const roman&) const;
    bool operator>(const roman&) const;
    roman& operator++();
    roman& operator--();
    roman operator++(int);//dummy variable to differentiate b/w post and pre
    roman operator--(int);
    void convertback();
};
void roman::convertback() {
    while (convertedvalue != 0) {
        if (convertedvalue >= 1000) {
            cout << "M";
            convertedvalue = convertedvalue - 1000;
        }
        else if (convertedvalue >= 900) {
            cout << "CM";
            convertedvalue = convertedvalue - 900;
        }
        else if (convertedvalue >= 500) {
            cout << "D";
            convertedvalue = convertedvalue - 500;
        }
        else if (convertedvalue >= 400) {
            cout << "CD";
            convertedvalue = convertedvalue - 400;
        }
        else if (convertedvalue >= 100) {
            cout << "C";
            convertedvalue = convertedvalue - 100;
        }
        else if (convertedvalue >= 90) {
            cout << "XC";
            convertedvalue = convertedvalue - 90;
        }
        else if (convertedvalue >= 50) {
            cout << "L";
            convertedvalue = convertedvalue - 50;
        }
        else if (convertedvalue >= 40) {
            cout << "XL";
            convertedvalue = convertedvalue - 900;
        }
        else if (convertedvalue >= 10) {
            cout << "X";
            convertedvalue = convertedvalue - 10;
        }
        else if (convertedvalue >= 9) {
            cout << "IX";
            convertedvalue = convertedvalue - 9;
        }
        else if (convertedvalue >= 5) {
            cout << "V";
            convertedvalue = convertedvalue - 5;
        }
        else if (convertedvalue >= 4) {
            cout << "IV";
            convertedvalue = convertedvalue - 4;
        }
        else if (convertedvalue >= 1) {
            cout << "I";
            convertedvalue = convertedvalue - 1;
        }
    }
}
void roman::input() {
    char tree[20];
    cout << "ENTER THE ROMAN NUMBER = ";

    cin.getline(tree, 20);
    int s = strlen(tree);
    size = s;
    a = new char[s + 1];
    for (int i = 0; i <= s; i++) {
        this->a[i] = tree[i];
        if (i == s + 1) {
            this->a[i] = '\0';
        }
    }

}
roman roman::operator++(int u)
{
    roman n = *this;
    convertedvalue++;
    return n;
}
roman roman::operator--(int y)
{
    roman p = *this;
    convertedvalue--;
    return p;
}
roman& roman::operator++() {
    ++convertedvalue;
    return *this;
}
roman& roman::operator--() {
    --convertedvalue;
    return *this;
}
bool roman::operator==(const roman& t)const {
    if (convertedvalue == t.convertedvalue) {
        return true;
    }
    return false;
}
bool roman::operator<(const roman& t) const
{
    if (convertedvalue < t.convertedvalue) {
        return true;
    }
    return false;
}

bool roman::operator>(const roman& t) const
{
    if (convertedvalue > t.convertedvalue) {
        return true;
    }
    return false;
}

bool roman::operator!=(const roman& t) const
{
    if (convertedvalue != t.convertedvalue) {
        return true;
    }
    return false;
}
roman roman:: operator+(const roman& obj)const {
    roman temp;
    temp.convertedvalue = convertedvalue + obj.convertedvalue;
    return temp;
}
roman roman:: operator-(const roman& obj)const {
    roman tem;
    tem.convertedvalue = convertedvalue - obj.convertedvalue;

    return tem;

}
roman roman:: operator*(const roman& obj)const {
    roman tmp;
    tmp.convertedvalue = convertedvalue * obj.convertedvalue;
    return tmp;
}
roman roman:: operator/(const roman& obj)const {
    roman tep;
    tep.convertedvalue = convertedvalue / obj.convertedvalue;
    return tep;
}
void roman::printnumber() {
    cout << convertedvalue << endl;
}
void roman::value()
{
    size = strlen(a);
    for (int i = 0; i < size; i++) {
        if (a[i] == 'I' && a[i + 1] == 'X') {
            convertedvalue = convertedvalue + 9;
        }
        if (a[i] == 'I' && a[i + 1] == 'V') {
            convertedvalue = convertedvalue + 4;
        }
        if (a[i] == 'C' && a[i + 1] == 'M') {
            convertedvalue = convertedvalue + 900;
        }
        if (a[i] == 'C' && a[i + 1] == 'D') {
            convertedvalue = convertedvalue + 400;
        }
        if (a[i] == 'X' && a[i + 1] == 'L') {
            convertedvalue = convertedvalue + 900;
        }
        if (a[i] == 'X' && a[i + 1] == 'C') {
            convertedvalue = convertedvalue - 90;
        }
        if (a[i] == 'I' && a[i + 1] != 'V' && a[i + 1] != 'X')
            convertedvalue = convertedvalue + 1;

        else if (a[i] == 'V' && a[i - 1] != 'I')
            convertedvalue = convertedvalue + 5;

        else if (a[i] == 'X' && a[i - 1] != 'I')
            convertedvalue = convertedvalue + 10;
        else if (a[i] == 'L' && a[i - 1] != 'X')
            convertedvalue = convertedvalue + 50;
        else if (a[i] == 'C' && a[i - 1] != 'X')
            convertedvalue = convertedvalue + 100;
        else if (a[i] == 'D' && a[i - 1] != 'C')
            convertedvalue = convertedvalue + 500;
        else if (a[i] == 'M' && a[i - 1] != 'C')
            convertedvalue = convertedvalue + 1000;
    }
}
roman::roman() {
    size = 0;
    convertedvalue = 0;
    a = new char[1];

    a = 0;
    
}
roman::~roman() {
    delete[]a;
    a = 0;
}
roman:: roman(char* b) {
    size = strlen(b);

    a = new char[size + 1];
    for (int i = 0; i < size; i++) {
        a[i] = b[i];
    }
    //strcpy(a, b);
}
void roman::printname() {
    cout << a << endl;
}
int main()
{
    
    roman r1;
    roman r2;
    r1.input();
    r2.input();
    r1.value();
    r1.printname();
    r1.printnumber();
    r2.value();
    r2.printname();
    r2.printnumber();
    if (r1 < r2) {
        cout << "r1 is smaller than r2" << endl;
    }
    if (r1 > r2) {
        cout << "r1 is greater than r2 " << endl;
    }
    if (r1 == r2) {
        cout << "r1 is equal to r2 " << endl;
    }
    if (r1 != r2) {
        cout << "r1 is not equal to r2" << endl;
    }
    cout << endl;
    cout << "  PRE " << endl;
    cout << "INCREMENT OPERATOR USED " << endl << endl;
    ++r1;
    ++r2;
    cout << "INCREMENT IN r1 ";
    r1.printnumber();
    cout << "INCREMENT IN r2 ";
    r2.printnumber();
    cout << endl << endl;
    cout << "DECREEMENT OPERATOR USED " << endl << endl;
    --r1;
    --r2;
    cout << "DECREEMENT IN r1 ";
    r1.printnumber();
    cout << "DECREEMENT IN r1 ";
    r2.printnumber();
    cout << endl;
    cout << "  POST ";
    cout << "INCREMENT OPERATOR USED " << endl << endl;
    r1++;
    r2++;
    cout << "INCREMENT IN r1 ";
    r1.printnumber();
    cout << "INCREMENT IN r2 ";
    r2.printnumber();
    cout << endl << endl;
    cout << "DECREEMENT OPERATOR USED " << endl << endl;
    r1--;
    r2--;
    cout << "DECREEMENT IN r1 ";
    r1.printnumber();
    cout << "DECREEMENT IN r1 ";
    r2.printnumber();
    roman r3;
    r3 = r1 + r2;
    cout << "USING + OPERATOR " << endl;
    r3.printnumber();
    r3.convertback();
    cout << endl;
    cout << "USING - OPERATOR " << endl;
    roman r4;
    r4 = r1 - r2;
    r4.printnumber();
    r4.convertback();
    cout << endl;
    cout << "USING * OPERATOR " << endl;
    roman r5;
    r5 = r1 * r2;
    r5.printnumber();
    r5.convertback();
    cout << endl;
    cout << "USING / OPERATOR " << endl;
    roman r6;
    r6 = r1 / r2;
    r6.printnumber();
    r6.convertback();
    cout << endl;

    cout << endl;
    system("pause");
    return 0;
}
