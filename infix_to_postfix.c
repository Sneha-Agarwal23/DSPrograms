#include<stdio.h>
#include<stdlib.h>      // for exit()
#include<ctype.h>     // for is digit(char )
#include<string.h>

#define SIZE 100


// declared here as global variable because stack[] is used by more than one functions
char stack[SIZE];
int top = -1;

void push(char item)        // define push operation
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}


char pop()       //pop operation
{
	char item ;

	if(top == -1)
	{
		printf("stack under flow: invalid infix expression");       // underflow may occur for invalid expression  where ( and ) are not matched
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}

/* This function is used to determine whether any symbol is operator or not
(that is symbol is operand)
* this function returns 1 if symbol is operator else return 0 */

int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
        return 0;
	}
}

/* The function is used to assign precedence to operator.
* In this function we assume that higher integer value
* means higher precedence */

int precedence(char symbol)
{
	if(symbol == '^')   // exponent operator, highest precedence
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          // lowest precedence
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
	int i, j;
	char item;
	char x;

	push('(');                               // push '(' onto stack in the start
	strcat(infix_exp,")");                  // add ')' to infix expression

	i = 0;
	j = 0;
	item = infix_exp[i];         // initialize before loop

	while(item != '\0')        // run loop till end of infix expression
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item;              // add operand symbol to postfix expression
			j++;
		}
		else if(is_operator(item) == 1)        // means symbol is operator
		{
			x = pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix_exp[j] = x;                  //pop all higher precedence operator
				j++;
				x = pop();                       // add them to postfix expression
			}
			push(x);
			/* because just above while loop will terminate we have
			popped one extra item
			for which condition fails and loop terminates */

			push(item);                 // push current operator symbol onto stack
		}
		else if(item == ')')         // if current symbol is ')' then
		{
			x = pop();                   // pop and keep popping until '(' encountered
			while(x != '(')
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else        // if current symbol is neither operand not '(' nor ')' and nor operator
		{
			printf("\nInvalid infix Expression.\n");        // the it is illegal  symbol
			exit(1);
		}
		i++;


		item = infix_exp[i];    // go to next symbol of infix expression
	}   // while loop ends here
	if(top > 0)
	{
		printf("\nInvalid infix Expression.\n");        // the it is illegal  symbol
		exit(1);
	}
	postfix_exp[j] = '\0'; // add blank to the end so that the print can occur smoothly

}

/* This program converts infix expression to postfix expression.
 * This program assume that there are Five operators: (*, /, +, -,^)
	in infix expression and operands can be of single-digit only.
 * This program will not work for fractional numbers.
 * Further this program does not check whether infix expression is
 valid or not in terms of number of operators and operands.*/

int main()
{
	char infix[SIZE], postfix[SIZE];         // declare infix string and postfix string

	printf("\nEnter Infix expression : ");
	gets(infix);

	InfixToPostfix(infix,postfix);                   // call to convert
	printf("Postfix Expression: ");
	puts(postfix);                     // print postfix expression

	return 0;
}
