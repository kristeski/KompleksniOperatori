#include <iostream>
using namespace std;
class KB {
public:
    long double real, imag;
    KB() : real(0), imag(0) {};
    KB(long double a, long double b) : real(a), imag(b) {};
    KB& operator ++() {
        real = real + 1;
        return *this;
    }
    KB operator ++(int) {
        KB tmp = *this;
        real = real + 1;
        return tmp;
    }
    KB operator +(KB& other) {
        return KB(real + other.real, imag + other.imag);
    }
    KB operator *(KB& other) {
        return KB(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }
    KB& operator -(int) {
        real = -real;
        imag = -imag;
        return *this;
    }
    KB operator -(KB &other) {
        KB tmp;
        tmp.real = this->real - other.real;
        tmp.imag = this->imag - other.imag;
        return tmp;
    }
    KB& operator ~() {
        imag = -imag;
        return *this;
    }
    KB operator /(KB& other) {
        long double imenitel = other.real * other.real + other.imag * other.imag;
        if (!imenitel) throw runtime_error("Nemozes da delis so 0");
        return KB((real * other.real + imag * other.imag) / imenitel,
            (other.real * imag - real * other.imag) / imenitel);
    }
    bool operator ==(KB& other) {
        return (real == other.real && imag == other.imag);
    }
    void operator =(KB& other) {
        real = other.real;
        imag = other.imag;
    }
    long double operator!() {
        return sqrt(real * real + imag * imag);
    }
};
int main()
{
    KB a;
    
}
