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

    void deleteNextNode(ListNode* current){
        if(current->next == nullptr)
            return;
        else
            current->next = current->next->next;
    }

    ListNode* getNextNumberNode(ListNode* current, int n){
        for(int i = 0 ; i < n ; i++){
            if(current== nullptr)
                return current;
            else
                current = current->next;
        }
        return current;
    }

    // 暴力解法，狗都不用
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     int len = 0;
    //     ListNode* ph = new ListNode();
    //     ph->next = head;
    //     ListNode* current = ph;
    //     while(current->next != nullptr){
    //         len++;
    //         current = current->next;
    //     }
    //     current = ph;
    //     for(int i = 0 ; i < len-n ; i++){
    //         current = current->next;
    //     }
    //     deleteNextNode(current);
    //     return ph->next;
    // }

    //快慢指针法
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ph = new ListNode();
        ph->next = head;
        ListNode* slow = ph;
        ListNode* fast = ph;
        fast = getNextNumberNode(fast,n);
        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        deleteNextNode(slow);
        return ph->next;
    }

    void printListNode(ListNode* head){
        if(head == nullptr)
            cout << "nullptr";
        while (head != nullptr)
        {
            cout << head->val;
            head = head->next;
        }
        cout<<endl;
    }
};

void test1(){
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
    // su->removeNthFromEnd(n1,2);
    // su->printListNode(n1);
    // su->printListNode(n3);
    cout << "test 1"<<endl;
    su->printListNode(su->removeNthFromEnd(n1,1));
}

void test2(){
    Solution *su = new Solution();
    ListNode *s = nullptr;
    ListNode* n1 = new ListNode(1);
    cout << "test 2"<<endl;
    su->printListNode(su->removeNthFromEnd(n1,1));
}

void test3(){
    Solution *su = new Solution();
    ListNode *s = nullptr;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    n1->next = n2;
    cout << "test 3"<<endl;
    su->printListNode(su->removeNthFromEnd(n1,2));
}

int main(){
    test1();
    test2();
    test3();
    return 0;
}