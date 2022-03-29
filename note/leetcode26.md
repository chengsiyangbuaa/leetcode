## 思路

![image-20220218214251829](http://tallestdaisy.oss-cn-beijing.aliyuncs.com/img/image-20220218214251829.png)

## 代码

```C++
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        long current_number = -10001;
        long write_point = 0;
        for(long i = 0 ; i < nums.size(); i++){
            if(nums[i]!=current_number){
                nums[write_point] = nums[i];
                current_number = nums[i];
                write_point++;
            }
        }
        return write_point;
    }
};

int main(){
    vector<long> nums = {1,1,1,2,2,2,2,2,3,3,3,4,5,6,7,7,7,7};
    long current_number = -10001;
    long write_point = 0;
    for(long i = 0 ; i < nums.size(); i++){
        if(nums[i]!=current_number){
            nums[write_point] = nums[i];
            current_number = nums[i];
            write_point++;
        }
    }
    return 0;
}
```

