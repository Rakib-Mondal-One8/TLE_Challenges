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

int helper(int i, string &s, vector<vector<vector<int>>>&dp, int first, int second, int sl, int l) {
	int n = sz(s);
	if (i == n - 1) {
		int changes = 5e5;

		//putting L
		if ((sl != 0 || l != 0) && (first != 0 || second != 0) && (l != 0 || first != 0)) {
			changes = min(changes, s[i] != 'L' ? 1LL : 0LL);
		}
		//putting R
		if ((sl != 1 || l != 1) && (first != 1 || second != 1) && (l != 1 || first != 1)) {
			changes = min(changes, s[i] != 'R' ? 1LL : 0LL);
		}

		return changes;
	}

	if (dp[i][sl][l] != -1)return dp[i][sl][l];

	int changes = 5e5;

	//putting L
	if (l != 0 || sl != 0)changes = min(changes, (s[i] != 'L' ? 1 : 0) + helper(i + 1, s, dp, first, second, l, 0));
	//putting R
	if (l != 1 || sl != 1)changes = min(changes, (s[i] != 'R' ? 1 : 0) + helper(i + 1, s, dp, first, second, l, 1));

	return dp[i][sl][l] = changes;
}

void RakibOne8()
{
	int n;
	cin >> n;

	string s;
	cin >> s;


	int ans = 5e5;
	for (int first = 0; first <= 1; first++) {
		for (int second = 0; second <= 1; second++) {
			vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(2, -1)));

			int cnt1 = (first == 0) ? s[0] != 'L' : s[0] != 'R';
			int cnt2 = (second == 0) ? s[1] != 'L' : s[1] != 'R';

			ans = min(ans, helper(2, s, dp, first, second, first, second) + cnt1 + cnt2);
		}
	}
	cout << ans << nl;
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