

#include <iostream>
#include <unordered_map>
#include<list>

using namespace std;


double find_root(unordered_map<string, array<string,2>> hash, string name, string maker){
    if (name == maker){ // 왕궁 만든사람일 때 
        return 1; 
    }
    if (hash.find(name) == hash.end()){ // 귀족이 아닐 때 == 족보를 찾지 못할 때
        return 0; 
    }
    return find_root(hash, hash[name][0],  maker) / 2 + find_root(hash, hash[name][1],  maker) / 2; // 두명의 수치를 더한 후 2를 나누면 된다.
}

int main()
{
    unordered_map<string, array<string,2>> hash; // hash에 이름과 부모이름 

    int n, m;
    string word1, word2, word3;
    cin >> n >> m;
    string arr [2];
    double answer_num = 0; // 새로운 왕의 수치 담을 변수
    double temp = 0;
    string answer; // 새로운 왕의 이름
    string maker; // 왕

    cin >> maker;
    for (int i = 0; i < n; i++){
        cin >> word1 >> word2 >> word3;
        hash[word1] = {word2, word3}; 
    }
    for (int i = 0; i < m; i++){
        cin >> word1;
        temp = find_root(hash, word1,  maker);
        if (answer_num < temp){
            answer_num = temp;
            answer = word1;
            
        }
    }
    cout << answer;

    return 0;
}
