// we have to do bubble,insertion ,selection sort
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            int temp = 0;
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int k = 0; k < len; k++)
    {
        printf("%d ", arr[k]);
    }
}

void insert_sort(int arr[],int len){
   for(int i = 1;i<len;i++){
      int k = arr[i];
      int j = i-1;
      while(j>=0 && arr[j] > k){
        arr[j+1] = arr[j];
        j = j-1;
      }
      arr[j+1] = k;
   }
    for (int p = 0; p < len; p++)
    {
        printf("%d ", arr[p]);
    }
}

void select_sort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        
        int min_ele = arr[i];
        int min_idx = 0;
        int temp = 0;
        for (int j = i; j < len; j++)
        {
            if (min_ele > arr[j])
            {      
                min_ele = arr[j];
                min_idx = j;   
            }
        }
        if (min_idx > i)
        {
            
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }

    }
    for (int k = 0; k < len; k++)
    {
        printf("%d ", arr[k]);
    }
   
}

int main()
{

    int length = 6;
    int arr[] = {34,3,9,5,22,11};
    int arr1[] = {7,34,3,9,5,22,11};
    int arr2[] = {7,2,4,1,11,3};

    printf("This is Bubble Sort: ");
    bubble_sort(arr, length);
    printf("\nThis is Selection Sort: ");
    select_sort(arr1, length+1);
    printf("\nThis is Insertion Sort: ");
    select_sort(arr2, length);
    return -1;
}