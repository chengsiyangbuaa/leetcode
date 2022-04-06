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
    string replaceSpace(string s) {
        int n = s.size();
        int count = 0;
        for(char c : s){
            if(c == ' ')
                count++;
        }
        s.resize(n+2*count);
        for(int i = n -1; i >= 0 ; i--){
            if(s[i] == ' '){
                s[i + 2*count] = '0';
                s[i + 2*count - 1] = '2';
                s[i + 2*count - 2] = '%';
                count--;
            }else
                s[i+2*count] = s[i];
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
    string s = "We are happy.";
    cout << su->replaceSpace(s);
}

void test2(){
    Solution* su = new Solution();
    string s = "     ";
    cout << su->replaceSpace(s);
}

void test3(){
    Solution* su = new Solution();
    string s = "     .....";
    cout << su->replaceSpace(s);
}

void test4(){
    Solution* su = new Solution();
    string s = ".....";
    cout << su->replaceSpace(s);
}

void test5(){
    Solution* su = new Solution();
    string s = "";
    cout << su->replaceSpace(s);
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
