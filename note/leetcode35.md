# leetcode35

## 类型：二分查找

## 总结

有了704的二分查找基础，这道题只需要进行小小的改动就可以完成

## 思路

### 前提

- 有序数列
- 查找问题

### 方法

- 二分查找

### 具体问题

- target in nums 
  - 查找target位置
- target not in nums
  - 找到target的插入index
  - 通过举例子来归纳如何返回正确的值（草稿）

## 代码

```c++
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


```

## 草稿

![image-20220211163804255](http://tallestdaisy.oss-cn-beijing.aliyuncs.com/img/image-20220211163804255.png)