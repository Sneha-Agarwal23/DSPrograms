#include<stdio.h>
#include<stdlib.h>
struct Node		//structure of the list
{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* N1)		// This function prints contents of linked list starting from the given node
{
    struct Node* ptr = N1;
    do{
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr != N1);
}

struct Node * insertAtFirst(struct Node* N1, int data)
{
    struct Node* ptr = (struct Node *)malloc(sizeof(struct Node));	//creating memory space
    ptr->data = data;		//inserting data in the list
    struct Node *p = N1-> next;		//this node points to the next node of the list
    while(p->next != N1)		//traversing the pointer
    {
        p = p->next;
    }
    p->next = ptr;		//inserting the node in the list
    ptr->next = N1;		//linking the new node to its next node
    N1 = ptr;			//making the new head
    return N1;			//returning the head
}

struct Node * insertAtEnd(struct Node* N1, int data)
{
    struct Node* ptr = (struct Node *)malloc(sizeof(struct Node));	//creating memory space
    ptr->data = data;		//inserting data in the node
    struct Node *p = N1;	//this node points to the head of the list
    while(p->next != N1)	//traversing the pointer
    {
        p = p->next;
    }
    p->next = ptr;	//inserting the node in the list
    ptr->next = N1;	//linking the new node to its next node
    return N1;	//returning the head
}

struct Node * insertAtIndex(struct Node* N1, int data, int index)
{
    struct Node* ptr = (struct Node *)malloc(sizeof(struct Node));	//creating memory space
    ptr->data = data;		//inserting data in the node
    struct Node *p = N1;	//this node points to the head of the list
    int i = 0;
    while(i != index - 1)	//traversing the pointer until the index
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;	//linking the new node to its next node
    p->next = ptr;	//linking the new node to its previous node
    return N1;		//returning the head
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

    N1->data = 10;
    N1->next = N2;

    N2->data = 20;
    N2->next = N3;

    N3->data = 30;
    N3->next = N4;

    N4->data = 40;
    N4->next = N1;

    printf("\nTraversal Before Any Insertion\n");
    linkedListTraversal(N1);

    N1 = insertAtFirst(N1, 5);
    printf("\nTraversal after insertion at beginning\n");
    linkedListTraversal(N1);

    printf("\nTraversal after insertion at end\n");
    N1 = insertAtEnd(N1, 50);
    linkedListTraversal(N1);

    printf("\nTraversal after insertion at an index\n");
    N1 = insertAtIndex(N1, 25, 3);
    linkedListTraversal(N1);

    return 0;
}

