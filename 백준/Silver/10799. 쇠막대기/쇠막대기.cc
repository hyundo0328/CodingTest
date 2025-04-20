#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<int> s;
	string str;
	cin >> str;
	
	int cnt = 0;
	for (int i=0; i<str.size(); i++){
		if (str[i] == '(' && str[i+1] == ')'){
			cnt += s.size();
			i++;
		} else if (str[i] == '('){
			s.push(i);
		} else if (str[i] == ')'){
			cnt++;
			s.pop();
		}
	}
	cout << cnt;
}