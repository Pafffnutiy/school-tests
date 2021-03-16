#include <fstream>
#include <iostream>

int main()
{
    std::ifstream inp("input_1.txt");
    size_t ans = 0;
    size_t tmp;
    while(inp >> tmp)
    {
        if (tmp % 2 == 0)
            ++ans;
        //inp >> tmp;
        //std::cout << tmp;
    }
    std::cout << ans << std::endl;
}
