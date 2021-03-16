#include <iostream>
#include <vector>
#include <sstream>
#include <string>


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
    std::vector<float> First;
    std::string str;
    std::getline(std::cin, str);
    std::stringstream inp;
    inp << str;
    
    for(float tmp = 0; inp >> tmp;)
        First.push_back(tmp);
    
    std::vector<float> Ans(First.size(), 0);
    
    for (long long int i = 1; i < First.size(); ++i)
        for( long long int j = 0; j < i; ++j)
            Ans[j] += C(i, j) * First[i];
    Ans.pop_back();
    for(auto elem : Ans)
        std::cout << elem << ' ';
    
    return 0;
}
