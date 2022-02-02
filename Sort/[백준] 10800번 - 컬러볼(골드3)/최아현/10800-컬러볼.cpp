#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>//pair 
#include <algorithm> //sort

using namespace std;

struct ball { // �� ����
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
	vector<pair<int, int>> v;   // <��� ��, ���� ����ȣ ������>

	for (int i = 0; i < N; i++) {
		cin >> b[i].color >> b[i].size;
		b[i].num = i;
		v.push_back(pair<int, int>(0, 0));
	}
	
	sort(b.begin(), b.end(), cmp); // ����

	int ssiz = 0;
	int scol = 0;
	int ctot = 0;

	//printf("total %d - %d�� �� ������ %d = �� �� %d \n",
					//	total, b[j].num, v[b[j].color - 1].second, v[b[j].num].first);

	for (int j = 0; j < N ; j++) {

		if (ssiz == b[j].size) { //ũ�Ⱑ ���� ��
			if (scol == b[j].color) { // ���� ���� ��
				v[b[j].num].first = total - v[b[j].color - 1].second;
				//printf("total %d - %d�� ũ�� %d ��%d ������ %d = �� �� %d \n",
				//	total, b[j].num, b[j].size, b[j].color, v[b[j].color - 1].second, v[b[j].num].first);
				ctot += b[j].size;
			}

			else{ // �� �ٸ� ��
				v[b[j].num].first = total - v[b[j].color - 1].second - ctot;
				//printf("total %d - %d�� ũ�� %d �� %d ������ %d - ctot %d = �� �� %d \n",
				//	total, b[j].num, b[j].size, b[j].color, v[b[j].color - 1].second, ctot, v[b[j].num].first);
				ctot += b[j].size;
			}

			total += b[j].size;
			v[b[j].color - 1].second += b[j].size;
		}
		else{ 
			v[b[j].num].first = total - v[b[j].color-1].second; // n�� ���� �� ��
			//printf("total %d - %d�� ũ�� %d �� %d ������ %d = �� �� %d \n",
			//			total, b[j].num, b[j].size, b[j].color, v[b[j].color - 1].second, v[b[j].num].first);
			total += b[j].size;  // �� ������
			v[b[j].color-1].second += b[j].size; // ���� ������

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