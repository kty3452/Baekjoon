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
    int cnt = 0;
    bool check_IOI = true;
    static int IOI_N[1000001] = {0, };
    for(int i = 0;i < m - 1;i++){
        if(IOI[i] == 'I') check_IOI = true;
        if(check_IOI) cnt++;
        if(IOI[i] == IOI[i + 1]) {
            check_IOI = false;
            if(cnt & 1 == 1) IOI_N[cnt/2]++;
            else IOI_N[(cnt-1)/2]++;
            cnt = 0;
        }
    }
    IOI_N[cnt/2]++;
    
    int result = 0;
    for(int i = n;i <= 1000000;i++){
        result += ((i - n + 1) * IOI_N[i]);
    }
    cout << result;
    return 0;
}