#include <bits/stdc++.h>
using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    
    long long tmp = n;
    
    while(tmp > 0){
        answer.push_back(tmp%10);
        tmp =  tmp / 10;
    }
    
    return answer;
}