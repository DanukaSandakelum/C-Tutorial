#include<stdio.h>
int string_lenght(const char* str)
{
    int length =0;
    while(str[length])
    {
        length++;



    }
    return length;

}
void convert_string_to_int(const char* str, int index, int* result)
{
    if(str[index] == '\0')

    {
        return;
    }
    *result = *result * 10 + (str[index] - '0');
    convert_string_to_int(str, index + 1, result);
}
int main()
{
    const char* str = "56782";
    int result = 0;
    int length = string_lenght(str);
    convert_string_to_int(str, 0, &result);
    printf("integer is: %d\n", result);
    return 0;
}