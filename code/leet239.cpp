#include<unordered_set>
#include<unordered_map>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>

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
void test7();
void test8();
void test(int i);
void testall(int i);

//此时我们需要一个队列，这个队列呢，放进去窗口里的元素，然后随着窗口的移动，队列也一进一出，每次移动之后，队列告诉我们里面的最大值是什么。
//每次窗口移动的时候，调用que.pop(滑动窗口中移除元素的数值)，que.push(滑动窗口添加元素的数值)，然后que.front()就返回我们要的最大值。
//找最大：有序队列，最大值放在队首
//单调序列不是优先级序列，单调队列不是排序

//答题区*********************************
class MyQueue{
public:
    deque<int> que;
    void pop(){
        que.pop_front();
    }

    void push(int x){
        while(!que.empty() && que.back() < x)
            que.pop_back();
        que.push_back(x);
    }

    int front(){
        return que.front();
    }

    bool empty(){
        return que.empty();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;
        for(int i = 0 ; i < k ; i++)
            que.push(nums[i]);
        result.push_back(que.front());
        for(int i = k ; i < nums.size() ; i++){
            if(!que.empty() && nums[i-k] == que.front())
                que.pop();
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};
//答题区*********************************
int main(){
    testall(8);
        return 0;
}
//测试
void test1(){
    Solution* su = new Solution();
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    int k = 3;
    printIntVector(su->maxSlidingWindow(nums,k));
}

void test2(){
    Solution* su = new Solution();
    vector<int> nums{9,10,9,-7,-4,-8,2,-6};
    int k = 5;
    printIntVector(su->maxSlidingWindow(nums,k));
}

void test3(){
    Solution* su = new Solution();
    
}

void test4(){
    Solution* su = new Solution();
    
}

void test5(){
    Solution* su = new Solution();
    
}

void test6(){
    Solution* su = new Solution();
    
}

void test7(){
    Solution* su = new Solution();
    
}

void test8(){
    Solution* su = new Solution();
    
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
    case 7:
        test7();
        break;
    case 8:
        test8();
        break;
    default:
        break;
    }
    cout <<endl<< "test: "<<i<<" end!"<<endl<<endl;
}

void testall(int k){
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
