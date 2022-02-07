/*
  입력받은 치킨집의 개수보다 m이 큰 경우 그냥 거리 출력
  m이 작은 경우 m개의 조합을 만들어 각 거리를 계산 후 최소값 비교 후 
*/
#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

// 치킨거리 구하는 함수
int findChickenDistance( vector<pair<int, int> > chicken, vector<pair<int, int> > house ){

    int tmp;
    int distance;
    int result = 0;

    for(int i = 0; i < house.size(); i++){
        distance = abs(house[i].first - chicken[0].first) + abs(house[i].second - chicken[0].second);
        for(int j = 1; j < chicken.size(); j++){
            tmp = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
            if(distance > tmp)
                distance = tmp;
        }
        result += distance;
    }   

    return result;
}
// 재귀함수에서 호출 했을 경우 치킨거리 구하는 함수
int findChickenDistance( vector<pair<int, int> > chicken, vector<pair<int, int> > house , vector<int> com){

    int tmp;
    int distance;
    int result = 0;

    for(int i = 0; i < house.size(); i++){
        distance = abs(house[i].first - chicken[com[0]].first) + abs(house[i].second - chicken[com[0]].second);
        for(int j = 1; j < com.size(); j++){
            tmp = abs(house[i].first - chicken[com[j]].first) + abs(house[i].second - chicken[com[j]].second);
            if(distance > tmp)
                distance = tmp;
        }
        result += distance;
    }   

    return result;
}

//  재귀를 이용해 조합을 만들어 치킨거리의 구하는 함수 호출
int findMinChickenDistance( vector<pair<int, int> > chicken, vector<pair<int, int> > house, vector<int> com, int m){
    
    int tmp;
    int minChikenDistance = 99999999;
    
    if(com.size() == m)
        return findChickenDistance(chicken, house, com);

    else if(com.size() == 0){

        for(int i = 0 ; i < chicken.size(); i++){
            com.push_back(i);
            tmp = findMinChickenDistance(chicken, house, com, m);
            com.pop_back();
            if(minChikenDistance > tmp)
                minChikenDistance = tmp;
        }
    }

    else{
        for(int i = com.back() + 1; i < chicken.size(); i++){
            com.push_back(i);
            tmp = findMinChickenDistance(chicken, house, com, m);
            com.pop_back();
            if(minChikenDistance > tmp)
                minChikenDistance = tmp;
        }
    }
    
    return minChikenDistance;
}

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, m;
    int input;
    int chickenDistance = 0;
    vector<pair<int, int> > chicken;
    vector<pair<int, int> > house;
    vector<int> com;

    
    cin >> n >> m;

    for(int i = 1 ; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> input;
            switch (input){
            case 1: house.push_back({i, j});    break;
            case 2: chicken.push_back({i, j});  break;
            default: break;
            }
        }
    }

    if(m >= chicken.size())
        chickenDistance = findChickenDistance(chicken, house);
    else
        chickenDistance = findMinChickenDistance(chicken, house, com, m);    
    

    cout << chickenDistance;

    return 0;
}
