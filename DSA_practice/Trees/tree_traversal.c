#include<stdio.h>
#include<stdlib.h>

//we need to make three traversal we'll create trees using linked list

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}; 
//we'll use stack for inorder
struct stack_n{
    struct Node *t;
    struct stack_n *next;
};
//pushing for INORDER
void push(struct stack_n** root,struct Node *t){
    struct stack_n* new_root = (struct stack_n*)malloc(sizeof(struct stack_n));
    if(new_root==NULL){
        printf("\nStack--Overflow\n");
    }
    new_root->t = t;
    new_root->next = (*root);
    *root = new_root;
}
int isEmpty(struct stack_n *top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct Node *pop(struct stack_n** root){
    struct Node *result;
    struct stack_n *top;
    if(isEmpty(*root)){
        printf("\nStack Underflow\n");
    }
    else{
        top = *root;
        result = top->t;
        *root = top->next;
       //
        return result;
    }
}

//main for in order
void InOrder(struct Node *root){
    struct Node *curr = root;
    struct stack_n *s = NULL;
    int status = 0;
    while(!status){
        if(curr!=NULL){
            push(&s,curr);
            curr = curr->left;
        }
        else{
            if(!isEmpty(s)){
                curr = pop(&s);
                printf("%d  ",curr->data);
                curr = curr->right;
            }
            else{
                status =1;
            }
        }
    }
}

void PreOrder(struct Node *root){
    if(root==NULL)
    return;
    printf("%d ",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}
void PostOrder(struct Node *root){
    if(root==NULL)
    {return ;}
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d  ",root->data);
}
//for creation of the node/element of tree

struct Node* create(int data){
    struct Node* node= (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left= NULL;
    node->right = NULL;

    return node;
}
int main(){
    struct Node *root = create(1);
    root->left = create(2);
    root->right = create(3);     
    root->left->left = create(4);
    root->left->right = create(5);
    // root->left->left->left = create(4);
    printf("\nDoing InOrder\n");
    InOrder(root);
    printf("\nDoing PreOrder\n");
    PreOrder(root);
    printf("\nDoing PostOrder\n");
    PostOrder(root);
    return 0;
}
//traversal
