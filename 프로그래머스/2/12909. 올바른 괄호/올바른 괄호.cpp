#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    stack<char> st;
    
    for(auto word:s){
        if(st.empty()){
            st.push(word);
            continue;
        }
        if(word == '('){
            st.push(word);
        } else {
            st.pop();
        }
    }
    
    if(st.empty()){
        return true;
    } else {
        return false;
    }
}