#include<stdio.h>
#include<stdlib.h>
struct Node		//structure of the list
{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* N1)	// This function prints contents of linked list starting from the given node
{
    struct Node* ptr = N1;
    do{
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr != N1);
}

struct Node * deleteAtFirst(struct Node * head)
{
    struct Node * cur = head;	//this node points to the head of the list
    while(cur->next != head)	//traversing the pointer
    {
        cur = cur->next;
    }
    cur->next = head->next;	//eliminating the forward linkages of the node
    free(head);		//freeing the memory space
    return head;	//returning the head
}

struct Node * deleteAtEnd(struct Node * head)
{
    struct Node * cur = head;	//this node points to the head of the list
    struct Node * prev = NULL;	//this node points to Null at the start but is meant to point to the node just before the last node
    while(cur->next != head)	//traversing the pointers uptil the end
    {
        prev = cur;
        cur = cur->next;
    }
    cur->next = NULL;		//eliminating the forward linkages of the node
    prev->next = head;		//linking the second last node to the start again so as to not break the circle
    free(cur);			//freeing the memory space
    return head;		//returning the head
}

struct Node * deleteAtIndex(struct Node * head, int index)
{
    struct Node * cur = head;		//this node points to the head of the list
    struct Node * ptr = head->next;	//this node points to the next of head of the list
    for(int i = 0; i < index - 1; i++)	//traversing the pointers uptil the index
    {
        cur = cur->next;
        ptr = ptr->next;
    }
    cur->next = NULL;		//eliminating the forward linkages of the node
    cur->next = ptr->next;	//eliminating the backward linkages of the node
    free(ptr);			//freeing the memory space
    return head;		//returning the head
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

    N1->data = 11;
    N1->next = N2;

    N2->data = 22;
    N2->next = N3;

    N3->data = 33;
    N3->next = N4;

    N4->data = 44;
    N4->next = N1;

    printf("\nTraversal Before Any Deletion\n");
    linkedListTraversal(N1);

    N1 = deleteAtFirst(N1);
    printf("\nTraversal after deletion at beginning\n");
    linkedListTraversal(N2);

    printf("\nTraversal after deletion at end\n");
    N1 = deleteAtEnd(N1);
    linkedListTraversal(N1);

    printf("\nTraversal after deletion at an index\n");
    N1 = deleteAtIndex(N1, 2);
    linkedListTraversal(N1);


    return 0;
}

