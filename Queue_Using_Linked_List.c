#include<stdio.h>
#include<stdlib.h>

struct Node     //defining queue structure
{
    int data;
    struct Node * next;
};

struct Node * front = NULL;   //defined globally to use in all functions
struct Node * rear = NULL;

void linkedlistTraversal()    //used for displaying the elements
{
    struct Node * ptr = front;  //creating a pointer to point at the front of a queue
    if(front == NULL)      //condition for underflow
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        while(ptr != NULL)    //the loop runs until all elements of queue have been traversed
        {
            printf("Element : %d\n", ptr->data);   //printing the elements
            ptr = ptr->next;  //incrementing the value of pointer
        }
    }
}

void enqueue(int val)   //this function inserts the element in a queue
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));  //creating an empty node in memory space
    if(ptr == NULL)   //condition for a full queue
    {
        printf("Queue is FULL\n");
    }
    else
    {
        ptr->data = val;  //storing the data in queue
        if(front == NULL)  //special condition for the first element in queue
        {
            front = rear = ptr;   //changing the values of front and rear to the first element
            front->next = NULL;   //making the next of both front and rear point to NULL
            rear->next = NULL;
        }
        else
        {
            rear->next = ptr;    //for all other elements
            rear = ptr;       //changing the value of rear to pointer
            rear->next = NULL;    // making the next of rear to NULL
        }

    }
}

void dequeue()    //this function deletes the element in a queue
{
    struct Node * ptr = front;   // This pointer points to the front of the queue
    if(front == NULL)           //condition for underflow
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Deleted Element : %d\n", ptr->data);        //printing the deleted element
        front = front->next;        //making front point to its next value
        free(ptr);                  //freeing the pointer
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    linkedlistTraversal();
    dequeue();
    printf("Queue after deletion:\n");
    linkedlistTraversal();
    return 0;
}
