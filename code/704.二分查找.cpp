/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = (low+high)/2;
            int num = nums[mid];
            if(num == target){
                return mid;
            } else if(num < target){
                low = mid + 1;
            } else{
                high = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end

