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
	int n, m, k;
	cin >> n >> m >> k;

	vector<int>c(n);
	for (auto &x : c)cin >> x;


	vector<vector<int>>p(n, vector<int>(m)); // 0 based indexing
	// to color the ith index in color 5 p[i][4];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)cin >> p[i][j];


	vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 2, 1e18)));

	/*
	dp[i][lastColor][beauty] = minimum cost to paint the suffix i to n-1.
	such that the color was lastColor and the beauty so far is beauty
	*/

	//base
	for (int i = 0; i <= m; i++)dp[n][i][k] = 0; // final beauty should be k lastColor doesn't matter


	for (int i = n - 1; i >= 0; i--) {
		for (int lastColor = 0; lastColor <= m; lastColor++) {
			for (int beauty = 0; beauty <= k; beauty++) {
				// dp[i][lastColor][beauty]

				int res = 1e18;
				for (int curColor = 1; curColor <= m; curColor++) {
					if ((curColor != c[i]) && (c[i] != 0))continue;

					int paintCost = (curColor != c[i]) ? p[i][curColor - 1] : 0;
					int newBeauty = (lastColor != curColor) ? beauty + 1 : beauty;

					if (beauty > k)continue;

					res = min(res, dp[i + 1][curColor][newBeauty] + paintCost);
				}
				dp[i][lastColor][beauty] = res;
			}
		}
	}
	(dp[0][0][0] == 1e18) ? cout << -1 << nl : cout << dp[0][0][0] << nl;


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