#include <stdio.h>

/*

Explanation: https://en.wikipedia.org/wiki/Insertion_sort

Best Case: O(n)
Worst Case: O(n^2)
Average Case: O(n^2)


*/

void insertion_sort(int *arr, int size, char order) {

    if(order == 'i') {
        for(int i=1;i<size;i++) {
            int key = arr[i];
            int j = i-1;
            while(j>=0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
    if(order == 'd') {
        for(int i=1;i<size;i++) {
            int key = arr[i];
            int j = i-1;
            while(j>=0 && arr[j] < key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }

}

int main()
{
    int a[5] = {4, 5, 1, 9, 3};
    insertion_sort(a,5,'d');
    return 0;
}