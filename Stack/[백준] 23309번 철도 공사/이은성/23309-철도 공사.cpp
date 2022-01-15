#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
 
    int n, m;                                   //n은 역의 개수 m은 개수 
    int a, b;
    int prevSt;                                 //prevSt 이전 역
    int first;                                  //첫 번째 역
    string s;
    unordered_map<int, pair<int, int>> st;      //st[특정역] = {이전역, 다음역} 순서로 생성

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n >> m;
    prevSt = 0;

    cin >> a;                                   //첫 번째 역 입력
    first = a;
    st[a] = {0, 0};
    prevSt = a;

    for(int i = 1; i < n; i++){                 //두 번째 역부터 순서대로 입력받고 st[역] = { 이전역, 다음역 } 으로 입력
        cin >> a;
        st[prevSt].second = a;
        st[a] = {prevSt, 0};
        prevSt = a;
    }

    st[first].first = a;                        //첫 번째 역과 마지막 역을 연결
    st[a].second = first;

    for(int i = 0; i < m; i++){                 //명령어 수행
        cin >> s ;
        if(s == "BN"){                          //BN a b 고유 번호 a를 가진 역의 다음 역의 고유 번호를 출력하고, 그 사이에 고유 번호 b인 역을 설립한다.
            cin >> a >> b;
            cout << st[a].second << '\n';
            st[b] = {a, st[a].second};
            st[st[a].second].first = b;
            st[a].second = b;
        }
        else if(s == "BP"){                     //BP a b 고유 번호 a를 가진 역의 이전 역의 고유 번호를 출력하고, 그 사이에 고유 번호 b인 역을 설립한다.
            cin >> a >> b;
            cout << st[a].first << '\n';
            st[b] = {st[a].first, a};
            st[st[a].first].second = b;
            st[a].first = b;
        }
        else if(s == "CN"){                     //고유 번호 a를 가진 역의 다음 역을 폐쇄하고 그 역의 고유 번호를 출력한다.
            cin >> a;
            cout << st[a].second << '\n';
            st[a].second = st[st[a].second].second;
            st[st[a].second].first = a;
        }
        else if(s == "CP"){                     //고유 번호 a를 가진 역의 이전 역을 폐쇄하고 그 역의 고유 번호를 출력한다.
            cin >> a;
            cout << st[a].first << '\n';
            st[a].first = st[st[a].first].first;
            st[st[a].first].second = a;
        }
    }

    return 0;
}
