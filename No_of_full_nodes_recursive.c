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

int countfullNodes(struct node * root)
{
    if(root == NULL)
    {
        return 0;
    }
    int count = 0;
    if(root->left && root->right)
    {
        count++;
    }
    count = count + (countfullNodes(root->left) + countfullNodes(root->right));

    return count;
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

    int f = countfullNodes(p);
    printf("The no of full nodes = %d", f);
    return 0;
}
