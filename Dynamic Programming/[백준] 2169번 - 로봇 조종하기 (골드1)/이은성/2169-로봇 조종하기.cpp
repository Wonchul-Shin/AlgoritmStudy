#include <iostream>
#include <vector>

using namespace std;

int arr[1000][1000];
int leftarr[1000];
int rightarr[1000];
int n, m; 

int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int max(int a, int b, int c){
    if(a > b){
        if(a > c)
            return a;
        return c;
    }
    else{
        if(b > c)
            return b;
        return c;
    }
}

void fillleft(int row){
    leftarr[0] = arr[row - 1][0] + arr[row][0];
    for(int i = 1; i < m; i++){
        leftarr[i] = max(leftarr[i - 1], arr[row - 1][i]) + arr[row][i];
    }
}

void fillright(int row){
    rightarr[m - 1] = arr[row - 1][m - 1] + arr[row][m - 1];
    for(int i = m - 2; i >= 0; i--){
        rightarr[i] = max(rightarr[i + 1], arr[row - 1][i]) + arr[row][i];
    }
}

void fillarr(){
    for(int i = 1; i < n; i++){
        fillleft(i);
        fillright(i);
        for(int j = 0; j < m; j++){
            if(j == 0){
                arr[i][j] = max(rightarr[j], arr[i - 1][j] + arr[i][j]);
            }
            else if(j == m - 1){
                arr[i][j] = max(leftarr[j], arr[i - 1][j] + arr[i][j]);
            }
            else{
                arr[i][j] = max(leftarr[j], rightarr[j], arr[i - 1][j] + arr[i][j]);
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i < m; i++){
        arr[0][i] = arr[0][i - 1] + arr[0][i];
    }

    fillarr();

    cout << arr[n - 1][m - 1];

    return 0;
}
