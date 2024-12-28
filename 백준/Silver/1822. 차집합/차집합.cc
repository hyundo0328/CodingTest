#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> A;
  vector<int> B;

  int n, m;
  cin >> n >> m;

  int num;
  for(int i=0;i<n;i++){
    cin >> num;
    A.push_back(num);
  }
  sort(A.begin(),A.end());

  for(int i=0;i<m;i++){
    cin >> num;
    B.push_back(num);
  }
  sort(B.begin(),B.end());

  int count = 0;
  vector<int> ans;
  for(int number:A){
    if(!binary_search(B.begin(),B.end(),number)){
      count++;
      ans.push_back(number);
    }
  }

  cout << count << '\n';
  for(int number:ans){
    cout << number << ' ';
  }
}