#include <bits/stdc++.h>
using namespace std;

int arr[100][100];

int dr[13][4] = {
  {0,0,0,0},
  {0,0,1,1},
  {0,0,0,1},
  {0,0,0,1},
  {0,0,1,1},
  {0,1,2,3},
  {0,1,1,2},
  {0,1,2,2},
  {0,1,1,1},
  {0,0,1,2},
  {0,1,1,2},
  {0,1,1,1},
  {0,1,1,2}
};
int dc[13][4] = {
  {0,1,2,3},
  {0,1,1,2},
  {0,1,2,2},
  {0,1,2,1},
  {0,1,0,1},
  {0,0,0,0},
  {1,1,0,0},
  {1,1,1,0},
  {0,0,1,2},
  {0,1,0,0},
  {1,0,1,1},
  {1,0,1,2},
  {0,0,1,0}
};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  while(true){
    int n;
    cin >> n;
    if(n == 0) break;

    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cin >> arr[i][j];
      }
    }

    int res = -10000000;

    for(int k=0; k<13; k++){
      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          bool flag = false;
          int tmp = 0;

          for(int w=0; w<4; w++){
            int r = i + dr[k][w];
            int c = j + dc[k][w];

            if(r<0 || r>=n || c<0 || c>=n){
              flag = true;
              break;
            }

            tmp += arr[r][c];
          }
          if(flag) break;
          res = max(res, tmp);
        }
      }
    }

    cout << T << ". " << res << "\n";
    T++;
  }
}
