#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    
    void init_t_count(vector<int>& t_count,string t){
        for(int i = 0 ; i < t.length() ; i++){
            t_count[t.at(i)]++;
        }
    }

    bool is_enough(vector<int> &s_count,vector<int> &t_count){
        for(int i = 'a' ; i <= 'z' ; i++){
            if(s_count[i] < t_count[i]){
                return false;
            }
        }
        for(int i = 'A' ; i <= 'Z' ; i++){
            if(s_count[i] < t_count[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int> s_count(256);
        vector<int> t_count(256);
        init_t_count(t_count,t);
        int len = s.size();
        int min_left = -1;
        int min_right = -1;
        int left = 0;
        int right = 0;
        int min_len = -1;
        while(right <= len){//right需要能够溢出，因为在这种情况下，left需要进行收敛，不可以直接停止
            if(is_enough(s_count,t_count)){
                if(min_len > right - left || min_len == -1){
                    min_len = right - left ;
                    min_left = left;
                    min_right = right;
                }
                s_count[s.at(left)]--;
                left++;
            }else{
                if(right >= len){//如果溢出则break
                    break;
                }
                s_count[s.at(right)]++;
                right++;
            }
        }
        if(min_len == -1){
            return "";
        }else{
            return s.substr(min_left,min_right-min_left);
        }
    }
};


int main(){
    string s = "AoooBBCDOABECODEANC";
    string t = "ABfC";
    Solution su;
    cout << su.minWindow(s,t);
    return 0;
}