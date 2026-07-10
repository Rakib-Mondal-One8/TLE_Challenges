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

void RakibOne8()
{
	int n;
	cin >> n;

	vector<vector<int>>edges(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;

		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	auto dfs = [&](auto && self, int root, int parent, vector<int>&dist) -> void{
		dist[root] = dist[parent] + 1;
		for (auto child : edges[root]) {
			if (child != parent) {
				self(self, child, root, dist);
			}
		}
	};

	vector<int>dist1(n + 1);
	vector<int>dist2(n + 1);
	vector<int>dist3(n + 1);

	dfs(dfs, 1, 0, dist1);
	int x = -1;
	int mn = INT_MIN;
	for (int i = 1; i <= n; i++) {
		if (dist1[i] > mn) {
			mn = dist1[i];
			x = i;
		}
	}
	debug(x);
	debug(dist1);

	dfs(dfs, x, 0, dist2);
	int y = -1;
	int diameter = INT_MIN;
	for (int i = 1; i <= n; i++) {
		if (dist2[i] > diameter) {
			diameter = dist2[i];
			y = i;
		}
	}
	debug(y);
	debug(dist2);

	dfs(dfs, y, 0, dist3);
	debug(dist3, diameter);

	int endOneSum = 0;
	int endTwoSum = 0;

	for (int i = 1; i <= n; i++) {
		endOneSum += dist2[i] - 1;
		endTwoSum += dist3[i] - 1;
	}

	debug(endOneSum, endTwoSum);

	for (int i = 1; i <= n; i++) {
		int res;
		// if (dist2[i] == diameter) {
		// 	cout << endTwoSum << " ";
		// }
		// else if (dist3[i] == diameter) {
		// 	cout << endOneSum << " ";
		// }
		// else
		if (dist2[i] <= dist3[i]) {
			res = ((n - (dist2[i] + 1)) * dist2[i]);
			cout << endOneSum -  res << " ";
		}
		else {
			res = ((n - (dist3[i] + 1)) * dist3[i]);
			cout << endTwoSum -  res << " ";
		}

	}
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