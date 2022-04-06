#include<unordered_set>
#include<unordered_map>
#include<string>
#include<iostream>
#include<vector>

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
    // 错误做法，不能用hashset，要用hashmap
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     unordered_set<int> hashset(nums.begin(),nums.end());
    //     unordered_set<int> result_set;
    //     vector<int> result;
    //     int i1, i2;
    //     for(auto it = hashset.begin();it != hashset.end();++it){
    //         if(hashset.find(target-*it) != hashset.end()){
    //             i1 = *it;
    //             i2 = target - *it;
    //         }
    //     }
    //     for(int i = 0 ; i < nums.size() ; i++){
    //         if(nums[i] == i1)
    //             result_set.insert(i);
    //         if(nums[i] == i2)
    //             result_set.insert(i);
    //     }
    //     for(auto it = result_set.begin(); it != result_set.end(); ++it)
    //         result.push_back(*it);
    //     return result;
    // }

    //使用hashmap的做法
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0 ; i < nums.size() ; i++){
            auto it = map.find(target - nums[i]);
            if(it != map.end())
                return {i,it->second};
            map.insert(make_pair(nums[i],i));
        }
        return {};
    }

};

//答题区
void test1(){
    Solution* su = new Solution();
    int list[] = {2,7,11,15};
    vector<int> nums(list,list+4);
    int target = 9;
    printIntVector(su->twoSum(nums,target));
}

void test2(){
    Solution* su = new Solution();
    int list[] = {3,2,4};
    vector<int> nums(list,list+3);
    int target = 6;
    printIntVector(su->twoSum(nums,target));
}

void test3(){
    Solution* su = new Solution();
    int list[] = {3,3};
    vector<int> nums(list,list+3);
    int target = 6;
    printIntVector(su->twoSum(nums,target));
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