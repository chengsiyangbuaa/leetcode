# leetcode209

## 思路

![image-20220219210239925](http://tallestdaisy.oss-cn-beijing.aliyuncs.com/img/image-20220219210239925.png)

## 代码

```c++
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long len = nums.size();
        int left = 0;
        int right = 0;
        int min_len = -1;
        int cur_sum = 0;
        while(right <= len && min_len != 1){ //允许right越界,因为越界的情况，还要继续考虑left的动态变化，left有可能继续收敛
            if(cur_sum < target){
                if(right >= len){//如果访问越界，则break
                    break;
                }
                cur_sum += nums[right];
                right++;
            }else{
                if(right - left < min_len || min_len == -1){
                    min_len = right - left;
                }
                cur_sum -= nums[left];
                left++;
            }
        }
        if(min_len == -1){
            return 0;
        }else{
            return min_len;
        }
        return min_len;
    }
};

int main(){
    vector<int> nums = {2,3,1,2,4,3};
    vector<int> &nums_r =nums; 
    Solution s;
    s.minSubArrayLen(7,nums_r);
    return 0;
}
```

