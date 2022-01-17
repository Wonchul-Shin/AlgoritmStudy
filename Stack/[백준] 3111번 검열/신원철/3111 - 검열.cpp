#include <iostream>
#include <stdio.h>
#include <string.h>
#include <list>
using namespace std;
char a[30];
char t[300003];
list<char> link;
int len_a = 0;
int len_t = 0;


// bool search_left(list<char> link, list<char>::iterator iter) { // 정순환 // 시간 오류 
// 	for (int i = 0; i < len_a; i++) {
// 		if (iter == link.end() || *iter != a[i]) // 만약 끝이거나 다르거나 하면 
// 			return false;
// 		iter++;
// 	}
// 	return true;
// }

bool search_left(list<char> *link, list<char>::iterator iter) { // 정순환
	for (int i = 0; i < len_a; i++) {
		if (iter == link->end() || *iter != a[i]) // 만약 끝이거나 다르거나 하면 
			return false;
		iter++;
	}
	return true;
}



bool search_right(list<char> *link, list<char>::iterator iter) { // 역순환 
	for (int i = len_a - 1; i >= 0; i--) {
		if (iter == link->begin() || *iter != a[i]) // 만약 처음이거나 다르거나 하면
			return false;
		iter--;
	}
	return true;
}
int main(void) {
	cin >> a;
	cin >> t;
	len_a = strlen(a);
	len_t = strlen(t);
	int check = 0;
	link.push_back('S'); // 대문자로 시작을 알림
	for (int i = 0; i < len_t; i++)
		link.push_back(t[i]);
	link.push_back('E'); // 대문자로 끝을 알림
	
	
	list<char>::iterator iter_left = link.begin(); // 정순환
	list<char>::iterator iter_right = link.end(); // 역순환
	int start_poit = 1; // 앞에서 시작할지 뒤로시작할지 -1을 계속 곱하며 순환
	while (1) { // break가 될 때까지 순환
		if (start_poit == 1) { // 만약 정순환일 때 
			if (iter_left == link.end()) // 끝에 도달하면 break
				break;
			if (search_left(&link, iter_left)) { // 만약 문자열을 찾으면 
				for (int i = 0; i < len_a; i++) // 해당 문자열 제거
					iter_left = link.erase(iter_left); 
				for (int i = 0; i < 2 * len_a; i++) { // 새로운 문자열이 생성될 수 있기 때무에 뒤로 이동 
					if (iter_left == link.begin()) // 맨앞이면 종료
						break;
					iter_left--;
				}
				start_poit *= -1; // 역순환으로 변경 
			}
			else{ // 만약 못찾으면 다음으로 이동
			    iter_left++;
			}
				
		}
		else { // 역순환일 때 
			if (iter_right == link.begin()) // 처음에 도달하면 break
				break;
			if (search_right(&link, iter_right)) { // 해당 문자열을 찾으면 
				for (int i = 0; i < len_a; i++) { // 문자열을 제거 
					iter_right = link.erase(iter_right);
					iter_right--;
				}
				for (int i = 0; i < 2 * len_a; i++) { //  새로운 문자열이 생성될 수 있기 때문에  앞으로 이동 
					if (*iter_right == 'E') // 끝일 때 
						break;
					iter_right++;
				}
				start_poit *= -1;
			}
			else{
			    iter_right--;
			}
		}
	}
	link.pop_front(); // 앞뒤 문자열 제거 
	link.pop_back();
	
	
	
	for (iter_left=link.begin(); iter_left != link.end(); iter_left++){ // 문자열 출력
	    cout << *iter_left;
	}
}