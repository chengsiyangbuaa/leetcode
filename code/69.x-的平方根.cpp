/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        long max = 1;
        int max_pow = 16;
        for(int i = 0 ; i < max_pow ; i++){
            max *= 2;
        }
        long low = 0;
        long high = max;
        while(low <= high){
            long middle = (low+high)/2;
            long number = middle*middle;
            if(number == x)
                return middle;
            else if(number < x)
                low = middle + 1;
            else
                high = middle - 1;
        }
        return high;
    }
};

// @lc code=end

