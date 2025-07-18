#include <stdio.h>

int string_lenght(const char* str)
{
    int lenght = 0;
    while(str[lenght] != '\0')
    {
        lenght++;
    }
    return lenght;
}

int count_numbers(const char* str)
{
    int count = 1;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ',')
        {
            count++;
        }
    }
    return count;
}

int convert_string_to_int(const char* str, int start, int end)
{
    int result = 0;
    for(int i = start; i <= end; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            result = result * 10 + (str[i] - '0');
        }
    }
    return result;
}

void string_to_int_array(const char* str, int* arr, int size)
{
    int start = 0;
    int arr_index = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ',')
        {
            arr[arr_index++] = convert_string_to_int(str, start, i - 1);
            start = i + 1;
        }
    }
    arr[arr_index] = convert_string_to_int(str, start, string_lenght(str) - 1);
}

void merge(int* result, int left, int mid, int right);

void merge_short(int* result, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        merge_short(result, left, mid);
        merge_short(result, mid + 1, right);
        merge(result, left, mid, right);
    }
}

void merge(int* result, int left, int mid, int right)
{
    int temp[right - left + 1];
    int i = left;
    int j = mid + 1;
    int k = 0;
    while(i <= mid && j <= right)
    {
        if(result[i] < result[j])
        {
            temp[k++] = result[i++];
        }
        else
        {
            temp[k++] = result[j++];
        }
    }
    while(i <= mid)
    {
        temp[k++] = result[i++];   
    }
    while(j <= right)
    {
        temp[k++] = result[j++];
    }
    for(int i = left, k = 0; i <= right; i++, k++)
    {
        result[i] = temp[k];
    }
}

void print_int_array(int* arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    char str[] = "10,15,85,52,45,78,258,879,654,123";
    int num_count = count_numbers(str);
    int numbers[num_count];

    string_to_int_array(str, numbers, num_count);

    printf("Original numbers:\n");
    print_int_array(numbers, num_count);

    merge_short(numbers, 0, num_count - 1);

    printf("Sorted numbers:\n");
    print_int_array(numbers, num_count);

    return 0;
}