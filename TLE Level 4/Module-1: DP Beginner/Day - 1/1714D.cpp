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
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void RakibOne8()
{
	string s;
	cin >> s;

	int n = sz(s);

	int m;
	cin >> m;

	vector<string>pattern(m);
	for (auto &x : pattern)cin >> x;

	/*
	dp[i][k] = minimum number of operations to color all the characters from i to n-1
	where k characters are already colored.

	dp[i][k] = dp[i+1][k-1]
	*/
	vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
	for (int i = n - 1; i >= 0; i--) {
		for (int k = 0; k < n; k++) {
			// invalid state
			if (k > n - i) {
				dp[i][k] = 1e9;
				continue;
			}

			// reached the answer
			if (k == n - i) {
				dp[i][k] = 0;
				continue;
			}

			//skip
			int skip = 1e9;
			if (k != 0)skip = dp[i + 1][k - 1];

			// pick
			int longestString = 0;
			int pick = 1e9;
			for (int j = 0; j < m; j++) {
				int string_len = sz(pattern[j]);

				if (i + string_len <= n && s.substr(i, string_len) == pattern[j]) {
					int colorings = 1 + dp[i + 1][max(k - 1, string_len - 1)];
					pick = min(pick, colorings);
				}
			}

			dp[i][k] = min(skip, pick);
		}
	}
	cout << dp[0][0] << nl;

}
int32_t main()
{
	init_code();
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	cin >> t;
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