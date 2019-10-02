#include <iostream>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;
int a;
int main() {
	map <string, string> mp;
	mp["somkin"] = "artyom";
	mp["kozlov"] = "roma";
	mp["kupreeva"] = "katya";
	mp["somkin"] = "moytra";
	mp["kirzhinov"] = "dovlet";
	//вывод на экран, пробежавшись по mapу
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		cout << (*it).first << ' ' << (*it).second << endl;
	}
	cout << "========\n";
	if (mp.find["somkin"] != mp.end()) { //поиск в map по ключу
		cout << "SOMKIN ZDES \n";
	}
	mp.erase("kirzhinov"); // удалить по ключу
	mp.erase(mp.find("somkin")); //удалить по итератору + поиск в map
	cout << (*mp.upper_bound("kozlov")).second;
	cout << (*mp.lower_bound("kozlov")).second;
	//у вектора тоже есть upper_bound и lower_bound, только он тоже должен быть отсортирован
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		cout << (*it).first << ' ' << (*it).second << endl;
	}
}