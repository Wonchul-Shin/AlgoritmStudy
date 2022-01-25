/*
    중간값보다 작거나 같은 우선순위 큐와 중간값보다 큰 우선순위 큐를 생성 left
    반복횟수가 홀수인 경우 중간값보다 작거나 같은 우선순위 큐에 푸시 rigth
    반복횟수가 짝수인 경우 중간값보다 큰 우선순위 큐에 푸시
    각 푸시 후에 left의 탑과 right의 탑의 값을 비교 후 스왑이 필요하면 스왑
    각 반복마다 left의 top을 출력
*/
#include <iostream>
#include <queue>

using namespace std;

int main(){
    
    int n, input, tmp;
    priority_queue<int> left;                               //중간값보다 작거나 같은 우선순위 큐
    priority_queue<int, vector<int>, greater<int>>  right;  //중간값보다 큰 우선순위 큐

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n;
    cin >> input;

    left.push(input);                           
    cout << left.top() << '\n';

    for(int i = 1; i < n; i++){
        cin >> input;
        
        if(i % 2 == 0){
            if( input > right.top()){
                tmp = right.top();
                left.push(tmp);
                right.pop();
                right.push(input);
            }
            
            else{
                left.push(input);
            }
        }

        else{
            if( input < left.top()){
                tmp = left.top();
                right.push(tmp);
                left.pop();
                left.push(input);
            }

            else{
                right.push(input);
            }
        }

        cout << left.top() << '\n';
    }

    return 0;
}
