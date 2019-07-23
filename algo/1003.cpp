#include<stdio.h>
#include<stdlib.h>

int arr[42][2];

int main() {

	arr[0][0] = 1; arr[0][1] = 0;
	arr[1][0] = 0; arr[1][1] = 1;
	for (int i = 2; i < 42; i++) {
		arr[i][0] = arr[i - 2][0] + arr[i - 1][0];
		arr[i][1] = arr[i - 2][1] + arr[i - 1][1];
	}



	int T,n;
	scanf("%d",&T);
	for (int t = 0; t < T; t++) {
		scanf("%d",&n);
		printf("%d %d\n",arr[n][0],arr[n][1]);


	}


	return 0;
}