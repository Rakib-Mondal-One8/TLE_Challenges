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
struct Hashing {
	string s;
	int n;
	int primes;
	vector<int> hashPrimes = { 1000000009 };
	const int base = 31;
	vector<vector<int>> hashValues;
	vector<vector<int>> powersOfBase;
	vector<vector<int>> inversePowersOfBase;
	Hashing(string a) {
		primes = sz(hashPrimes);
		hashValues.resize(primes);
		powersOfBase.resize(primes);
		inversePowersOfBase.resize(primes);
		s = a;
		n = s.length();
		for (int i = 0; i < sz(hashPrimes); i++) {
			powersOfBase[i].resize(n + 1);
			inversePowersOfBase[i].resize(n + 1);
			powersOfBase[i][0] = 1;
			for (int j = 1; j <= n; j++) {
				powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
			}
			inversePowersOfBase[i][n] = mminvprime(powersOfBase[i][n], hashPrimes[i]);
			for (int j = n - 1; j >= 0; j--) {
				inversePowersOfBase[i][j] = mod_mul(inversePowersOfBase[i][j + 1], base, hashPrimes[i]);
			}
		}
		for (int i = 0; i < sz(hashPrimes); i++) {
			hashValues[i].resize(n);
			for (int j = 0; j < n; j++) {
				hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
				hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
			}
		}
	}
	vector<int> substringHash(int l, int r) {
		vector<int> hash(primes);
		for (int i = 0; i < primes; i++) {
			int val1 = hashValues[i][r];
			int val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
			hash[i] = mod_mul(mod_sub(val1, val2, hashPrimes[i]), inversePowersOfBase[i][l], hashPrimes[i]);
		}
		return hash;
	}
};
void RakibOne8()
{
	string s;
	cin >> s;

	Hashing hs = Hashing(s);
	int n = sz(s);

	for (int windowSize = 1; windowSize <= n; windowSize++) {

		bool ok = true;
		int len = windowSize;
		for (int curIndex = 0; curIndex < n; curIndex += len) {
			len = min(len, n - curIndex);

			ok &= hs.substringHash(0, len - 1) == hs.substringHash(curIndex, curIndex + len - 1);
		}
		if (ok)
			cout << windowSize << " ";
	}

}
int32_t main()
{
	// init_code();
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

