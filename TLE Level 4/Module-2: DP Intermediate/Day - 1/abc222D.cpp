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
const int mod = 998244353;
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

	vector<int>a(n + 1), b(n + 1);

	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++)cin >> b[i];

	/*
	dp[i][j] = number of non-decreasing sequences that can be made
	by choosing the ith value as j.

	dp[i][j] = sum[i-1][j] + sum[i-1][j-1]+.... sum[i-1][0];

	sum[i][1] = dp[i][1] + sum[i-1][1];
	sum[i][2] = dp[i][2] + sum[i-1][2];
	.
	.
	.
	sum[i][j] = dp[i][j] + sum[i-1][j]
	*/

	vector<vector<int>>dp(n + 1, vector<int>(3005));
	// vector<vector<int>>sum(n + 1, vector<int>(3005));

	for (int j = a[1]; j <= b[1]; j++)dp[1][j] = 1;

	for (int i = 2; i <= n; i++) {
		int prefix = 0;
		for (int j = 0; j <= 3000; j++) {
			prefix =  (prefix + dp[i - 1][j]) % mod;
			if (j >= a[i] && j <= b[i])
				dp[i][j] = prefix;
		}
	}

	int ans = 0;
	for (int i = 0; i <= 3000; i++)ans = (ans + dp[n][i]) % mod;
	cout << ans << nl;
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