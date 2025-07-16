#include <stdio.h>
int main(){
    int a[10]={10,2,8,4,25,789,351,984,654,123};
    int length =sizeof(a)/sizeof(int);
    
    for(int i=0;i<length-1;i++){
        int min_number =i;
        for(int j=i+1;j<length;j++)
        {
            if(a[j]<a[min_number]){
                min_number = j;
            }
            
        }

        if(min_number !=i){
            int temp =a[i];
            a[i] =a[min_number];
            a[min_number]=temp;
        }
    }
    for(int i=0;i<length;i++){
        printf("a[%d] = %d\n",i,a[i]);
    }
}