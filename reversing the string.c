#include <stdio.h>
#include <string.h>

void PrintArray(char* arr[], int n)
{
    int i;
   {
        for ( i = 0; i < n; i++)
        printf("%s ", arr[i]);
    }
}

void ReverseArray(char* arr[], int n)
{
    char* temp;
    int i;

    // Move from begin and end. Keep
    // swapping strings.
    int j = n - 1;
    for ( i = 0; i < j; i++) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
    }
}

int main()
{
    char* arr[] = { "hi", "hello", "good", "morning" };
    int n = sizeof(arr) / sizeof(arr[0]);

    PrintArray(arr, n);

    printf("\n");

    ReverseArray(arr, n);

    PrintArray(arr, n);

    return 0;
}
