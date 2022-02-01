#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

    int n;
    long long count = 0;
    long long input;
    stack<pair<long long, int>> s;                        //stack[몇번째 사람] = { 키, 인원};             
    vector<pair<long long, int>> v;

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> input;
        v.push_back({input, 1});
    }
   

    for(int i = 0; i < n; i++){
        if(s.empty()){
            s.push(v[i]);
        }
        else if(v[i].first < s.top().first){
            s.push(v[i]);
            count++;
        }
        else if(v[i].first == s.top().first){
            v[i].second += s.top().second;
            count += s.top().second;
            s.pop();
            i--;
        }
        else{
            count += s.top().second;
            s.pop();
            i--;
        }
    }

    cout << count;
    return 0;
}