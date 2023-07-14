// Given  an array, print the Next Greater
// Element for every element.
#include <stdio.h>

void FindGreatestNumber(int arr[], int n)
{
    int check, i, j;
    for (i = 0; i < n; i++) {
        check = -1;
        for (j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) { 
                check = arr[j];
                break;
            }
        }
        printf("%d --> %d/n", arr[i], check);
    }
}
int main()
{
    int arr[12] ={34,34,5,6,3,34,56,7,8};
    int n = sizeof(arr) / sizeof(arr[0]);
    FindGreatestNumber(arr, n);
    return 0;
}