#include <stdio.h>
void mearge(int arr[] , int left, int mid, int right){
    int temp[right -left +1];
    int i =left;
    int j = mid +1; // right part of array
    int k =0;

    
    while(i<=mid && j<=right){
        if(arr[i] <arr[j])
        {
            temp[k++]= arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }


    }
    while(i<=mid){
        temp[k++]=arr[i++];

    }
    while(j<=right){
        temp[k++] =arr[j++];
    }
    for(int i=left,k=0;i<=right;i++,k++)
    {
        arr[i] =temp[k];
    }
 }

 void mearge_short(int arr[],int left , int right)
 {
    if(left <right)
    {
        int mid = (left + right )/2;
        mearge_short(arr, left, mid );
        mearge_short(arr,mid+1,right);
        mearge(arr,left,mid,right);

        
    }
 }
 void print_array(int arr[] , int lenght)
 {
    for (int i=0 ;i<lenght;i++)
    {
        printf("a[%d]=%d\n",i,arr[i]);
    }
 }
 int main()
 {
    int a[] ={10,15,85,52,45,78,258,879,654,123};
    int lenght= sizeof(a)/sizeof(int);
    mearge_short(a,0,lenght-1);
    print_array(a,lenght);
    
 }
