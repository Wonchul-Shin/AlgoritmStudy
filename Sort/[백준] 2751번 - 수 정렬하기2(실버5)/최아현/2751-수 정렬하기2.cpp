/*#include <cstdio>
#include <iostream>
#include <queue>
#include <functional> // greater

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> pq; //오름차순

	int N, x; 

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		pq.push(x);
	}
	for (int i = 0; i < N; i++) { 
		cout << pq.top() << '\n';
		pq.pop();
	}
	return 0;
}*/

#include <cstdio>
#include <iostream>

using namespace std;

void mysort()


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int bubble_sort[1000000];
	int N, x;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
	}




	return 0;
}