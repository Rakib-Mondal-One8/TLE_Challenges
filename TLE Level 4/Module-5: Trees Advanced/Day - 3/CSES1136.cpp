#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) ((int)(x).size())
#define nl '\n'
#ifdef Rakib_18
#include "debug.hpp"
#else
#define debug(...)
#endif
void init_code() {
#ifdef Rakib_18
	freopen("Error.txt", "w", stderr);
#endif
}
using namespace chrono;

/*_________________________________________________________________________________________________________________________________________________________________________________________________________________________*/
const int mod = 1e9 + 7;
int expo(int a, int b, int mod) { int res = 1; while (b > 0) { if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1; } return res; }
int mminvprime(int a, int b) { return expo(a, b - 2, b); }
int inv(int i) { if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod; }
bool isPrime(int n) { if (n <= 1)return false; if (n <= 3)return true; if (n % 2 == 0 || n % 3 == 0)return false; for (int i = 5; i * i <= n; i += 6) { if (n % i == 0 || n % (i + 2) == 0)return false; } return true; }
int lcm(int a, int b) { return (a / __gcd(a, b)) * b; }
int mod_add(int a, int b, int m) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
int mod_mul(int a, int b, int m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
int mod_sub(int a, int b, int m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
int mod_div(int a, int b, int m) { a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m; }  //only for prime m
int nXOR(int n) { if (n % 4 == 0)return n; if (n % 4 == 1)return 1; if (n % 4 == 2)return n + 1; return 0; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*_________________________________________________________________________________________________________________________________________________________________________________________________________________________*/
struct BinaryLifting {
	int n;
	int mxLog;
	int maxRequirement;
	vector<vector<int>>parent;

	BinaryLifting(int n1, vector<int> *edges, int requirement, int root) {
		n = n1;
		mxLog = log2(requirement + 1);
		maxRequirement = requirement;
		parent.resize(n1);

		for (int i = 0; i < n; i++) {
			parent[i].resize(mxLog + 1);
			for (int j = 0; j <= mxLog; j++) {
				parent[i][j] = -1;
			}
		}
		fillParentTable(root, edges);
	}

	void fillParentTable(int root, vector<int> *edges) {
		vector<bool>visited(n);
		dfsBinaryLifting(root, edges, visited);

		for (int j = 1; j <= mxLog; j++)
		{
			for (int i = 0; i < n; i++) {
				int intermediate = parent[i][j - 1];
				if (intermediate != -1) {
					parent[i][j] = parent[intermediate][j - 1];
				}
			}
		}
	}

	void dfsBinaryLifting(int root, vector<int> *edges, vector<bool>&visited) {
		visited[root] = true;

		for (auto i : edges[root]) {
			if (!visited[i]) {
				parent[i][0] = root;
				dfsBinaryLifting(i, edges, visited);
			}
		}
	}

	int kthParent(int u, int k) {
		for (int i = 0; i <= mxLog; i++) {
			if ((k >> i) & 1) {

				if (u == -1)return u;
				u = parent[u][i];
			}
		}
		return u;
	}
};

struct LCA {
	int n;
	vector<int>level;
	LCA(int n1, int root, vector<int> *edges) {
		n = n1;
		level.resize(n1);
		dfsLCA(root, -1, edges);
	}

	void dfsLCA(int root, int parent, vector<int> *edges) {
		for (auto i : edges[root]) {
			if (i != parent) {
				level[i] = level[root] + 1;
				dfsLCA(i, root, edges);
			}
		}
	}

	int getLCA(int u, int v, BinaryLifting &bl_object) {
		if (level[u] < level[v])swap(u, v);
		int diff = level[u] - level[v];
		u = bl_object.kthParent(u, diff);

		if (u == v)return u;

		for (int i = bl_object.mxLog; i >= 0; i--) {
			int parent1 = bl_object.parent[u][i];
			int parent2 = bl_object.parent[v][i];
			if (parent1 != parent2 && parent1 != -1 && parent2 != -1) {
				u = parent1;
				v = parent2;
			}
		}

		return bl_object.parent[u][0];
	}

};
void RakibOne8()
{
	int n, m;
	cin >> n >> m;

	vector<int>* edges = new vector<int>[n + 1];
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;

		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int root = 1;
	BinaryLifting bl = BinaryLifting(n + 1, edges, n, 1);
	LCA lca = LCA(n + 1, root, edges);

	vector<int>occ(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;

		int res = lca.getLCA(u, v, bl);

		occ[res] -= 1;

		int par = bl.parent[res][0];
		if (par != -1) occ[par] -= 1;

		occ[u]++;
		occ[v]++;
	}

	auto dfs = [&](auto && self, int root, int parent) -> int{
		int res = occ[root];
		for (auto child : edges[root]) {
			if (child != parent) {
				res += self(self, child, root);

			}
		}
		occ[root] = res;
		return res;
	};
	dfs(dfs, 1, -1);

	for (int i = 1; i <= n; i++)cout << occ[i] << " ";
	cout << nl;

}
int32_t main()
{
	init_code();
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	// cin >> t;
	auto start1 = high_resolution_clock::now();
	while (t--)
	{
		RakibOne8();
	}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef Rakib_18
	cerr << "Time: " << duration . count() / 1000 << " ms" << endl;
#endif
	return 0;
}