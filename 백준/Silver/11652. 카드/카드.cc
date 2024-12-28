#include <bits/stdc++.h>
using namespace std;

long long arr[100005];
long long mxVal = LONG_LONG_MAX;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  sort(arr, arr+n);

  int cnt = 0;
  int mxCnt = 0;
  for(int i = 0; i < n; i++){
    if(i == 0 || arr[i-1] == arr[i]) cnt++;
    else{
      if(cnt > mxCnt){
        mxCnt = cnt;
        mxVal = arr[i-1];
      }
      cnt = 1;
    }
  }
  if(cnt > mxCnt) mxVal = arr[n-1];

  cout << mxVal;
}