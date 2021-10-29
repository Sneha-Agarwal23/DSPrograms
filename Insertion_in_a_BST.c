#include<stdio.h>
#include<stdlib.h>

struct node	//Represents a node of binary tree  
{
    int data;
    struct node *left;
    struct node *right;
};

struct node * newNode(int data)	//function will create a new node 
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));	//creating memory space
    temp->data=data;	//Assigning data to newNode, set left and right children to NULL  
    temp->left=NULL;
    temp->right=NULL;

    return temp;	//adds the node to the tree
}

struct node * insert(struct node * root, int key)	//function to insert a new node with given key in BST
{
    if(root == NULL)	//If the tree is empty, return a new node
    {
        return newNode(key);
    }
    if(key == root->data)	//check if same value already exists in tree
    {
        printf("Cannot insert %d, already exist in BST", key);
        return;
    }
    else if(key < root->data)	//Otherwise, recur down the tree
    {
        root->left = insert(root->left,key);

    }
    else
    {
        root->right = insert(root->right,key);

    }
    return root;	//return the (unchanged) node pointer
}

void inorder(struct node* root)		// A utility function to do inorder traversal(print) of BST
{

    if(root != NULL)
    {
        inorder(root->left);
        printf("%d\n", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct node* root = NULL;	//points to the root of binary tree  
    root = insert(root,50);	//Adding nodes to the binary tree  
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);

    inorder(root);

    return 0;
}
