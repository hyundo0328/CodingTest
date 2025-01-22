#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    int count = nums.size()/2;
    set<int> s;
    for(auto num:nums){
        s.insert(num);
    }
    
    if(s.size() > count){
        return count;
    } else {
        return s.size();
    }
}