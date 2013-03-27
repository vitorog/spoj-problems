#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    std::string input;
    std::string output = "Ready\n";
    bool waiting_input = true;
    do{
        getline(std::cin, input);
        if(input=="  "){
            waiting_input = false;
        }
        if(waiting_input){
            if(input[0]=='d' && input[1]=='b' ||
                    input[0]=='q' && input[1]=='p' ||
                    input[0]=='b' && input[1]=='d' ||
                    input[0]=='p' && input[1]=='q'){
                output.append("Mirrored pair\n");
            }else{
                output.append("Ordinary pair\n");
            }
        }
    }while(!input.empty());
    std::cout << output;
    return 0;
}
