#include <iostream>
using namespace std;

#define MAXSIZE 1000000 // 计算质数个数为1000000以内的

int main() {
	int a, cnt = 0;
	cin >> a;
	bool *tmp = new bool[a + 1];
	// 设置质数标志
	for (int i = 0; i <= a; i++) {
		tmp[i] = true;
	}
	for (int i = 2; i <= a / 2; i++) {
		if (tmp[i]) {
			int j = 2;
			while (i * j <= a) {
				tmp[i * j] = false;
				j++;
			}
		}
	}
	int *prime = new int[MAXSIZE];
	for (int i = 2; i <= a; i++) {
		if (tmp[i]){
			prime[cnt++] = i;
		}
	}
	cout << cnt <<" "<< prime[cnt-1]<<endl;
	delete[] tmp;
	delete[] prime;
}
