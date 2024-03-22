#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[10000];

string change(int idx, string answer) {
    int num = arr[idx];
    char str;
    if (num > 9) {
        str = 55 + num;
    } else {
        str = 48 + num;      
    }
    answer.push_back(str);
    return answer;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int arr_size = 0;
    int idx = 1;
    while(answer.length() != t) {
        
        int cnt = arr_size;          
        while(cnt >= 0) {
            if(idx == p) {
                answer = change(cnt, answer);
                if (answer.length() == t) {
                    break;
                }
            }
            cnt--;
            idx++;
            if(idx > m) {
                idx = 1;
            }
            
        }

        int i = 0;
        arr[i]++;
        
        
        while(arr[i] == n) {
            if(i == arr_size) {
                arr_size++;
            }
            arr[i] = 0;
            arr[i + 1]++;
            i++;       
        }
    }
  
    return answer;
}