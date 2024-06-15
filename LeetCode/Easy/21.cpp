#include<bits/stdc++.h>
using namespace std;



class ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* solve(ListNode *head1, ListNode *head2){

    ListNode* tmp = NULL;
    if (head1== NULL) return head2;
    if(head2 ==NULL) return head1;
    if(head1->val > head2->val){
        tmp = head1;
        head1 = head2;
        head2 = tmp;
    }
    ListNode *res = head1;
    while(head1!= NULL && head2!=NULL){
        ListNode *tmp = NULL;
        while(head1!=NULL && head1->val <=head2->val){
            tmp = head1;
            head1 = head2->next;
        }
        temp->next = head2;



        ListNode *temp = head1;
        head1 = head2;
        head2 = temp;
    }
    return res;


}


int main(){



    return 0;
}