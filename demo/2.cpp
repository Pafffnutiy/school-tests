#include <iostream>
#include <vector>

void outp(std::vector<std::vector<size_t>> Map){
    for (size_t i = 0; i < Map.size(); ++i){
        for(size_t j = 0; j < Map[i].size(); ++j)
            std::cout << Map[i][j] << ' ';
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
int main()
{
    enum Mode {Up, Down, Right, Left};
    size_t M, N;
    std::cin >> M >> N;
    std::vector<std::vector<size_t>> Map(N, std::vector<size_t>(M, 0));
    size_t i = 0, j = 0, m = M - 1, n = N - 1;
    Mode mode = Right;
    
    for (size_t cnt = 1; cnt <= M * N; ++cnt)
    {
        Map[i][j] = cnt;
        if(j == m && mode == Right)
            mode = Down;
        if(i == n && mode == Down){
            --n;
            mode = Left;
        }
        if(i == N - n - 1 && mode == Up)
            mode = Right;
        if(j == M - m - 1 && mode == Left){
            --m;
            mode = Up;
        }
        if (mode == Right)
            ++j;
        else if(mode == Left)
            --j;
        else if(mode == Up)
            --i;
        else
            ++i;
        outp(Map);
        //std::cout << i << ' ' << j << std::endl;
    }
    
    return 0;
}
