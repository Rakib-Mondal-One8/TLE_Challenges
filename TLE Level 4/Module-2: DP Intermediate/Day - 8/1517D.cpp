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
bool valid(int i, int j , int n, int m) {
	return i >= 0 && i < n && j >= 0 && j < m;
}
void RakibOne8()
{
	int n, m, steps;
	cin >> n >> m >> steps;

	vector<vector<int>>verticalEdges(n, vector<int>(m));
	vector<vector<int>>horizontalEdges(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			cin >> horizontalEdges[i][j];
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			cin >> verticalEdges[i][j];
		}
	}

	vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(21)));

	/*
	dp[i][j][k] = minimum boredness that can get to reach from (i,j) to (i,j) in k steps
	*/

	vector<int>dx = {0, 0, 1, -1};
	vector<int>dy = {1, -1, 0, 0};
	for (int k = 0; k <= 20; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				if (k & 1) {
					dp[i][j][k] = -1;
				} else {
					if (k == 0) {
						dp[i][j][k] = 0;
					}
					else {
						dp[i][j][k] = 2e9;
						for (int cases = 0; cases < 4; cases++) {
							int newI = i + dx[cases];
							int newJ = j + dy[cases];

							if (valid(newI, newJ, n, m)) {
								int edgeWeight = 0;
								if (newI != i) edgeWeight = verticalEdges[min(i, newI)][j];
								else edgeWeight = horizontalEdges[i][min(newJ, j)];

								dp[i][j][k] = min(dp[i][j][k], 2 * edgeWeight + dp[newI][newJ][k - 2]);
							}

						}
					}
				}

			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dp[i][j][steps] << " ";
		}
		cout << nl;
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