#include<stdio.h>

struct node	//Represents a node of binary tree  
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data)	//function will create a new node 
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));	//creating memory space
    newNode->data=data;		//Assigning data to newNode, set left and right children to NULL
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;	//adds the node to the tree
}
int max(int a,int b)	//returns maximum of two integers
{
    if(a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

/*  The function Compute the "height" of a tree. Height is the
    number of nodes along the longest path from the root node
    down to the farthest leaf node.*/

int height(struct node* root)
{
    if(root == NULL)	//base case tree is empty 
        return 0;

    return 1 + max(height(root->left),height(root->right));	//If tree is not empty then height = 1 + max of left height and right heights
}

int isBst(struct node* root)	//Returns true if binary tree is height-balance
{
    int leftheight;	//for height of left subtree
    int rightheight;	//for height of right subtree

    if(root == NULL)	//If tree is empty then return true as empty tree is also a bst
    {
        return 1;
    }

    leftheight = height(root->left);	//Getting the height of left and right sub trees
    rightheight = height(root->right);

    if(abs(leftheight - rightheight) <= 1 && isBst(root->left) && isBst(root->right))		//checking the condition for BST
        return 1;

    return 0;		//If we reach here then tree is not height-balanced and it returns false.
}

int main()
{
    struct node* root=createNode(9);	//root pointer points to the root of binary tree  
    root->left=createNode(4);		//Adding nodes to the binary tree 
    root->right = createNode(11);
    root->left->left = createNode(2);
    root->left->left->left = createNode(9);
    root->left->right = createNode(7);
    root->right->left = createNode(8);
    root->right->right = createNode(14);

    if(isBst(root)== 1)		//checking the result of the function call.
    {
        printf("Tree is Balanced and is a BST");
    }
    else
    {
        printf("Unbalanced tree");
    }

    return 0;
}


