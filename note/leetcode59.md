# leetcode59

## 思路

![image-20220220120211301](http://tallestdaisy.oss-cn-beijing.aliyuncs.com/img/image-20220220120211301.png)

![image-20220220120228062](http://tallestdaisy.oss-cn-beijing.aliyuncs.com/img/image-20220220120228062.png)

## 代码

```c++
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n,vector<int>(n,0));
        int row = 0;
        int column = 0;
        int move = 0;
        int min_row = 0;
        int min_column = 0;
        int max_row = n - 1;
        int max_column = n - 1;
        for(int i = +1 ; i <= n*n ; i++){
            result[row][column] = i;
            move%=4;
            switch(move){
                case 0:
                    if(column == max_column){
                        move++;
                        min_row++;
                        row++;
                    }else{
                        column++;
                    }
                    break;
                case 1:
                    if(row == max_row){
                        move++;
                        max_column--;
                        column--;
                    }else{
                        row++;
                    }
                    break;
                case 2:
                    if(column == min_column){
                        move++;
                        max_row--;
                        row--;
                    }else{
                        column--;
                    }
                    break;
                case 3:
                    if(row == min_row){
                        move++;
                        min_column++;
                        column++;
                    }else{
                        row--;
                    }
                    break;
            }
        }
        return result;
    }
};


int main(){
    int n = 4;
    Solution su;
    su.generateMatrix(n);
}
```

