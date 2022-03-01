#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <cmath>
using namespace std;
 
int n, m;
vector<pair<int, int>> house; // 주거지 좌표 모음
vector<pair<int, int>> chicken; // 치킨집 좌표 모음 
vector<bool> check(13);
int answer = INT_MAX;



void distance_check() {
    int temp_answer = 0;
    for (int i = 0; i < house.size(); i++) { // 집들을 돌면서 
        int distance = INT_MAX; // 무한대 값을 넣음 
        for (int j = 0; j < chicken.size(); j++) { // 모든 치킨집과의 거리를 구한다 
            if (!check[j]) // 만약 없애기로한 지점이면  
                continue;
            else {
                distance = min(distance, abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second)); // 거리구하고 최소값을 넣음
            }
        }
        temp_answer += distance; // 최소값을 임시 answer에 넣음
    }
    answer = min(answer, temp_answer); 
}
 
void combi(int start, int cnt) {
    if (cnt == m) { // m이 없앨 치킨집 만큼 나왔을 때 
        // 거리 계산
        distance_check();
        return;
    }
    else {
        for (int i = start; i < chicken.size(); i++) {
            if (!check[i]) {
                check[i] = true;
                combi(i + 1, cnt + 1);
                check[i] = false;
            }
        }
    }
}
 
int main()
{
    cin >> n >> m;
    int info;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> info;
            if (info == 1) {
                house.push_back(make_pair(i, j));
            }
            else if (info == 2) {
                chicken.push_back(make_pair(i, j));
            }
        }
    }
    combi(0, 0);
    cout << answer;
    return 0;
}
