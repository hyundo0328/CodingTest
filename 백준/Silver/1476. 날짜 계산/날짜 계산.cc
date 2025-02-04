#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int e, s, m; // e: 지구(1 <= e <= 15), s: 태양(1 <= s <= 28), m: 달(1 <= m <= 19)
  cin >> e >> s >> m;
  
  int year = 1;
  while(1){
    if((year-e)%15 == 0 && (year-s)%28==0 && (year-m)%19 == 0){
      break;
    } else {
      year++;
    }
  }
  
  cout << year << "\n";
  
  return 0;
}