#include <iostream>
#include <functional>
#include <vector>
#include <stack>
#include <algorithm>

typedef std::pair<int, int> ii;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::vector<ii> pmt;
    std::stack<int> stk;
    std::stack<int> tmpStk;
    
    int N, M;
    std::cin >> N >> M;
    for(int i = 1; i <= N; i++) pmt.push_back(ii(i, M));
    
    std::function<void(ii)> dfs;
    dfs = [&](ii a){
        int n = a.first, m = a.second;
        if(m == 0) {
            //success
            while(!stk.empty()){
                tmpStk.push(stk.top());
                stk.pop();
            }
            while(!tmpStk.empty()){
                int tmp = tmpStk.top();
                tmpStk.pop();
                std::cout << tmp << " ";
                stk.push(tmp);
            }
            std::cout << "\n";
            return ;
        }
        if(n > N) {
            //fail
            return ;
        }
        for(int i = n; i <= N; i++){
            stk.push(i);
            dfs(ii(i+1, m-1));
            stk.pop();
        }
    };
    dfs(ii(1, M));
    return 0;
}
