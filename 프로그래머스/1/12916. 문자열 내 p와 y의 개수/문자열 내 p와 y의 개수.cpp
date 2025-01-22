#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    int count_p = 0;
    int count_y = 0;
    
    for(auto c:s){
        if(c == 'P' || c == 'p'){
            count_p++;
        } else if (c == 'Y' || c == 'y'){
            count_y++;
        }
    }
    
    if(count_p == count_y){
        return true;
    } else {
        return false;
    }
}