#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <math.h>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::vector<int> board; // board[row] = col
    int n;
    std::cin >> n;
    board.resize(n);
    
    std::function<int(int)> set_queen;
    set_queen = [&](int row) -> int {
        if(row == n) return 1;
        int ret = 0;
        for(int curr_col = 0; curr_col < n; curr_col++){
            bool there_can_be_queen = 1;
            for(int check_every_row = 0; check_every_row < row; check_every_row++){
                // check some column is alreay exist
                if(board[check_every_row] == curr_col) {
                    there_can_be_queen = 0;
                    break;
                }
                // check cross
                if(abs(check_every_row - row) == abs(curr_col - board[check_every_row])) {
                    there_can_be_queen = 0;
                    break;
                }
            }
            if(there_can_be_queen){
                board[row] = curr_col;
                //set queen of next row
                ret += set_queen(row + 1);
            }
        }
        return ret;
    };
    
    std::cout << set_queen(0);
    return 0;
}
