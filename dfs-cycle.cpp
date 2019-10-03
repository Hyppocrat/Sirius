#include <iostream>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <list>
#include <vector>
using namespace std;
//список смежности
vector <int> gr[113];

//пусть в графе не больше, чем 100 вершин
int n, m; // n - число вершин, m - число ребер

vector <int> pred(113, -1); //массив предков
//pred[i] = p <=> в вершину i пришли из вершины p

vector <int> used(113, 0); // массив вершин которые мы посещали
//used[i] = 0, если вершина белая (в ней еще не были)\
//used[i] = 1, если вершина серая (зашли, но не вышли)
//used[i] = 2, если вершина черная (вышли из неё)

int cycle_start = -1;
int cycle_finish = -1;

//обход в глубину для поиска цикла
bool dfs(int s) {
	used[s] = 1;
	for (int i = 0; i < gr[s].size(); ++i) {
		int x = gr[s][i];
		if (!used[x]) {
			pred[x] = s;
			if (dfs(x)) {
				return true;
			}
		}
		else if (used[x] == 1 && pred[s] != x) {
			cycle_finish = s;
			cycle_start = x;
			return true;
		}
	}
	used[s] = 2;
	return false;
}


int main() {

	cin >> n >> m;
	//считали граф
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		if (!used[i] && dfs(i)) {
			cout << "Cycle est!\n";
			int p = cycle_finish;
			while (p != cycle_start) {
				cout << p << ' ';
				p = pred[p];
			}
			cout << cycle_start;
		}
		else {
			cout << "Cycla net!";
		}
	}
}