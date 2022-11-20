#include "queue.h"
#include "stack.h"
#include<stdio.h>
#include<stdlib.h>
struct Node *root = NULL;

void treeCreate(){
    struct Node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);
    printf("Enter root value: ");
    scanf("%d",&x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild=NULL;
    enqueue(&q,root);
    while(!isEmpty(q)){
        p = dequeue(&q);
        printf("Enter Left child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1){
             t = (struct Node *)malloc(sizeof(struct Node));
             t->data = x;
             t->lchild = t->rchild = NULL;
             p->lchild = t;
             enqueue(&q,t);
        }
        printf("Enter Right child of %d: ",p->data);
        scanf("%d",&x);
        if(x!=-1){
             t = (struct Node *)malloc(sizeof(struct Node));
             t->data = x;
             t->lchild = t->rchild = NULL;
             p->rchild = t;
             enqueue(&q,t);
        }

    }
}
void preorder(struct Node *p){
    if(p){
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void inOrder(struct Node *p){
    if(p){
        inOrder(p->lchild);
        printf("%d ",p->data);
        inOrder(p->rchild);
    }
}
void postOrder(struct Node *p){
    if(p){
        postOrder(p->lchild);
        postOrder(p->rchild);
        printf("%d ",p->data);
    }
}
void IPreOrder(struct Node *p){
    struct Stack stk;
    stackCreate(&stk,100);
    while(p|| !isEmptyStack(stk)){
        if(p){
            printf("%d ",p->data);
            push(&stk,p);
            p=p->lchild;
        }
        else{
            p=pop(&stk);
            p=p->rchild;
        }
    }
}
void IinOrder(struct Node *p){
    struct Stack stk;
    stackCreate(&stk,100);
    while(p || !isEmptyStack(stk)){
        if(p){
            push(&stk,p);
            p=p->lchild;
        }
        else{
            p =pop(&stk);
            printf("%d ",p->data);
            p=p->rchild;
        }
    }
}
void IpostOrder(struct Node *p){
    struct Stack stk;
    long int temp;
    stackCreate(&stk,100);
    while(p || isEmptyStack(stk)){
        if(p){
            push(&stk,p);
            p=p->lchild;
        }
        else{
            temp = pop(&stk);
            if(temp>0){
                push(&stk,((struct Node *)(-temp)));
                p = ((struct Node *)temp)->rchild;
            }
            else{
                printf("%d ",((struct Node *)temp)->data);
                p =NULL;
            }
        }
    }
}
int main(){
  treeCreate();
  printf("\nThis is preorder traversal: ");
  preorder(root);
  printf("\nThis is iterative preorder traversal: ");
  IPreOrder(root);
  printf("\nThis is inorder traversal: ");
  inOrder(root);
  printf("\nThis is iterative inorder traversal: ");
  IinOrder(root);
  printf("\nThis is postorder traversal: ");
  postOrder(root);
  printf("\nThis is iterative postorder traversal: ");
  IpostOrder(root);
}