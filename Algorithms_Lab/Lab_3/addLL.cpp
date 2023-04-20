#include<iostream>
using namespace std;

// struct Node{
//     int data;
//     struct Node *next;
// }*first= NULL;

// void printLL(struct Node *p){
//     while(p!=NULL){
//         printf("%d ",p->data);
//         printLL(p->next);
//     }
// }
// void create(A[],int l){
//     struct Node *t,*last;
//     first = new Node; 
//     first->data = A[0];
//     first->next = NULL;
//     last = first;
//     for(int i =0;i<l;i++){
//         //making a temporary node to act as a router
//         t = new Node;
//         t->data = A[i];
//         first->next = NULL;
//         last = t;
//     }
// }
int nodig(int num){
    int n =0,j=1;
    while(num>0){
        num = num/j;
        n++;
    }
    return n;
}
void add(int a1,int a2){
   int a1len,a2len;
   a1len = nodig(a1);
   a2len = nodig(a2);
   cout<<a1len;
   cout<<a2len;
}
int main(){
    int a1 = 4221,a2=123;
    add(a1,a2);

}