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

void tripleOrder(struct node * root)
{
    if(root != NULL)
    {
        printf("%c", root->data);

        tripleOrder(root->left);
        printf("%c", root->data);

        tripleOrder(root->right);
        printf("%c", root->data);

    }
}

int main()
{
    struct node* p = createNode('a');
    p->left = createNode('b');
    p->right = createNode('c');
    p->left->left = createNode('d');
    p->right->right = createNode('e');

    tripleOrder(p);
    return 0;
}

