#include <iostream>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <list>
using namespace std;
int a, b;
int main() {
	int n;
	cin >> n;
	list <int> lst;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		lst.push_back(a);
		lst.pop_back();
		lst.push_front(a);
		lst.pop_front();
		lst.front();
		lst.back();
		lst.insert(куда, кого); //куда - итератор на элемент 
								//перед которым надо вставить новый
		lst.erase(откуда); // откуда - итератор на элемент, который надо удалить.
		lst.size();
		lst.empty();
	}
	
	for (auto it = lst.begin(); it != lst.end(); ++it) {
		cout << (*it) << ' ';
	}
	
}