#include<stdio.h>
#include<stdlib.h>

#define SIZE 32
//������, ����, ���� ��(�ٸ��� ��)
int arr[SIZE][SIZE][SIZE];

int main() {

	//�ٸ��� ���� �ϳ����, ��-���� + 1.
	//������ �� �ǳʰ� 1��~7�� ������ 7���� ����� ���� �����ϴ�.
	//������ �� �ǳ� �� 4~10 ���� �� �� �ִٸ� 7���� ��찡 �����ϴ�.
	for (int i = 1; i < SIZE; i++) {
		for (int j = 1; j < SIZE; j++) {
			arr[i][j][1] = j-i+1;
		}
	}


	int sum;
	for (int s = 2; s < SIZE; s++) {//�ٸ��� ����
		for (int i = 1; i < SIZE; i++) {
			for (int j = i+s-1; j < SIZE; j++) {
				sum = 0;

				//�ٸ��� ���� �ϳ� ���� ��(s-1)���� �ڽź��� �������� �ϳ� �ռ� ��� ���([k][j])�� ���Ѵ�.
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