#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;

}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, s, t, time;
    int num = 0;
    vector<pair<int, int> > v;          //{시작시각, 종료시각}
    priority_queue<int, vector<int>, greater<int> > tt;                     // 종료시간

    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> s >> t;
        v.push_back({s, t}); 
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < n; i++){
        time = v[i].first;
        
        while(!tt.empty()){
            if(tt.top() <= time){
                tt.pop();
                continue;
            }
            break;
        }

        tt.push(v[i].second);

        if(num < tt.size())
            num = tt.size();
    }

    cout << num;

    return 0;
}
