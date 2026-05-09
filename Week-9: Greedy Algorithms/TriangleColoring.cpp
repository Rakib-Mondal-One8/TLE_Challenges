#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#ifdef Rakib_18
#include "debug.hpp"
#else
#define debug(...)
#endif
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
const int mod = 998244353LL;
struct Mint {
	int val;

	Mint(long long v = 0) {
		if (v < 0) v = v %  + mod;
		if (v >= mod) v %= mod;
		val = v;
	}

	static int mod_inv(int a, int m = mod) {
		int g = m, r = a, x = 0, y = 1;
		while (r != 0) {
			int q = g / r;
			g %= r; swap(g, r);
			x -= q * y; swap(x, y);
		}
		return x < 0 ? x + m : x;
	}
	explicit operator int() const { return val; }
	Mint& operator+=(const Mint &other) { val += other.val; if (val >= mod) val -= mod; return *this; }
	Mint& operator-=(const Mint &other) { val -= other.val; if (val < 0) val += mod; return *this; }
	static unsigned fast_mod(uint64_t x, unsigned m = mod) {
#if !defined(_WIN32) || defined(_WIN64)
		return x % m;
#endif
		unsigned x_high = x >> 32, x_low = (unsigned) x;
		unsigned quot, rem;
		asm("divl %4\n"
		    : "=a" (quot), "=d" (rem)
		    : "d" (x_high), "a" (x_low), "r" (m));
		return rem;
	}
	Mint& operator*=(const Mint &other) { val = fast_mod((uint64_t) val * other.val); return *this; }
	Mint& operator/=(const Mint &other) { return *this *= other.inv(); }
	friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
	friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
	friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
	friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
	Mint& operator++() { val = val == mod - 1 ? 0 : val + 1; return *this; }
	Mint& operator--() { val = val == 0 ? mod - 1 : val - 1; return *this; }
	// friend Mint operator<=(const Mint &a, const Mint &b) { return (int)a <= (int)b; }
	Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
	Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
	Mint operator-() const { return val == 0 ? 0 : mod - val; }
	bool operator==(const Mint &other) const { return val == other.val; }
	bool operator!=(const Mint &other) const { return val != other.val; }
	Mint inv() const { return mod_inv(val); }
	Mint power(long long p) const {
		assert(p >= 0);
		Mint a = *this, result = 1;
		while (p > 0) {
			if (p & 1) result *= a;
			a *= a, p >>= 1;
		}
		return result;
	}
	friend ostream& operator << (ostream &stream, const Mint &m) { return stream << m.val; }
	friend istream& operator >> (istream &stream, Mint &m) { return stream >> m.val;   }
};
namespace comb {
int n(0);
vector<Mint> _fac{1}, _invfac{1}, _inv{0};
void init(int m) {
	m = min (m, mod - 1);
	if (m <= n) return;
	_fac.resize(m + 1); _invfac.resize(m + 1); _inv.resize(m + 1);
	for (int i = n + 1; i <= m; i++) _fac[i] = _fac[i - 1] * i;
	_invfac[m] = _fac[m].inv();
	for (int i = m; i > n; i--) _invfac[i - 1] = _invfac[i] * i, _inv[i] = _invfac[i] * _fac[i - 1];
	n = m;
}
Mint fac(int m) { if (m > n) init(2 * m); return _fac[m]; }
Mint invfac(int m) { if (m > n) init(2 * m); return _invfac[m]; }
Mint inv(int m) { if (m > n) init(2 * m); return _inv[m]; }
Mint ncr(int n, int r) { if (n < r || r < 0) return 0; return fac(n) * invfac(r) * invfac(n - r); }
}
using comb::fac, comb::invfac, comb::inv, comb::ncr;
void RakibOne8()
{
	int n;
	cin >> n;

	vector<int>a(n);
	for (auto &x : a)cin >> x;

	int ans = 1;
	for (int i = 0; i < n; i += 3) {
		int maxWeight = max({a[i] + a[i + 1], a[i] + a[i + 2], a[i + 2] + a[i + 1]});
		int cnt = 0;
		if (a[i] + a[i + 1] == maxWeight)cnt++;
		if (a[i] + a[i + 2] == maxWeight)cnt++;
		if (a[i + 1] + a[i + 2] == maxWeight)cnt++;

		ans = (ans * cnt) % mod;
	}
	cout << ans*ncr(n / 3, n / 6) << nl;
}
int32_t main()
{
	// init_code();
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	// cin >> t;
	while (t--)
	{
		RakibOne8();
	}
	return 0;
}