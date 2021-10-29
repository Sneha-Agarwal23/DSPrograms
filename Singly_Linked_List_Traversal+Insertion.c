#include<stdio.h>
#include<stdlib.h>
struct Node		//structure of the list
{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node * ptr)		// This function prints contents of linked list starting from the given node
{
    while(ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertAtFirst(struct Node * head, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));		//creating memory space
    ptr->data = data;		//inserting data in the list
    ptr->next = head;		//making the next pointer point to next
    return ptr;			//returning the current pointer
}

struct Node * insertAtIndex(struct Node * head, int data, int index)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));		//creating memory space
    ptr->data = data;		//inserting data in the node
    struct Node * p = head;	//this node points to the head of the list
    int i = 0;
    while(i != index - 1)	//traversing the pointer uptill the index
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;	//making the new node point and link to the next node
    p->next = ptr;		//linking the next node
    return head;		//returning the head
}

struct Node * insertAtLast(struct Node * head, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));	//creating memory space
    ptr->data = data;		//inserting data in the node
    struct Node * p = head;	//this node points to the head of the list
    while(p->next != NULL)	//traversing the pointer uptil the current end of list
    {
        p = p->next;
    }
    p->next = ptr;		//making the new node point and link to the next node
    ptr->next = NULL;		//linking the next node to NULL
    return head;		//returning the head
}

int main()
{
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 6;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 18;
    third->next = fourth;

    fourth->data = 24;
    fourth->next = NULL;

    printf("Traversal Before Insertion\n");
    linkedListTraversal(head);

    printf("Traversal after insertion at first\n");
    head = insertAtFirst(head, 3);
    linkedListTraversal(head);

    printf("Traversal after insertion at index\n");
    head = insertAtIndex(head, 15, 3);
    linkedListTraversal(head);

    printf("Traversal after insertion at last\n");
    head = insertAtLast(head, 30);
    linkedListTraversal(head);
    return 0;
}
