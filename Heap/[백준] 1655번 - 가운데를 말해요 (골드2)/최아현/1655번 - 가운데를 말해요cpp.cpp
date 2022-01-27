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
		
		if ( i% 2 == 0 ) { // �Է¹��� �������� ¦���� ��
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
		else { // �Է¹��� �������� Ȧ���� ��
			
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

		if (r_heap.size() == 0) {  // ������ �� ť �� ��
			r_heap.push(num);      
		}
		else if (l_heap.size() == 0) { //���� �� ť �� ��
			if (r_heap.top() < num) {  //������ ť�� ž���� num�� Ŭ ��
				left(num);
			}
			else l_heap.push(num);
		}
		else if (l_heap.size() > r_heap.size()) { // ���� ť ũ�Ⱑ �� Ŭ ��
			if (l_heap.top() <= num) {             //���� ť ž�� ���Ͽ� ž�� �� Ŭ ��
				r_heap.push(num); 
			}
			else right(num);
		}
		else if (l_heap.size() < r_heap.size()) {  // ������ ť ũ�Ⱑ �� Ŭ ��
			if (l_heap.top() > num) {  //���� ť ž ���� ���� �� 
				right(num);
			}
			else  l_heap.push(num);
		}
		else { // ���� ����� ���� ��
			if (l_heap.top() < num) {
				r_heap.push(num);
			}
			else right(num);
		}
		cout << l_heap.top() << '\n';
	}
}