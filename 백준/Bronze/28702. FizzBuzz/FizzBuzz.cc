#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string FB[3];
    cin >> FB[0];
    cin >> FB[1];
    cin >> FB[2];
    int idx = 0;

    for(int i = 0;i < 3;i++){
        if(all_of(FB[i].begin(), FB[i].end(), ::isdigit)){
            idx = i;
            break;
        } 
    }

    int result = stoi(FB[idx]) + (3 - idx);
    if(result % 3 == 0 && result % 5 == 0) cout << "FizzBuzz";
    else if(result % 3 == 0) cout << "Fizz";
    else if(result % 5 == 0) cout << "Buzz";
    else cout << result;

    return 0;
}