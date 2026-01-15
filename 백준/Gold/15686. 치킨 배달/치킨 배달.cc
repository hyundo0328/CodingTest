#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[52][52];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int permute(){
  int ans = INT_MAX;
  vector<int> permutation(chicken.size(), 1);
  fill(permutation.begin(), permutation.end() - m, 0);
  do{
    int dis = 0;
    for(auto h:house){
      int tmp = INT_MAX;
      for(int i=0; i<permutation.size(); i++){
        if(permutation.at(i) == 0) continue;

        int chic = abs(chicken[i].first - h.first) + abs(chicken[i].second - h.second);
        tmp = min(tmp, chic);
      }
      dis += tmp;
    }
    ans = min(ans, dis);
  } while(next_permutation(permutation.begin(), permutation.end()));

  return ans;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> board[i][j];
      if(board[i][j] == 1) house.push_back({i, j});
      if(board[i][j] == 2) chicken.push_back({i, j});
    }
  }

  cout << permute();
}