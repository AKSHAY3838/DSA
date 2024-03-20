#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;   
}Node;
Node* createNode(int value){
      Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL){
        printf("memory is not allocated\n");
        exit(0);
    }
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;        
}
Node* insertNode(Node* root,int value){
    if(root==NULL)
        return createNode(value);
    else if (value<root->data)
        root->left=insertNode(root->left,value);
    else
        root->right=insertNode(root->right,value);
        return root;    
}
void inorderTraversal(Node* root){
    if(root!=NULL){
    inorderTraversal(root->left);
    printf("%d",root->data);
    inorderTraversal(root->right);
    }
}
void preorderTraversal(Node* root){
    if(root!=NULL){
    printf("%d",root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    }
}
void postorderTraversal( Node* root){
    if(root!=NULL){
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d",root->data);
    }
}
int searchBST(Node *root,int key){
    if(root==NULL)
        return 0;
else if (key==root->data){
        printf("key element is found\n");
        return 1;
    }
    else if (key<root->data)
        return searchBST(root->left,key);
    else
        return searchBST(root->right,key);  
}
int main(){
    Node *root=NULL;
    int choice,key;
    int value[]={5,3,7,3,7,9,2};
    int numvalue=sizeof(value)/sizeof(value[0]);
    for (int i = 0; i < numvalue; i++){
            root=insertNode(root,value[i]);
    }
   while (1){
    printf("\nEnter the your choice");
    printf("\n 1 for in-order,\n 2 for preorder,\n 3 for postorder,\n 4 fro searching an element,\n 5 for exit \n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:printf("In-order traversal is \n");
            inorderTraversal(root);
        
        break;
    case 2:printf("pre-order traversal is \n");
            preorderTraversal(root);
        break;
    case 3:printf("post-order traversal is \n");
            postorderTraversal(root);
        break;
    case 4:printf("enter searching element key \n");
            scanf("%d",&key);
            if(searchBST(root,key))
                printf("Element is found \n");
            else
                printf("element is not found\n");
        break;
    case 5: return 0;
            break;
    default:printf("Invalid choice\n");
        break;
    }
   }   
}