#include <iostream>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;
int a, b;
int main() {
	multimap<int, int> mmp;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		mmp.insert(make_pair(a, b)); // добавить элемент в multimap
	}
	for (auto it = mmp.begin(); it != mmp.end(); ++it) {
		cout << (*it).first << ' ' << (*it).second << endl;
	}
	cout << mmp.count(1);
}