#include<unordered_set>
#include<unordered_map>
#include<string>
#include<iostream>
#include<vector>

using namespace std;

void printIntIntUnordered_map(unordered_map<int,int> map);
void printIntUnorderedSet(unordered_set<int> set);
void printIntVector(vector<int> a);
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test(int i);
void testall(int i);
//答题区*********************************
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> hash1(256,0);
        vector<int> hash2(256,0);
        for(int i = 0 ; i < ransomNote.size() ; i++)
            hash1[ransomNote[i]]++;
        for(int i = 0 ; i < magazine.size() ; i++)
            hash2[magazine[i]]++;
        for(int i = 0 ; i < 256 ; i++){
            if(hash1[i] > hash2[i])
                return false;
        }
        return true;
    }
};
//答题区*********************************
int main(){
    testall(6);
    return 0;
}
//编写测试
void test1(){
    Solution* su = new Solution();
    cout << su->canConstruct("a","b");
}

void test2(){
    Solution* su = new Solution();
    cout << su->canConstruct("aa","ab");    
}

void test3(){
    Solution* su = new Solution();
    cout << su->canConstruct("aa","aab");
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
