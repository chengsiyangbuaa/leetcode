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

    //暴力做法
    // bool is_string(string haystack, string needle,int s){
    //     if(haystack.size() - s < needle.size())
    //         return false;
    //     for(int i = 0; i < needle.size() ; i++){
    //         if(haystack[i+s] != needle[i])
    //             return false;
    //     }
    //     return true;
    // }
    // int strStr(string haystack, string needle) {
    //     if(needle.size() == 0)
    //         return 0;
    //     for(int i = 0 ; i < haystack.size() ; i++){
    //         if(is_string(haystack, needle, i))
    //             return i;
    //     }
    //     return -1;
    // }

    //KMP
    bool isFrontEndSubEqual(string needle, int maxIndex, int subsize){
        for(int i = subsize ; i>=0 ; i--){
            if(needle[subsize - i] != needle[maxIndex-i])
                return false;
        }
        return true;
    }

    int getMaxFrontEndSub(string needle, int maxIndex){
        if(maxIndex == 0)
            return 0;
        int result = 0;
        for(int a = 0 ; a < maxIndex ; a++){
            if(isFrontEndSubEqual(needle, maxIndex, a))
                result = a+1;
        }
        return result;
    }

    vector<int> computeNextArray(string needle){
        int n = needle.size();
        vector<int> result(n,0);
        for(int i = 0 ; i <  n- 1 ; i++)
            result[i] = getMaxFrontEndSub(needle,i);
        
        return result;
    }

    int strStr(string haystack, string needle) {
        vector<int> nextArray = computeNextArray(needle);
        int size_h = haystack.size();
        int size_n = needle.size();
        if(size_n == 0)
            return 0;
        int np = 0;
        int hp = 0;
        while(np < size_n && hp < size_h){
            if(np == 0){
                if(haystack[hp] != needle[np]){
                    hp++;
                    continue;
                }
            }

            if(haystack[hp] == needle[np]){
                np++;
                hp++;
            }else
                np = nextArray[np-1];
            
            if(np == size_n)
                return hp- size_n;
        }
        return -1;
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
    string haystack  = "aabaabaaf";
    string needle = "aabaaf";
    cout << su->strStr(haystack, needle);
}

void test2(){
    Solution* su = new Solution();
    string haystack  = "aabaacaabaaf";
    string needle = "aabaaf";
    cout << su->strStr(haystack, needle);
}

void test3(){
    Solution* su = new Solution();
    string haystack  = "ababcaababcaabc";
    string needle = "ababcaabc";
    cout << su->strStr(haystack, needle);
}

void test4(){
    Solution* su = new Solution();
    string haystack  = "sllo";
    string needle = "lls";
    cout << su->strStr(haystack, needle);
}

void test5(){
    Solution* su = new Solution();
    string haystack  = "";
    string needle = "llswed";
    cout << su->strStr(haystack, needle);
    
}

void test6(){
    Solution* su = new Solution();
    string needle = "aabaaf";
    printIntVector(su->computeNextArray(needle));
    printIntVector(su->computeNextArray("aaabaaa"));
    printIntVector(su->computeNextArray("aaaaaaa"));
    printIntVector(su->computeNextArray("aabaaf"));
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
