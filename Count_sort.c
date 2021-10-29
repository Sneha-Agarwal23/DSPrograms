#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void printArray(int A[], int n)		//Function used to print the array
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int maximum(int A[], int n)		//This function finds the maximum element of the passed array and returns it.
{
    int max = A[0];
    for(int i = 0; i < n; i++)
    {
        if(max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}
void countSort(int A[], int n)		//This function sorts the array
{
    int i, j;
    int max = maximum(A, n);		//The maximum element of the array is found     {2,6,4,8}
    int count[max + 1];   //count array     {0,0,1,0,2,0,3,0,4}
    for(i = 0; i < max+1; i++)
    {
        count[i] = 0;		//The count array is filled with blanks.
    }
    for(i = 0; i < n; i++)		//Modify the count array such that each element at each index stores the sum of previous counts.
    {
        count[A[i]] = count[A[i]] + 1;		//The modified count array indicates the position of each object in the output sequence.
    }
    i = 0;      //counter for count array
    j = 0;      //counter for given array
    while(i <= max)
    {
        if(count[i] > 0)			//Output each object from the input sequence followed by decreasing its count by 1.
        {
            A[j] = i;       //{1,2,3,4}
            count[i] = count[i] - 1;        //{2,4,6,8}
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int A[] = {9,14,2,11,6,23};
    int n = 6;
    printf("Before Sorting: \n");
    printArray(A, n);
    countSort(A, n);
    printf("After Sorting: \n");
    printArray(A, n);
    return 0;

}
