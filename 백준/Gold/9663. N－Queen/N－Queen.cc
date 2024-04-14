#include <iostream>
using namespace std;

int n;
int col[16]{ 100 };
int result = 0;
bool promising(int i) {

	bool s = true;
	int k = 1;
	while (k < i) {
		if (col[i] == col[k] || i - k == col[i] - col[k] || i - k == col[k] - col[i]) {
			s = false;
			return s;
		}
		k++;
	}
		
	if (s && i == n) {
		result++;
	}
	return s;
}


void queen(int i) {

	if (promising(i)) {
		
	
		for (int j = 1; j <= n; j++)
		{
			
			if (i + 1 <= n) {
				col[i + 1] = j;
				queen(i + 1);
			}
			
		}	
	}
}


int main() {
	
	cin >> n;
	queen(0);
	cout << result;
}