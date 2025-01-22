#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> ms;
    
    for(auto oper:operations){
        char op = oper[0];
        int num = stoi(oper.substr(2));
        
        if(op == 'I'){
            ms.insert(num);
        } else {
            if(ms.size() == 0) continue;
            if(num == 1){
                ms.erase(--ms.end());
            } else if (num == -1){
                ms.erase(ms.begin());
            }
        }
    }
    
    if(ms.size() == 0){
        return {0,0};
    } else {
        return {*--ms.end(), *ms.begin()};
    }
}