#include<stdio.h>
int main()
{
    int arr[100], n, i, element;
    printf("Enter the length of the array: \n");
    scanf("%d", &n);		//accepting the size of array
 
    printf("Enter the elements of the array: \n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);		//Accepting elements of the array
    }

    printf("Enter the element to search: \n");
    scanf("%d", &element);		// scanning the searched element

    int start = 0, end = n - 1, mid;
    while(start <= end)
    {
        mid = (start + end)/2;		//dividing the array into two parts
        if(arr[mid] == element)		//matching mid with searched element
        {
            printf("Element %d is present at the position : %d ", element, mid + 1);
            break;
        }
        else if(arr[mid] > element)	//if searched element value is lesser than mid elements value then searching takes place in the first half
        {
            end = mid - 1;		
        }
        else
        {
            start = mid + 1;		//if searched element value is greater than mid elements value then searching takes place in the later half
        }
    }
    return 0;
}
