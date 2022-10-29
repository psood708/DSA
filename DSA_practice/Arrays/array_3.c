#include <stdio.h>
#include <stdlib.h>

void min_max(int arr[], int len)
{
    int min = arr[0], max = 0;
    for (int i = 0; i < len; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    printf("Max: %d  Min: %d", max, min);
    // for 2nd largest and 2nd minimum
    int arr1[len - 2];
    for (int k = 0; k < len - 2; k++)
    {
        if (arr[k] != min || arr[k] != max)
        {
            arr1[k] = arr[k];
        }
    }
    int max1 = 0, min1 = arr1[0];
    for (int j = 0; j < len - 2; j++)
    {
        if (min1 > arr1[j])
        {
            min1 = arr1[j];
        }
        if (max1 < arr[j])
        {
            max1 = arr1[j];
        }
    }
    printf("\n2nd Max: %d  2nd Min: %d ", max1, min1);
}

int main()
{

    int arr[] = {8, 4, 6, 2, 9};
    min_max(arr, 5);
    return -1;
}