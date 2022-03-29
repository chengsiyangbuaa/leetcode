#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        int write = len - 1;
        vector<int> return_list(len);
        while(left <= right && write >= 0){
            if(nums[left]*nums[left] > nums[right]*nums[right]){
                return_list[write] = (nums[left]*nums[left]);
                write--;
                left++;
            }else{
                return_list[write] = (nums[right]*nums[right]);
                write--;
                right--;
            }
        }
        return return_list;
    }
};

int main(){
    vector<int> nums = {-4,-1,0,3,10};
    vector<int> &nums_r =nums; 
    Solution s;
    vector<int> v = s.sortedSquares(nums_r);

    return 0;
}