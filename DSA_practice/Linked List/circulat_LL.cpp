#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
     int data;
     Node *next;
};

class LinkedList{
    private:
      Node *Head;
    public:
      LinkedList(){Head=NULL;}
      LinkedList(int A[],int n);
      ~LinkedList();
      void Display();
      void Insert(int index,int x);
      int Delete(int index);
      int Length();
      void RDisplay(Node *h);
};

LinkedList::LinkedList(int A[],int n){
    Node *last,*t;
    Head = new Node;
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    for(int i =1;i<n;i++){
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList(){
    Node *p = Head;
    while(Head){
        Head = Head->next;
        delete p;
        p = Head;
    }
}
//here we will be implementing a circular linked list
void LinkedList::Display(){
    Node *p = Head;
     do{
        cout<<p->data<<" ";
        p = p->next;

     }while(p!=Head);
     cout<<"\n";
}
//only we need to change the circular linked list from here
int LinkedList::Length(){
    Node *p = Head;
    int len = 0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}
//inserting in a circular linked list
void LinkedList::Insert(int index,int c){
    Node *p = Head;
    Node *t;
    if(index==0){
        t = new Node;
        t->data = c;
        if(Head==NULL){
            Head = t;
            Head->next = Head;
        }
        else{
            while(p->next!=Head){
            p=p->next;
            p->next = t;
            t->next = Head;
            Head = t;
            }
        }
    }
    else{
        for(int i = 0;i<index-1;i++)p=p->next;
        t = new Node;
        t->data = c;
        t->next = p->next;
        p->next = t;
    }
}

int LinkedList::Delete(int index){
    Node *p,*q=NULL;
    int x = -1;
    if(index == 1){
        p = Head;
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
int main(){
    int A[] = {1,2,3,4,5};
    LinkedList l(A,5);
    l.Insert(0,45);
    l.Display();
    return 0;
}