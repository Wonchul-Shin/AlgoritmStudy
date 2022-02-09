/*
    입력 받은 순서대로 vector에 넣고 
    멀티탭에 자리가 있는 경우 그냥 멀티탭에 넣고
    자리가 없는경우 앞으로 큐를 살펴보고 앞으로 꽂을 일이 없는 것이 있다면 빼고 넣고
    멀티탭에 있는 것들이 다 앞으로 큐에 들어올 예정이면 큐의 뒤부터 가장 마지막에 들어오는
    멀티탭을 빼서 큐에 있는것을 넣는다
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b){
    return a.first > b.first;
}
int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, k, input, count = 0;
    int d, size;
    bool check;
    pair<int, int> p;           //{index, 다음까지 거리 ( 다음에 없으면 100000)}
    vector<int> multitap;               
    vector<int> q;

    cin >> n >> k;

    for (int i = 0; i < k; i++){
        cin >> input;
        q.push_back(input);
    }

    for(int i = 0; i < q.size(); i++){
        check = false;
        for(int j = 0; j < multitap.size(); j++){
            if(q[i] == multitap[j]){
                check = true;
                break;
            }
        }

        if(multitap.size() < n && !check)
            multitap.push_back(q[i]);

        else if(!check){
            p = {-1, 0};
            for(int j = 0; j < multitap.size(); j++){
                d = 100000;
                for(int l = q.size() - 1 ; l > i; l--){
                    if(multitap[j] == q[l]){
                        d = l - i;
                    }
                }
                if(d > p.second){
                    p = {j, d};
                }
            }

            multitap.erase(multitap.begin() + p.first);
            multitap.push_back(q[i]);
            count++;
        }
    }
    
    cout << count;

    return 0;
}
