#include <stdio.h>

int main(){
    int a[9], max, count;
    
    for(int i=0; i<9; i++){
        scanf("%d", &a[i]);
    }
    max = a[0];
    count = 1;
    for(int i=1; i<9; i++){
        if(a[i]>max){
            max = a[i];
            count = i+1;
        }
    }
    printf("%d\n", max);
    printf("%d", count);
    
    return 0;
}