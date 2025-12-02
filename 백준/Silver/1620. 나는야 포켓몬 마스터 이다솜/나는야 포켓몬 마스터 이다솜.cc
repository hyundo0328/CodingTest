#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> dogam;
string arr[100005];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for(int i=1; i<=n; i++){
    cin >> arr[i];

    dogam.insert({arr[i], i});
  }

  while(m--){
    string query; cin >> query;

    // if(isdigit(query[0]))
    if('1' <= query.at(0) && query.at(0) <= '9'){
      cout << arr[stoi(query)] << '\n';
    } else {
      cout << dogam[query] << '\n';
    }
  }
}