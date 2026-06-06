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

void generateTransitions(int index, int mask1, int mask2, int n,
                         vector<vector<int>>& transitions) {
	// If index exceeds n, stop (invalid path).
	if (index > n) return;

	// If we've exactly reached n, record the transition.
	if (index == n) {
		transitions[mask1].push_back(mask2);
		return;
	}

	// Case 1: current block is "1" in mask1
	generateTransitions(index + 1, mask1 | (1 << index), mask2, n, transitions);

	// Case 2a: current block is "0" in mask1, and "1" in mask2
	generateTransitions(index + 1, mask1, mask2 | (1 << index), n, transitions);

	// Case 2b: skip 2 blocks (like placing a horizontal domino)
	generateTransitions(index + 2, mask1, mask2, n, transitions);
}

int go(int index, int mask, int n, int m, vector<vector<int>>& dp, const vector<vector<int>>& transitions) {
	if (index == m) {
		return (mask == 0 ? 1 : 0);
	}

	if (dp[index][mask] != -1) {
		return dp[index][mask];
	}

	long long answer = 0;

	for (auto newMask : transitions[mask]) {
		answer = (answer + go(index + 1, newMask, n, m, dp, transitions)) % mod;
	}

	return dp[index][mask] = answer;
}


void RakibOne8()
{
	int n, m;
	cin >> n >> m;

	int totalMasks = (1 << n);
	vector<vector<int>> transitions(totalMasks);

	generateTransitions(0, 0, 0, n, transitions);

	vector<vector<int>> dp(m + 1, vector<int>(totalMasks, -1));

	cout << go(0, 0, n, m, dp, transitions) << "\n";


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