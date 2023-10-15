/*
- 문제 푸는 방법
1. 바이너리 함수를 사용해서 풀기
2. 하나의 벡터에 다 넣고 정렬 후 연속된 것 찾아서 풀기
3. map을 사용해서 풀기

*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int n, m;
map<string, int> mp;
vector<string> result;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n + m; i++) {
        string s;
        cin >> s;
        mp[s]++;
        if(mp[s] == 2) {
            result.push_back(s);
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << endl;
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }
}