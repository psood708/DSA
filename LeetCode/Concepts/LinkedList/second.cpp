#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // constructor belows
public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 0; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int lengthofLL(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {

        temp = temp->next;
        cnt++;
    }
    return cnt;
}

// search in a linked list
int searchLL(Node *head, int key)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == key)
            return 1;
        temp = temp->next;
    }
    return 0;
}
void print(Node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
// here we work in the deletion of the linked List (deletion of the head of the LL)
Node* removeHead(Node* head){
    if(head==NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// here we'll delete the tail of the LL
Node* removeTail(Node* head){
    if(head==NULL|| head->next==NULL) return NULL;
    Node* temp=head;
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    delete(temp->next);
    temp->next = nullptr;
    return head;
}

// delete kth elelemnt of the LL
Node* removeKelem(Node* head,int k){
    if(head==NULL) return head;
    else if(k>lengthofLL(head)) return head;
    else if(k==1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    else if(k==lengthofLL(head)){
        return removeTail(head);
    }
        int cnt = 0;
        Node* temp = head;
        Node* prev=NULL;
        while(temp!=NULL){
            cnt++;
            if(cnt==k){
                    prev->next = prev->next->next;
                    free(temp);
                    break;
            }
            prev = temp;
            temp= temp->next;
        }
    return head;
    
}
int main()
{
    vector<int> arr = {12,5,8,7};
    Node* head1 = convertArr2LL(arr);
    // head = removeHead(head);
    // print(head);
    cout<<endl;
    // this here we'll see the difference in the head
    // Node* head1 = removeTail(head);
   head1 = removeKelem(head1,4);
   print(head1);
    // print(head2);
    // print(head1);
    return 0;
}