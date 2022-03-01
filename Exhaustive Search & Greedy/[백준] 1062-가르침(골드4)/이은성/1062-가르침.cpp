#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int usingalpha[26]{0, };
bool check[26]{false, };
vector<string> v;

int findmax(int k, int last){
    int tmp, max = 0;
    int count;
    bool flag;

    if(k == 0){                                   //여기서 최대 값 찾기
        count = 0;                                  
        for(int i = 0; i < v.size(); i++){
            flag = true;
            for(int j = 0; j < v[i].size(); j++){
                if(!check[v[i][j] - 'a']){
                    flag = false;
                    break;
                }
            }

            if(flag)
                count++;
        }
        return count;
    }
                                         
    for(int i = last + 1; i < 26; i++){          //여기서 재귀
        if(!check[i] && usingalpha[i] > 0){
            check[i] = true;
            if(i == 25)
                tmp = findmax(0, i);
            else
                tmp = findmax(k - 1, i);
            check[i] = false;
            if(tmp > max)
                max = tmp;

        }
    }
    return max;
}

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, k; cin >> n >> k;
    int usingcount = 0;
    string s;

    check['a'-'a'] = true;
    check['n'-'a'] = true;
    check['t'-'a'] = true;
    check['i'-'a'] = true;
    check['c'-'a'] = true;

    for(int i = 0; i < n; i ++){
        cin >> s;
        for(int j = 0; j<s.size(); j++){
            usingalpha[s[j] - 'a']++;
        }
        v.push_back(s);
    }

    for(int i = 0; i < 26; i++){
        if(usingalpha[i] > 0)
            usingcount++;
    }

    if(k < 5){
        cout << 0;
        return 0;
    }
    else if(k > usingcount){
        cout << n;
        return 0;
    }

    cout << findmax(k - 5, -1);

    return 0;
}
