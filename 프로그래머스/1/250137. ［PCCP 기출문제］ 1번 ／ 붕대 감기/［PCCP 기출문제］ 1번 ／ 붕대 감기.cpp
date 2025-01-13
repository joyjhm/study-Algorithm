#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int idx = 0;
    int time = 1;
    int duration = 0;
    int hp = health;
    
    while(idx < attacks.size()) {
        if(attacks[idx][0] == time) { 
            hp -= attacks[idx][1];
            if(hp <= 0) {
                return -1;
            }
            idx++;
            duration = 0;
        }
        else {
            duration++;
            if(duration == bandage[0]) {
                hp = min(health, hp + bandage[1] + bandage[2]);
                duration = 0;
            }
            else {
                hp = min(health, hp + bandage[1]);
            }
        }
        time++;
    }
    
    return hp;
}