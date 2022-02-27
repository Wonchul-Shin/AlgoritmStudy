#include <iostream>
#include <vector>

using namespace std;

int arr[101][100001];           //arr[i][j] = i번째까지 물건까지 계산했을때 무게 j에서의 최대 값 

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; cin >> n >> k;
    int w, v;
    vector<pair<int, int> > obj;

    for(int i = 0; i < n; i++){
        cin >> w >> v;
        obj.push_back({w, v});
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            //최대 크기보다 지금 물건의 크기가 크면 이전물건까지 계산했을때 무게가 j인 값을 넣음
            if(obj[i - 1].first > j)                        
                arr[i][j] = arr[i - 1][j];                  
            //만약 이전물건까지 봤을때 j 에서 이번물건의 무게만큼 뺀 최대값에서 이번 물건의 무게를 더한 값이 크면 그 값을 넣음
            else                                            
                arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - obj[i - 1].first] + obj[i - 1].second);
        }
    }

    cout << arr[n][k];

    return 0;
}
