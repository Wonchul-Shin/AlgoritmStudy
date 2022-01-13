#include <iostream>
#include <queue>

using namespace std;

int main(){

    int n, k;

    cin >> n >> k;
    queue<int> q1, q2;                      //1~n을 담아둘 q1과 출력용 q2 생성

    for(int i = 1; i <= n; i++)             //q1 =  1 ~ n 으로 초기화
        q1.push(i);
    
    for(int i = 1; !q1.empty(); i++){
        if(i % k == 0){                     //k 번마다 q2로 q1의 fromt를 푸쉬
            q2.push(q1.front());    
            q1.pop();
        }
        else{                               //나머지 경우 q1의 front를 back으로 푸쉬
            q1.push(q1.front());
            q1.pop();
        }
    }

    cout << '<';                            //출력
    while(1){
        cout << q2.front();
        q2.pop();
        if(q2.empty()){
            cout << '>';
            break;
        }
        else
            cout <<", ";
    
    }

    return 0;
}
