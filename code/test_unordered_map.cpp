#include<unordered_set>
#include<unordered_map>
#include<string>
#include<iostream>
#include<vector>

using namespace std;

void printIntIntUnordered_map(unordered_map<int,int> map);
void printIntUnorderedSet(unordered_set<int> set);
void printIntVector(vector<int> a);
void printDoubleIntVector(vector<vector<int>> a);

void test1(){
    unordered_map<int,int> map{{1,3},{2,4}};
    cout << map.begin()->first<<","<<map.begin()->second << endl;
    cout << (++map.begin())->first<<","<<(++map.begin())->second << endl;
}

void test2(){
    unordered_map<int,int> map;
    map.insert(make_pair(3,6));
    map.insert(make_pair(4,8));
    map.insert(make_pair(5,10));
    cout <<"people container has " << map.bucket_count()<<" buckets."<<endl;
    auto pr = map.insert(make_pair(6,12));
    cout << "Element " << (pr.second ? "was" : "was not") << " inserted." <<endl; 
    cout << pr.first->first <<","<< pr.first->second << endl;
    pr = map.insert(make_pair(6,15));
    cout << "Element " << (pr.second ? "was" : "was not") << " inserted." <<endl; 
    cout << pr.first->first <<","<< pr.first->second << endl;
}

void test3(){
    unordered_map<int,int> map;
    map[1] = 1;
    printIntIntUnordered_map(map);
    map[1]++;
    printIntIntUnordered_map(map);
}

void test4(){
    unordered_map<int,int> map;
    map[1]++;
    printIntIntUnordered_map(map);
}

void test5(){
    unordered_map<int,vector<int>> map;
    map[1].push_back(3);
    auto it = map.begin();
    cout << it->first<<" ";
    printIntVector(it->second);
    cout << endl;
}

void test6(){
    
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