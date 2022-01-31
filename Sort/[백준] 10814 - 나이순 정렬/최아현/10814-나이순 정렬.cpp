#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> v[201]; // 나이는 1보다 크거나 같으며, 200보다 작거나 같은 정수

	int N, x;
	string s;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> s;
		v[x].push_back(s); // 인덱스(나이)에 이름 삽입
	}

	for (int i=1; i<=200; i++) {
		for (int j=0; j < v[i].size(); j++) { // 나이가 같으면 먼저 가입한 사람이 앞에 오는 순서
			cout << i << ' ' << v[i][j] << '\n';
		}
	}
	return 0;
}