#include <iostream>
#include <vector>


const long long int len = 10000000;

std::vector<long long int> knownFacs(len, -1); 

long long int fac(long long int n)
{
    if (knownFacs[n] != -1 && n < len)
        return knownFacs[n];
    else if (n == 0)
        return 1;
    else{
        long long int ans;
        ans = n * fac(n - 1);
        knownFacs[n] = ans;
        return ans;
    }
        
}

long long int C(long long int n, long long int k)
{
    return fac(n) / fac(k) / fac(n - k);
}


int main()
{
    std::vector<long long int> First;
    std::string inp;
    std::getline(std::cin, inp);
    std::cout << inp;
    long long int tmp = 0;
    for(char c : inp){
        tmp = 10 * tmp + static_cast<int>(c);
        if (c == ' ')
            First.push_back(tmp);
    }
    std::vector<long long int> Ans(First.size(), 0);
    for (long long int i = 1; i < First.size(); ++i)
        for( long long int j = 1; j <= i; ++i)
            Ans[j] += C(i, j) * First[i];
    for(auto elem : Ans)
        std::cout << elem << ' ';
    return 0;
}
