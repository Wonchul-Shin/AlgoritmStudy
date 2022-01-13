#include <iostream>
#include <queue>

using namespace std;

int main(){

    int m, n, x;                                   //n = 주차장 크기 m = 들어올 차량 대수
    int *arr, *rs, *weight;                     //arr = 주차장 배열, rs = 각 arr당 단위무게당 요금, weight = 차량의 무게
    int total = 0;                              //total = 오늘의 수입

    queue<int> q, in;                           //q = 차량의 입장과 퇴장 순서, in = 입장 대기 차량

    cin >> n >> m;

    arr = new int[n + 1]{0};
    rs = new int[n + 1];
    weight = new int[m + 1];

    for(int i = 1; i <= n; i++)
        cin >> rs[i];
    for(int i = 1; i <= m; i++)
        cin >> weight[i];
    
    for(int i = 0; i < 2 * m; i++){
        cin >> x;
        q.push(x);
    }

    while(!q.empty()){
        if(q.front() > 0){                          //차량 입차, 주차장에 자리 없을시 입장 대기열로 이동
            for(int i = 1; i <= n; i++){
                if(arr[i] == 0){
                    arr[i] = q.front();
                    q.pop();
                    break;
                }
                
                if(i == n){
                    in.push(q.front());
                    q.pop();
                }
            }
        }

        else{                                       //차량 출차 + 요금계산 
            for(int i = 1; i <= n; i++){
                if(arr[i] == q.front() * (-1)){
                    total += rs[i] * weight[q.front() * (-1)];
                    q.pop();
                    arr[i] = 0;

                    if(!in.empty()){                //입장 대기열에 차량 있을 시에 빈 자리로 주차
                        arr[i] = in.front();
                        in.pop();
                    }
                    break;
                }
            }
        }

    }


    cout << total;
    return 0;
}
