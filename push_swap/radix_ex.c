#include <stdio.h>
#include <stdlib.h>

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int *output = malloc(n * sizeof(int)); // output array
    int i, count[10] = { 0 };
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
    free(output);
}
 
// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort_(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int max = getMax(arr, n);
    int exp;
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    // for (int exp = 1; m / exp > 0; exp *= 10)
    //     countSort(arr, n, exp);
    exp = 1;
    while (max / exp > 0)
    {
        countSort(arr, n, exp);
        exp *= 10;
    }
}
 
// A utility function to print an array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
 
// Driver Code
int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2147483647, 1, 0, 36};
    int n = sizeof(arr) / sizeof(arr[0]);
     
      // Function Call
      radixsort_(arr, n);
    print(arr, n);
    return 0;
}