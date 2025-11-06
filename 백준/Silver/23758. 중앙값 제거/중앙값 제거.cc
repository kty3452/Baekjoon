#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> V = {0};
    for(int i = 1;i <= n;i++){
        int num;
        cin >> num;
        V.push_back(num);
    }
    int pow_of_two[31];
    int base = 1;
    for(int i = 0;i < 31;i++){
        pow_of_two[i] = base;
        base <<= 1;
    }
    int end = (n + 1)/2;
    sort(V.begin() + 1, V.begin() + n + 1);
    int result = 0;
    
    for(int i = 1;i <= end;i++){
        for(int j = 30;j >= 0;j--){
            if(V[i] >= pow_of_two[j]){
                result += j;
                break;
            }
        }
    }

    cout << result + 1;

    return 0;
}