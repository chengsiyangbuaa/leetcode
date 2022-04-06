#include<string>
#include<vector>
#include<iostream> 

using namespace std;

void test1(){
    string s = "mingxuanshen";
    cout << s;
}

void test2(){
    string s = "mingxuanshen";
    string s1 = "xiaoqiezi";
    string s2 = s + s1;
    cout << s2;
}

void test3(){
    string s = "mingxuanshen";
    string s1 = "xiaoqiezi";
    string s2 = s + s1;
    cout <<"s.size() = " <<s.size()<<endl;
    cout <<"s1.size() = " <<s1.size()<<endl;
    cout <<"s2.size() = " <<s2.size()<<endl;
    cout <<"s[0] = "<<s[0]<< endl;
    cout <<"s[1] = "<<s[1]<< endl;
    cout <<"s[2] = "<<s[2]<< endl;
    cout <<"s[3] = "<<s[3]<< endl;
    cout <<"s[4] = "<<s[4]<< endl;
}

void test4(){
    long number = 1999999999;
    string str = to_string(number);
    long sum = 0;
    for(int i = 0 ; i < str.size() ; i++)
        sum += (int)(str[i]-'0')*(int)(str[i]-'0');
    cout << sum << endl;
}

void test5(){
    string s = "asdfgh";
    cout << s.size() << endl;
    s.resize(s.size() + 10);
    cout << s.size() << endl;
    cout << s << endl;   
    s.resize(s.size() - 13);
    cout << s.size() << endl;
    cout << s << endl;  
}

void test6(){
    string s = "12345678";
    string s1(s.begin(), s.begin()+4);
    cout << s1 << endl;
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

int main(){
    int k = 6;
    for(int i = 1 ; i <= k ; i++ )
        test(i);
    return 0;
}