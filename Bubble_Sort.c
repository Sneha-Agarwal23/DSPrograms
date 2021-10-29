#include<stdio.h>

void printArray(int A[], int n)   //function for printing the array
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubbleSort(int A[], int n)  //this function sorts the given array
{
    int temp;
    for(int i = 0; i < n ; i++)   //this loop accesses the element which is compared to the rest of the array
    {
        for(int j = i + 1; j < n; j++)   //this loop is used to access the elements of the array after the ith loop position
        {
            if(A[i] > A[j])   //comparing the accessed elements
            {
                temp = A[i];
                A[i] = A[j];        //steps for swapping
                A[j] = temp;
            }
        }
    }
}

int main()
{
    int A[] = {99, 67, 103, 55, 43, 72, 83};
    int n = 7;
    printArray(A, n);
    printf("After Sorting:\n");
    bubbleSort(A, n);
    printArray(A, n);
    return 0;
}
