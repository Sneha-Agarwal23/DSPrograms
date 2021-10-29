#include<stdio.h>
int main()
{
    int arr[10], i, n, element;
    printf("Enter the length of the array\n");
    scanf("%d", &n); 		//accepting the length of the array

    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++)		//accepting the elements of the array
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search\n");		//searched element is accepted
    scanf("%d", &element);

    for(i = 0; i < n; i++)		//standard array loop to traverse through it.
    {
        if(arr[i] == element)		//matching the searched element with each element of the array.
        {
            printf("Element %d is present\n", element);
            printf("%d is present at the location %d", element, i+1);
        }
    }
    return 0;
}
