#include<iostream>
using namespace std;
class Node{
    public:
     int data;
     Node *next;
};
class LinkedList1{
    private:
     Node *Head1;
    public:
    LinkedList1(){Head1=NULL;}
      LinkedList1(int A[],int n);
      void Display1();
      int Delete1(int index1);
      int Length1();
     
};

class LinkedList{
    private:
      Node *Head;
    public:
      LinkedList(){Head = NULL;}
      LinkedList(int A[],int n);
      void Display();
      int Delete(int index);
      int Length();
};
///this is for 
LinkedList1::LinkedList1(int A[],int n){
    Node *last,*t;
    Head1 = new Node;
    Head1->data = A[0];
    Head1->next = Head1;
    last = Head1;
    for(int i=1;i<n;i++){
        t= new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
 
int LinkedList1::Length1(){
    Node *p = Head1;
    int len = 0;
    while(p){
        len++;
        p = p->next;
    }
}
int LinkedList1::Delete1(int index){
     Node *p,*q=NULL;
     int x =-1;
     if(index ==1){
        p=Head1;
        Head1 = Head1->next;
        x = p->data;
        delete p;
     }
     else{
        p=Head1;
        for(int i=0;i<index;i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
     }
     return x;
}
void LinkedList1::Display1(){
    Node *p = Head1;
    do{
        cout<<p->data<<" ";
        p = p->next;
    }while(p!=Head1);
    cout<<"\n";
}
 
///this iis for linkedlist 1
LinkedList::LinkedList(int A[],int n){
    Node *last,*t;
    Head = new Node;
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    for(int i=1;i<n;i++){
        t= new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
 
int LinkedList::Length(){
    Node *p = Head;
    int len = 0;
    while(p){
        len++;
        p = p->next;
    }
}
int LinkedList::Delete(int index){
     Node *p,*q=NULL;
     int x =-1;
     if(index ==1){
        p=Head;
        Head = Head->next;
        x = p->data;
        delete p;
     }
     else{
        p=Head;
        for(int i=0;i<index;i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
     }
     return x;
}
void LinkedList::Display(){
    Node *p = Head;
    do{
        cout<<p->data<<" ";
        p = p->next;
    }while(p!=Head);
    cout<<"\n";
}
void createArr(int a[],int len){
    cout<<"Enter"<<len<<"elements for number: ";
    for(int i =0;i<len;i++){
        cin>>a[i];
    }
    
}

void subtract(LinkedList l,LinkedList1 l1){
    int borrow = 0;
    int mediator = 0
    Node *p = Head;
    Node *t = Head1;
    while(p){
     mediator = (p->data) - (t->data);   
     p = p->next;
     t = t->next;
    }

}

int main(){
    int len1,len2;
    
    cout<<"Enter the number of elements for number 1: ";
    cin>>len1;
    cout<<endl;
    cout<<"Enter the number of elements for number 2: ";
    cin>>len2;
    int arr1[len1],arr2[len2];
    createArr(arr1,len1);
    createArr(arr2,len2);
    LinkedList l1(arr1,len1);
    LinkedList1 l2(arr2,len2);
    l1.Display();
    l2.Display1();
    

    

}