#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

struct node *root=NULL;
struct node *prev=NULL;
int side;

struct node *insert(struct node *list,int val)
{
    if(list==NULL)
    {
        struct node *new_node=malloc(sizeof(struct node));
        new_node->data=val;
        new_node->left=new_node->right=NULL;
        return new_node;
    }
    else if(list->data>val)
    {
        list->left=insert(list->left,val);
    }
    else
        list->right=insert(list->right,val);
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

struct node *search(struct node *list,int val)
{
    while(list!=NULL)
    {
        //printf("\nHI\n");
        if(list->data==val)
            return list;
        else if(list->data>val)
            {
                prev=list;
                side=1;
                list=list->left;
            }
        else
            {
                prev=list;
                side=2;
                list=list->right;
            }
    }
}

void delete_node(struct node *list)
{
    int temp;
    while(list->left!=NULL || list->right!=NULL)
    {
        struct node *ptr=list;
        if(list->left!=NULL)
        {
            prev=list;
            list=list->left;
            side=1;
            while(list->right!=NULL)
            {
            side=2;
            prev=list;
            list=list->right;
            }
        }
        else if(list->right!=NULL)
        {
            prev=list;
            list=list->right;
            side=2;
            while(list->left!=NULL)
            {
            side=1;
            prev=list;
            list=list->left;
            }
        }
        temp=ptr->data;
        ptr->data=list->data;
        list->data=temp;
    }
    free(list);
    if(prev!=NULL)
    {
    if(side==1)
        prev->left=NULL;
    else
        prev->right=NULL;
    }
    else
        root=NULL;
}

int main()
{
    int n,val,del;
    //root has been shifted from here to global
    printf("Enter the number of elements you want to enter : ");
    scanf("%d",&n);
    while(n!=0)
    {
        printf("enter value : ");
        scanf("%d",&val);
        root=insert(root,val);
        n--;
    }
    printf("enter the value to be deleted : ");
    scanf("%d",&del);
    delete_node(search(root,del));
    printf("the new tree is : ");
    inorder(root);
    return 0;
}
