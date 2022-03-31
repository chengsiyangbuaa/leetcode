#include<string>
#include<iostream>
#include<vector>
#include <unordered_set>

using namespace std;

void printIntVector(vector<int> a){
    for(int i = 0 ; i < a.size() ; i++){
        cout<<a[i];
        if(i != a.size()-1)
            cout<<",";
        else
            cout<<endl;
    }
}

//答题区
class Solution {
public:
    //使用数组哈希实现，浪费空间,狗都不用
    // vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //     vector<int> hashtable_nums1(1001,0);
    //     vector<int> hashtable_nums2(1001,0);
    //     vector<int> result(0);
    //     for(int i = 0 ; i < nums1.size() ; i++)
    //         hashtable_nums1[nums1[i]]++;
    //     for(int i = 0 ; i < nums2.size() ; i++)
    //         hashtable_nums2[nums2[i]]++;
    //     for(int i = 0 ; i < hashtable_nums1.size() ; i++){
    //         if(hashtable_nums1[i] != 0 && hashtable_nums2[i] != 0)
    //             result.push_back(i);
    //     }
    //     return result;
    // }

    //使用STL的unordered_set实现
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // vector<int> hashtable_nums1(1001,0);
        // vector<int> hashtable_nums2(1001,0);
        unordered_set<int> set1(nums1.begin(),nums1.end());
        unordered_set<int> result_set;
        for(auto it = nums2.begin(); it != nums2.end(); ++it){
            if(set1.find(*it) != set1.end())
                result_set.insert(*it);
        }
        vector<int> result(result_set.begin(),result_set.end());
        return result;
    }
};
//答题区

void test1(){
    Solution* su = new Solution();
    int nums1[] = {1,2,2,1};
    int nums2[] = {1,2,3,1};
    vector<int> v1(nums1,nums1+4);
    vector<int> v2(nums2,nums2+4);
    printIntVector(su->intersection(v1,v2));
}

void test2(){
    Solution* su = new Solution();
    int nums1[] = {1,2,4,5,6,7,2,1};
    int nums2[] = {1,2,3,1,8,7,5,9,10};
    vector<int> v1(nums1,nums1+8);
    vector<int> v2(nums2,nums2+9);
    printIntVector(su->intersection(v1,v2));
}

void test3(){
    Solution* su = new Solution();
    int nums1[] = {4,9,5};
    int nums2[] = {9,4,9,8,4};
    vector<int> v1(nums1,nums1+3);
    vector<int> v2(nums2,nums2+5);
    printIntVector(su->intersection(v1,v2));
}

int main(){
    test1();
    test2();
    test3();
    return 0;
}