#include <iostream>
#include <set>
using namespace std;

int main()
{
    
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int n, m, num;
    int small, big;
    char operation;
    multiset<int> container;
    cin >> n;
    

    for (int i = 0; i < n; i++){
        cin >> m;
        for (int j = 0; j < m; j++){
            cin >> operation;
            if (operation == 'D'){
                cin >> num;
                if(!container.empty()){ // 컨테이너가 비어있지 않을 때 / 비어있으면 무시
                    if(num == -1){ // 최솟값을 삭제할 때
                        container.erase(container.begin());
                    }
                
                    else{ // 최댓값을 삭제할 때
                            
                        container.erase(--container.end());
                        
                    }
                }
                
                
            }
            
            else{ // Operation이 INSERT일 때
                cin >> num;
                container.insert(num);

            }
        }
        if(container.empty()){
            cout << "EMPTY" << "\n";
        }
        else{
            small = *container.begin();
            big = *--container.end();
            cout << big << " " << small << "\n";
        }
    }
    
    return 0;
}