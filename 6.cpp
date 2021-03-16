#include <iostream>
#include <vector>

int main()
{
    std::vector<long long int> First, Second{-5, 6}, Ans;
    for (long long int inp; std::cin >> inp;)
        First.push_back(inp);
    Ans.push_back(First[0] * Second[0]);
    for (long long int i = 1; i < First.size(); ++i)

    return 0;
}
