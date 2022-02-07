#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> h;
vector<pair<int, int>> ck;
vector<int> cklist;
int M;

vector<int> A;
void pick_ck() {
	//printf("pick ck \n");
	int result = 0;

	for (int i = 0; i < h.size(); i++) {
		int min = 1000;
		//printf("%d번 집 \n", i);

		for (int j = 0; j < A.size(); j++) {
			//printf("%d 번 치킨집 \n", A[j]);
			int tp = abs((h[i].first + 1) - (ck[A[j]].first + 1)) + abs((h[i].second + 1) - (ck[A[j]].second + 1));
			//printf("tp : %d\n", tp);

			if (min > tp) {
				min = tp;
			}
		}
		result += min;
		//printf("min : %d, result: %d\n", min, result);
	}
	cklist.push_back(result);
	A.clear();
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, x;
	cin >> N >> M;
	
	//vector<int> city[100];
	vector<int> temp;
	vector<int> s;

	int count = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x ;
			//city[i].push_back(x); 
			if (x == 2) {
				ck.push_back(pair<int, int>(i, j));
				s.push_back(cnt);
				cnt++;

				if (count < M) {
					temp.push_back(1);
				}
				else {
					temp.push_back(0);
				}
				count++;
			}
			else if (x == 1) {
				h.push_back(pair<int, int>(i, j));
			}
		}
	}

	/*
	printf("temp: ");
	for (int i = 0; i < temp.size(); i++) {
		cout << temp[i] << ' ';
	}cout << '\n';

	printf("s: ");
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << ' ';
	}cout << '\n';

	printf("ck: \n");
	for (int i = 0; i < ck.size(); i++) {
		cout << ck[i].first+1 << ' ';
		cout << ck[i].second+1 << '\n';
	}cout << '\n';*/


	//printf("do---\n");
	do {
		//printf("    ***********    ");
		for (int i = 0; i < s.size(); ++i) {
			if (temp[i] == 1)
				A.push_back(s[i]);
		}
		pick_ck();

	} while (prev_permutation(temp.begin(), temp.end()));

	int min = *min_element(cklist.begin(), cklist.end());

	cout << min;

	return 0;
}