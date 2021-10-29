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
struct node * inOrderPredecessor(struct node * root)    //to find the previous node in tree
{
    struct node * cur = root;
    while(cur && cur->left != NULL)     //looping down the tree to find leftmost leaf
    {
        cur = cur->left;
    }
    return cur;
}

/* Given it is a non empty binary tree ,return
the node with minimum key value found in that tree
Note that the entire tree need not be searched
*/

struct node * deleteNode(struct node * root, int value)     //this function deletes the value and returns the new root.
{
    if(root == NULL)        //base case for empty tree
    {
        return root;
    }
    if(value < root->data)      //if value is smaller than root's value then recur on the left side sub tree
    {
        root->left = deleteNode(root->left, value);
    }
    else if(value > root->data)     //if value is larger than root's value then recur on the right side sub tree
    {
        root->right = deleteNode(root->right, value);
    }
    else        //enters if value is equal to that of root's data
    {
        if(root->left == NULL)      //condition if node has only one child or no child
        {
            struct node * temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)        //condition if node has only one child or no child
        {
            struct node * temp = root->left;
            free(root);
            return temp;
        }
        struct node * temp = inOrderPredecessor(root->right);       //node with two children , Getting in order predecessor
        root->data = temp->data;                                    //copy the inorder predecessor's data to this current node
        root->right = deleteNode(root->right, temp->data);          //delete the successor
    }
    return root;        //return new root

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
    root = insert(root,30);
    root = insert(root,20);
    root = insert(root,40);
    root = insert(root,70);
    root = insert(root,60);
    root = insert(root,80);
    printf("Before Deletion: \n");
    inorder(root);

    printf("After Deletion of 40 \n");
    root = deleteNode(root, 40);
    inorder(root);

    return 0;
}

