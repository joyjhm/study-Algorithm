#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

pair<int,int> pos_time, total_time, op_start_time, op_end_time;

pair<int,int> cal_time(string pos_time) {
    int minute = stoi(pos_time.substr(0,2));
    int second = stoi(pos_time.substr(3,5));
    
    return {minute, second};
}

// first 보다 second가 작거나 같은지 비교하는 함수
bool diff_time(pair<int,int> first, pair<int,int> second) {
    if(first.first < second.first) {
        return false;
    }
    else if(first.first == second.first && first.second >= second.second) {
        return true;
    }
    else if(first.first == second.first && first.second < second.second) {
        return false;
    }
    return true;
}

void is_opening() {
    if(diff_time(op_end_time, pos_time) &&
        diff_time(pos_time, op_start_time)) {
            pos_time.first = op_end_time.first;
            pos_time.second = op_end_time.second;
    }    
}

void is_end() {
    if(total_time.first - pos_time.first == 1) {
        if(total_time.second + 60 - pos_time.second < 10) {
            pos_time.first = total_time.first;
            pos_time.second = total_time.second;
        }

    }
    else if(total_time.first - pos_time.first == 0) {
        if(total_time.second - pos_time.second < 10) {
            pos_time.first = total_time.first;
            pos_time.second = total_time.second;
        }
    }
}

void is_start() {
    if(pos_time.first == 0 && pos_time.second < 10) {
        pos_time.first = 0;
        pos_time.second = 0;
    }
}



string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {

    string answer = "";
    pos_time = cal_time(pos);
    total_time = cal_time(video_len);
    op_start_time = cal_time(op_start);
    op_end_time = cal_time(op_end);
    
    is_start();
    is_end();
    is_opening();
        

    for (int i = 0; i < commands.size(); i++) {
        
        cout << pos_time.first << ":" << pos_time.second << '\n';
        
        if(commands[i].compare("next") == 0) {
            pos_time.second += 10;
            if(pos_time.second >= 60) {
                pos_time.second -= 60;
                pos_time.first++;
            }
            is_end();
        }
        else if(commands[i].compare("prev") == 0) {
            pos_time.second -= 10;
            if(pos_time.second < 0 && pos_time.first == 0) {
                pos_time.first = 0;
                pos_time.second = 0;
            }
            else if(pos_time.second < 0) {
                pos_time.second = 60 + pos_time.second;
                pos_time.first--;
            }
            is_start();
        }

        is_opening();        
    }
    
    
    cout << pos_time.first << ":" << pos_time.second << '\n';
    
            
    if (pos_time.first < 10) {
        answer += "0";
    }
    answer += to_string(pos_time.first);
    
    answer += ":";
    
    if(pos_time.second < 10) {
        answer += "0";
    }
    
    answer += to_string(pos_time.second);
    
    return answer;
}