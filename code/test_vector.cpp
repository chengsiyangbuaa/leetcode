#include<vector>
#include<iostream> 
using namespace std;

void printIntVector(vector<int> a){
    for(int i = 0 ; i < a.size() ; i++){
        cout<<a[i];
        if(i != a.size()-1)
            cout<<",";
        else
            cout<<endl;
    }
}

void test1(){
    vector<int> a(10);
    printIntVector(a);
}

void test2(){
    vector<int> a(10,1);
    printIntVector(a);
}

void test3(){
    vector<int> a(10,1);
    vector<int> b(a);
    printIntVector(b);
}

void test4(){
    vector<int> a(10,1);
    vector<int> b(a.begin(),a.begin()+3);
    printIntVector(b);
}

void test5(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> b(a,a+10);
    printIntVector(b);
}

void test6(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> b(a,a+10);
    b.push_back(11);
    b.push_back(12);
    b.push_back(13);
    printIntVector(b);
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