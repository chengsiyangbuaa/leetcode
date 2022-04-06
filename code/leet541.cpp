#include<unordered_set>
#include<unordered_map>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

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
class Solution {
public:

    void reverseString(string &s,int start, int end) {
        if(start < 0 || end >= s.size())
            return;
        int left = start;
        int right = end;
        while(left < end && right >= start && left < right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }

    string reverseStr(string s, int k) {
        int n = s.size();
        int current = 0;
        while(current < n){
            if(current + k < n)
                reverseString(s,current,current+k-1);
            else
                reverseString(s,current,n-1);
            current += 2*k;
        }   
        return s;
    }
};
//答题区*********************************
int main(){
    testall(6);
    return 0;
}
//测试
void test1(){
    Solution* su = new Solution();
    string s = "abcdefg";
    int k = 2;
    cout << su->reverseStr(s,k);
}

void test2(){
    Solution* su = new Solution();
    string s = "abcd";
    int k = 2;
    cout << su->reverseStr(s,k);
}

void test3(){
    Solution* su = new Solution();
    string s = "abcdefghi";
    int k = 2;
    cout << su->reverseStr(s,k);
}

void test4(){
    Solution* su = new Solution();
    string s = "abcdefg";
    int k = 100;
    cout << su->reverseStr(s,k);
}

void test5(){
    Solution* su = new Solution();
    string s = "abcdefghijklmnopq";
    int k = 4;
    cout << su->reverseStr(s,k);
}

void test6(){
    Solution* su = new Solution();
    string s = "a";
    int k = 1;
    cout << su->reverseStr(s,k);
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
