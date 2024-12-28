#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> vec;

  int num;
  for(int i=0;i<n;i++){
    cin >> num;
    vec.push_back(num);
  }
  sort(vec.begin(), vec.end(), greater<int>());

  for(int number:vec){
    cout << number << '\n';
  }
}