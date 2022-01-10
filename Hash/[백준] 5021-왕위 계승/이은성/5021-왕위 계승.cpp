#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

double findtier(map<string, pair <string, string>> map, int tier, string name, string checkName);

int main(){

    int n, m, tier;
    string name;
    string s1, s2, s3;
    map<string, pair <string, string>> map;                             // map[아들] = { 부모, 부모 } 의 형태로 저장
    vector< pair <double, string>> checkName;                           //checkName =>  <피의농도 , 사람이름>의 형태로 저장  

    cin >> n >> m;                                          
    cin >> name;

    for(int i = 0; i < n; i++){
        cin >> s1 >> s2 >> s3;
        map.insert({s1, {s2, s3}});
    }

    for(int i = 0; i < m; i++){
        cin >> s1 ;
        checkName.push_back({findtier(map, 1, name, s1), s1});
    }

    sort(checkName.begin(), checkName.end());

    cout << checkName.back().second ;

    return 0;

}

double findtier(map<string, pair <string, string>> map, int tier, string name, string checkName){
    double a, b;

    if(map.find(checkName) == map.end())                                // 부모 정보가 map에 없으면 0 리턴
        return 0;
    
    else if(map[checkName].first == name)                               // elseif에서 부모중 한쪽에 전대 왕이 있어도 반대편 부모의 농도계산후 덧셈 
        return (1.0/pow(2,tier + 1)) + findtier(map, tier + 1, name, map[checkName].second);
        
    else if(map[checkName].second == name)
        return (1.0/pow(2,tier + 1)) + findtier(map, tier + 1, name, map[checkName].first);
    
    a = findtier(map, tier + 1, name, map[checkName].first);            // 양쪽 부모 중에 어느쪽도 전대 왕이 아니면 각각의 부모의 농도를 구해서 더함
    b = findtier(map, tier + 1, name, map[checkName].second);   
    

    return a + b;

}
