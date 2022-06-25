#include <stdio.h>


/*

Explanation: https://www.programiz.com/dsa/bubble-sort

Best Case: O(n)
Worst Case: O(n^2)
Average Case: O(n^2)

*/

void bubble_sort(float *arr, int size, char order)
{

    if (order == 'i')
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    float temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    else if (order == 'd')
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - 1; j++)
            {
                if (arr[j] < arr[j + 1])
                {
                    float temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }

            for(int k=0;k<size;k++){
                printf("%f\t",arr[k]);
            }
            printf("\n");

        }
    }
}

int main()
{
    float a[6] = {99.7,88.5,90.1,91.0,85.8,97.9};
    bubble_sort(a, 6, 'd');
    return 0;
}