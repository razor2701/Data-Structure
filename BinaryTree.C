#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}node;
int count = 0;
 int leafc = 0;
 int temp = 1;
node* create()
{
    printf("\nEnter data: ");
    printf("\nNote:Enter '-1' to stop\n");
    int x;
    scanf("%d",&x);
    if(x== -1)
        return NULL;
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = x;
    printf("Enter Left child of %d",x);
    new_node->left = create();
    printf("Enter Right child of %d",x);
    new_node->right = create();
    count++;
return new_node;
}
int leaf(node* lroot)
{
    if(lroot == NULL)
     return 0;
    if(lroot->left == NULL && lroot->right==NULL)
     return 1;
    else
    {
        return leaf(lroot->left)+leaf(lroot->right);

    }

}
int height(node* hroot)
{
    if(hroot == NULL)
     return 0;
    while(hroot->left != NULL && hroot->right!=NULL)
    {
      temp++;
      hroot = hroot->left;
    }
return temp;
}
int main()
{
 node* root;
 int leaf_count;
 int heightt;
 root = create();
 printf("\nCount: %d",count);
 printf("\nLeaf Nodes: %d",leaf(root));
 printf("\nHeight of tree: %d",height(root));
return 0;
}
