/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
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
        return low;
    }
};
// @lc code=end

