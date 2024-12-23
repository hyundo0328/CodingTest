#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[9];
bool isUsed[9];
int num_arr[9];

void func(int num){
  if(num == m){
    for(int i=0; i<m; i++){
      cout << arr[i] << ' ';
    }

    cout << '\n';
    return;
  }

  for(int i=1; i<=n; i++){
    if(!isUsed[i]){
      arr[num] = num_arr[i];
      isUsed[i] = 1;

      func(num+1);

      isUsed[i] = 0;
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i=1;i<=n;i++){
    cin >> num_arr[i];
  }
  sort(num_arr+1, num_arr+n+1);
  func(0);
}