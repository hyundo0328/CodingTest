#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> answer;

void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        answer.push_back({from, to});
        return ;
    }
    hanoi(n - 1, from, aux, to);
    hanoi(1, from, to, aux);
    hanoi(n - 1, aux, to, from);
}

vector<vector<int>> solution(int n) {
    hanoi(n, 1, 3, 2);
    
    return answer;
}