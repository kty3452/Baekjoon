#include <iostream>

using namespace std;

int main(){
    int A, B, C;
    cin >> A;
    cin >> B;
    cin >> C;
    int mul = 1;
    if(B >= 1000) mul = 10000;
    else if(B >= 100) mul = 1000;
    else if(B >= 10) mul = 100;
    else mul = 10;
    
    cout << A + B - C << "\n";
    cout << A * mul + B - C;
    
    return 0;
}