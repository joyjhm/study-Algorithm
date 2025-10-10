#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> split(string str, char del) {
    stringstream ss(str);
    vector<string> v;    
    string tmp;
    
    while(getline(ss, tmp, del)) {
        v.push_back(tmp);
    }

    return v;
}

int getTimes(string start, string end) {
    auto s = split(start, ':');
    auto e = split(end, ':');
    return 60 * (stoi(e[0]) - stoi(s[0])) + stoi(e[1]) - stoi(s[1]);
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";

    int n = musicinfos.size();
    int cnt = m.length();

    
    for (int i = 0; i < m.length() - 1; i++) {
        if(m[i + 1] == '#') {
            cnt--;
        }
    }

    int max_time = 0;

    for (int i = 0; i < n; i++) {
        vector<string> v = split(musicinfos[i], ',');
        int time = getTimes(v[0], v[1]);
        
        int info_cnt = v[3].length();
        for (int j = 0; j < v[3].length() - 1; j++) {
            if(v[3][j + 1] == '#') {
                info_cnt--;
            }
        }
        
        if(cnt > time) {
            continue;
        }

        int idx = 0;
        int str_len = 0;
        int len = v[3].length();
        string str = "";

        while(str_len != cnt) {
            
            if(v[3][(idx + 1) % len] == '#') {
                str.push_back(v[3][idx % len]);
                str.push_back(v[3][(idx + 1) % len]);
                idx += 2;
            } else {
                str += v[3][idx % len];
                idx++;
            }
            str_len++;
        }


        string tmp = str;
        str_len = 0;
        idx = tmp.length();
        
        while(str_len < info_cnt && cnt + str_len <= time) {
            if(tmp == m) {
                if(max_time < time) {
                    answer = v[2];
                    max_time = time;
                }
            }

            if(tmp[1] == '#') {
                tmp = tmp.substr(2);
            }
            else {
                tmp = tmp.substr(1);
            }
            
            
            if(v[3][(idx + 1) % len]  == '#') {
                tmp.push_back(v[3][idx % len]);
                tmp.push_back(v[3][(idx + 1) % len]);   
                idx += 2;
            } else {
                tmp.push_back(v[3][idx % len]);
                idx++;
            }
            str_len++;   
        }

    }
    return answer;
}