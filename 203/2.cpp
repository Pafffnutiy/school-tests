#include <iostream>
#include <fstream>
#include <cmath>

void func2()
{
    std::ifstream in("input", std::ifstream::binary);
    double val;
    double buff;
    in >> val;
    buff = val;
    while(in>>val)
    {
        if ( std::abs(val) < std::abs(buff) )
            buff = val;
    }
    std::cout << buff << '\n';
}

int main(int argc, char** argv)
{
    func2();
}
