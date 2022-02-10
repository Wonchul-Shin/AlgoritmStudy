#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include<string.h> 
using namespace std;

int n, m;
int answer = 0;
vector<bool> check;
vector < vector <char> > table; // 글자들을 저장할 배열 
vector<char> alpha;


void word_check() {
    int temp_answer = 0;
    for (int i = 0; i < n; i++) { // word table을 돌면서 
    
        
        int word_size = table[i].size();
        int idx = 0;
        int fail = 0;
        for (int j = 0; j < word_size; j++) { // 글자를 돌면서
            
            while(idx < alpha.size()){
                if(check[idx]){ // 해당 글자가 조합에 있다면 
                    if(table[i][j] == alpha[idx]){
                        break;
                    }
                    else{
                        idx++;
                    }
                    
                }
                else{ // 해당 글자가 조합 안에 없다면 
                    idx++;
                }
                
                if(idx == alpha.size()){ // idx가 끝까지 도달는데
                        fail = 1;
                }
                
            }
            if(fail == 1){
                break;
            }
            
            if(j == word_size - 1){
                temp_answer++;
            }    
            
            
            
            
        }
        
    }
    answer = max(answer, temp_answer); 
}


void combi(int start, int cnt) {
    if (cnt == m) { // m이 없앨 치킨집 만큼 나왔을 때 
        // 거리 계산
        // distance_check();
        
        int aivle = 1;
        for (int j = 0; j < alpha.size(); j++){
            if(alpha[j] == 'a' || alpha[j] == 'c' || alpha[j] == 'n' || alpha[j] == 't' || alpha[j] == 'i'){
                if(!check[j]){ // 항상 들어가는 글자를 배우지 못했다면
                    aivle = 0;
                    break;
                }
            }
        }
        if (aivle == 1){
            word_check();
        }
        return;
    }
    else {
        // 폐업하지 않을 치킨집 고르기
        for (int i = start; i < alpha.size(); i++) {
            if (!check[i]) {
                check[i] = true;
                combi(i + 1, cnt + 1);
                check[i] = false;
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    string word;
    
    set <char> alphabet; // 사용된 글자들을 저장할 배열 
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        set <char> temp; // 해당 글자에 사용된 알파뱃을 저장
        cin >> word;
        for(auto i :  word){
            temp.insert(i);
            alphabet.insert(i); // 사용된 글자들을 저장
        }
        
        vector<char> v(temp.begin(), temp.end()); // char 배열 생성 set -> char 
        table.push_back(v);
    }

    std::copy(alphabet.begin(), alphabet.end(), std::back_inserter(alpha));
    check.resize(alpha.size());
    
    
    if(m < 5){ // 5보다 작으면 아무것도 못함
        cout << "0";
        return 0;
    }
    
    if(alpha.size() <= m){ // 사용된 글자보다 사용할 수 있는 글자가 더 많거나 같다면
        cout << n; // 모든 단어를 읽을 수 있음
        return 0;
    }
    
    
    combi(0, 0);
    


    cout << answer;
    return 0;
}
