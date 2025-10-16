#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        string AC;
        cin >> AC;
        int n;
        cin >> n;
        int X[100001] = {0, };   // static 제거
        int idx = 1;
        string arr;
        cin >> arr;
        string num = "";
        for(int i = 0;i < arr.size();i++){
            if(isdigit(arr[i])) num += arr[i];
            if((arr[i] == ',' || arr[i] == ']') && !num.empty()) {
                X[idx++] = stoi(num);
                num = "";
            };
        }

        int head = 1, tail = n;
        int R = 0;

        for(auto c : AC){
            if(c == 'R') R++;
            else{
                if(head > tail){ // 배열 비었는데 D 수행
                    cout << "error\n";
                    goto end;
                }
                if(R % 2 == 0) head++;
                else tail--;
            }
        }

        if(R % 2 == 0){
            cout << "[";
            for(int i = head; i <= tail; i++){
                cout << X[i];
                if(i != tail) cout << ",";
            }
            cout << "]\n";
        }
        else{
            cout << "[";
            for(int i = tail; i >= head; i--){
                cout << X[i];
                if(i != head) cout << ",";
            }
            cout << "]\n";
        }

        end:;
    }

    return 0;
}
