#include<cstdio>
#include<iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;
	long long mint = 1, maxt, avgt, person = 0;

	sort(times.begin(), times.end()); // 심사대 시간 정렬

	maxt = *max_element(times.begin(), times.end()) * (long long)n;  // 심사대 최대 시간 * 인원

	while (mint <= maxt) {

		avgt = ((maxt + mint) / 2);

		long long cnt = 0;
		for (int i = 0; i < times.size(); i++) {
			// 각 시간별 평균 시간 최대인원
			cnt += avgt / times[i];
		}
		if (cnt < n) { // 심사대 > 최대인원
					  
			mint = avgt + 1;
		}
		else {
			if (avgt <= maxt) {
				answer = avgt;
			}
			maxt = avgt - 1;
		}
	}

	return answer;
}
