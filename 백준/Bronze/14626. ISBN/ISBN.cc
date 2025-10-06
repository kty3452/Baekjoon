#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string isbn;
    cin >> isbn;
    int store[10] = {0, 7, 4, 1, 8, 5, 2, 9, 6, 3};
    int sum = 0;
    int idx = 0;
    for(int i = 0;i < isbn.length();i++){
        if(isbn[i] != '*'){
            if(i % 2 == 0) sum += (isbn[i] - 48);
            else sum += ((isbn[i] - 48) * 3);
        }
        else idx = i;
    }
    sum %= 10;
    if(idx % 2 == 0) cout << (10 - sum) % 10;
    else cout << store[(10 - sum) % 10];

    return 0;
}