#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int N;
int cnt = 0;
int front_n = 0;
int rear_n = 0;
void right(int key, int k);
void left(int key, int k);
int main() {
	int arrayN[100000];
	int K;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arrayN[i]);
	}
	int temp = 0;
	for (int i = 1; i < N; i++) {
		if (arrayN[i] < arrayN[temp]) {
			temp = i;
		}
	}

	left(temp, K - 1);
	right(temp, K - 1);
	if (rear_n + front_n == K-1) {
		cnt--;
	}
	cout << cnt;
	return 0;
}

void left(int key, int k) {
	if (key - k < 0) {
		if (key - 1 >= 0) {
			front_n = key;
			cnt++;
		}
		return;
	}
	else {
		cnt++;
		left(key - k, k);
	}
}
void right(int key, int k) { //key + k == N-1 
	if (key + k < N) {
		cnt++;
		right(key + k, k);
	}
	else {
		if (key < N-1) {
			rear_n = (N - 1)- key;
			cnt++;
			return;
		}
		else {
			return;
		}
	}
}