#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int sum = 0;
    
    for (int i = 1; i <= n; i++) {
        if ((n - sum) / i <= 0) {
            break;
        }
        
        if((n - sum) % i == 0) {
            answer++;
        }
        sum += i;
    }
    
    return answer;
}