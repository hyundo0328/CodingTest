// 첫째 줄에 N과 X가 주어진다. (1 ≤ N, X ≤ 10,000)
// 둘째 줄에 수열 A를 이루는 정수 N개가 주어진다.
#include <stdio.h>

int main(){
    int n, x, num;
    
    scanf("%d %d", &n, &x);
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        if(num < x){
            printf("%d ", num);
        }
    }
    
    return 0;
}