#include <iostream>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <list>
#include <vector>
using namespace std;
//матрица смежности
int gr[113][113];

//пусть в графе не больше, чем 100 вершин
int n, m; // n - число вершин, m - число ребер

vector <int> used(113, 0); // массив вершин которые мы посещали
//used[i] = 1, если в i-й вершине мы были

//обход в глубину
void dfs(int s) {
	used[s] = 1;
	for (int i = 1; i <= n; ++i) {
		if (gr[s][i] && !used[i]) {
			dfs(i);
		}
	}
}


int main() {

	cin >> n;
	//считали матрицу смежности
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> gr[i][j];
		}
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