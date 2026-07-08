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
const int N = 3e5 + 1;
struct BinaryLifting {
	int n;
	int mxLog;
	int maxRequirement;
	vector<vector<int>>parent;
	vector<vector<int>>mn;

	BinaryLifting(int n1, vector<pair<int, int>> *edges, int requirement, int root) {
		n = n1;
		mxLog = log2(requirement + 1);
		maxRequirement = requirement;
		parent.resize(n1);
		mn.resize(n1);

		for (int i = 0; i < n; i++) {
			parent[i].resize(mxLog + 1);
			mn[i].resize(mxLog + 1);
			for (int j = 0; j <= mxLog; j++) {
				parent[i][j] = -1;
				mn[i][j] = INT_MAX;
			}
		}
		fillParentTable(root, edges);
	}

	void fillParentTable(int root, vector<pair<int, int>>*edges) {
		vector<bool>visited(n);
		dfsBinaryLifting(root, edges, visited);

		for (int j = 1; j <= mxLog; j++) {
			for (int i = 0; i < n; i++) {
				int intermediate = parent[i][j - 1];
				if (intermediate != -1) {
					parent[i][j] = parent[intermediate][j - 1];

					mn[i][j] = min({mn[i][j], mn[intermediate][j - 1], mn[i][j - 1]});
				}
			}
		}
	}

	void dfsBinaryLifting(int root, vector<pair<int, int>>*edges, vector<bool>&visited) {
		visited[root] = true;

		for (auto i : edges[root]) {
			if (!visited[i.first]) {
				parent[i.first][0] = root;
				mn[i.first][0] = i.second;
				dfsBinaryLifting(i.first, edges, visited);
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

	int kthMin(int u, int k) {
		int minVal = INT_MAX;
		for (int i = mxLog; i >= 0; i--) {
			if ((k >> i) & 1) {
				if (u == -1) return minVal;

				minVal = min(minVal, mn[u][i]);
				u = parent[u][i];
			}
		}

		return minVal;
	}
};
struct LCA {
	int n;
	vector<int>level;
	LCA(int n1, int root, vector<pair<int, int>>*edges) {
		n = n1;
		level.resize(n1);
		dfsLCA(root, -1, edges);
	}

	void dfsLCA(int root, int parent, vector<pair<int, int>>*edges) {
		for (auto i : edges[root]) {
			if (i.first != parent) {
				level[i.first] = level[root] + 1;
				dfsLCA(i.first, root, edges);
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

	vector<pair<int, int>> *edges = new vector<pair<int, int>>[n + 1];
	for (int i = 1; i <= m; i++) {
		int u, v, weight;
		cin >> u >> v >> weight;

		edges[u].push_back({v, weight});
		edges[v].push_back({u, weight});

	}
	int root = 1;

	BinaryLifting bl = BinaryLifting(n + 1, edges, n, root);
	LCA lca = LCA(n + 1, root, edges);

	debug(bl.mn);

	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;

		int l = lca.getLCA(u, v, bl);

		int dest1 = lca.level[u] - lca.level[l];
		int dest2 = lca.level[v] - lca.level[l];

		int min1 = bl.kthMin(u, dest1);
		int min2 = bl.kthMin(v, dest2);

		cout << min(min1, min2) << nl;

		// cout << lca.getMin(u, v, bl) << nl;

	}

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