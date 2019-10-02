#include <iostream>
#include <deque>
using namespace std;
int main() {
	deque <int> dq;
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		if (a % 2 == 0) {
			dq.push_back(a);
		}
		else {
			dq.push_front(a);
		}
	}
	while (!dq.empty()) {
		cout << dq.front() << ' ';
		dq.pop_front();
	}
}