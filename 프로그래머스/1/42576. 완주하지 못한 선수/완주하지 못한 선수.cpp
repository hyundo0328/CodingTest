#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    multiset<string> s;
    for(auto name:participant){
        s.insert(name);
    }
    for(auto name:completion){
        s.erase(s.find(name));
    }
    
    return *s.begin();
}