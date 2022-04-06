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
    //两重循环+三数之和
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int length = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size() ; i++){
            if(length - 3 >= 0 && (long) nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target)
                continue;;//剪枝
            if(i+3 < length && (long) nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)
                break;//剪枝
            if(i-1 >=0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j = i + 1 ; j < length ; j++){
                if( j + 2 < length && (long) nums[i] + nums[j] + nums[j+1] + nums[j+2] > target)
                    break;//剪枝
                if(length - 2 >= 0 && (long) nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target)
                    continue;//剪枝
                if(j-1 >i && nums[j] == nums[j-1]){
                    continue;
                }
                int k = j+1;
                int l = length-1;
                while(k < l){
                    if(k>=length || l<0 )
                        break;
                    if(k-1 > j &&nums[k] == nums[k-1]){
                        k++;
                        continue;
                    }
                    if(l+1 < length && nums[l] == nums[l+1]){
                        l--;
                        continue;
                    }
                    long l1 = nums[i];
                    long l2 = nums[j];
                    long l3 = nums[k];
                    long l4 = nums[l];
                    long sum = l1+l2+l3+l4;
                    if(sum  == target){
                        result.push_back({nums[i],nums[j],nums[k],nums[l]});
                        // cout << nums[i] <<" " << nums[j]<<" " <<nums[k]<<endl;
                        k++;
                        l--;
                    }else if(sum > target)
                        l--;
                    else
                        k++;
                }
            }
        }
        return result;
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
    vector<int> nums({1,0,-1,0,-2,2});
    int target = 0;
    printDoubleIntVector(su->fourSum(nums,target));
}

void test2(){
    Solution* su = new Solution();
    vector<int> nums({2,2,2,2});
    int target = 8;
    printDoubleIntVector(su->fourSum(nums,target));
}

void test3(){
    Solution* su = new Solution();
    vector<int> nums({-4,-3,-2,-1,0,1,2,3,4});
    int target = 0;
    printDoubleIntVector(su->fourSum(nums,target));
}

void test4(){
    Solution* su = new Solution();
    vector<int> nums({-3,-1,0,2,4,5});
    int target = 2;
    printDoubleIntVector(su->fourSum(nums,target));
}

void test5(){
    Solution* su = new Solution();
    vector<int> nums({-1,0,1,2,-1,-4});
    int target = -1;
    printDoubleIntVector(su->fourSum(nums,target));
}

void test6(){
    Solution* su = new Solution();
    vector<int> nums({0});
    int target = 0;
    printDoubleIntVector(su->fourSum(nums,target));
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
