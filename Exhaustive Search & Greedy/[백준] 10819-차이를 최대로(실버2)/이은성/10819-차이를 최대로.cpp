/*
    인덱스로 순열을 만들어 각 순열에 대한 수식을 완전탐색으로 비교
*/
#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

int findmax(vector<int> &v1, vector<int> v2, deque<int> d){
    int max, maxtmp;
    int tmp, size;
    int sum = 0;

    if(v1.size() == v2.size()){
        for(int i = 0; i + 1 < v1.size(); i++){
            sum += abs(v1[v2[i]] - v1[v2[i + 1]]);
        }
        return sum;
    }

    tmp = d.front();
    v2.push_back(tmp);
    d.pop_front();
    max = findmax(v1, v2, d);
    v2.pop_back();
    d.push_back(tmp);

    size = d.size();
    if(size == 1)
        return max;

    for(int i = 1; i < size; i++){
        tmp = d.front();
        v2.push_back(tmp);
        d.pop_front();
        maxtmp = findmax(v1, v2, d);
        max = max > maxtmp ? max : maxtmp;
        v2.pop_back();
        d.push_back(tmp);
    }

    return max;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, input, max;
    vector<int> v1;                  //  입력받은 값 배열
    vector<int> v2;                 //  선택한 인덱스
    deque<int> d;                  //  선택하지 않은 인덱스

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> input;
        v1.push_back(input);
        d.push_back(i);
    }

    max = findmax(v1, v2, d);

    cout << max;

    return 0;
}
