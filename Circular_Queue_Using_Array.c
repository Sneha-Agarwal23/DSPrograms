#include<stdio.h>
#define SIZE 10 //defining a macro of size 10

int queue[SIZE];
int rear = -1;//defined globally for use in all functions
int front = -1;

void enqueue(int n)     //this function is used to insert data in the queue
{
    if((rear + 1)% SIZE == front)       //condition of overflow
    {
        printf("Queue Overflow!\n");
    }
    if(front == -1 && rear == -1)       //special case condition for the first element in the queue
    {
        front++;        //incrementing front to 0
        rear = 0;       //incrementing rear to 0
    }
    else
    {
        if(rear == SIZE - 1)        //special condition to flip the value of rear at the end of the queue to form a circle
            rear = 0;
        else
            rear++;         //linear increment for rest of the elements
    }
    queue[rear] = n;        //inserting the element in queue
}

void dequeue()      //this function is used to delete data in the queue
{
    if(front == -1 && rear == -1)           //condition for underflow
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        printf("Element Deleted : %d\n", queue[front]); //printing the deleted element
        front = (front + 1)% SIZE;          // incrementing front to its new value
    }
}

void get_top()      //this function is used to get the topmost element
{
    printf("Topmost Element: %d\n", queue[front]);      //printing the topmost element
}

void display()      //this function displays the entire queue
{
    int i = front;
    if(front == -1 && rear == -1)
    {
        printf("Queue Underflow!\n");       //condition for underflow
    }
    else
    {
        printf("Displaying Queue:\n");
        while(i <= rear)     //loop runs from front till rear
        {
            printf("%d\n", queue[i]);   //printing the queue elements
            i = (i + 1)% SIZE;    //updating the value of i in a circular manner
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
