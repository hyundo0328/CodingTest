#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> answer;
int cnt = 0;

void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
      cnt++;
      answer.push_back({from, to});
      // cout << from << " " << to << '\n';
      return;
    }

    hanoi(n - 1, from, aux, to);
    cnt++;
    answer.push_back({from, to});
    // cout << from << " " << to << '\n';
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    cin >> n;
    
    hanoi(n, 1, 3, 2);

    cout << cnt << '\n';
    for(auto ans:answer){
      cout << ans.first << " " << ans.second << '\n';
    }
    
    return 0;
}
