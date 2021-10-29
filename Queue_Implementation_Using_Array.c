#include<stdio.h>
#define SIZE 10  //defining a macro of size 10

int queue[SIZE];
int rear = -1;  //defined globally for use in all functions
int front = -1;

void enqueue(int n)   //this function is used to insert data in the queue
{
    if(rear == SIZE - 1)  //condition of overflow
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        if(front == -1 && rear == -1) //special case condition for the first element in the queue
        {
            front++;   //incrementing front to 0
            rear++;    //incrementing rear to 0
        }
        queue[rear] = n;   //inserting data in queue
        rear++;            //incrementing rear for rest values
    }
}

void dequeue()   //this function is used to delete data in the queue
{
    if(front == -1 && rear == -1)   //condition for underflow
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        printf("Element deleted : %d\n", queue[front]);  //printing the deleted element
        front++; // incrementing front to its new value
    }
}

void get_top()  //this function is used to get the topmost element
{
    printf("Top element : %d\n",queue[front]);  //printing the topmost element
}

void display()  //this function displays the entire queue
{
    int i;
    if(front == -1 && rear == -1)   //condition for underflow
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        printf("Displaying Queue:\n");
        for(i = front; i < rear; i++)   //the loop runs from front till rear
        {
            printf("%d\n", queue[i]);
        }
    }
}

int main()
{
    enqueue(11);
    enqueue(22);
    enqueue(33);
    enqueue(44);
    dequeue();
    get_top();
    display();
    return 0;

}
