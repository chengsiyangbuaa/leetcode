#include <unordered_set>
#include<string>
#include<iostream>
#include<vector>

using namespace std;

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

void test1(){
    int a[] = {1,2,3,4,5,6,7,8,9,0};
    vector<int> nums1(a,a+10);
    unordered_set<int> uset(nums1.begin(),nums1.end());
    printIntUnorderedSet(uset);
}

void test2(){
    unordered_set<int> uset;
    uset.insert(1);
    uset.insert(1);
    printIntUnorderedSet(uset);
}

void test3(){
    unordered_set<string> uset1{
        "mingxuanshen"
        "xiaoqiezi"
    };
    unordered_set<string> uset2(uset1.begin(),uset1.end());
}

void test4(){
    int a[] = {1,2,3,4,5,6,7,8,9,9,9,9,9};
    vector<int> nums1(a,a+13);
    unordered_set<int> uset(nums1.begin(),nums1.end());
    printIntUnorderedSet(uset);
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

int main(){
    int k = 6;
    for(int i = 1 ; i <= k ; i++ )
        test(i);
    return 0;
}