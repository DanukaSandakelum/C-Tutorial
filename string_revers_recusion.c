#include<stdio.h>
int strlenght(const char* str)
{
    int length = 0;
    while(str[length])
    {
        length++;
    }
    return length;
}
void reverse_string(char* str , int start, int end)
{
    if(start >=end)
    {
        return;
    }
    char temp = str[start];
    temp =str[start];
    str[start] = str [end];
    str[end] =temp;
    reverse_string(str, start +1,end -1);
}
int main()
{
    char arr1[] ="Danuka";
    int length = strlenght(arr1);
    reverse_string(arr1,0, length-1);
    printf("Reversed string: %s\n", arr1);
    return 0;
}

