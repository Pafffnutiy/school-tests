#include <iostream>
#include <fstream>
//#include <cstdin>

void func7()
{
    std::fstream f("input", std::fstream::binary | std::fstream::in | std::fstream::out);
    int32_t cnt = 0;
    int32_t temp;
    std::size_t i = 0, index = 0;
    while (!f.eof())
    {
        f.read(reinterpret_cast<char*>(&temp),4);
        if (temp < 0)
        {
            ++cnt;
            index = i;
        }
        ++i;
    }

    f.clear();

    f.close();
    f.open("input", std::fstream::binary | std::fstream::in | std::fstream::out);

    f.seekp(4*index, std::fstream::beg);
    f.write(reinterpret_cast<char*>(&cnt), 4);
    
    f.close();
}


int main()
{
    func7();
    return 0;
}

