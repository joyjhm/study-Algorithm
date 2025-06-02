#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

struct Status {
    string clock;
    bool isPresent;
    int val;
};

vector<string> split(const string& str, char delim) {
    vector<string> result;
    stringstream ss(str);
    string token;
    
    while (getline(ss, token, delim)) {
        result.push_back(token);
    }
    
    return result;
}

int getTime(string start, string end) {
    int start_hour = stoi(start.substr(0, 2));
    int start_min = stoi(start.substr(3, 2));
    
    int end_hour = stoi(end.substr(0, 2));
    int end_min = stoi(end.substr(3, 2));
    
    if(end_min - start_min < 0) {
        return (end_hour - 1 - start_hour) * 60 + (end_min + 60 - start_min); 
    }
    else {
        return (end_hour - start_hour) * 60 + (end_min - start_min);
    }
    

}


vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, Status> m;
    
    for (int i = 0; i < records.size(); i++) {
        vector<string> record = split(records[i], ' ');

        if(!m.count(record[1])) {
            m[record[1]] = {record[0], true, 0};            
        }
        else {
            if(m[record[1]].isPresent) {
                string start = m[record[1]].clock;
                string end = record[0];
                int time = getTime(start, end);

                m[record[1]].val += time;
                m[record[1]].isPresent = false;
            }
            else {
                m[record[1]].clock = record[0];
                m[record[1]].isPresent = true;
            }
        }
        
    }
    
    for (pair<string, Status> p: m) {
        if(p.second.isPresent) {
            int time = getTime(p.second.clock, "23:59");
            p.second.val += time;
        }
        
        int fee;
        if(p.second.val - fees[0] < 0) {
            fee = fees[1];
        }
        else {
            fee = fees[1] + ceil((double)(p.second.val - fees[0]) / fees[2]) * fees[3];    
        }
        
        answer.push_back(fee);
    }
    
    
    return answer;
}