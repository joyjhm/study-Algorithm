#include <string>
#include <vector>

using namespace std;

int students[32];
bool isReserve[32];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for (int i = 1 ; i <= n; i++) {
        students[i] = 1;
    }
    
    for (int i = 0; i < reserve.size(); i++) {
        int idx = reserve[i];
        students[idx]++;
        isReserve[idx] = true;
    }
    
    for (int i = 0; i < lost.size(); i++) {
        int idx = lost[i];
        students[idx]--;
    }
    
    
//     for (int i = 0; i < lost.size(); i++) {
//         int idx = lost[i];
        
//         if(students[idx] > 0) {
//             continue;
//         }
        
//         if (students[idx - 1] > 1) {
//             students[idx - 1]--;
//             students[idx]++;
//         }
//         else if(students[idx + 1] > 1) {
//             students[idx + 1]--;
//             students[idx]++;
//         }
//     }
    
    for (int i = 1; i <= n; i++) {
        if(students[i] >= 2) {
            if(students[i - 1] == 0 && i != 1) {
                students[i]--;
                students[i - 1]++;
            }
            else if(students[i + 1] == 0 && i != n) {
                students[i]--;
                students[i + 1]++;
            }
        }
    }
    
    
    for (int i = 1; i <= n; i++) {
        if(students[i] > 0) {
            answer++;
        }
    }
    
    return answer;
}