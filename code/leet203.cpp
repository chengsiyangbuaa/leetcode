#include<vector>
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode H = ListNode();
        ListNode *Hp = &H;
        Hp->next = head;
        ListNode *current = Hp;
        while(current->next != nullptr){
            if(current->next->val == val){
                current->next = current->next->next;
            }else{
                current = current->next;
            }
            
        }
        return Hp->next;
    }
};

int main(){
    ListNode n1 = ListNode(1);
    ListNode n2 = ListNode(2);
    ListNode n3 = ListNode(6);
    ListNode n4 = ListNode(3);
    ListNode n5 = ListNode(4);
    ListNode n6 = ListNode(5);
    ListNode n7 = ListNode(6);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = nullptr;
    ListNode H = ListNode();
    H.next = &n1;
    ListNode *Hp = &H;
    Solution su;
    ListNode *result = su.removeElements(Hp,6);
    while(result->next != nullptr){
        cout << result->next->val << endl;
        result = result->next;
    }
}