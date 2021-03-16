#include <fstream>
#include <iostream>

const int32_t INF = 1215752192;

int main() //TODO test this shit
{
    /*
    std::fstream w("input");
    for(int32_t i = -5; i < 5; ++i)
        w.write(reinterpret_cast<char*>(&i), 4);
    w.close();
    */

    std::fstream file("input");
    int32_t temp, q=4, cnt = 0, k = 0, m = INF; // k - the number of numbers; m - position to place the sum (after m-th number)
    for (int32_t i = 0, tmp; !file.eof(); ++i){
        ++k;
        file.read(reinterpret_cast<char*>(&tmp), q);
        std::cout << tmp << '\n';
        if (tmp >= 0)
            ++cnt;
        if (m == INF && tmp > 0)
            m = i;
    }
    file.seekp(q * m, std::fstream::beg);
    file.read(reinterpret_cast<char*>(&temp), q);
    std::cout << cnt << ' ' << m << ' ' << k << std::endl; //DEBUG
    file.close();
        
    return 0;
    file.open("input");
    file.seekp(q * m, std::fstream::beg);
    file.write(reinterpret_cast<char*>(&cnt), q);
    for(int32_t i = m, anotherTemp; i <= k; ++i){
        file.read(reinterpret_cast<char*>(&anotherTemp), q);
        file.seekp(q, std::fstream::cur);
        file.write(reinterpret_cast<char*>(&temp), q);
        temp = anotherTemp;
    }
    file.close();
}

