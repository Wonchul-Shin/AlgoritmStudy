#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {

	int n, count = 0;
	int i, j;
	string s;

	vector<int> out_car;

	cin >> n;

	unordered_map<string, int> hash;
	out_car.insert(out_car.begin(), 0); //헷갈릴 것 같아서 0대입

	for (i = 1; i <= n; i++) {
		cin >> s;               //들어간 순서대로 차량번호와 1, 2, 3, 4 로 표시
		hash[s] = i;
	}

	for (j = 1; j <= n; j++) {
		cin >> s;                 //들어간 순서를 가지고 있는 차량이름 찾아서 나온대로 백터에 넣음
		out_car.insert(out_car.begin() + j, hash[s]);
	}

	int temp;
	i = 1; 

	while (i <= n) { //정렬 
		for (int k = 1; k < n - 1; k++) {
			if (out_car[k] > out_car[k + 1]) {  //일단 큰수가 앞에있으면 카운터 세고
				count++;
				for (j = 1; j < n; j++) {  //큰수를 뒤로 옮겨서 한번 정렬
					if (out_car[j] > out_car[j + 1]) {
						temp = out_car[j];
						out_car[j] = out_car[j + 1];
						out_car[j + 1] = temp;
					}
				}
			}
		}
		i++;
	}

	cout << count;

	return 0;
}
