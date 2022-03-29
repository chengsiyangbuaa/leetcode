#include <iostream>
using namespace std;

int main(){
    cout << "hello world!"<<endl;
    int x;
    cin >> x;
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
        if(number == x){
            cout << middle;
            return middle;
        }
        else if(number < x)
            low = middle + 1;
        else
            high = middle - 1;
    }
    cout << high;
    return 0;
}
// @lc code=end

