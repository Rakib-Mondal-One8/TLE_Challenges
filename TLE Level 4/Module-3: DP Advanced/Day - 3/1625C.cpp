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
	int n, l, k;
	cin >> n >> l >> k;

	vector<int>d(n + 1);
	vector<int>speed(n + 1);

	for (int i = 0; i < n; i++)cin >> d[i];
	for (int i = 0; i < n; i++)cin >> speed[i];
	d[n] = l;

	const int INF = 1e18;

	/*
	//Recursive Solution

	vector<vector<int>>dp(n + 2, vector<int>(k + 1, -1));

	auto go = [&](int index, int canRemove, auto && f) {
		if (index == n)return 0LL;

		if (dp[index][canRemove] != -1)return dp[index][canRemove];

		int answer = INF;
		for (int i = index + 1; i < speed.size() && (i - (index + 1)) <= canRemove; i++) {
			answer = min(answer, f(i, canRemove - (i - (index + 1)) , f) + (d[i] - d[index]) * speed[index]);
		}

		return dp[index][canRemove] = answer;
	};

	cout << go(0LL, k, go) << nl;
	*/



	//dp[i][j] = minimum time to reach l such that the no of speed post can remove is j

	vector<vector<int>>dp(n + 1, vector<int>(k + 1, INF));
	for (int i = 0; i <= k; i++)dp[n][i] = 0;

	for (int i = n - 1; i >= 0; i--) {
		for (int canRemove = 0; canRemove <= k; canRemove++) {

			int answer = INF;
			for (int next = i + 1; (next - (i + 1)) <= canRemove && next <= n; next++) {
				answer = min(answer, dp[next][canRemove - (next - (i + 1))] + (d[next] - d[i]) * speed[i]);
			}

			dp[i][canRemove] = answer;
		}
	}

	cout << dp[0][k] << nl;

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