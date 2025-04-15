#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPossible[1000000];

int solution(int elements[], size_t elements_len) {
    int answer = 0;
    
    for (int i = 1; i <= elements_len; i++) {
        int sum = 0;
        for (int j = 0; j < i; j++) {
            sum += elements[j];
        }
        isPossible[sum] = true;
        int start = 0;
        int end = i;
        for (int j = 0; j < elements_len; j++) {
            sum -= elements[start % elements_len];
            sum += elements[end % elements_len];
            isPossible[sum] = true;
            start++;
            end++;
        }
    }
    
    for (int i = 1; i <= 1000000; i++) {
        if(isPossible[i]) {
            answer++;
        }
    }
    
    return answer;
}