#include<stdio.h>
void sum_of_numbers(int number, int* result)
{
   
   if(number ==0)
   {
        *result =0;
        return;
   }
   else{
        sum_of_numbers(number -1,result);
        *result = *result +number;
   }

}
int main()
{
    int number =10;
     int result = 0;
    printf("Sum of numbers from 0 to %d is: ", number);
    sum_of_numbers(number, &result);
    printf("%d\n", result);
}