#include <bits/stdc++.h>
using namespace std;

int arr[1000000];
int ans[1000000];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i=0; i<n; i++) cin >> arr[i];

  stack<int> st;
  for(int i=n-1; i>=0; i--){
    while(!st.empty() && arr[i] >= st.top()) st.pop();
    if(!st.empty()) ans[i] = st.top();
    else ans[i] = -1;

    st.push(arr[i]);
  }

  for(int i=0; i<n; i++) cout << ans[i] << ' ';
}