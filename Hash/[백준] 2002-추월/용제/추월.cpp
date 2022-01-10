#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<string, int> arr;
vector<string> v;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	int N, cnt = 0;
	string s;
	cin >> N;
	// 해쉬 테이블에 차량 번호와 들어가는 순서 입력
	for (int i = 0; i < N; i++) {
		cin >> s;
		arr.insert({ s,i });
	}
	// 차량이 나오는 순서를 배열에 저장
	for (int i = 0; i < N; i++) {
		cin >> s;
		v.push_back(s);
	}
	// 나온 순서대로 확인하여 나온 순서가 들어간 순서보다 빠른 차량 확인
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[v[i]] > arr[v[j]]) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
}
