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

const int N = 2e5 + 7;
const int M = 20;
vector<int> edges[N];
int Par[N][M];
int dep[N];
void dfs(int cur, int parent) {
	dep[cur] = dep[parent] + 1;
	Par[cur][0] = parent;

	for (int j = 1; j < M; j++) {
		Par[cur][j] = Par[Par[cur][j - 1]][j - 1];
	}

	for (auto child : edges[cur]) {
		if (child != parent)dfs(child, cur);
	}
}

int LCA(int u, int v) {
	if (u == v)return u;
	if (dep[u] < dep[v]) swap(u, v);

	int diff = dep[u] - dep[v];

	for (int i = 0; i < M; i++) {
		if ((diff >> i) & 1) u = Par[u][i]; // lift u to reach the same level as v
	}

	for (int i = M - 1; i >= 0; i--) {
		if (Par[u][i] != Par[v][i]) {
			u = Par[u][i];
			v = Par[v][i];
		}
	}

	return ((u != v) ? Par[u][0] : u);
}
void RakibOne8()
{
	int n, q;
	cin >> n >> q;

	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;

		edges[p].push_back(i);
	}

	dfs(1, 0); // Binary Lifting

	while (q--) {
		int u, v;
		cin >> u >> v;

		cout << LCA(u, v) << nl;
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