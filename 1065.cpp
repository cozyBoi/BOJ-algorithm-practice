#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

typedef std::pair<int, int> ii;

int main(){
    std::ios_base::sync_with_stdio(false);
    
    int cnt = 0;
    
    std::vector<ii> v;
    
    int input;
    std::cin >> input;
    while(input) {
        if(input < 10){
            cnt++;
            input--;
            continue;
        }
        v.push_back(ii(input,
                       [=](int in)-> int {
                           int i;
                           for(i = 0; in != 0; i++, in/=10);
                           return i-1;
                       }(input)
                       ));
        input--;
    }
    
    std::for_each(v.begin(), v.end(),
                  [&cnt](ii a){
                      int i = a.first, j = a.second;
                      int prev = i % 10, now = (i / 10) % 10, minus;
                      i = i / 10;
                      minus = prev - now;
                      while(--j){
                          prev = i % 10;
                          now = (i / 10) % 10;
                          i = i / 10;
                          if(minus != prev - now) return;
                      }
                      cnt++;
                  }
                  );
    std::cout << cnt;
    return 0;
}
