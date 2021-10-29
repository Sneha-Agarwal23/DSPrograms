#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 20

struct stack		//stack structure
{
    int top;
    char arr[MAX];
}s;

int isEmpty()		//checks if stack is empty
{
    if (s.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()		//checks if stack is out of capacity or not
{
    if (s.top == (MAX - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(char val)		//function used to push the element in the stack
{
    if(isFull())
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        s.top = s.top + 1;
        s.arr[s.top] = val;
    }
}

char pop()		//function to pop the element from the stack
{
    if(isEmpty())
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        char val = s.arr[s.top];
        s.top = s.top - 1;
        return val;
    }
}

int parenthesisMatch(char  exp[])
{
    for (int i = 0; exp[i]!='\0'; i++)	//iterating through the expression characterwise
    {
        if(exp[i]=='(')		//if opening brace is encountered it is pushed in stack
        {
            push('(');
            continue;		//iteration ends but loop continues
        }
        else if(exp[i]==')')		//upon encountering closing braces in the expression the next steps are followed to match the brackets
        {
            if(s.arr[s.top] == '(')	//the top element in stack is matched with the brace type
            {
                pop();  // Pop the stack until closed bracket is found
            }
            else
            {
                return 1;
            }
        }
    }
    if(s.top == -1)
    {
        return 0;  // Finally if the stack is empty, return that the expression is balanced
    }
}
int main()
{
    char exp[] = "8 * (9)";
    if(parenthesisMatch(exp) == 0)
    {
        printf("The parenthesis is matching");
    }
    else
    {
        printf("The parenthesis is not matching");
    }
    return 0;
}
