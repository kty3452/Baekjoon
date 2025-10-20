#include <iostream>
#include <queue>

using namespace std;

void D(int cv, string numbers[], queue<int> &Q){
    int nv = cv * 2;
    if(nv >= 10000) nv %= 10000;
    if(numbers[nv] == "") {
        numbers[nv] = numbers[cv] + "D";
        Q.push(nv);
    }

}
void S(int cv, string numbers[], queue<int> &Q){
    int nv;
    if(cv <= 0) nv = 9999;
    else nv = cv - 1;
    
    if(numbers[nv] == "") {
        numbers[nv] = numbers[cv] + "S";
        Q.push(nv);
    }
}
void L(int cv, string numbers[], queue<int> &Q){
    int nv = ((cv * 10) + (cv / 1000)) % 10000;
    if(numbers[nv] == "") {
        numbers[nv] = numbers[cv] + "L";
        Q.push(nv);
    }
}
void R(int cv, string numbers[], queue<int> &Q){
    int nv = (cv / 10) + ((cv % 10) * 1000);
    if(numbers[nv] == "") {
        numbers[nv] = numbers[cv] + "R";
        Q.push(nv);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    while(n--){
        int start, end;
        cin >> start >> end;

        string numbers[10001] = {"", };
        numbers[start] = "start";
        queue<int> Q;
        Q.push(start);
        while(!Q.empty()){
            int cv = Q.front();
            Q.pop();
            D(cv, numbers, Q);
            S(cv, numbers, Q);
            L(cv, numbers, Q);
            R(cv, numbers, Q);
            if(numbers[end] != "") break;
        }
        cout << numbers[end].substr(5) << "\n";
    }
}