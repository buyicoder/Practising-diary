#ifndef MY_COMPLEX_H
#define MY_COMPLEX_H

namespace my_complex
{

class complex
{
public:
	complex(double r = 0, double i = 0)
    : re(r), im(i)  
    {}
    complex& operator += (const complex&);
    double real() const { return re; }
    double imag() const { return im; }
private:
	double re;
	double im;

};

} // namespace my_complex
#endif