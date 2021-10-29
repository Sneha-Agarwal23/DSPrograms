#include<stdio.h>
void display(int arr[], int n)		//helping function used to print the array
{
    for(int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int indInsertion(int arr[], int size, int element, int capacity, int index)    //this function inserts the element to the desired index in the given array
{
    if(size >= capacity)		//checking if the array has space left
    {
        return -1;
    }
    for(int i = size - 1; i >= index; i--)     //iterating from the last element up to the index in a reverse loop(control variable decremented)
    {
        arr[i+1] = arr[i];			//the elements are moved to their simultaneous locations one position ahead of their current positions
    }
    arr[index] = element;		//the space created at the index due to this movement is then filled by the inserted element.
    return 1;
}

int main()
{
    int arr[100] = {7,9,3,5,21,75};

    int size = 6, element = 15, index = 4;

    printf("Array Before Insertion: \n");
    display(arr, size);

    indInsertion(arr, size, element, 100, index);
    size += 1;		//incrementing value of size due to insertion.

    printf("Array After Insertion: \n");
    display(arr, size);
    return 0;
}
