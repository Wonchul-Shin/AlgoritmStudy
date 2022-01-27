/*#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, num, half;
	priority_queue<int> pq1;
	priority_queue<int> pq2;

	cin >> n;

	for (int i=1; i<= n; i++) {
		cin >> num;
		
		if ( i% 2 == 0 ) { // 입력받은 정수들이 짝수일 때
			pq1.push(num);
			half = i / 2;
			
			for (int x = 1; x <= i ; x++) {
				pq2.push(pq1.top());
				if ((half+1) == x) {
					cout << pq1.top() << '\n';
				}
				pq1.pop();
			}
		}
		else { // 입력받은 정수들이 홀수일 때
			
			pq2.push(num);
			half = (i / 2) + 1;
			for (int y = 1; y <= i ; y++) {
				pq1.push(pq2.top());
				if (half == y) {
					cout << pq2.top() << '\n';
				}
				pq2.pop();
			}
		}
	}

	return 0;
}*/
-----------------------------------------------------------------------
#include<stdio.h>
#include <iostream>
#include<algorithm>
#include<queue>

using namespace std;

priority_queue<int> r_heap;
priority_queue<int> l_heap;

void right(int num) {
	r_heap.push(l_heap.top());
	l_heap.pop();
	l_heap.push(num);
}
void left(int num) {
	l_heap.push(r_heap.top());
	r_heap.pop();
	r_heap.push(num);
}
int main() {

	int N, num;
	cin >> N;

	for (int i=1; i <= N; i++) {
		cin >> num;

		if (r_heap.size() == 0) {  // 오른쪽 빈 큐 일 때
			r_heap.push(num);      
		}
		else if (l_heap.size() == 0) { //왼쪽 빈 큐 일 때
			if (r_heap.top() < num) {  //오른쪽 큐의 탑보다 num이 클 때
				left(num);
			}
			else l_heap.push(num);
		}
		else if (l_heap.size() > r_heap.size()) { // 왼쪽 큐 크기가 더 클 때
			if (l_heap.top() <= num) {             //왼쪽 큐 탑과 비교하여 탑이 더 클 때
				r_heap.push(num); 
			}
			else right(num);
		}
		else if (l_heap.size() < r_heap.size()) {  // 오른쪽 큐 크기가 더 클 때
			if (l_heap.top() > num) {  //왼쪽 큐 탑 보다 작을 때 
				right(num);
			}
			else  l_heap.push(num);
		}
		else { // 둘의 사이즈가 같을 때
			if (l_heap.top() < num) {
				r_heap.push(num);
			}
			else right(num);
		}
		cout << l_heap.top() << '\n';
	}
}
