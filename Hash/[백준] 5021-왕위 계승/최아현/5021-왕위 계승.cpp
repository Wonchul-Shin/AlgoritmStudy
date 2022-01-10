#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {

	int n, m;
	string s;
	string p1, p2;
	
	string king;

	unordered_map<string, double> hash;
	vector<string> v;

	cin >> n >> m;  
	cin >> s;  

	hash[s] = 1.0;  //왕 1 대입

	for (int i = 0; i < n ; i++) {
		
		cin >> s >> p1 >> p2;  // 자녀 부모 받아서
		if (hash[p1] != NULL && hash[p2] != NULL) {  //값이 존재하면 혈통
			hash[s] = hash[p1] + hash[p2];  // 혈통계산
		}
		else if (hash[p1] != NULL) {  //P1만 혈통
			hash[s] = hash[p1] / 2;
		}
		else if (hash[p2] != NULL) { //P2만 혈통일 경우
			hash[s] = hash[p2] / 2;
		}
		else { // 둘다 아닐경우
			hash[s] = 0.0;
		}
	}

	for (int j = 0; j < m; j++) {  // 후보 받아서 벡터에 후보이름 넣음
		cin >> s;
		v.insert(v.begin() + j, s);
	}
	king = v[0];

	for (int k = 1; k < m; k++) {  // 후보이름(키)으로 hash값 찾아서 가장 큰 값 찾기
		if (hash[king] < hash[v[k]])
			king = v[k];
	}

	cout << king;

	return 0;
}
