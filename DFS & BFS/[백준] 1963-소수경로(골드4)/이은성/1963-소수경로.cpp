#include <iostream>
#include <unordered_map>
#include <cstring>
#include <queue>

using namespace std;

int cnt;
bool arr[10000];
bool flag;
unordered_map<string, int> prime;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    string p1, p2, str;
    priority_queue<pair<int, string> > pq;
    pair<int, string> tmp;

    for(int i = 2; i < 100; i++){
        for(int j = i * i; j < 10000; j += i){
            arr[j] = true;
        }
    }    

    for(int i = 1000; i < 10000; i++){
        if(!arr[i]){
            prime[to_string(i)] = 1;
        }
    }

    for(int i = 0; i < t; i++){
        cin >> p1 >> p2;
        flag = false;
        memset(arr, false, 10000);

        while(!pq.empty())
            pq.pop();

        pq.push({0, p1});
        arr[stoi(p1)] = true;

        while(!pq.empty()){
            tmp = pq.top();
            pq.pop();

            if(tmp.second == p2){
                cnt = -tmp.first;
                flag = true;
                break;
            }
            
            for(int j = 0; j < 4; j++){
                str = tmp.second;
                for(int k = 0; k < 10; k++){
                    str[j] = '0' + k;
                    if(stoi(str) < 1000)
                        continue;
                    if(prime.count(str) && !arr[stoi(str)]){
                        pq.push({tmp.first - 1, str});
                        arr[stoi(str)] = true;
                    }
                }
            }
        }

        if(flag)
            cout << cnt << '\n';
        else
            cout << "Impossible\n";
    }


    return 0;
}
