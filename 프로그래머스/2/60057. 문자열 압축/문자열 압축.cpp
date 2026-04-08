#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s) {
    int n = s.length();

    int answer = n;
    for (int i = 1; i < n; i++) {

        string prev = s.substr(0, i);
        int cnt = 1;
        int len = n;
        for (int j = i; j < n; j += i) {
            string cur = s.substr(j, i);

            if(prev == cur) {
                cnt++;
            }
            else {
                if(cnt > 1) {
                    int val = cnt;
                    int rest = 1;
                    while(val / 10) {
                        val /= 10;
                        rest++;
                    }
                    len -= (cnt * i) - (i + rest);
                }
                prev = cur;    
                cnt = 1;
            }
        }

        if(cnt > 1) {
            int val = cnt;
            int rest = 1;
            while(val / 10) {
                val /= 10;
                rest++;
            }
            len -= (cnt * i) - (i + rest);
        }

        answer = min(answer, len);
    }

    return answer;
}