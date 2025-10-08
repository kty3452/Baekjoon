#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string sic;
    cin >> sic;

    int first_idx = 0;
    string sics[50] = {"", };
    int result[50] = {0, };
    int cnt = 0;

    for(int i = 0;i <= sic.size();i++){
        if(i == sic.size()){
            sics[cnt++] = sic.substr(first_idx, i - first_idx);
        }
        else if(!isdigit(sic[i])){
            sics[cnt++] = sic.substr(first_idx, i - first_idx);
            if(sic[i] == '-') sics[cnt++] = sic[i];
            first_idx = i + 1;
        }
    }

    first_idx = 0;
    cnt = 0;
    int sum = 0;
    for(int i = 0;i < 50;i++){
        if(sics[i] == ""){
            result[cnt++] = sum;
            break;
        }
        else if(sics[i] == "-"){
            result[cnt++] = sum;
            sum = 0;
        }
        else{
            sum += stoi(sics[i]);
        }
    }
    for(int i = 1;i < 50;i++){\
        result[0] -= result[i];
    }
    cout << result[0];

    return 0;
}