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

	sort(times.begin(), times.end()); // 심사대 시간 정렬

	maxt = *max_element(times.begin(), times.end()) * (long long)n;  // 심사대 최대 시간 * 인원

	while (mint <= maxt) {

		avgt = ((maxt + mint) / 2);

		long long cnt = 0;
		for (int i = 0; i < times.size(); i++) {
			// 각 시간별 평균 시간까지 처리할 수 있는 최대인원.
			cnt += avgt / times[i];
		}
		if (cnt < n) { // 심사대보다 최대인원이 적을 때
					   // 최소값을 평균 + 1 로 좁혀준다.
			mint = avgt + 1;
		}
		else {
			// avgt(평균 시간)이 maxt(최대 시간) 이하면
			// avgt 는 최소값이 될 수도 있기 때문에 answer에 넣어주고
			if (avgt <= maxt) {
				answer = avgt;
			}
			// 최소 값을 찾기 위해 범위를 더 좁혀준다
			maxt = avgt - 1;
		}
	}

	return answer;
}*/