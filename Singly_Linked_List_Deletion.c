#include<stdio.h>
#include<stdlib.h>
struct Node		//structure of the list
{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node * ptr)	// This function prints contents of linked list starting from the given node
{
    while(ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * deleteAtFirst(struct Node * head)
{
    struct Node * ptr = head;		//this node points to the head of the list
    head = head->next;			//making the head point to next
    free(ptr);				//freeing the pointer
    return head;			//returning the head
}

struct Node * deleteAtIndex(struct Node * head, int index)
{
    struct Node * p = head;		//this node points to the head of the list
    struct Node * q = head->next;	//this node points to the next of head of the list
    for(int i = 0; i < index-1; i++)	//traversing the pointers uptill the index
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;		//making the previous pointer point to the next node skipping the current node
    free(q);			//freeing the pointer
    return head;		//returning the head
}

struct Node * deleteAtLast(struct Node * head)
{
    struct Node * p = head;		//this node points to the head of the list
    struct Node * q = head->next;	//this node points to the next of head of the list
    while(q->next != NULL)		//traversing the pointers uptil the end
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;		//making the new node point and link to NULL
    free(q);			//freeing the pointer
    return head;		//returning the head
}
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

    printf("Traversal Before Deletion\n");
    linkedListTraversal(head);

    printf("Traversal after deletion at first\n");
    head = deleteAtFirst(head);
    linkedListTraversal(head);

    printf("Traversal after deletion at index\n");
    head = deleteAtIndex(head, 1);
    linkedListTraversal(head);

    printf("Traversal after deletion at last\n");
    head = deleteAtLast(head);
    linkedListTraversal(head);
    return 0;
}
