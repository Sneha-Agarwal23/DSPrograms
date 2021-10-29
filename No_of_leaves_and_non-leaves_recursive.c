#include<stdio.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node* createNode(int data)      //creating new nodes to link and create the tree
{
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));    //creating new node
    n->data = data;       //inserting data in node
    n->left = NULL;       //setting the left pointer to NULL
    n->right = NULL;   //setting the right pointer to NULL
    return n;
}

int countLeaves(struct node * root)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        return countLeaves(root->left) + countLeaves(root->right);
    }
}

int countnonLeaves(struct node * root)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root->left == NULL && root->right == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + countnonLeaves(root->left) + countnonLeaves(root->right);
    }
}

int main()
{
    struct node* p = createNode(2);
    p->left = createNode(4);
    p->right = createNode(6);
    p->left->left = createNode(8);
    p->left->right = createNode(10);
    p->right->left = createNode(12);
    p->right->right = createNode(24);

    int l = countLeaves(p);
    int n = countnonLeaves(p);
    printf("The Number of Leaves is = %d\n", l);
    printf("The Number of Non-Leaves is = %d", n);
    return 0;
}
