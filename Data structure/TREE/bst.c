#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
typedef struct tree TREE;

TREE *insert_into_bst(TREE *root,int data)
{
    TREE *newnode;
    TREE *parent=NULL;
    TREE *currnode;
    newnode=(TREE *)malloc(sizeof(TREE));
    if(newnode==NULL)
    {
        printf("MEMORY ALLOCATION FAILED\n");
        return root;
    }
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    if(root==NULL)
    {
        root=newnode;
        printf("ROOT NODE INSERTED\n");
        return root;
    }
    currnode=root;
    while(currnode!=NULL)
    {
        parent=currnode;
        if(newnode->data < currnode->data)
            currnode=currnode->left;
        else
        {
            currnode=currnode->right;
        }
    }
    if(newnode->data<parent->data)
        parent->left=newnode;
    else
        parent->right=newnode;
    printf("DATA INSERTED\n");
    return root;
}

void inorder(TREE *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
void preorder(TREE *root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(TREE *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}
TREE *delete(TREE *root,int item)
{
    TREE *currnode;
    TREE *parent;
    TREE *p;
    TREE *successor;
    if(root == NULL)
    {
        printf("Tree is empty\n");
        return root;
    }

    parent = NULL;
    currnode = root;
    while (currnode != NULL && item != currnode->data)
    {
        parent = currnode;
        if(item < currnode->data)
            currnode  = currnode->left;
        else
            currnode = currnode->right;
    }

    if(currnode == NULL)  {
        printf("Item not found\n");
        return root;
    }

    if(currnode->left == NULL)
        p = currnode->right;
    else if (currnode->right == NULL)
        p = currnode->left;
    else
    {
        successor = currnode->right;
        while(successor->left != NULL)
            successor = successor->left;

        successor->left = currnode->left;
        p = currnode->right;
    }

    if (parent == NULL) {
        free(currnode);
        return p;
    }

    if(currnode == parent ->left)
        parent->left = p;
    else
        parent->right = p;

    free(currnode);
    printf("DATA DELETED\n");
    return root;

}

void count_node(TREE *root,int* count)
{
    if(root!=NULL)
    {
        count_node(root->left,count);
        *count++;
        count_node(root->right,count);
    }
}
void count_leaf(TREE *root,int * count)
{
    if(root!=NULL)
    {
        count_leaf(root->left,count);
        count_leaf(root->right,count);
        if(root->left==NULL && root->right==NULL)
            *count++;
    }

}
void search_data(TREE *root,int data)
{
    TREE *currnode;
    currnode=root;
    while(currnode!=NULL && currnode->data!=data)
    {
        if(data<currnode->data)
            currnode=currnode->left;
        else
            currnode=currnode->right;
    }
    if(currnode==NULL)
        printf("DATA NOT PRESENT\n");
    else
        printf("DATA FOUND\n");
}
void inorder_successor(TREE *root,int data)
{
    TREE *currnode;
    currnode=root;
    TREE *temp;
    TREE *parent;
    int successor;
    while(currnode!=NULL && currnode->data!=data)
    {
        if(data<currnode->data)
            currnode=currnode->left;
        else
            currnode=currnode->right;
    }
    if(currnode==NULL)
        printf("DATA NOT PRESENT\n");
    else
    {
        temp=currnode;
        if(temp->right!=NULL )
        {
            temp=temp->right;
            while(temp!=NULL)
            {
                parent=temp;
                temp=temp->left;
            }   
            successor=parent->data;       
        }
        else if(temp->right==NULL && temp->left==NULL)
        {
            temp=root;
            while(data>temp->data)
                temp=temp->right;
            successor=temp->data;
        }
        else 
            successor=temp->data;
        printf("INORDER SUCCESSOR IS %d\n",successor);
    }
    
}

int main()
{
    TREE *root;
    root=NULL;
    int choice,data;
    int count =0;
    while(1)
    {
        printf("1-INSERT\n2-INORDER TRAVERSAL\n3-PREORDER TRAVERSAL\n4-POSTORDER TRAVERSAL\n5-DELETE\n");
        printf("6-COUNT NODES\n7-COUNT LEAVES\n8-SEARCH\n9-PRINT SORTED TREE\n10-INORDER SUCCESSOR\n");
        printf("11-ROOT\n12-INSERT RANDOM NUMBER\n13-COUNT INTERIOR NODES\n14-PRINT ITEMS IN DECREESING ORDER\n15-PRINT EVEN DATA\n");
        printf("16-PRINT ODD DATA\n17-INORDER PREDESSESOR\n18-EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("ENTER DATA\n");
                scanf("%d",&data);
                root=insert_into_bst(root,data);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                printf("ENTER DATA TO BE DELETED\n" );
                scanf("%d",&data);
                root=delete(root,data);
                break;
            case 6:
                count_node(root,&count);
                printf("TOTAL NODES=%d\n",count);
                count=0;
                break;
            case 7:
                count_leaf(root,&count);
                printf("TOTAL LEAVES=%d\n",count);
                count=0;
                break;
            case 8:
                printf("ENTER DATA\n");
                scanf("%d",&data);
                search_data(root,data);
                break;
            case 9:
                inorder(root); 
                break;
            case 10:
                printf("ENTER DATA\n");
                scanf("%d",&data);
                inorder_successor(root,data);
                break;
            case 11:exit(1);

        }
    }
}