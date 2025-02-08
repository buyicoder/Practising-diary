#include <iostream>
#include <vector>
#include "my_complex.h"
#include <algorithm>

int main(){
    my_complex::complex c1(1,2);
    std::cout<<(c1.real())<<std::endl;
    return 0;
}