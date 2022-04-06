#include<unordered_set>
#include<unordered_map>
#include<string>
#include<iostream>
#include<vector>

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
    void Islegallist(int numlist[], int M, int N)
{
    int left = numlist[0];
    int right = numlist[0]; //左右浮标初始化为首个数字
    int tag = 1;            //标记是否合法
    for (int i = 0; i < N; i++)
    {
        if (numlist[i] > M + i) //排除栈满的情况
        {
            tag = 0;
            break;
        }
        if (i != 0)
        {
            if (numlist[i] == left - 1)
                left--;
            else if (numlist[i] == right + 1)
                right++;
            else
            {
                tag = 0;
                break;
            }
        }
    }

    if (tag == 1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}
};
//答题区*********************************
int main(){
    testall(6);
    return 0;
}
//测试
void test1(){//F
    Solution* su = new Solution();
    int numlist[] = {6,5,4,3,2,1,7};
    int M = 5;
    int N = 7;
    su->Islegallist(numlist,M,N);
}

void test2(){//F
    Solution* su = new Solution();
    int numlist[] = {7,6,5,4,3,2,1};
    int M = 5;
    int N = 7;
    su->Islegallist(numlist,M,N);
}

void test3(){//T
    Solution* su = new Solution();
    int numlist[] = {3,2,1,7,6,5,4};
    int M = 5;
    int N = 7;
    su->Islegallist(numlist,M,N);
}

void test4(){//T
    Solution* su = new Solution();
    int numlist[] = {1,3,2,6,5,4,7};
    int M = 5;
    int N = 7;
    su->Islegallist(numlist,M,N);
}

void test5(){//T
    Solution* su = new Solution();
    int numlist[] = {2,1,3,4,5,7,6};
    int M = 5;
    int N = 7;
    su->Islegallist(numlist,M,N);
}

void test6(){//F
    Solution* su = new Solution();
    int numlist[] = {3,1,2,4,5,6,7};
    int M = 5;
    int N = 7;
    su->Islegallist(numlist,M,N);
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
