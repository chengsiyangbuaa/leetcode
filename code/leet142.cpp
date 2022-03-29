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

    int getSize(ListNode* current){
        int result = 0;
        while(current != nullptr){
            current = current->next;
            result++;
        }
        return result;
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

    // 快慢指针，慢指针走一步，快指针走两步
    ListNode *detectCycle(ListNode *head) {
        ListNode* ph = new ListNode();
        ph->next = head;
        ListNode* slow = ph;
        ListNode* fast = ph;
        int step = 0;
        bool flag = false;//false 表示无环
        while(fast != nullptr && fast->next != nullptr){
            if(fast == slow && fast != ph){
                flag = true;
                break;
            }
            step++;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(!flag)
            return nullptr;
        slow = ph;
        fast = ph;
        fast = getNextNumberNode(fast,step);
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
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

    void printNode(ListNode* node){
        if(node == nullptr)
            cout << "nullptr" << endl;
        else
            cout << node->val << endl;
    }
};

void test1(){
    cout<<"test1"<<endl;
    Solution *su = new Solution();
    ListNode *s = nullptr;
    ListNode* n11 = new ListNode(1);
    ListNode* n12 = new ListNode(2);
    ListNode* n13 = new ListNode(3);
    ListNode* n14 = new ListNode(4);
    ListNode* n15 = new ListNode(5);
    n11->next = n12;
    n12->next = n13;
    n13->next = n14;
    n14->next = n15;
    su->printNode(su->detectCycle(n11));
}

void test2(){
    cout<<"test2"<<endl;
    Solution *su = new Solution();
    ListNode *s = nullptr;
    ListNode* n11 = new ListNode(1);
    ListNode* n12 = new ListNode(2);
    ListNode* n13 = new ListNode(3);
    ListNode* n14 = new ListNode(4);
    ListNode* n15 = new ListNode(5);
    n11->next = n12;
    n12->next = n13;
    n13->next = n14;
    n14->next = n15;
    n15->next = n13;
    su->printNode(su->detectCycle(n11));
}

void test3(){
    cout<<"test3"<<endl;
}

int main(){
    test1();
    test2();
    test3();
    return 0;
}