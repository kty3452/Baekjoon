// 과일 탕후루

#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    static int fruits[200001][2] = {0, };
    int idx = 0, cnt = 0, prev_fruit = 0;
    for(int i = 0;i < n;i++){
        int fruit;
        cin >> fruit;
        if(fruit != prev_fruit) {
            fruits[idx][0] = prev_fruit;
            fruits[idx++][1] = cnt;
            cnt = 0;
        }
        prev_fruit = fruit;
        cnt++;
    }
    fruits[idx][0] = prev_fruit;
    fruits[idx][1] = cnt;

    cnt = 0;
    bool contained[10] = {false, };
    int max = 0, sum = 0;
    for(int i = 1;i <= n;i++){
        if(fruits[i][1] == 0) break;
        if(cnt < 2 || (cnt >= 2 && contained[fruits[i][0]] == true)){
            sum += fruits[i][1];
            if(contained[fruits[i][0]] == false) {
                cnt++;
                contained[fruits[i][0]] = true;
            }
        }
        else if(cnt >= 2 && contained[fruits[i][0]] == false){
            max = max > sum ? max : sum; 
            sum = fruits[--i][1];
            for(int j = 0;j < 10;j++) contained[j] = false;
            contained[fruits[i][0]] = true;
            cnt = 1;
        }
    }

    max = max > sum ? max : sum; 
    cout << max;
}