#include<stdio.h>
void display(int arr[], int n)		//helping function used to print the array
{
    for(int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

void indDeletion(int arr[], int size, int index)		//function to delete the element at the given index
{
    for(int i = index; i < size - 1; i++)		//loop runs from given index uptill end of array
    {
        arr[i] = arr[i+1];		//the space left after deletion is filled up by its next element and this goes on until the end
    }
}		//at the end there will be an empty space at the end of the array and not in the middle

int main()
{
    int arr[100] = {6,12,18,24,30,36};
    int size = 6,  index = 3;

    printf("Array Before Deletion: \n");
    display(arr, size);

    indDeletion(arr, size, index);
    size -= 1;		//decrement of size so as to avoid traversal to the empty space at last left after deletion

    printf("Array After Deletion: \n");
    display(arr, size);
    return 0;
}
