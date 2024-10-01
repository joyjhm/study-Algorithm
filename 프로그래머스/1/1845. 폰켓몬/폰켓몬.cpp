#include <vector>
using namespace std;

bool visited[200001];

int solution(vector<int> nums)
{
    int answer = 0;
    int len = nums.size();
    
    for (int i = 0; i < len; i++) {
        int target = nums[i];
        if(!visited[target]) {
            visited[target] = true;
            answer++;
        }
        
        if(answer >= len / 2) {
            break;
        }
    }
    
    return answer;
}