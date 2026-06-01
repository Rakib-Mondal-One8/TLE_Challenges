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
	int k, a, b;
	cin >> k >> a >> b;

	string str;
	cin >> str;
	int n = sz(str);
	debug(k, a, b, n);

	// int range = (n + 1) / k;
	// debug(range);
	// if ((range < a) || (range > b)) {
	// 	cout << "No solution" << nl;
	// 	return ;
	// }

	vector<vector<int>>dp(n + 1, vector<int>(k + 1));
	/*
	dp[i][j] = number of ways to divide the first i elements into segments such that
	length of each segment lies b/w a to b
	*/

	//Base
	dp[0][0] = 1;
	// const int INF = 1e9;
	// for (int i = 1; i <= n; i++)dp[i][0] = -INF;
	// for (int i = 1; i <= k; i++)dp[0][i] = -INF;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			for (int len = a; len <= b; len++) {
				if (i >= len) {
					dp[i][j] += dp[i - len][j - 1];
				}
			}
		}
	}
	debug(dp);
	if (dp[n][k] == 0) {
		cout << "No solution" << nl;
		return ;
	}

	vector<string> res;

	int i = n, j = k;

	while (j > 0) {
		for (int len = a; len <= b; len++) {
			if (i >= len && dp[i - len][j - 1]) {

				// last segment is [i-len, i-1]
				res.push_back(str.substr(i - len, len));

				i -= len;
				j--;
				break;
			}
		}
	}

	reverse(res.begin(), res.end());
	for (auto s : res)cout << s << nl;


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