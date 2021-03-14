#include <iostream>
#include <fstream>

int main(){
    
    std::fstream file("output.txt", std::fstream::in | std::fstream::out | std::fstream::binary);
    int32_t q = 4, k = 20;
    for (int i=10; i < k; ++i)
        file.write(reinterpret_cast<char*>(&i), q);
    file.close();


    file.open("output.txt", std::fstream::in | std::fstream::out | std::fstream::binary);
    int32_t first, second;
    file.seekg(0, std::fstream::beg);
    file.read(reinterpret_cast<char*>(&first), q);
    file.seekg(4, std::fstream::cur);
    file.read(reinterpret_cast<char*>(&second), q);
    //std::cout << one << std::endl;
    //std::cout << three << std::endl;
    file.seekp(0, std::fstream::beg);
    file.write(reinterpret_cast<char*>(&second), q);
    file.seekp(8, std::fstream::beg);
    file.write(reinterpret_cast<char*>(&first), q);
    file.close();


    file.open("output.txt", std::fstream::in | std::fstream::out | std::fstream::binary);
    int32_t ans = 0;
    for(int i = 10; i < k; ++i){
        file.read(reinterpret_cast<char*>(&ans), q);
        std::cout << ans << std::endl;
    }
    file.close();
    return 0;
}
