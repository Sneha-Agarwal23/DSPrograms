#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *prev, *next;       //structure of list
};

struct node* start = NULL;      //this points to the start of the list

void traverse()     // Function to traverse the linked list
{
	if (start == NULL)  //Empty list condition
	{
		printf("\nList is empty\n");
		return;
	}
	struct node* temp;  // Else print the Data
	temp = start;
	while (temp != NULL)
	{
		printf("Data = %d\n", temp->data);
		temp = temp->next;
	}
}


void insertAtFront(int data)        // Function to insert at the front of the linked list
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));       //creating memory space
	temp->data = data;      //adding data to the node
	temp->prev = NULL;      //linking the new node


	temp->next = start;     // Pointer of temp will be assigned to start
	start = temp;
}


void insertAtEnd(int data)      // Function to insert at the end of the linked list
{

	struct node *temp, *trav;
	temp = (struct node*)malloc(sizeof(struct node));       //creating memory space
	temp->prev = NULL;      //linking the new node
	temp->next = NULL;
	temp->data = data;      //adding data to the node
	temp->next = NULL;
	trav = start;

	if (start == NULL)      // If list is empty
	{
		start = temp;
	}
	else
	{
		while (trav->next != NULL)  // Traversing the pointer till last
			trav = trav->next;

		temp->prev = trav;          // Changes Links
		trav->next = temp;
	}
}


void insertAtPosition(int data,int pos)     // Function to insert at any specified position in the linked list
{
	int i = 1;
	struct node *temp, *newnode;
	newnode = malloc(sizeof(struct node));      //creating memory space
	newnode->next = NULL;       //linking the new node
	newnode->prev = NULL;
	newnode->data = data;       //adding data to the node
	temp = start;


	if (start == NULL)      // If list is empty
	{
		start = newnode;
		newnode->prev = NULL;
		newnode->next = NULL;
	}


	else if (pos == 1)      // If position entered is first position
	{
		newnode->next = start;
		newnode->next->prev = newnode;
		newnode->prev = NULL;
		start = newnode;
	}


	else
	{
		while (i < pos - 1)         // Traversing the pointer till position
		{
			temp = temp->next;
			i++;
		}
		newnode->next = temp->next;     // Change links
		newnode->prev = temp;
		temp->next = newnode;
		temp->next->prev = newnode;
	}
}

int main()
{
	int choice,data,pos;
	printf("\t1 Print the list\n");
	printf("\t2 For insertion at starting\n");
    printf("\t3 For insertion at end\n");
	printf("\t4 For insertion at any position\n");
	printf("\t5 To exit\n");

	while (1)
	{

		printf("\nEnter Choice :\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			traverse();
			break;
		case 2:
		    printf("\nEnter number to be inserted: ");
	        scanf("%d", &data);
			insertAtFront(data);
			break;
		case 3:
		    printf("\nEnter number to be inserted: ");
	        scanf("%d", &data);
			insertAtEnd(data);
			break;
		case 4:
	        printf("\nEnter position : ");      // Enter the position and data
	        scanf("%d", &pos);
	        printf("\nEnter number to be inserted: ");
	        scanf("%d", &data);
			insertAtPosition(data,pos);
			break;
		case 5:
			exit(1);
			break;
		default:
			printf("Incorrect Choice. Try Again \n");
			continue;
		}
	}
	return 0;
}

