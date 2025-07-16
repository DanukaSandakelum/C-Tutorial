#include <stdio.h>
void bouble(int arr[], int lenght){

    for(int i=0;i<lenght; i++)
    {

        for (int j=0; j<lenght-1; j++)
        {
            if(arr[j] >arr[j+1])
            {
                int temp =arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }

    }
}

void print_arr(int arr[], int lenght)
{
    for(int i=0;i<lenght;i++)
    {
        printf("a[%d] =%d\n", i, arr[i]);
    }
}
int main(){
    int a[]={10,2,8,4,25,789,351,984,654,123};
    int length =sizeof(a)/sizeof(int);

    printf("this is nomal array\n");
    print_arr(a,length);

    bouble(a,length);
    printf("this is bouble sort array\n");
    print_arr(a,length);
    
    return 0;
}