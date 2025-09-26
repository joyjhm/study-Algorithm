#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {

    int n = sequence.size();
    int start = 0;
    int end = 0;
    int sum = 0;
    int len = n;
    int result = 0;
    for (int end = 0; end < n; end++) {
        sum += sequence[end];
        
        while(sum > k) {
            sum -= sequence[start];
            start++;
        }
        if(sum == k) {
            if(end - start + 1 < len) {
                len = end - start + 1;
                result = start;
            }
        }
    }
    
    vector<int> answer = {result, result + len - 1};

    return answer;
}