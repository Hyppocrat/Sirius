#include <iostream>
#include <deque>
#include <queue>
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

vector <int> dist(113, 0); //dist[i] - кратчайшее расстояние
//от старта до i-й вершины ( - 1)



//обход в ширину
void bfs(int s) {
	dist[s] = 1;
	queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < gr[x].size(); ++i) {
			int to = gr[x][i];
			if (dist[to] == 0) {
				dist[to] = dist[x] + 1;
				q.push(to);
			}
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
	bfs(3);
	for (int i = 1; i <= n; ++i) {
		cout << dist[i] - 1 << ' ';
	}
}