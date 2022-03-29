#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // int len = nums.size();
        // int j = 0;
        // for(int i = 0 ; i < len ; i++){
        //     if(nums[i] != val){
        //         nums[j] = nums[i];
        //         j++;
        //     }
        // }
        // return j;

        //优化双指针
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        while(left <= right){
            if(nums[right] == val){
                right--;    
                continue;
            }
            if(nums[left] == val){
                nums[left] = nums[right];
                right--;
            }
            left++;
        }
        return left;
    }   
};

int main(){
    int val = 3;
    vector<int> nums = {3,7,3,5,3,6};
    int len = nums.size();
    int j = 0;
    for(int i = 0 ; i < len ; i++){
        if(nums[i] != val){
            nums[j] = nums[i];
            j++;
        }
    }
}