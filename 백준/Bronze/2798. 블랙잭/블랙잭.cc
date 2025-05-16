#include <iostream>
using namespace std;

int main(void){
	int N, M, max = -1, sum;
	cin>>N;
	cin>>M;
	int arr[N];
	for(int i = 0;i < N;i++){
		cin>>arr[i];
	}
	for(int i = 0;i < N - 2;i++){
		for(int j = i+1;j < N - 1;j++){
			for(int k = j+1;k < N;k++){
				sum = arr[i] + arr[j] + arr[k];
				if(sum <= M&&sum > max){
					max = sum;
				}
			}
		}
	}
	cout<<max;
}