#include <stdio.h>


/*

Explanation: https://www.programiz.com/dsa/bubble-sort

Best Case: O(n)
Worst Case: O(n^2)
Average Case: O(n^2)

*/

void bubble_sort(int *arr, int size, char order)
{

    if (order == 'i')
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
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
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}

int main()
{
    int a[5] = {4, 5, 1, 9, 3};
    bubble_sort(a, 5, 'i');
    return 0;
}