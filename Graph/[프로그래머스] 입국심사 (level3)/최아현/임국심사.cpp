/*#include<cstdio>
#include<iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;
	long long mint = 1, maxt, avgt, person = 0;

	sort(times.begin(), times.end()); // �ɻ�� �ð� ����

	maxt = *max_element(times.begin(), times.end()) * (long long)n;  // �ɻ�� �ִ� �ð� * �ο�

	while (mint <= maxt) {

		avgt = ((maxt + mint) / 2);

		long long cnt = 0;
		for (int i = 0; i < times.size(); i++) {
			// �� �ð��� ��� �ð����� ó���� �� �ִ� �ִ��ο�.
			cnt += avgt / times[i];
		}
		if (cnt < n) { // �ɻ�뺸�� �ִ��ο��� ���� ��
					   // �ּҰ��� ��� + 1 �� �����ش�.
			mint = avgt + 1;
		}
		else {
			// avgt(��� �ð�)�� maxt(�ִ� �ð�) ���ϸ�
			// avgt �� �ּҰ��� �� ���� �ֱ� ������ answer�� �־��ְ�
			if (avgt <= maxt) {
				answer = avgt;
			}
			// �ּ� ���� ã�� ���� ������ �� �����ش�
			maxt = avgt - 1;
		}
	}

	return answer;
}*/