#include <iostream>
#include <deque>
#include <set>
using namespace std;
int a;
int main() {
	set <int> st, st2;
	set <char> st3;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		st.insert(a);//добавить элемент в сет	
	}
	set<int>::iterator it = st.begin();
	for (set<int>::iterator it2 = st.begin(); it2 != st.end(); ++it2) {
		cout << (*it2) << ' ';
	}
	if (st.find(5) != st.end()) {
		cout << endl << "PYATERKA!";
	}
	//st.lower_bound(a);
	//st.upper_bound(a);
	cout << (*st.begin());
	//st.erase(it);
	//st.erase(st.begin());
	st.empty(); // пуст ли сет
	cout << '\n' << st.size();	// кол-во элементов в сете
}
