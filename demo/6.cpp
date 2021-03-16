#include <iostream>
#include <vector>

int main()
{
    std::vector<long long int> First, Second{-5, 6}, Ans;
    for (long long int inp; std::cin >> inp;)
        First.push_back(inp);
    Ans.resize(First.size() + Second.size() - 1);
    for (auto &elem : Ans)
        elem = 0;
    for (long long int i = 0; i < First.size(); ++i)
        for(long long int j = 0; j < Second.size(); ++j)   
            Ans[i + j] += First[i] * Second[j];

    for(auto elem : Ans)
        std::cout << elem << ' ';
    return 0;
}
