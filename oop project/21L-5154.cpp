//RAMEEN JAVAID BUTT
//21L-5154
//ASSIGNMENT 2
#include <iostream>
#include<math.h>
using namespace std;
class ComplexNumber
{
private:
    int real;
    int imaginary;
public:
    ComplexNumber(int x = 0, int y = 0); //with default arguments
    ~ComplexNumber(); //Does Nothing.
    void Input();
    void Output();
    bool IsEqual(ComplexNumber);
    ComplexNumber Conjugate();
    ComplexNumber Add(ComplexNumber);
    ComplexNumber Subtract(ComplexNumber);
    ComplexNumber Multiplication(ComplexNumber);
    float Magnitude();
};
ComplexNumber ComplexNumber::Multiplication(ComplexNumber c)
{
    ComplexNumber mul;
    mul.real = (real * c.real) - (imaginary * c.imaginary);
    mul.imaginary = (real * c.imaginary) + (imaginary * c.real);
    return mul;
}
ComplexNumber::~ComplexNumber()
{
    real = 0;
    imaginary = 0;
}
ComplexNumber ComplexNumber::Add(ComplexNumber c)
{
    ComplexNumber tt;
    tt.real = real + c.real;
    tt.imaginary = imaginary + c.imaginary;
    return tt;
}
ComplexNumber ComplexNumber::Subtract(ComplexNumber c)
{
    ComplexNumber zz;
    zz.real = real - c.real;
    zz.imaginary = imaginary - c.imaginary;
    return zz;
}
float ComplexNumber::Magnitude()
{
    float temp = sqrt(pow(real, 2) + pow(imaginary, 2));
    return temp;
}
ComplexNumber::ComplexNumber(int x, int y)
{
    real = x;
    imaginary = y;
}
ComplexNumber ComplexNumber::Conjugate()
{
    imaginary = -imaginary;
    return imaginary;

}
bool ComplexNumber::IsEqual(ComplexNumber c)
{
    if (real == c.real && imaginary == c.imaginary)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void ComplexNumber::Input()
{
    cout << "ENTER REAL: ";
    cin >> real;
    cout << endl;
    cout << "ENTER IMAGINARY: ";
    cin >> imaginary;

}
void ComplexNumber::Output()
{
    if (imaginary > 0)
    {
        cout << real << " " << "+" << " " << imaginary << "i";
    }


    else if (imaginary < 0)
    {
        cout << real << "" << imaginary << "i";


    }
    if (imaginary == 0)
    {
        cout << real << " " << "+" << " " << imaginary << "i";
    }
}
int main()
{
    ComplexNumber c;
    ComplexNumber c2;
    cout << "ENTER C1 " << endl;
    cout << endl;
    c.Input();
    cout << endl;
    cout << "ENTER C2 " << endl;
    cout << endl;
    c2.Input();
    cout << endl;
    cout << "C1 = ";
    c.Output();
    cout << endl;
    cout << "C2 = ";
    c2.Output();
    c.IsEqual(c2);
    cout << endl;
    cout << endl;
    if (c.IsEqual(c2) == true)
    {
        cout << "<-|C1 is equal to C2|->" << endl;

    }
    else
    {
        cout << "-C1 is not equal to C1-";
    }
    cout << endl;
    cout << endl;
    ComplexNumber c3;
    cout << "C1+C2 =  ";
    c3 = c.Add(c2);
    c3.Output();
    cout << endl;
    cout << endl;
    cout << "C1-C2 =  ";
    ComplexNumber c4;
    c4 = c.Subtract(c2);
    c4.Output();
    cout << endl << endl;
    ComplexNumber c5;
    cout << "C1*C2 =  ";
    c5 = c.Multiplication(c2);
    c5.Output();
    cout << endl << endl;
    cout << "CONJUGATE OF C1 = ";
    c.Conjugate();
    c.Output();
    cout << endl;
    cout << "CONJUGATE OF C2 =  ";
    c2.Conjugate();
    c2.Output();
    cout << endl;
    cout << endl;
    cout << "MAGNITUDE OF C1 =  ";
    cout << c.Magnitude();
    cout << endl;
    cout << "MAGNITUDE OF C2 =  ";
    cout << c2.Magnitude();
    cout << endl;
    cout << endl;

    return 0;
}