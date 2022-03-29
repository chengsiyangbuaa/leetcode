# leetcode704

## 类型：二分查找

## 总结

### 二分查找边界问题

#### 初始设置

- low的设置，low=0
- high的设置，high=size()-1
- middle的设置，middle = (low+high)/2
- low和high的含义是**数组的下标**，**意义是当前窗口的位置**
- **窗口内的所有数字都有可能是target**

#### 迭代设置

##### 迭代逻辑

- 二分查找是为了从**有序数列**中快速找到target
- 当nums[middle] = target时，返回middle(**迭代终结条件，跳出函数**)，middle就是target的下标
- 当nums[middle] > target时，说明这个数列中，包含middle，middle右侧的(**默认升序**)所有数都不可能是target
  - low不变
  - high改变，变为middle-1
  - 此时，[low，high]窗口中的数字均有可能是target
- 当nums[middle] > target时，说明这个数列中，包含middle，middle左侧的(**默认升序**)所有数都不可能是target
  - high不变
  - low改变，变为middle+1
  - 此时，[low，high]窗口中的数字均有可能是target
- 终结条件
  - 窗口的大小为 < 0
  - 即high < low

## 思路

### 前提条件

- 有序数列
- 查找问题

### 方法

- 二分查找

### 具体问题

- 找target的index

## 代码

```c++
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
```



## 草稿

![image-20220211162546403](http://tallestdaisy.oss-cn-beijing.aliyuncs.com/img/image-20220211162546403.png)

