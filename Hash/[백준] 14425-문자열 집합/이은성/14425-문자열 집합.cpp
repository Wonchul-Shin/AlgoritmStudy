#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){

    int n, m;
    int count = 0;
    string s;
    unordered_map<string, int> um;

    cin >> n >> m;

    for(int i = 0; i < n ; i++){
        cin >> s;
        um[s] = 0;
    }

    for(int i = 0; i < m; i++){
        cin >> s;
        if(um.find(s) != um.end())
            count++;
    }

    cout << count;
    
    return 0;
}
