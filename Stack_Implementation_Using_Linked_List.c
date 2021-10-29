#include<stdio.h>
#include<stdlib.h>

struct Node
{		            //structure of the stack
    int data;
    struct Node * next;
};

struct Node* top = NULL;	//pointer pointing to the start of stack

void linkedListTraversal(struct Node *ptr)		//function to display(traverse) through the list
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node* top)		//checks if stack is underflowing
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node* top)		//checks if stack is overflown
{
    struct Node* p = (struct Node*)malloc(sizeof(struct Node)); 	//a test node is created just to see if space is available or not
    if(p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node* push(struct Node* top, int x)		//calling push function inserts elements in the stack
{
    if(isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node* n = (struct Node*) malloc(sizeof(struct Node));		//new node is created
        n->data = x;		//data is inserted to the node
        n->next = top;
        top = n;		//the value of top is incremented after insertion
        return top;		//it returns the pointer pointing to the new position after insertion
    }
}

int pop(struct Node* tp)	//calling pop function deletes elements from stack
{
    if(isEmpty(tp))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node* n = tp;		//creating a node to access the top element of stack
        top = (tp)->next;		//making the top pointer point to its next element
        int x = n->data;		//extracting data from node
        free(n);			//freeing the memory space
        return x;			//it returns the popped element
    }
}

int main(){
    top = push(top, 15);
    top = push(top, 30);
    top = push(top, 60);

    linkedListTraversal(top);

    int element = pop(top);
    printf("Popped element is %d\n", element);
    printf("After popping the element,the traversal is: \n");
    linkedListTraversal(top);
    return 0;
}
