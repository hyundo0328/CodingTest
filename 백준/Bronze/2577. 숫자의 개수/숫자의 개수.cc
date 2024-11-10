#include <stdio.h>

int main(){
    int a, b, c, sum;
    int count[10] = {0,0,0,0,0,0,0,0,0,0};
    
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    sum = a*b*c;
    
    int i=0;
    while(sum>0){
        count[sum%10] += 1;
        sum /= 10;
        i++;
    }
    
    for(int i=0;i<10;i++){
        printf("%d\n",count[i]);
    }
    
    return 0;
}