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

vector <int> used(113, 0); // массив вершин которые мы посещали
//used[i] = 1, если в i-й вершине мы были

//обход в глубину
void dfs(int s) {
	used[s] = 1;
	for (int i = 0; i < gr[s].size(); ++i) {
		int x = gr[s][i];
		if (!used[x]) {
			dfs(x);
		}
	}
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

	dfs(1);

	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			cout << "NE SVYAZEN!";
			return 0;
		}
	}
	cout << "SVYAZEN!";	
}