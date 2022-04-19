#include<unordered_set>
#include<unordered_map>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

void printIntIntUnordered_map(unordered_map<int,int> map);
void printIntUnorderedSet(unordered_set<int> set);
void printIntVector(vector<int> a);
void printDoubleIntVector(vector<vector<int>> a);
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test(int i);
void testall(int i);

//答题区*********************************
class MyQueue {
public:
    stack<int> tail_stack;
    stack<int> head_stack;
    MyQueue() {

    }
    
    void push(int x) {
        tail_stack.push(x);
    }
    
    int pop() {
        int result;
        if(head_stack.empty()){
            while(!tail_stack.empty()){
                head_stack.push(tail_stack.top());
                tail_stack.pop();
            }
            result = head_stack.top();
            head_stack.pop();
        }
        else{
            result = head_stack.top();
            head_stack.pop();
        }
        return result;
    }
    
    int peek() {
        int result;
        if(head_stack.empty()){
            while(!tail_stack.empty()){
                head_stack.push(tail_stack.top());
                tail_stack.pop();
            }
            result = head_stack.top();
        }
        else{
            result = head_stack.top();
        }
        return result;
    }
    
    bool empty() {
        return tail_stack.empty() && head_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
//答题区*********************************
int main(){
    testall(6);
    return 0;
}
//测试
void test1(){
    MyQueue* myQueue = new MyQueue();
    myQueue->push(1); // queue is: [1]
    myQueue->push(2); // queue is: [1, 2] (leftmost is front of the queue)
    cout << myQueue->peek() << endl; // return 1
    cout << myQueue->pop()<< endl; // return 1, queue is [2]
    cout << myQueue->empty()<< endl; // return false
}

void test2(){
    MyQueue* myQueue = new MyQueue();
    myQueue->push(1); 
    myQueue->push(2); 
    myQueue->push(3); 
    myQueue->push(4); 
    myQueue->push(5); 
    myQueue->push(6); 
    cout << myQueue->pop()<< endl; 
    cout << myQueue->pop()<< endl; 
    cout << myQueue->pop()<< endl; 
    cout << myQueue->pop()<< endl; 
    cout << myQueue->pop()<< endl; 
    cout << myQueue->pop()<< endl; 
    cout << myQueue->empty()<< endl; 
}

void test3(){
    MyQueue* myQueue = new MyQueue();
    myQueue->push(1); 
    myQueue->push(2); 
    myQueue->push(3); 
    myQueue->push(4); 
    myQueue->push(5); 
    myQueue->push(6); 
    cout << myQueue->pop()<< endl; 
    cout << myQueue->pop()<< endl; 
    cout << myQueue->pop()<< endl; 
    cout << myQueue->pop()<< endl; 
    cout << myQueue->pop()<< endl; 
    cout << myQueue->pop()<< endl; 
    cout << myQueue->empty()<< endl; 

}

void test4(){
    MyQueue* myQueue = new MyQueue();
    myQueue->push(1); // queue is: [1]
    myQueue->push(2); // queue is: [1, 2] (leftmost is front of the queue)
    cout << myQueue->peek() << endl; // return 1
    cout << myQueue->pop()<< endl; // return 1, queue is [2]
    cout << myQueue->empty()<< endl; // return false
}

void test5(){
    
}

void test6(){
    
}

void test(int i){
    cout << "test: "<< i<<" start!"<<endl;
    switch (i)
    {
    case 1:
        test1();
        break;
    case 2:
        test2();
        break;
    case 3:
        test3();
        break;
    case 4:
        test4();
        break;
    case 5:
        test5();
        break;
    case 6:
        test6();
        break;
    default:
        break;
    }
    cout <<endl<< "test: "<<i<<" end!"<<endl<<endl;
}

void testall(int i){
    int k = 6;
    for(int i = 1 ; i <= k ; i++ )
        test(i);
}

void printIntUnorderedSet(unordered_set<int> set){
     auto it = set.begin();
     while(it != set.end()){
        cout<<*it;
        ++it;
        if(it != set.end())
            cout<<" ";
        else
            cout<<endl;    
     }    
}

void printIntVector(vector<int> a){
    for(int i = 0 ; i < a.size() ; i++){
        cout<<a[i];
        if(i != a.size()-1)
            cout<<",";
        else
            cout<<endl;
    }
}

void printIntIntUnordered_map(unordered_map<int,int> map){
    auto it = map.begin();
    while(it != map.end()){
        cout << "<" << it->first << "," << it->second << ">";
        ++it;
        if(it != map.end())
            cout<<" ";
        else
            cout<<endl;
    }    
}

void printDoubleIntVector(vector<vector<int>> a){
    for(int j = 0 ; j < a.size() ; j++){
        for(int i = 0 ; i < a[j].size() ; i++){
                cout<<a[j][i];
                if(i != a[j].size()-1)
                    cout<<",";
                else
                    cout<<endl;
        }
    }
}
