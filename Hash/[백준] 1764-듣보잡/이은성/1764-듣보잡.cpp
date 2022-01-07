#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n, m, count = 0;
    string s;
    unordered_map<string, int> um;
    vector<string> v;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> s;
        um[s] = 0;
    }

    for(int i = 0; i < m; i++){
        cin >> s;
        if(um.find(s) != um.end()){
            count ++;
            v.push_back(s);
        }
    }

    sort(v.begin(), v.end());
    cout << count << '\n';

    for(auto i : v){
        cout << i << '\n';       
    }
    return 0;
}
