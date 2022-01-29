/*
    처음 받는 n과 m으로 n + 1 개의 동적배열을 할당, for문으로 m번 반복해서 입력받음
    그뒤에 입력받는 a, b를 통해 선행으로 풀어야 되는 문제가 있는 경우 arr[문제번호]++
    그 뒤에 multimap um에 um[선행문제] = 다음에 풀 문제 같은 느낌으로 입력 
    (실제로는 multimap이기 때문에 다른 방식으로 입력해야 함)
    m개의 (a,b)의 순서쌍을 다 받은 후에 선행문제가 없는 문제들(arr[문제번호]가 0인 경우)을 
    우선순위 큐에 입력, 선행 문제가 없는 문제들을 모두 넣고나면 
    우선순위 큐(order, 오름차순)의 top을 pop하고 출력 후에 푼 문제의 후행 문제들의 arr[문제번호]--
    그후에 다시 arr[문제번호] == 0 인 문제들을 우선순위큐에 push반복
*/
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int main(){

    int n, m, a, b, solve;
    int *arr;
    unordered_multimap<int, int> ab;                        // ab[선행] = 후행 실제로는 -> {선행, 후행}
    priority_queue<int, vector<int>, greater<>> order;
    pair<unordered_multimap<int, int>::iterator, unordered_multimap<int, int>::iterator> p;

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n >> m;

    arr = new int[n + 1]{0,};                               // 문제 배열, arr[문제번호] = 0 => 선행 문제가 없음

    for(int i = 0; i < m; i++){                             
        cin >> a >> b;                                      // 선행문제 후행문제 순으로 입력받음, ab ba multimap에 입력
        ab.insert(pair<int, int>(a, b));                    
        arr[b]++;
    }

    for(int i = 1; i <= n; i++){                            // 선행 문제가 없는 문제들을 우선순위 큐에 push
        if(arr[i] == 0){
            order.push(i);
            arr[i]--;
        }
    }

    while(!order.empty()){                                  // 우선순위 큐가 빌 때 까지 반복, 큐의 최상위를 풀고 푼 문제를 출력 
        solve = order.top();
        order.pop();
        cout << solve << ' ';
        
        if(ab.find(solve) != ab.end()){                     // 문제를 푼 뒤에 후행 문제가 있는지 확인해서 후행문제들의 arr[문제번호]를 1씩 빼줌

            p = ab.equal_range(solve);
            
            for(auto i = p.first; i != p.second; i++){
                arr[i->second]--;
            }

            for(int i = 1; i <= n; i++){                            // 선행 문제가 없는 문제들을 우선순위 큐에 push
                if(arr[i] == 0){
                    order.push(i);
                    arr[i]--;
                }
            }
        }
    }

    return 0;
}