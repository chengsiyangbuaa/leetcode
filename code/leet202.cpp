#include<unordered_set>
#include<string>
#include<iostream>
#include<vector>

using namespace std;

//答题区
class Solution {
public:

    //计算每一位的平方
    int computeSumBitsSqar(int number){
        string str = to_string(number);
        int sum = 0;
        for(int i = 0 ; i < str.size() ; i++)
            sum += (int)(str[i]-'0')*(int)(str[i]-'0');
        return sum;
    }
    //使用数组哈希，浪费空间，狗都不用
    // bool isHappy(int n) {
    //     int current = n;
    //     vector<bool> hashtable_n(65536,false);
    //     while(current != 1){
    //         current = computeSumBitsSqar(current);
    //         if(hashtable_n[current])
    //             return false;
    //         hashtable_n[current] = true;
    //     }
    //     return true;
    // }

    //使用unordered_set
    bool isHappy(int n) {
        int current = n;
        // vector<bool> hashtable_n(65536,false);
        unordered_set<int> hashset;
        while(current != 1){
            current = computeSumBitsSqar(current);
            if(hashset.find(current) != hashset.end())
                return false;
            hashset.insert(current);
        }
        return true;
    }
};

//答题区
void test1(){
    Solution* su = new Solution();
    int n = 100;
    cout << su->isHappy(n)<<endl;
}

void test2(){
    Solution* su = new Solution();
    int n = 2;
    cout << su->isHappy(n)<<endl;
}

void test3(){
    Solution* su = new Solution();
    int n = 58;
    cout << su->isHappy(n)<<endl;
}

void test4(){
    Solution* su = new Solution();
    int n = 42;
    cout << su->isHappy(n)<<endl;
}

void test5(){
    Solution* su = new Solution();
    int n = 1999999999;
    cout << su->isHappy(n)<<endl;
}

void test6(){
    Solution* su = new Solution();
    int n = 19;
    cout << su->isHappy(n)<<endl;
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