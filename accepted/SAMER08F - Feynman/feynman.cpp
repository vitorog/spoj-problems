/*Created by Vitor Shade - 07-04-13
 *
 *Explanation:
 *For a given N > 1, we have the N^2 size-1 squares + the whole size-N square, that makes (N^2 + 1) squares.
 *Also, we can fit 4 size-(N-1) squares inside a size-N square (top-left, top-right, bottom-left and bottom-right).
 *We can do this for all squares whose size < N, and for each square of size M (M < N), it is possible to fit
 *(N-M+1) size-M squares in each direction. This results in (N-M+1)*(N-M+1) size-M squares within a size-N square.
 *Thus, the total of squares is N^2 + (N-M+1)^2 + 1, for all 1 < M < N.
 */

#include <iostream>

void PrintNumSquares(const int& n)
{
    if(n > 1){
        long int num = (n*n) + 1; //NxN size-1 squares + 1 size-N square
        for(int i = 2; i < n; i++){  //For each size 1 < i < N, it is possible to fit (n-i+1) squares in each direction
            num += (n-i+1)*(n-i+1);
        }
        std::cout << num << std::endl;
    }else{
        std::cout << n << std::endl;
    }
}

int main()
{
    int n;
    while(true){
        std::cin >> n;
        if(n != 0){
            PrintNumSquares(n);
        }else{
            break;
        }
    }
    return 0;
}

