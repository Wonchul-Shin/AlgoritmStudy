#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n, m, temp;
    unordered_map<int, array<int,2>> hash;
    string command;
    int origin_station, new_station;
    int next, nextnext, nextnextnext, before, beforebefore, beforebeforebefore;
    cin >> n >> m;
    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> temp;
        arr[i] = temp;
    }
    
    if (n == 1){ // 만약 처음 역이 하나라면 
        hash[arr[0]] = {0, 0}; // 역하나 상태로 만듦
    }
    
    else if (n == 2){ // 역이 두개라면 각각 역을 앞뒤로 연결 
        hash[arr[0]] = {arr[1], arr[1]}; 
        hash[arr[1]] = {arr[0], arr[0]};
    }
    else{ // 역이 3개 이상일 때 연결
        for (int i = 1; i < n - 1; i++){
            hash[arr[i]] = {arr[i - 1], arr[i + 1]};
        }
        hash[arr[0]] = {arr[n - 1], arr[1]};
        hash[arr[n - 1]] = {arr[n - 2] , arr[0]};
    }

    for(int i = 0; i < m; i++){ // 작업 수만큼 돌면서 
        
        cin >> command >> origin_station; 
        if (command == "BN" || command == "BP"){
            cin >> new_station;
        }
        
        if(command == "BN"){
            //    before -  [origin_station] - new_station - [next] - next next
            
            int before = hash[origin_station][0];
            if (before == 0){  // 만약 전이 0이라면 역이 하나밖에 없는 것이다. 
                cout <<  origin_station << "\n";
                hash[origin_station] = {new_station, new_station};
                hash[new_station] = {origin_station, origin_station};
            }
            else{
                int next = hash[origin_station][1];
                int nextnext = hash[next][1];
                cout <<  next << "\n";
                
                hash[origin_station] = {before, new_station};
                hash[new_station] = {origin_station, next};
                hash[next] = {new_station, nextnext};
            }
        }
           
        else if(command == "BP"){
             //    beforebefore - [before] - new_station - [origin_station] - next  
            
           int before = hash[origin_station][0];
        
            if (before == 0){ // 만약 전이 0이라면 역이 하나밖에 없는 것이다. 
                cout <<  origin_station << "\n";
                hash[origin_station] = {new_station, new_station};
                hash[new_station] = {origin_station, origin_station};
            }
            else{
                int next = hash[origin_station][1];
                int beforebefore = hash[before][0];
            
                cout <<  before << "\n";
                
                hash[origin_station] = {new_station, next};
                hash[new_station] = {before, origin_station};
                hash[before] = {beforebefore, new_station};
            }
      }
      
        else if(command == "CN"){
             //    before -  [origin_station] -(next삭제) -  nextnext  - nextnextnext 
             
            int before = hash[origin_station][0];
            int next = hash[origin_station][1];
            
            if (next == before){ // 만약 2개밖에 존재하지 않는다면
                cout <<  next << "\n";
                hash[origin_station] = {0, 0}; // 역 하나상태로 만들고 
                hash.erase(next); // 역 삭제 
            }
            else{
                int nextnext = hash[next][1];
                int nextnextnext = hash[nextnext][1];

                cout <<  next << "\n";
                hash.erase(next); // 역 삭제
                hash[origin_station] = {before, nextnext};
                hash[nextnext] = {origin_station, nextnextnext};
            }
        }
        
        else if(command == "CP"){
            //     beforebeforebefore - beforebefore - (before 삭제) -  [origin_station] - next 
            
            
            int before = hash[origin_station][0];
            int next = hash[origin_station][1];
            
            if (next == before){ // 만약 2개밖에 존재하지 않는다면
                cout <<  before << "\n";
                hash[origin_station] = {0, 0}; // 역 하나상태로 만들고 
                hash.erase(before); // 역 삭제 
            }
            else{
                int beforebefore = hash[before][0];
                int beforebeforebefore = hash[beforebefore][0];
                cout <<  before << "\n";
                hash.erase(before); // 역 삭제
                hash[origin_station] = {beforebefore, next};
                hash[beforebefore] = {beforebeforebefore, origin_station};

            }
        }
        
    }
    return 0;
}
