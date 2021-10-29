#include<stdio.h>
#include<stdlib.h>
struct node       //initialization of the structure
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data)      //creating new nodes to link and create the tree
{
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));    //creating new node
    n->data = data;       //inserting data in node
    n->left = NULL;       //setting the left pointer to NULL
    n->right = NULL;      //setting the right pointer to NULL
}

void preOrder(struct node* root)     //preorder traversal
{
    if(root != NULL)      //if the pointer is not pointing to NULL
    {
        printf("%d\n", root->data);    //accessing the data


        preOrder(root->left);          //recurring on the left side of the root


        preOrder(root->right);         //recurring on the right side of the root
    }
}

void postOrder(struct node* root)    //postorder traversal
{
    if(root != NULL)            //if the pointer is not pointing to NULL
    {
        postOrder(root->left);      //recurring on the left side of the root


        postOrder(root->right);     //recurring on the right side of the root


        printf("%d\n", root->data);  //accessing the data
    }
}

void inOrder(struct node* root)     //inorder traversal
{
    if(root != NULL)            //if the pointer is not pointing to NULL
    {
        inOrder(root->left);        //recurring on the left side of the root


        printf("%d\n", root->data);     //accessing the data


        inOrder(root->right);       //recurring on the right side of the root
    }
}

int main()
{
    struct node* p = createNode(10);
    p->left = createNode(20);
    p->right = createNode(30);
    p->left->left = createNode(40);
    p->left->right = createNode(50);
    p->right->right = createNode(60);
    p->right->left = createNode(70);


    printf("PreOrder Traversal: \n");
    preOrder(p);


    printf("PostOrder Traversal: \n");
    postOrder(p);


    printf("InOrder Traversal: \n");
    inOrder(p);


    return 0;
}

