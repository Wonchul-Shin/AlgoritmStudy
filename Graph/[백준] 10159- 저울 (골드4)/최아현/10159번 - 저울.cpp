/*#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

vector<int> big[101];
vector<int> sml[101];
vector<int> cnt;

void up(int num) {
	if (!big[num].size() == 0) {
		for (int i = 0; i < big[num].size(); i++) {
			cnt.push_back(big[num][i]);
			up(big[num][i]);
		}
	}
}
void down(int num) {
	if (!sml[num].size() == 0) {
		for (int i = 0; i < sml[num].size(); i++) {
			cnt.push_back(sml[num][i]);
			down(sml[num][i]);
		}
	}
}
int main() {
	int N, M, x, y;

	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		big[y].push_back(x); // �ڽź��� ū ��
		sml[x].push_back(y); // �ڽź��� ������
	}

	for (int k = 1; k <= N; k++) {
		up(k);
		down(k);

		sort(cnt.begin(), cnt.end());
		cnt.erase(unique(cnt.begin(), cnt.end()), cnt.end());

		cout << N - (cnt.size()+1) << "\n";
		cnt.clear();
	}
	return 0;
}*/