#include <cstdio>
#include <iostream>
#include <queue>
#include <vector> //배열처럼 사용

using namespace std;

int main() {

	int N, M;
	int total = 0;
	queue<int> wait; //기다리는 줄
	vector<int> park; //주차장
	vector<int> Wk;  //차량무게
	vector<int> Rs; //주차공간 요금

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		Rs.insert(Rs.begin() + i, p);  //Rs = [ 2, 3, 5 ]
		park.insert(park.begin()+i, 0); //주차장 공간확보 (값 0 = 빈자리)
	}
	for (int i = 0; i < M; i++) {
		int c;
		cin >> c;
		Wk.insert(Wk.begin() + i, c);  //Wk = [ 200, 100, 300, 800 ]
	}

	for (int i = 0; i < M * 2; i++) {
		int parking;
		cin >> parking;

		if (parking > 0) { //들어오는 차
			int w = 1;
			for (int j = 0; j < N; j++) { // park(주차장) 안쪽 빈자리부터 확인
				if (park[j] == 0) { //빈 곳에 주차
					park[j] = parking;
					w = 0; //주차성공 시 waiting 없음
					break;
				}
			}
			if (w == 1) { //waiting 있을 시 wait큐에 push
				wait.push(parking);
			}
		}
		else{ //나가는 차
			for (int j = 0; j < N; j++) {
				if (park[j] == parking * (-1)) { //나가는 차 자리 찾아서 
					total += Rs[j] * Wk[parking * (-1)-1]; // 주차공간요금 * 무게 계산해서 total에 합침
					
					park[j] = 0; // 주차자리 빈곳으로 지정
					if (!wait.empty()) { // 기다리는 차가 있을 시 
						park[j] = wait.front(); //처음 기다린 차를 주차빈자리에 넣고
						wait.pop(); //wait큐에서 삭제 
					}
					break;
				}
			}
		}
	}
	cout << total;
	return 0;
}