#include<bits/stdc++.h>
using namespace std;
#define nl "\n";


const int N = 2e5 + 7;
const int M = 20;
vector<vector<int>>edges(N);
int parents[N][M];
void dfs(int cur, int parent) {

	parents[cur][0] = parent;
	for (int i = 1; i < M; i++) {
		parents[cur][i] = parents[parents[cur][i - 1]][i - 1];
	}

	for (auto child : edges[cur]) {
		if (child != parent)dfs(child, cur);
	}

}

int KthBoss(int employee, int k) {

	int boss = employee;
	for (int i = 0; i < M; i++) {
		if ((1 << i) & k) boss = parents[boss][i];
	}
	return boss;
}
void RakibOne8()
{
	int n, q;
	cin >> n >> q;

	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;

		edges[x].push_back(i);
	}
	dfs(1, 0);
	while (q--) {
		int e, k;
		cin >> e >> k;

		int res = KthBoss(e, k);
		res = res > 0 ? res : -1;
		cout << res << nl;

	}

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	RakibOne8();
	return 0;
}