#include <iostream>
#include <algorithm>

int main()
{
    std::string s;
    std::cin >> s;
    std::cout << std::count(begin(s), end(s), 'a') << std::endl;
    return 0;
}
