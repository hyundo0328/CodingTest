#include <bits/stdc++.h>
using namespace std;

class cmp{
public:
  bool operator() (int a, int b){
    if(abs(a) != abs(b)) return abs(a) > abs(b);
    return a>0 && b<0;
  }
};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  priority_queue<int, vector<int>, greater<int>> pq;

  int n;
  cin >> n;

  int num;
  while(n-- > 0){
    cin >> num;
    pq.push(num);
  }

  int sum = 0;
  while(pq.size() != 1){
    int a, b;
    a = pq.top(); pq.pop();
    b = pq.top(); pq.pop();
    sum += a+b;
    pq.push(a+b);
  }

  cout << sum;
}