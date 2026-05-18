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

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
/*Problem Link -> */
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pi pair<int, int>
#define pll pair<ll, ll>
#define Yes cout << "YES" << '\n'
#define No cout << "NO" << '\n'
#define nl '\n'
#define loop(i, s, n) for (ll i = s; i <= n; i++)
#define sz(x) ((int)(x).size())
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using pbdms = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*Debug*/
#ifdef Rakib_18
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void init_code() {
#ifdef Rakib_18
	freopen("Error.txt", "w", stderr);
#endif
}
// const ll mod = 1e9 + 7;
// const int mod = 998244353;
// const long long mod = 1375927501846395853LL;
ll expo(ll a, ll b, ll mod) { ll res = 1; while (b > 0) { if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1; } return res; }
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
ll inv(ll i) { if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod; }
bool isPrime(ll n) { if (n <= 1)return false; if (n <= 3)return true; if (n % 2 == 0 || n % 3 == 0)return false; for (ll i = 5; i * i <= n; i += 6) { if (n % i == 0 || n % (i + 2) == 0)return false; } return true; }
ll lcm(ll a, ll b) { return (a / __gcd(a, b)) * b; }
ll mod_add(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
ll mod_sub(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
ll mod_div(ll a, ll b, ll m) { a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m; }  //only for prime m
int nXOR(int n) { if (n % 4 == 0)return n; if (n % 4 == 1)return 1; if (n % 4 == 2)return n + 1; return 0; }
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void solve()
{

}
int main()
{
	init_code();
	fastio();
	int t = 1;
	// cin >> t;
	auto start1 = high_resolution_clock::now();
	while (t--)
	{
		solve();
	}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef Rakib_18
	cerr << "Time: " << duration . count() / 1000 << " ms" << endl;
#endif
	return 0;
}