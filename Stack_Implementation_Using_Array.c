#include<stdio.h>
#include<stdlib.h>
int stack[100], ch, n, x, top, value;		//initializing the array used for stack
void push();
void pop();
int get_top();
void main()
{
    top = -1;
    printf("Stack using array menu\n");
    printf("Enter the length of the stack: \n");
    scanf("%d", &n);
    printf("\n 1.Push \n 2.Pop \n 3.Get_top \n 4.Exit\n");
    while(1)
    {
        printf("Enter your choice\n");
        scanf("%d", &ch);		//switch case is used to get commands from user for multiple operations of the stack application
        switch(ch)
        {
            case 1:
                {
                    push();		//calling push function to insert elements
                    break;
                }
            case 2:
                {
                    pop();		//calling pop function to delete elements
                    break;
                }
            case 3:
                {
                    x = get_top();		//this function gets the top element of the stack
                    printf("Topmost element = %d\n", x);
                    break;
                }
            case 4:
                {
                    printf("Exiting the program\n");
                    exit(1);
                    break;
                }
            default:
                    printf("Enter a valid choice\n");
        }
    }
}

void push()
{
    if(top >= n - 1)		//condition for overflow of stack(when the array is full)
        printf("Stack Overflow\n");
    else
    {
        printf("Enter the value you want to push\n");
        scanf("%d", &value);
        top++;		//the value of top is incremented before insertion
        stack[top] = value;		//elements are added one after the another
    }
}

void pop()
{
    if(top <= -1)		//condition for underflow
        printf("Stack Underflow! It is empty.\n");
    else
    {
        printf("Value popped = %d\n", stack[top]);	//the topmost element of stack is popped off(deleted)
        top--;
    }
}

int get_top()
{
    return stack[top];		//returns top element.
}
