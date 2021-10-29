#include<stdio.h>
#include<stdlib.h>

struct node	//Represents a node of binary tree  
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;	//points to the root of binary tree  

struct node* createNode(int data)	//function will create a new node 
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));		//creating memory space
    newNode->data=data;		//Assigning data to newNode, set left and right children to NULL  
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;		//adds the node to the tree
}

struct node * search(struct node * root, int key)	//function will search for the particular node in the binary tree  
{
    if(root == NULL)	//Checking whether tree is empty  
    {
        return NULL;
    }
    else
    {
        if(key == root->data)	//If value is found in the given binary tree then position is returned  
        {
            return root;
        }
        else if(key < root->data)	//Search in left subtree  
        {
            return search(root->left, key);
        }
        else		//Search in right subtree  
        {
            return search(root->right, key);
        }
    }
}

int main()
{
    root=createNode(9);		//Adding nodes to the binary tree  
    root->left=createNode(4);
    root->right = createNode(11);
    root->left->left = createNode(2);
    root->left->right = createNode(7);
    root->right->left = createNode(8);
    root->right->right = createNode(14);

    struct node * n = search(root, 11);
    if(n != NULL)
    {
        printf("Found : %d", n->data);
    }
    else
    {
        printf("Element not found\n");
    }
    return 0;
}
