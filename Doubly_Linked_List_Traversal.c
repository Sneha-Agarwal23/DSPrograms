#include<stdio.h>
#include<stdlib.h>
struct Node		//structure of the list
{
    int data;
    struct Node* prev;
    struct Node* next;
};

void linkedListTraversal(struct Node* N1, struct Node* N4)	// This function prints contents of linked list starting from the given node
{
    struct Node* ptr = N1;		//this node points to the head
    printf("Printing values in forward direction: \n");
    while(ptr != NULL)
    {
        printf("Element is %d\n", ptr->data);	//accessing the nodal data and printing it
        ptr = ptr->next;	//making the current pointer point to the next node in the list
    }
    ptr = N4;		//making the pointer point to the tail of the doubly lined list
    printf("Printing values in backward direction: \n");	//printing the list backwards just to check the linkages
    while(ptr != NULL)
    {
        printf("Element is %d\n", ptr->data);		//accessing the nodal data and printing it
        ptr = ptr->prev;		//making the current pointer point to the previous node in the list
    }

}
int main()
{
    struct Node* N1;
    struct Node* N2;
    struct Node* N3;
    struct Node* N4;

    N1 = (struct Node *)malloc(sizeof(struct Node));
    N2 = (struct Node *)malloc(sizeof(struct Node));
    N3 = (struct Node *)malloc(sizeof(struct Node));
    N4 = (struct Node *)malloc(sizeof(struct Node));

    N1->data = 4;
    N1->next = N2;
    N1->prev = NULL;

    N2->data = 8;
    N2->next = N3;
    N2->prev = N1;

    N3->data = 12;
    N3->next = N4;
    N3->prev = N2;

    N4->data = 16;
    N4->next = NULL;
    N4->prev = N3;

    linkedListTraversal(N1, N4);
    return 0;

}
