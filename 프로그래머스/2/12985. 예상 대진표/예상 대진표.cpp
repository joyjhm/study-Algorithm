//비트 마스크로 풀어보기

#include <iostream>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    while(a != b) {
        if (a % 2 == 0) {
            a = a / 2;
        } else {
            a = a / 2 + 1;   
         }
        if (b % 2 == 0) {
            b = b / 2;
        } else {
            b = b / 2 + 1;
        }
        answer++;
    }
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << answer << endl;

    return answer;
}
