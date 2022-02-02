#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>//pair 
#include <algorithm> //sort

using namespace std;

struct ball { // 공 정보
	int color;
	int size;
	int num;
};

bool cmp(ball &a, ball &b) {
	if (a.size == b.size) return a.color < b.color;
	return a.size < b.size;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, total = 0;
	cin >> N;
	vector<ball> b(N);
	vector<pair<int, int>> v;   // <출력 값, 같은 공번호 누적합>

	for (int i = 0; i < N; i++) {
		cin >> b[i].color >> b[i].size;
		b[i].num = i;
		v.push_back(pair<int, int>(0, 0));
	}
	
	sort(b.begin(), b.end(), cmp); // 정렬

	int ssiz = 0;
	int scol = 0;
	int ctot = 0;

	for (int j = 0; j < N ; j++) {

		if (ssiz == b[j].size) { //크기가 같을 때
			if (scol == b[j].color) { // 색도 같을 때
				v[b[j].num].first = total - v[b[j].color - 1].second;
				ctot += b[j].size;
			}

			else{ // 색 다를 때
				v[b[j].num].first = total - v[b[j].color - 1].second - ctot;
				ctot += b[j].size;
			}

			total += b[j].size;// 총 누적합
			v[b[j].color - 1].second += b[j].size;// 같은 색의 누적합
		}
		else{ 
			v[b[j].num].first = total - v[b[j].color-1].second; // n번 공의 총 합
			total += b[j].size;  
			v[b[j].color-1].second += b[j].size; 

			ssiz = b[j].size;
			scol = b[j].color;
			ctot = b[j].size;
		}
	}

	for (int k = 0; k < N; k++) {
		cout << v[k].first << '\n';
	}
	return 0;
}
