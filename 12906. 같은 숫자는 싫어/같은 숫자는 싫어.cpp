#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    for(auto num:arr){
        if(answer.size() == 0) {
            answer.push_back(num);
            continue;
        }
        
        if(answer.back() == num) {
            continue;
        } else {
            answer.push_back(num);    
        }
        
    }

    return answer;
}