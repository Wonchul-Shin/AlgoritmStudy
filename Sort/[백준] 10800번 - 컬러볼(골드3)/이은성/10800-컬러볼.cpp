/*
    seq 벡터에 크기와 색을 입력받고 그것을 복사한 v 벡터를 오름차순으로 정렬
    v벡터의 처음부터 끝까지 sum에 누적합을 구하고
    colorv[색] = {크기, 누적합} 을 구한 후에
    seq의 처음부터 끝까지 seq의 값을 sum의 누적합과 colorv[seq의 색]을 구해서
    두 값의 차로 결과를 구함
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<long long , long long> pll;

bool compare(const pll &a, const pll &b){
    return a.first < b.first;
}
int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, color, size;
    long long sumsize, colorsize, tmp;
    vector<pll> seq;                // { 크기 , 색 }
    vector<pll> sum;               //  {크기, 누적합}

    cin >> n;

    vector<vector<pll> > colorv(n + 1);         // colorv[색번호] = {크기, 누적합}

    for(int i = 0; i < n; i ++){
        cin >> color >> size;
        
        seq.push_back({size, color});
    }

    vector<pll> v(seq);                             
    sort(v.begin(), v.end());                   // v벡터에 seq값을 복사 후 정렬

    sum.push_back({v[0].first, 0});
    colorv[v[0].second].push_back({v[0].first, 0});

    for(int i = 1; i < n; i++){                 // 누적 합 계산
        sum.push_back({v[i].first, sum[sum.size() - 1].first + sum[sum.size() - 1].second});
        if(colorv[v[i].second].size() == 0)
            colorv[v[i].second].push_back({v[i].first, 0});
        else
            colorv[v[i].second].push_back({v[i].first, colorv[v[i].second].back().first + colorv[v[i].second].back().second});
            
    }

    for(int i = 0; i < n; i++){                 // 결과값 계산
        tmp = lower_bound(sum.begin(), sum.end(), pll(seq[i].first, 0), compare) - sum.begin();
        sumsize = sum[tmp].second;
        tmp = lower_bound(colorv[seq[i].second].begin(), colorv[seq[i].second].end(), pll(seq[i].first, 0), compare) - colorv[seq[i].second].begin();
        colorsize = colorv[seq[i].second][tmp].second;

        cout << sumsize - colorsize << '\n';
    }

    return 0;
}
