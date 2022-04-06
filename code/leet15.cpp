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

int main(){
    testall(6);
    return 0;
}
//答题区*********************************
class Solution {
public:
    // 暴力,狗都不用
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     if(nums.size() < 3)
    //         return {};
    //     sort(nums.begin(), nums.end());
    //     unordered_set<int> hasBeenSet1;
    //     unordered_set<int> set(nums.begin(),nums.end());
    //     vector<vector<int>> result;
    //     for(int i = 0 ; i < nums.size() ; i++){
    //         if(hasBeenSet1.find(nums[i]) != hasBeenSet1.end())
    //             continue;
    //         hasBeenSet1.insert(nums[i]);
    //         unordered_set<int> hasBeenSet2;
    //         for(int j = i+1 ; j < nums.size() ; j++){
    //             unordered_set<int> hasBeenSet3;
    //             if(hasBeenSet2.find(nums[j]) != hasBeenSet2.end())
    //                 continue;
    //             hasBeenSet2.insert(nums[j]);
    //             for(int k = j+1 ; k < nums.size() ; k++){
    //                 if(hasBeenSet3.find(nums[k]) != hasBeenSet3.end())
    //                     continue;
    //                 hasBeenSet3.insert(nums[k]);
    //                 if(nums[i] + nums[j] + nums[k] == 0)
    //                     result.push_back({nums[i] , nums[j] , nums[k]});
    //             }
    //         }
    //     }
    //     return result;
    // }

    //用map做，没做出来
    //用双指针做
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < nums.size() ; i++){
            if(i-1 >=0 && nums[i] == nums[i-1])
                continue;
            int j = i+1;
            int k = nums.size()-1;
            while(j < k){
                if(j>=nums.size() || k<0 )
                    break;
                if(j-1 > i &&nums[j] == nums[j-1]){
                    j++;
                    continue;
                }
                if(k+1 < nums.size() && nums[k] == nums[k+1]){
                    k--;
                    continue;
                }
                if(nums[j]+nums[k]  == 0-nums[i]){
                    result.push_back({nums[i],nums[j],nums[k]});
                    // cout << nums[i] <<" " << nums[j]<<" " <<nums[k]<<endl;
                    j++;
                    k--;
                }else if(nums[j]+nums[k] > 0-nums[i])
                    k--;
                else
                    j++;
            }
        }
        return result;
    }
};
//答题区*********************************

//测试
void test1(){//[[-1,-1,2],[-1,0,1]]
    Solution* su = new Solution();
    int list[] = {-1,0,1,2,-1,-4};
    vector<int> nums(list, list+6);
    printDoubleIntVector(su->threeSum(nums));
}

void test2(){
    Solution* su = new Solution();
    int list[] = {-1,0,1,2,-1,-4,2};
    vector<int> nums(list, list+7);
    printDoubleIntVector(su->threeSum(nums));
}

void test3(){//[0,0,0]
    Solution* su = new Solution();
    int list[] = {0,0,0,0};
    vector<int> nums(list, list+4);
    printDoubleIntVector(su->threeSum(nums));
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
