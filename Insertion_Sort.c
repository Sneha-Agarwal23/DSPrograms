#include<stdio.h>

void printArray(int A[], int n)   //function for printing the array
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int A[], int n)   //this function gives us the sorted array
{
    int i, j, key;    //key is the element which is inserted in any position in the array
    for(i = 1; i < n; i++)
    {
        key = A[i];     //initializing the value of key in each iteration
        j = i - 1;      //j is the variable used for indexing
        while(j >= 0 && A[j] > key)    /*moving elements of array which are greater than
                                         the value of key to one position ahead of their current location*/
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;    //putting the value of key in its sorted position
    }
}

int main()
{
    int A[] = {12, 54, 65, 7, 23, 9, 11};
    int n = 7;
    printArray(A, n);
    printf("After Sorting:\n");
    insertionSort(A, n);
    printArray(A, n);
    return 0;
}
