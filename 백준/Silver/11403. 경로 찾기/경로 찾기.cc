#include <bits/stdc++.h>
using namespace std;

int n;
int arr[102][102];
bool visited[102];

void dfs(int v) {
	for (int i = 0; i < n; i++) {
		if (!visited[i] && arr[v][i]) {
			visited[i] = true;
			dfs(i); 
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		memset(visited, false, 102);
		dfs(i);
		for (int j = 0; j < n; j++) {
			if (visited[j]) arr[i][j] = 1;
		}
	}

  
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}