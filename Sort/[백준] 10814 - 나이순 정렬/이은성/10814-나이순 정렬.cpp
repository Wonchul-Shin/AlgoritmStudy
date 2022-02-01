/*
    카운터 정렬을 사용해 정렬
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, input;
    int arr[201]{0,};
    int sum[201]{0,};
    string s;
    vector<pair<int, string>> v1;
    
    cin >> n;
    vector<pair<int, string>> v2(n);

    for(int i = 0; i < n; i++){
        cin >> input >> s;
        
        v1.push_back({input, s});
        arr[input]++;
    }

    sum[0] = arr[0];

    for(int i = 0; i <= 200; i++){                                  //누적합 구하기
        sum[i] = arr[i] + sum[i - 1];
    }

    for(int i = v1.size() - 1; i >= 0; i--){                        //카운팅정렬
        v2[sum[v1[i].first] - 1] = v1[i];
        sum[v1[i].first]--;
    }

    for(auto i : v2){
        cout << i.first << ' ' << i.second << '\n';
    }
    
    return 0;
}