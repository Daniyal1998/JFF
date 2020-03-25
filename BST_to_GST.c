#include<stdio.h>
#include<stdlib.h>
int sum=0;
struct node
{
    int data;
    struct node *left,*right;
};

struct node *insert(int val,struct node *list)
{
    if(list==NULL)
    {
        struct node *new_node;
        new_node=malloc(sizeof(struct node));
        new_node->data=val;
        new_node->left=new_node->right=NULL;
        return new_node;
    }
    else if(list->data<val)
        list->right=insert(val,list->right);
    else
        list->left=insert(val,list->left);
    return list;
}

void inorder(struct node *list)
{
    if(list==NULL)
        return;
    inorder(list->left);
    printf("%d ",list->data);
    inorder(list->right);
}

void gst(struct node *list)
{
    if(list==NULL)
        return;
    gst(list->left);
    sum=list->data=sum-list->data;
    gst(list->right);
}

int main()
{
    struct node *root=NULL;
    int no,val;
    printf("enter the number of nodes you want to enter : ");
    scanf("%d",&no);
    while(no!=0)
    {
        printf("Enter value : ");
        scanf("%d",&val);
        sum+=val;
        root=insert(val,root);
        no--;
    }
    printf("The Binary search tree is : ");
    inorder(root);
    printf("\n");
    gst(root);
    printf("The greater sum tree is : ");
    inorder(root);
    printf("\n");
    return 0;
}
