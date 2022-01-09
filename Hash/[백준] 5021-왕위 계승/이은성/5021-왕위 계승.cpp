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
    map<string, pair <string, string>> map;
    vector< pair <double, string>> checkName;

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

    if(map.find(checkName) == map.end())
        return 0;
    
    else if(map[checkName].first == name)
        return (1.0/pow(2,tier + 1)) + findtier(map, tier + 1, name, map[checkName].second);
        
    else if(map[checkName].second == name)
        return (1.0/pow(2,tier + 1)) + findtier(map, tier + 1, name, map[checkName].first);
    
    a = findtier(map, tier + 1, name, map[checkName].first);
    b = findtier(map, tier + 1, name, map[checkName].second);   
    

    return a + b;

}