#include <iostream>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;
int a;
int main() {
	multiset <int> mst;// как сет, только хранит дубликатыы
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		mst.insert(a);
	}
	//3 4 1 3 1 5 3 4
	// 1 1 3 3 3 4 5
	for (auto it = mst.lower_bound(3); it != mst.upper_bound(3); ++it) {
		cout << (*it) << ' ';
	}
	mst.erase(3);//удалит все тройки
	cout << endl;
	mst.erase(mst.find(1));//удалит только одну единичку
	cout << mst.count(4) << endl; // сколько раз встречается элемент в мультисете
	for (auto it = mst.begin(); it != mst.end(); ++it) {
		cout << (*it) << ' ';
	}
}