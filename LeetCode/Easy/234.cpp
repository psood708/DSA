#include<bits/stdc++.h>
using namespace std;
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
         ListNode* slow = head;
         ListNode* fast = head;
         ListNode* prev = NULL;

         while(fast && fast->next){
            fast = fast->next->next;
            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
         }
         if(fast)
            slow = slow->next;
         while(prev && slow){
            if(prev-> val != slow->val)
                return false;
            prev = prev->next;
            slow = slow->next;
         }
         return true;
    }


int main ()
{
     
    return 0;
}