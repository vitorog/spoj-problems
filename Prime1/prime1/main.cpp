/*Sieve of Eratosthenes simple implementation prime calculator, by Vitor Shade*/
/* It is not fast enough for SPOJ :( */

#include <iostream>
#include <vector>


void ApplySieve(long unsigned int lower_num, long unsigned int upper_num)
{
    std::vector<bool> marked;
    for(long unsigned int i = 2; i <= upper_num; i++){
        marked.push_back(false);
    }
    long unsigned int p = 2;
    bool finished = false;  
    while(!finished){
        finished = true;       
        for(long unsigned int i = p*p; i <= upper_num; i+=p){
            marked[i - 2] = true;
        }       
        for(long unsigned int i = p; i <= upper_num; i++){
            if(marked[i - 2] == false){
                finished = false;
                p = i;
                if(p >= lower_num){
                    std::cout << p << std::endl;
                }
                marked[i - 2] = true;
                break;
            }
        }
    }
}

int main(int argc, char** argv)
{
    int test_cases;
    std::cin >> test_cases;
    long unsigned int numbers[20]; //Maximum test cases = 10
    for(int i = 0; i < test_cases; i++){
        std::cin >> numbers[(2*i)] >> numbers[(2*i) + 1];
    }
    for(int i = 0; i < test_cases; i++){
        ApplySieve(numbers[(2*i)] , numbers[(2*i) + 1]);
        std::cout << std::endl;
    }
    return 0;
}
