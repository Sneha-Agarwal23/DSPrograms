#include<stdio.h>
#include<stdlib.h>

void printArray(int A[], int n)   //function for printing the array
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// Merges two sub arrays of A[].
void merge(int A[], int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];// First sub array is A[l..m]
                    // Second sub array is A[m+1..r]

    for(i = 0; i < n1; i++)// Copy data to temp arrays L[] and R[]
    {
        L[i] = A[low + i];
    }
    for(j = 0; j < n2; j++)// Copy data to temp arrays L[] and R[]
    {
        R[j] = A[mid + 1 + j];
    }

    i = 0, j = 0, k = low;// Initial index of sub arrays - i -1st,j-2nd,k- merged
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])//merging and sorting
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1)// Coping the remaining elements of L[], if there are any
    {
        A[k] = L[i];
        i++;
        k++;
    }
    while(j < n2)// Coping the remaining elements of R[], if there are any
    {
        A[k] = R[j];
        j++;
        k++;
    }

}

void mergeSort(int A[], int low, int high)//master function to dictate the sorting order
{
    if(low < high)
    {
        int mid = (low + high) / 2;//finding mid

        mergeSort(A, low, mid); // Sort first and second halves
        mergeSort(A, mid + 1, high);

        merge(A, low, mid, high);
    }
}
int main()
{
    int A[] = {2,23,9,56,12,65};
    int size = sizeof(A) / sizeof(A[0]);
    printf("Given array is \n");
    printArray(A, size);

    mergeSort(A, 0, size - 1);

    printf("\nSorted array is \n");
    printArray(A, size);
    return 0;
}

