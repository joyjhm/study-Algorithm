#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    int width = 0;
    int height = 0;

    for (int i = 0; i < sizes.size(); i++) {
        int w = sizes[i][0];
        int h = sizes[i][1];
        
        if (w > h) {
            width = max(w, width);
            height = max(h, height);
        } else {
            width = max(h, width);
            height = max(w, height);
        }
    }   

    return width * height;
}