#include <bits/stdc++.h>
using namespace std;

long long solution(long long n) {
    string str = to_string(n);
    
    for(int i = 0; i < str.size(); i++) {
        sort(str.rbegin(), str.rend());
    }
    
    return stoll(str);
}