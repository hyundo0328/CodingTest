#include <bits/stdc++.h>
using namespace std;

vector<int> vec;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i=0; i<n; i++){
    int num; cin >> num;
    vec.push_back(num);
  }

  sort(vec.begin(), vec.end());

  cin >> n;
  for(int i=0; i<n; i++){
    int num; cin >> num;
    cout << binary_search(vec.begin(), vec.end(), num) << '\n';
  }
}