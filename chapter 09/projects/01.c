/**********************************************************************
 * Write a program that asks the user to enter a series of integers
 * (which it stores in an array), then sorts the integers by calling
 * the function selection_sort. When given an array with n elements, 
 * selection_sort must do the following: 
 * 1. Search the array to find the largest element, then move it to 
 *    the last position in the array.
 * 2. Call itself recursively to sort the first n-1 elements of the 
 *    array
 **********************************************************************/

#include <stdio.h>

void selection_sort(int a[], int n);

int main(void)
{
    char ch;
    int i, entries = 0, a[30] = {0};
    printf("Enter a series of up to 30 integers: ");
    for (i = 0; i < 30 && (ch = getchar() != '\n'); i++) {
        scanf(" %d", &a[i]);
        entries++;
    }

    printf("Unsorted array: ");
    for (i = 0; i < entries; i++)
        printf("%d ", a[i]);

    selection_sort(a, entries);

    printf("\nSorted array: ");
    for (i = 0; i < entries; i++)
        printf("%d ", a[i]);

    return 0;
}

void selection_sort(int a[], int n)
{
    if (n == 0) return;
    
    int i, index_largest = 0;

    for (i = 1; i < n; i++) {
        if (a[i] > a[index_largest])
            index_largest = i;
    }

    int largest = a[index_largest];
    a[index_largest] = a[n-1];
    a[n-1] = largest;

    selection_sort(a, n - 1);
}
