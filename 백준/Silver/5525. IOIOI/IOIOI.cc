// IOIOI

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    cin >> m;

    string IOI;
    cin >> IOI;

    int space = n * 2;
    int result = 0;

    for(int i = 0;i < m - space;i++){
        bool check_IOI = true;
        if(IOI[i] == 'I'){
            for(int j = i + 1;j <= i + space;j++){
                if(IOI[j] == IOI[j - 1]) {
                    check_IOI = false;
                    break;
                }
            }
            if(check_IOI) result++;
        }
    }
    cout << result;
    return 0;
}