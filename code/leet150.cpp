#include<unordered_set>
#include<unordered_map>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

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
    int evalRPN(vector<string>& tokens) {
        int result;
        stack<int> sta;
        for(int i = 0 ; i < tokens.size() ; i++){
            int temp1;
            int temp2;
            if(tokens[i] == "/"){
                temp1 = sta.top();
                sta.pop();
                temp2 = sta.top();
                sta.pop();
                sta.push(temp2/temp1);
            }else if(tokens[i] == "*"){
                temp1 = sta.top();
                sta.pop();
                temp2 = sta.top();
                sta.pop();
                sta.push(temp1*temp2);
            }else if(tokens[i] == "+"){
                temp1 = sta.top();
                sta.pop();
                temp2 = sta.top();
                sta.pop();
                sta.push(temp1 + temp2);
            }else if(tokens[i] == "-"){
                temp1 = sta.top();
                sta.pop();
                temp2 = sta.top();
                sta.pop();
                sta.push(temp2-temp1);
            }else
                sta.push(stoi(tokens[i]));
        }
        

        return sta.top();
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
    vector<string> tokens{"2","1","+","3","*"};
    cout << su->evalRPN(tokens);
}

void test2(){
    Solution* su = new Solution();
    vector<string> tokens{"4","13","5","/","+"};
    cout << su->evalRPN(tokens);
}

void test3(){
    Solution* su = new Solution();
    vector<string> tokens{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << su->evalRPN(tokens);
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
