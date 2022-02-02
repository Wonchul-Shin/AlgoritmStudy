/*
    버블정렬의 특성상 오름차순으로 정렬 할 경우 큰값은 한번에 맨 오른쪽 끝으로 정렬되지만
    작은 값의 경우 한 단계에 한 번씩밖에 이동하지 않음
    따라서 입력받은 값과 정렬후의 인덱스 값을 비교해서
    이전 값 - 정렬 후 값이 가장 큰 값이 최대 단계라고 봐도 무방함
    마지막에 정렬되었는지 체크하는 단계까지 생각하면
    priority.top() 의 값 + 1이 정답이라고 볼 수 있음
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    int input;
    vector<pair<int, int> > v;                                  // { 값, 입력시 인덱스}
    priority_queue<int> pq;                                     // { 각 인덱스마다 이동 거리를 내림차순으로 정렬}

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> input;
        v.push_back({input, i});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        pq.push(v[i].second - i);
    }

    cout << pq.top() + 1;
    
    return 0;
}
