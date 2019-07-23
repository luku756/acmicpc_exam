#include<stdio.h>
#include<stdlib.h>

#define SIZE 32
//시작점, 끝점, 점의 수(다리의 수)
int arr[SIZE][SIZE][SIZE];

int main() {

	//다리의 수가 하나라면, 끝-시작 + 1.
	//오른쪽 강 건너가 1번~7번 있으면 7가지 경우의 수가 가능하다.
	//오른쪽 강 건너 중 4~10 번을 고를 수 있다면 7가지 경우가 가능하다.
	for (int i = 1; i < SIZE; i++) {
		for (int j = 1; j < SIZE; j++) {
			arr[i][j][1] = j-i+1;
		}
	}


	int sum;
	for (int s = 2; s < SIZE; s++) {//다리의 개수
		for (int i = 1; i < SIZE; i++) {
			for (int j = i+s-1; j < SIZE; j++) {
				sum = 0;

				//다리의 수가 하나 적은 것(s-1)에서 자신보다 시작점이 하나 앞선 모든 경우([k][j])를 더한다.
				for (int k = i+1; k <= j; k++) {
					sum += arr[k][j][s - 1];
				}
				arr[i][j][s] = sum;
			}
		}

	}


	int T,n,m;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d %d", &n,&m);
		printf("%d\n",arr[1][m][n]);
	}


	return 0;
}