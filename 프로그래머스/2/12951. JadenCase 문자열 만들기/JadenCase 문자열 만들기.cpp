#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";
    
    if(s[0] >= 'a' && s[0] <= 'z'){
        answer.push_back(s[0]-32);
    } else {
        answer.push_back(s[0]);
    }
    
    for(int i=1;i<s.size();i++){
        if(s[i-1] == ' ' && 'a' <= s[i] && s[i] <= 'z'){
            answer.push_back(s[i]-32);
        } else if (s[i-1] != ' ' && 'A' <= s[i] && s[i] <= 'Z') {
            answer.push_back(s[i]+32);
        } else {
            answer.push_back(s[i]);
        }
    }
    
    return answer;
}