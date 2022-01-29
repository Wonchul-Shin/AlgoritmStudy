#include <iostream>
#include <vector>

using namespace std;


void myMerge(int* arr, int start, int mid, int end) {
    int* tmp = new int[end - start];
    int left = start, right = mid;

    for (int i = 0; i < end - start; i++) {
        if (left == mid) {
            tmp[i] = arr[right];
            right++;
        }
        else if (right == end) {
            tmp[i] = arr[left];
            left++;
        }
        else {
            if (arr[left] > arr[right]) {
                tmp[i] = arr[right];
                right++;
            }
            else {
                tmp[i] = arr[left];
                left++;
            }
        }
    }

    for (int i = 0; i < end - start; i++)
        arr[start + i] = tmp[i];

    delete tmp;
}

void mySort(int* arr, int start, int end) {
    int tmp;

    if (end - start == 1) {
        return;
    }
    else if (end - start == 2) {
        if (arr[start] > arr[end - 1]) {
            tmp = arr[start];
            arr[start] = arr[end - 1];
            arr[end - 1] = tmp;
            return;
        }
    }
    tmp = (end + start) / 2;

    mySort(arr, start, tmp);
    mySort(arr, tmp, end);
    myMerge(arr, start, tmp, end);
}

int main() {

    int n;
    int* arr;

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n;

    arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mySort(arr, 0, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';

    return 0;
}