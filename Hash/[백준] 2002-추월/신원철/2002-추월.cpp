#include <iostream>
#include <unordered_map>
#include<list>

using namespace std;
int main()
{
    int n;
    int answer = 0;
    cin >> n;
    

    unordered_map<string, int> hash;
    
    list<int> chain;
    
    list<int>::iterator iter = chain.begin();



    string word;

    for(int i = 0; i < n; i++){ 
        cin >> word;
        hash[word] = i; // 해시의 키로 인덱스를 설정함 0 1 2 3 4 5
        chain.push_back(i); // 리스트에도 배열을 담음 0 1 2 3 4 5 
    }
    iter = chain.begin();
    for(int i = 0; i < n; i++){ // for 문을 돌면서 
        cin >> word; // word를 받고
        iter = chain.begin(); // 포인터는 리스트의 가장 앞의 값으로 

        if (hash[word] == *iter){ // 만약 해시의 키값이 인덱스와 같다면 (순서를 지켰다면)
            chain.pop_front(); // 리스트에서 pop

        }
        else{ // 해시의 키값이 인덱스와 같지 않다면
            for(iter=chain.begin(); iter != chain.end(); iter++){
                if(hash[word] == *iter){ // 리스트에서 해당 값을 찾아서 
                    chain.erase(iter); // 지우고
                    answer++; // 답을 하나 올린다. 
                    break;
                }
            }
        }
    }

    cout << answer;


    return 0;
}

