#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hashtable_s(256,0);
        vector<int> hashtable_t(256,0);

        if(s.size() != t.size())
            return false; 
        
        for(int i = 0 ; i < s.size() ; i++)
            hashtable_s[s[i]]++;

        for(int i = 0 ; i < t.size() ; i++)
            hashtable_t[t[i]]++;

        for(int i = 0 ; i < 256 ; i++){
            if(hashtable_s[i] != hashtable_t[i])
                return false;
        }
        return true;
    }
};


int main(){
    Solution* su = new Solution();
    cout<<su->isAnagram("anagram","nagaram")<<endl;
    cout<<su->isAnagram("anagram","anagram")<<endl;
    cout<<su->isAnagram("a","b")<<endl;
    cout<<su->isAnagram("a","ab")<<endl;
    return 0;
}