#include<unordered_set>
#include<unordered_map>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printIntIntUnordered_map(unordered_map<int,int> map);
void printIntUnorderedSet(unordered_set<int> set);
void printIntVector(vector<int> a);
void printDoubleIntVector(vector<vector<int>> a);
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test(int i);
void testall(int i);

//答题区*********************************
class Solution {
public:

    //查看有多少尾部空格
    int tailspaces(string s){
        int count = 0;
        for(int i = s.size()-1 ; i >= 0 ; i--){
            if(s[i] != ' ')
                break;
            count++;
        }
        return count;
    }
    //消除尾部空格
    void deleteTailSpaces(string &s){
        s.resize(s.size() - tailspaces(s));
    }

    //查看首部有多少空格
    int headspaces(string s){
        int count = 0;
        for(int i = 0; i <s.size() ; i++){
            if(s[i] != ' ')
                break;
            count++;
        }
        return count;
    }

    //消除首部空格
    void deleteHeadSpace(string &s){
        int head = headspaces(s);
        movewordleft(s,head,s.size()-head,head);
        s.resize(s.size() - head);
    }


    //将单词向左移动
    void movewordleft(string &s, int start, int wordsize, int spacecounts){
        for(int i = start; i < start +wordsize ; i++){
            s[i - spacecounts] = s[i];
            if(spacecounts != 0)
                s[i] = ' ';
        }
    }
    
    //消除多余空格,返回多余空格数
    int deletespaces(string &s){
        int i = 0;
        int spacecounts = 0;
        while(i < s.size()){
            if(s[i] != ' ')
                i++;
            else{
                i++;
                while(s[i] == ' '){
                    spacecounts++;
                    i++;
                }
                int start = i;
                int wordsize = 0;
                while(i < s.size() && s[i] != ' '){
                    i++;
                    wordsize++;
                }
                movewordleft(s,start,wordsize,spacecounts);
            }
        }
        return spacecounts;
    }
    //消除多余空格
    void deleteOtherSpace(string &s){
        s.resize(s.size() - deletespaces(s));
    }
        

    //反转字符串
    void reverseString(string &s,int start, int end) {
        if(start < 0 || end >= s.size())
            return;
        int left = start;
        int right = end;
        while(left < end && right >= start && left < right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }

    //使用双指针做题
    //双指针消除多余空格
    void removespaces(string &s){
        int slow = 0;
        int fast = 0;
        int n = s.size();
        while(s[fast] == ' ')
            fast++;
        while(fast < n){
            if(s[fast] != ' '){
                s[slow] = s[fast];
                slow++;
                fast++;
            }else{//遇到空格
                while(fast < n){//去掉句中空格
                    if(fast == n-1){//以空格结尾
                        s.resize(slow);
                        return;
                    }
                    if(s[fast+1] == ' ')
                        fast++;
                    else{//单个空格赋值
                        s[slow] = s[fast];
                        slow++;
                        fast++;
                        break;
                    }
                }
            }
        }
        s.resize(slow);
    }

    string reverseWords(string s) {
        // //消除尾部空格
        // deleteTailSpaces(s);
        // //消除首部空格
        // deleteHeadSpace(s);
        // //消除多余空格
        // deleteOtherSpace(s);

        //使用双指针消除空格
        removespaces(s);

        //反转整个字符串
        int n = s.size();
        reverseString(s,0,n-1);
        //反转每个单词
        int left = 0;
        int right = 0;
        while(left < n && right < n){
            while(right < n && s[right] != ' ')
                right++;
            reverseString(s,left,right-1);
            right++;
            left = right;
        }
        return s;
    }
    };
//答题区*********************************
int main(){
    testall(6);
    return 0;
}
//测试
void test1(){
    Solution* su = new Solution();
    string s = "   the      sky     is        blue   ";
    su->removespaces(s);
    cout << s << endl;
    cout << s.size() << endl;
}

void test2(){
    Solution* su = new Solution();
    string s = "a good   example";
    s = su->reverseWords(s);
    cout << s << endl;
}

void test3(){
    Solution* su = new Solution();
    string s = "  hello world  ";
    s = su->reverseWords(s);
    cout << s << endl;
}

void test4(){
    Solution* su = new Solution();
    string s = "the      sky     is    h    blue";
    s = su->reverseWords(s);
    cout << s << endl;
}

void test5(){
    Solution* su = new Solution();
    string s = "the      sky     is    h    blue";
    
    su->deleteTailSpaces(s);
    //消除首部空格
    su->deleteHeadSpace(s);
    //消除多余空格
    su->deleteOtherSpace(s);
    int n = s.size();
    su->reverseString(s,0,n-1);
    cout << s << endl;
}

void test6(){
    Solution* su = new Solution();
    
}

void test(int i){
    cout << "test: "<< i<<" start!"<<endl;
    switch (i)
    {
    case 1:
        test1();
        break;
    case 2:
        test2();
        break;
    case 3:
        test3();
        break;
    case 4:
        test4();
        break;
    case 5:
        test5();
        break;
    case 6:
        test6();
        break;
    default:
        break;
    }
    cout <<endl<< "test: "<<i<<" end!"<<endl<<endl;
}

void testall(int i){
    int k = 6;
    for(int i = 1 ; i <= k ; i++ )
        test(i);
}

void printIntUnorderedSet(unordered_set<int> set){
     auto it = set.begin();
     while(it != set.end()){
        cout<<*it;
        ++it;
        if(it != set.end())
            cout<<" ";
        else
            cout<<endl;    
     }    
}

void printIntVector(vector<int> a){
    for(int i = 0 ; i < a.size() ; i++){
        cout<<a[i];
        if(i != a.size()-1)
            cout<<",";
        else
            cout<<endl;
    }
}

void printIntIntUnordered_map(unordered_map<int,int> map){
    auto it = map.begin();
    while(it != map.end()){
        cout << "<" << it->first << "," << it->second << ">";
        ++it;
        if(it != map.end())
            cout<<" ";
        else
            cout<<endl;
    }    
}

void printDoubleIntVector(vector<vector<int>> a){
    for(int j = 0 ; j < a.size() ; j++){
        for(int i = 0 ; i < a[j].size() ; i++){
                cout<<a[j][i];
                if(i != a[j].size()-1)
                    cout<<",";
                else
                    cout<<endl;
        }
    }
}
