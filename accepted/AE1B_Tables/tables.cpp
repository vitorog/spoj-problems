/*
 *Created by Vitor Shade
 *27/03/2013
 */

#include <iostream>
#include <list>

int main(int argc, char** argv)
{
    int num_boxes, screws_per_table, num_tables;
    std::cin >> num_boxes >> screws_per_table >> num_tables;
    std::list<int> num_screws; //Num. screws on each box
    for(int i = 0; i < num_boxes; i++){
        int n;
        std::cin >> n;
        num_screws.push_back(n);
    }
    num_screws.sort(); //Puts the highest elements on end
    int required_screws = num_tables * screws_per_table;
    int total_screws = 0;
    int total_boxes = 0;
    for(std::list<int>::reverse_iterator it = num_screws.rbegin(); it != num_screws.rend(); it++){
        total_screws += (*it);
        total_boxes++;
        if(total_screws >= required_screws){
            break;
        }
    }
    std::cout << total_boxes;
    return 0;
}
