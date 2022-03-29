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
    ListNode* swapPairs(ListNode* head) {
        ListNode *ph = new ListNode();
        ph->next = head;
        ListNode *current1 = ph;
        while(current1!= nullptr){
            if(current1->next == nullptr)
                break;
            else if(current1->next->next == nullptr)
                break;
            else{
                ListNode *current2 = current1->next;
                ListNode *current3 = current1->next->next;
                current2->next = current3->next;
                current3->next = current2;
                current1->next = current3;
                current1 = current2;
            }
        }
        return ph->next;
    }

    void printListNode(ListNode* head){
        while (head != nullptr)
        {
            cout << head->val;
            head = head->next;
        }
        cout<<endl;
    }
};

int main(){
    Solution *su = new Solution();
    ListNode *s = nullptr;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    su->swapPairs(n1);
    su->printListNode(n1);
    su->printListNode(n2);
    ListNode* n11 = new ListNode(1);
    su->swapPairs(n11);
    su->printListNode(n11);
    su->swapPairs(s);
    su->printListNode(s);
    return 0;

}