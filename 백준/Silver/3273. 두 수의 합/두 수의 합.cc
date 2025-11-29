#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[100002];
	int n; cin >> n;

	for(int i=0; i<n; i++) cin >> arr[i];
	sort(arr, arr+n);

	int num; cin >> num;

	int st = 0, end = n-1;

	int count = 0;
	while(st < end){
		if(arr[st] + arr[end] < num) st++;
		else if(arr[st] + arr[end] > num) end--;
		else if(arr[st] + arr[end] == num){
			count++;
			st++;
		}
	}

	cout << count;
}