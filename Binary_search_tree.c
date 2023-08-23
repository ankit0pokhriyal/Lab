#include <stdio.h>
#include <malloc.h>
struct node{
    struct node *left;
    int data;
    struct node *right;
};
struct node *tree;
void create_tree(struct node *);
struct node *insertElement(struct node *, int);
void preorderTraversal(struct node *);
void inorderTraversal(struct node *);
void postorderTraversal(struct node *);
struct node *smallestElement(struct node *);
struct node *largestElement(struct node *);
struct node *mirrorImage(struct node *);
struct node *deleteElement(struct node *, int);
struct node *deleteTree(struct node *);
int totalNodes(struct node*);
int totalExternalNodes(struct node*);
int totalInternalNodes(struct node*);
int Height(struct node*);
int main(){
    int option, val;
    struct node *ptr;
    create_tree(tree);
    do{
        printf("\n 1. Insert Element");
        printf("\n 2. Preorder Traversal");
        printf("\n 3. Inorder Traversal");
        printf("\n 4. Postorder Traversal");
        printf("\n 5. Find the smallest element");
        printf("\n 6. Find the largest element");
        printf("\n 7. Delete an element");
        printf("\n 8. Count the total number of nodes");
        printf("\n 9. Count the total number of external nodes");
        printf("\n 10. Count the total number of internal nodes");
        printf("\n 11. Determine the height of the tree");
        printf("\n 12. Find the mirror image of the tree");
        printf("\n 13. Delete the tree");
        printf("\n 14. Exit");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch(option)
        {
            case 1: 
                printf("\n Enter the value of the new node : ");
                scanf("%d", &val);
                tree = insertElement(tree, val);
                break;
                
            case 2:
                printf("\n The elements of the tree are : \n");
                preorderTraversal(tree);
                break;
            case 3:
                printf("\n The elements of the tree are : \n");
                inorderTraversal(tree);
                break;
            case 4:
                printf("\n The elements of the tree are : \n");
                postorderTraversal(tree);
                break;
            case 5:
                ptr = smallestElement(tree);
                printf("\n Smallest element is :%d",ptr->data);
                break;
            case 6:
                ptr = largestElement(tree);
                printf("\n Largest element is : %d", ptr->data);
                break;
            case 7:
                printf("\n Enter the element to be deleted : ");
                scanf("%d", &val);
                tree = deleteElement(tree, val);
                break;
            case 8:
                printf("\n Total no. of nodes = %d", totalNodes(tree));
                break;
            case 9:
                printf("\n Total no. of external nodes =%d",
                totalExternalNodes(tree));
                break;
            case 10:
                printf("\n Total no. of internal nodes = %d", 
                totalInternalNodes(tree));
                break;
            case 11:
                printf("\n The height of the tree = %d",Height(tree));
                break;
            case 12:
                tree = mirrorImage(tree);
                break;
            case 13:
                tree = deleteTree(tree);
                break;
        }
    }while(option!=14);
    return 0;
    
}
void create_tree(struct node *tree)
{
    tree = NULL;
}
struct node *insertElement(struct node *tree, int val)
{
    struct node *ptr, *nodeptr, *parentptr;
    ptr = (struct node*)malloc(sizeof (struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if(tree==NULL)
    {
        tree = ptr;
        tree->left =NULL;
        tree->right =NULL;
    }
    else
    {
        parentptr = NULL;
        nodeptr = tree;
        while(nodeptr != NULL)
        {
            parentptr = nodeptr;
            if(val<nodeptr->data)
            {
                nodeptr = nodeptr->left;
            }
            else{
                nodeptr = nodeptr->right;
            }
        }
        if(val<parentptr->data){
            parentptr->left = ptr;
        }
        else
        {
            parentptr->right = ptr;
        }
    }
    return tree;
}
void preorderTraversal(struct node *tree){
    if(tree != NULL){
        printf("%d\t", tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}        
void inorderTraversal(struct node *tree)
{
    if(tree != NULL)
    {
       inorderTraversal(tree->left);
       printf("%d\t", tree->data);
       inorderTraversal(tree->right);
    }
}
void postorderTraversal(struct node *tree)
{
    if(tree != NULL)
    { 
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("%d\t", tree->data);
    }
     
}
struct node *deleteElement(struct node *tree, int val)
{
    struct node *cur, *parent, *suc, *psuc, *ptr;
    if(tree->left == NULL)
    {
        printf("\nTree is empty");
        return(tree);
    }
    parent = tree;
    cur = tree->left;
    while(cur!=NULL && val!=cur->data)
    {
        parent = cur;
        cur = (val<cur->data)? cur->left:cur->right;
    }
    if(cur == NULL)
    {
       printf("\n The value to be deleted is not present in the tree");
       return(tree);
    }
    if(cur->left == NULL)
       ptr = cur->right;
    else if(cur->right == NULL)
       ptr = cur->left;
    else
    {
        psuc = cur;
        cur = cur->left;
        while(suc->left!=NULL)
        { 
           psuc = suc;
           suc = suc->left;
        }
        if(cur==psuc)
        {
        suc->left = cur->right;
        }
        else
        {
           suc->left = cur->left;
           psuc->left = suc->right; 
           suc->right = cur->right;
        }
        ptr = suc;
    }

    if(parent->left == cur)
        parent->left=ptr;
    else
        parent->right=ptr;
    free(cur);
    return tree;
}
struct node *smallestElement(struct node *tree)
{
    if( (tree == NULL) || (tree->left == NULL))
       return tree;
    else
       return smallestElement(tree ->left);
}
struct node *largestElement(struct node *tree)
{
    if( (tree == NULL) || (tree->right == NULL))
       return tree;
    else
       return largestElement(tree->right);
}
int totalNodes(struct node *tree)
{
    if(tree==NULL)
       return 0;
    else
       return(totalNodes(tree->left) + totalNodes(tree->right) + 1);
}
int totalExternalNodes(struct node *tree)
{
    if(tree==NULL)
       return 0;
    else if((tree->left==NULL) && (tree->right==NULL))
       return 1;
    else
       return (totalExternalNodes(tree->left) +
       totalExternalNodes(tree->right));
}
int totalInternalNodes(struct node *tree)
{
    if( (tree==NULL) || ((tree->left==NULL) && (tree->right==NULL)))
        return 0;
    else
       return (totalInternalNodes(tree->left)
       + totalInternalNodes(tree->right) + 1);
}
int Height(struct node *tree)
{
    int leftheight, rightheight;
        if(tree==NULL)
           return 0;
    else
    {
        leftheight = Height(tree->left);
        rightheight = Height(tree->right);
        if(leftheight > rightheight)
           return (leftheight + 1);
        else
          return (rightheight + 1);
        
    }
}
struct node *mirrorImage(struct node *tree)
{
    struct node *ptr;
    if(tree!=NULL) 
    {
        mirrorImage(tree->left);
        mirrorImage(tree->right);
        ptr=tree->left;
        ptr->left = ptr->right;
        tree->right = ptr;
    }
}
struct node *deleteTree(struct node *tree)
{
    if(tree!=NULL)
    {
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
}