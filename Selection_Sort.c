#include<stdio.h>

void printArray(int A[], int n)   //function for printing the array
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int A[], int n)   //this function gives us the sorted array
{
    int i, j, temp, index;       //index is the variable used to store the minimum position
    for(i = 0; i < n - 1; i++)
    {
        index = i;      //taking the value of index to the unsorted start of the array
        for(j = i + 1; j < n; j++)    //finding the minimum element
        {
            if(A[j] < A[index])      //comparing all elements with the index element
            {
                index = j;      //smallest element(unsorted) position is stored in index
            }
        }
        temp = A[i];
        A[i] = A[index];       //swapping to put the minimum element at the minimum position which is stored in i in each iteration
        A[index] = temp;
    }
}

int main()
{
    int A[] = {12, 54, 65, 7, 23, 9, 11};
    int n = 7;
    printArray(A, n);
    printf("After Sorting:\n");
    selectionSort(A, n);
    printArray(A, n);
    return 0;
}

