#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
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

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sa = getSize(headA);
        int sb = getSize(headB);
        if(sa > sb){
            headA = getNextNumberNode(headA,sa-sb);
        }else{
            headB = getNextNumberNode(headB,sb-sa);
        }
        while(headA != nullptr){
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
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
    cout<<"test1"<<endl;
    Solution *su = new Solution();
    ListNode *s = nullptr;
    ListNode* n11 = new ListNode(1);
    ListNode* n12 = new ListNode(2);
    ListNode* n13 = new ListNode(3);
    ListNode* n14 = new ListNode(4);
    ListNode* n15 = new ListNode(5);
    ListNode* n22 = new ListNode(22);
    ListNode* n23 = new ListNode(23);
    n11->next = n12;
    n12->next = n13;
    n13->next = n14;
    n14->next = n15;
    n22->next = n23;
    n23->next = n14;
    su->printListNode(su->getIntersectionNode(n11,n22));
    su->printListNode(su->getIntersectionNode(n22,n11));
    su->printListNode(su->getIntersectionNode(n22,n22));
}

void test2(){
    cout<<"test2"<<endl;
    Solution *su = new Solution();
    ListNode *s = nullptr;
    ListNode* n11 = new ListNode(4);
    ListNode* n12 = new ListNode(1);
    ListNode* n13 = new ListNode(8);
    ListNode* n14 = new ListNode(4);
    ListNode* n15 = new ListNode(5);
    ListNode* n22 = new ListNode(5);
    ListNode* n23 = new ListNode(0);
    ListNode* n24 = new ListNode(1);
    n11->next = n12;
    n12->next = n13;
    n13->next = n14;
    n14->next = n15;
    n22->next = n23;
    n23->next = n24;
    n24->next = n13;
    su->printListNode(su->getIntersectionNode(n11,n22));
    su->printListNode(su->getIntersectionNode(n22,n11));
    su->printListNode(su->getIntersectionNode(n22,n22));
}

void test3(){
    cout<<"test3"<<endl;
    Solution *su = new Solution();
    ListNode *s = nullptr;
    ListNode* n11 = new ListNode(1);
    ListNode* n12 = new ListNode(2);
    ListNode* n13 = new ListNode(3);
    ListNode* n14 = new ListNode(4);
    ListNode* n15 = new ListNode(5);
    ListNode* n22 = new ListNode(22);
    ListNode* n23 = new ListNode(23);
    n11->next = n12;
    n12->next = n13;
    n13->next = n14;
    n14->next = n15;
    n22->next = n23;
    su->printListNode(su->getIntersectionNode(n22,n11));
}

int main(){
    test1();
    test2();
    test3();
    return 0;
}