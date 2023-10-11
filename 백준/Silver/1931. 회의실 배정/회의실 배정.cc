#include<iostream>
#include<algorithm>
using namespace std;

pair<int, int> meeting[100000];

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second) 
    {
        return a.first < b.first; 
    }
    return a.second < b.second; 
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        meeting[i] = make_pair(a,b);
    }
    sort(meeting, meeting + n, compare);
    int index = 0;
    int result = 0;
    for(int i = 0; i < n; i++) {
        if(index <= meeting[i].first) {
            index = meeting[i].second;
            result++;
        }
    }
    cout << result;
     
}