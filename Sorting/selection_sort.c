#include <stdio.h>

/*

Explanation: https://en.wikipedia.org/wiki/Selection_sort

Time Complexity:
Worst Case: O(n^2)
Best Case: O(n^2)

*/

void selection_sort(int *arr, int n, char order)
{
    // increasing order
    if (order == 'i')
    {
        for (int i = 0; i < n - 1; i++) {
            int min = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min])
                    min = j;
            }
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    // decreasing order
    else if(order == 'd') {

        for (int i = 0; i < n - 1; i++) {
            int max = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[max])
                    max = j;
            }
            int temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
        }

    }

}

int main()
{
    int a[5] = {4, 5, 1, 9, 3};
    selection_sort(a, 5, 'd');
    return 0;
}