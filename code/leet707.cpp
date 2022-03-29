#include<iostream>

using namespace std;

struct Node{
    int val = 0;
    Node *next = nullptr;
    Node *front = nullptr;
    Node() : val(0),next(nullptr){};
    Node(int num) : val(num),next(nullptr){};
};

class MyLinkedList {

public:
    int len;
    Node* head;
    Node* tail;
    MyLinkedList() {
        len = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        head->front = nullptr;
        tail->next = nullptr;
        tail->front = head;
    }
    
    int get(int index) {
        if(index < 0)
            return -1;
        else if(index >= len)
            return -1;
        else{
            Node* p = head->next;
            for(int i = 0 ; i < index ; i++){
                p = p->next;
            }
            return p->val;
        }
    }

    void addNodeBehind(int val, Node* currentNode){
        Node* add = new Node(val);
        add->next = currentNode->next;
        currentNode->next = add;
        add->front = currentNode;
        add->next->front = add;
        len++;
    }

    void addNodeFront(int val, Node* currentNode){
        Node* add = new Node(val);
        add->front = currentNode->front;
        currentNode->front = add;
        add->next = currentNode;
        add->front->next = add;
        len++;
    }
    
    void addAtHead(int val) {
        addNodeBehind(val,head);
    }
    
    void addAtTail(int val) {
        addNodeFront(val,tail);
    }
    
    void addAtIndex(int index, int val) {
        if(index > len)
            return;
        else if(index <= 0)
            addAtHead(val);
        else if(index == len)
            addAtTail(val);
        else{
            Node* p = head->next;
            for(int i = 0 ; i < index ; i++){
                p = p->next;
            }
            addNodeFront(val,p);
        }
    }
    
    void deleteCurrentNode(Node* currentNode){
        Node* front = currentNode->front;
        Node* behind = currentNode->next;
        front->next = behind;
        behind->front = front;
        len--;
    }

    void deleteAtIndex(int index) {
        if(index < 0)
            return;
        else if(index >= len)
            return;
        else{
            Node* p = head-> next;
            for(int i = 0 ; i < index ; i++){
                p = p->next;
            }
            deleteCurrentNode(p);
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(){
    MyLinkedList* obj = new MyLinkedList();
    // cout << (obj->get(0))<<endl;
    obj->addAtHead(3);
    obj->addAtTail(4);
    cout << (obj->get(0))<<endl;
    cout << (obj->get(1))<<endl;
    cout << (obj->get(2))<<endl;
    obj->deleteAtIndex(1);
    cout << (obj->get(0))<<endl;
    cout << (obj->get(1))<<endl;
    cout << (obj->get(2))<<endl;
    obj->addAtIndex(4,6);
    cout << (obj->get(0))<<endl;
    cout << (obj->get(1))<<endl;
    cout << (obj->get(2))<<endl;
    obj->addAtIndex(1,6);
    obj->addAtIndex(0,2);
    cout << (obj->get(0))<<endl;
    cout << (obj->get(1))<<endl;
    cout << (obj->get(2))<<endl;
    obj->addAtHead(1);
    obj->addAtTail(8);
    cout << (obj->get(0))<<endl;
    cout << (obj->get(1))<<endl;
    cout << (obj->get(2))<<endl;
    cout << (obj->get(3))<<endl;
    cout << (obj->get(4))<<endl;
    cout << (obj->get(5))<<endl;
    MyLinkedList* linkedList = new MyLinkedList();
    linkedList->addAtHead(1);
    linkedList->addAtTail(3);
    linkedList->addAtIndex(1,2);   //链表变为1-> 2-> 3
    cout << (linkedList->get(0))<<endl;
    cout << (linkedList->get(1))<<endl;
    cout << (linkedList->get(2))<<endl;
    linkedList->get(1);            //返回2
    linkedList->deleteAtIndex(1);  //现在链表是1-> 3
    linkedList->get(1);            //返回3
    cout << (linkedList->get(0))<<endl;
    cout << (linkedList->get(1))<<endl;
    cout << (linkedList->get(2))<<endl;
    cout << "******"<< endl;
    MyLinkedList* linkedList1 = new MyLinkedList();
    linkedList1->addAtHead(2);
    linkedList1->deleteAtIndex(1);
    cout << (linkedList1->get(0))<<endl;
    cout << (linkedList1->get(1))<<endl;
    cout << (linkedList1->get(2))<<endl;
    return 0;
}