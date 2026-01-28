using namespace std;
#include <iostream>
#include <algorithm>

int main(){
    const int STANDARD = 0;
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int l = 0, r = n - 1, result = 2000000001, resultL = arr[l], resultR = arr[r];
    while(l < r){
        int temp = arr[l] + arr[r];
        int gap = temp > STANDARD ? temp : -temp;
        if(gap < result){
            result = gap;
            resultL = arr[l];
            resultR = arr[r];
        }
        l += (temp < STANDARD);
        r -= (temp > STANDARD);
        if(gap == STANDARD) break;
    }
    cout << resultL << " " << resultR;
    return 0;
}