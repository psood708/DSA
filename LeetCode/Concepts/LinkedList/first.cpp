#include<bits/stdc++.h>
using namespace std;
// we don't get OOPS with struct
// we'll get OOPS with class
class Node{
    public:
        int data;
        Node* next;
    public:
        Node(int data1,Node* next1){
            data = data1;
            next = next1;
        }
    public:
         Node(int data1){
            data = data1;
            next = nullptr;
         }

};

Node* convertArr2LL(vector<int> &arr){
    Node* head= new Node(arr[0]);
    Node* mover = head;
    for(int i =0;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
    }
int lengthofLL(Node *head) { 
    int cnt = 0;
    Node* temp = head;
    while(temp){
        // cout<<temp->data<<" ";/
        temp = temp->next;
        cnt++;
    }
    return cnt;

}


// search in a linked list
int searchLL(Node* head , int key ) {  
    Node* temp = head;
    while(temp){
        if(temp->data == key) return 1;
        temp= temp->next;
    }
    return 0;


}
int main ()
{
    vector<int> arr = {2,5,7,8};
    // Node* y = new Node(arr[0]);
    Node* head = convertArr2LL(arr);
    Node* temp = head;
    while(temp){
        // cout<<temp->data<<" ";
        temp = temp->next;
    }
    // cout<<endl<<lengthofLL(head);
    int res = searchLL(head,5);
    res?cout<<"5 is present in LL" : cout<<"5 is not present in LL";
    // cout<< head->next;
    return 0;
}