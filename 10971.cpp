#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

const int VERY_BIG = 100000001;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::vector<std::vector<int> > dist;
    int n;
    std::cin >> n;
    dist.resize(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int now;
            std::cin >> now;
            if(now == 0) now = VERY_BIG;
            dist[i].push_back(now);
        }
    }
    //input
    
    std::vector<int> pmt; //permutaion
    for(int i = 0; i < n; i++) pmt.push_back(i);
    
    int grobal_min = VERY_BIG;
    do{
        int local_min = 0, first = pmt[0];
        int prev = first;
        for(auto&curr : pmt){
            if(first == curr) continue;
            local_min += dist[prev][curr];
            prev = curr;
        }
        local_min += dist[pmt[pmt.size()-1]][first]; // last -> first
        if(local_min < grobal_min) grobal_min = local_min;
    }while(std::next_permutation(pmt.begin(), pmt.end()));
    
    std::cout << grobal_min;
    return 0;
}
