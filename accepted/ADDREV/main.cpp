/*
 *ADDREV SPOJ PROBLEM by Vitor Shade
 *Created: 26/01/2013
 */

#include <iostream>
#include <vector>
#include <cmath>

int ReverseNumber(const int & num)
{
    std::vector<int> digits;
    int d = num;
    do{
        digits.push_back(d%10);
        d = d/10;
    }while( d != 0 );
    int rev_num = 0;
    for(int i = 0; i < digits.size(); i++){
        rev_num += (digits.at(i) * std::pow(10,digits.size() - i - 1));
    }
    return rev_num;
}

int main()
{
    int test_cases;
    int x;
    int y;
    std::cin >> test_cases;
    for(int i = 0; i < test_cases; i++){
        std::cin >> x >> y;
        std::cout << ReverseNumber(ReverseNumber(x) + ReverseNumber(y)) << std::endl;
    }
    return 0;
}

