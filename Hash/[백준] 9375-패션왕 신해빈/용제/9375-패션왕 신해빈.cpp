#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<string, int> arr;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int ans = 1;
	int testcase, n;
	cin >> testcase;
	while (testcase--) {
		cin >> n;
		string cloth, kind;
		// 옷과 종류 입력받고 종류별로 몇개의 옷이 있는지 확인
		for (int i = 0; i < n; i++) {
			cin >> cloth >> kind;
			arr[kind]++;
		}
		// 나올 수 있는 조합 계산
		for (auto it = arr.begin(); it != arr.end(); it++) {
			ans = ans * (it->second + 1);
		}
		cout << ans-1 << '\n';
		arr.clear();
		ans = 1;
	}
}
