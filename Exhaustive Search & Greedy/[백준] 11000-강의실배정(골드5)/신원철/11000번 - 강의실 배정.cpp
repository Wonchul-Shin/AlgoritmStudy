#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    vector<pair<int, int>> lecture;
    int answer = 0;

    int n;
    cin >> n;

    int v = 0;

    while(n--){
        int s, t;
        cin >> s >> t;
        lecture.push_back(make_pair(s, t));
    }
    
    sort(lecture.begin(), lecture.end(), comp); // vector 정렬 
    priority_queue<int, vector<int>, greater<int>>room; // 빠른게 앞에 오도록 
    
    int first = 1;
    int start, end;
    
    room.push(lecture[0].second); //가장 빨리 시작하는 수업의 끝나는 시간

    for(auto i : lecture){
        start = i.first;
        end = i.second;
        
        if (room.top() > start){ // 큐에서 가장 빨리 끝나는 수업의 종료 시간보다 빨리 시작한다면 
            if(first == 0){ // 첫번째가 아니라면
                room.push(end); // 큐에 push
            }
            else{ // 첫번째라면 이미 큐 안에 있음으로 넘어감
                first = 0; 
            }
            
            answer++;
        }
        
        else{ // 가장 빨리 끝나는 수업의 종료시간보다 늦게 시작한다면 / 같은 강의실을 쓸 수 있다면. 
            room.pop(); // 기존에 있던 수업의 종료시간을 pop하고
            room.push(end); // 해당 수업의 종료시간을 push
        }
        
    }
    
    
    cout << room.size();
}