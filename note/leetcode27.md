## 思路1

这个思路和官方的思路1一样，能够使原来的数组**保留元素的相对位置不变**。

但是题目的要求是保留元素的**相对位置可以改变**。所以可以用更高效的方法。

![image-20220217213154779](http://tallestdaisy.oss-cn-beijing.aliyuncs.com/img/image-20220217213154779.png)

### 缺点

![image-20220217215152418](http://tallestdaisy.oss-cn-beijing.aliyuncs.com/img/image-20220217215152418.png)

## 思路2

![image-20220217215212632](http://tallestdaisy.oss-cn-beijing.aliyuncs.com/img/image-20220217215212632.png)

## 代码

```c++
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
```

