#include <fstream>
#include <iostream>

int main() //TODO test this shit
{
    std::fstream file("output.txt");
    int32_t first, second, temp, q=4, sum = 0, k = 4, m = 1; // k - the number of numbers; m - position to place the sum (after m-th number)
    for (int32_t i = 0, tmp; i < k; ++i){
        file.read(reinterpret_cast<char*>(&tmp), q);
        sum += tmp;
    }
    file.seekp(q * m, std::fstream::beg);
    file.read(reinterpret_cast<char*>(&temp), q);
    std::cout << sum << ' ' << temp << std::endl; //DEBUG
    file.close();

    file.open("output.txt");
    file.seekp(q * m, std::fstream::beg);
    file.write(reinterpret_cast<char*>(&sum), q);
    for(int32_t i = m, anotherTemp; i <= k; ++i){
        file.read(reinterpret_cast<char*>(&anotherTemp), q);
        file.seekp(-4, std::fstream::cur);
        file.write(reinterpret_cast<char*>(&temp), q);
        temp = anotherTemp;
    }
    file.close();
}

