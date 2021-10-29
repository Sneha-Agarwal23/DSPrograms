#include<stdio.h>

void printArray(int A[], int n)   //function for printing the array
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
/* this function takes the last element as pivot, places it at its correct position in sorted array
and places all elements smaller than pivot to the left of the pivot and all greater elements to the right*/

int partition(int A[], int low, int high)
{
    int pivot = A[high];   //initializing the value of pivot
    int i = low - 1;     //index of the smaller element and indicates the right position of the pivot so far found
    int j = low;
    int temp;
    for(j = low; j <= high - 1; j++)    //loop runs from low till high
    {
        if(A[j] < pivot)    //if current element is smaller than pivot then it is swapped to the left side of the array
        {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[i+1];         //else the element are shifted/swapped to the right array
    A[i+1] = A[high];
    A[high] = temp;
    return (i + 1);      //returning the next pivot
}

void quickSort(int A[], int low, int high) //this function is used to divide the array into two sub arrays
{
    if(low < high)
    {
        int partionIndex = partition(A, low, high);   //partition index, A[partition Index] is now at its sorted place

        quickSort(A, low, partionIndex - 1);    //sorting left sub array

        quickSort(A, partionIndex + 1, high);    //sorting right sub array

    }
}

int main()
{
    int A[] = {12, 54, 65, 7, 23, 9};
    int n = 6;
    printArray(A, n);
    printf("After Sorting:\n");
    quickSort(A, 0, n);
    printArray(A, n);
    return 0;
}
