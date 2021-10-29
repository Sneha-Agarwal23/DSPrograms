#include<stdio.h>

struct node
{
    char data;
    struct node * left;
    struct node * right;
};

struct node* createNode(char data)      //creating new nodes to link and create the tree
{
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));    //creating new node
    n->data = data;       //inserting data in node
    n->left = NULL;       //setting the left pointer to NULL
    n->right = NULL;   //setting the right pointer to NULL
    return n;
}

int countNodes(struct node * root)
{
    if(root != NULL)
    {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    else
    {
        return 0;
    }
}
int main()
{
    struct node* p = createNode('a');
    p->left = createNode('b');
    p->right = createNode('c');
    p->left->right = createNode('d');
    p->right->left = createNode('e');
    p->left->right->left = createNode('f');
    p->right->left->right = createNode('g');

    int c = countNodes(p);
    printf("The Number of Nodes is = %d", c);
    return 0;
}
