#include <bits/stdc++.h>
using namespace std;

int n, m, member;
string group, name;

unordered_map<string, string> nameTogroup;
unordered_map<string, vector<string>> groupToname;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);


  cin >> n >> m;
  
  while(n-- > 0){
    cin >> group;
    cin >> member;
    
    for(int i=0;i<member;i++){
      cin >> name;
      nameTogroup[name] = group;
      groupToname[group].push_back(name);
    }

    sort(groupToname[group].begin(), groupToname[group].end());
  }

  string st;
  int t;
  while(m-- > 0){
    cin >> st;
    cin >> t;

    if(t == 0){
      for(auto mem : groupToname[st]){
        cout << mem << '\n';
      }
    } else {
      cout << nameTogroup[st] << '\n';
    }
  }
}