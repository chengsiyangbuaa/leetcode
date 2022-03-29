#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* hp = new ListNode();
        ListNode* current = head;
        while(current != nullptr){
            ListNode* tmp = current->next;
            current->next = hp->next;
            hp->next = current;
            current = tmp;
        }
        return hp->next;
    }

    void printListNode(ListNode* head){
        while (head != nullptr)
        {
            cout << head->val;
            head = head->next;
        }
        
    }
};

int main(){
    Solution *su = new Solution();
    ListNode *s = nullptr;
    // ListNode* n1 = new ListNode(1);
    // ListNode* n2 = new ListNode(2);
    // ListNode* n3 = new ListNode(3);
    // ListNode* n4 = new ListNode(4);
    // ListNode* n5 = new ListNode(5);
    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    // n4->next = n5;
    su->printListNode(su->reverseList(s));
    return 0;

}