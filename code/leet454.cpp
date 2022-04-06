#include<unordered_set>
#include<unordered_map>
#include<string>
#include<iostream>
#include<vector>

using namespace std;

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

//答题区
class Solution {
public:
    //暴力解决,狗都不用，汪汪
    // int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    //     int count = 0;
    //     for(int i : nums1){
    //         for(int j : nums2){
    //             for(int k : nums3){
    //                 for(int l : nums4){
    //                     if(i+j+k+l == 0)
    //                         count++;
    //                 }
    //             }
    //         }
    //     }
    //     return count;
    // }

    //用hashmap做
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count = 0;
        unordered_map<int,int> map1;
        unordered_map<int,int> map2;
        for(int i : nums1){
            for(int j : nums2)
                map1[i+j]++;
        }
        for(int i : nums3){
            for(int j : nums4)
                map2[i+j]++;
        }
        for(auto it = map1.begin() ; it != map1.end() ; ++it){
            if(map2.find(0 - it->first) != map2.end())
                count += it->second * map2[0 - it->first];
        }
        return count;
    }
};

//答题区
void test1(){
    Solution* su = new Solution();
    int list1[] = {1,2};
    int list2[] = {-2,-1};
    int list3[] = {-1,2};
    int list4[] = {0,2};
    vector<int> nums1(list1,list1+2);
    vector<int> nums2(list2,list2+2);
    vector<int> nums3(list3,list3+2);
    vector<int> nums4(list4,list4+2);
    cout << su->fourSumCount(nums1,nums2,nums3,nums4)<<endl;
}

void test2(){
    Solution* su = new Solution();
    int list1[] = {0};
    int list2[] = {0};
    int list3[] = {0};
    int list4[] = {0};
    vector<int> nums1(list1,list1+1);
    vector<int> nums2(list2,list2+1);
    vector<int> nums3(list3,list3+1);
    vector<int> nums4(list4,list4+1);
    cout << su->fourSumCount(nums1,nums2,nums3,nums4)<<endl;
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