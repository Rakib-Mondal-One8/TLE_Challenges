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
void _print(char t) {cerr << t;}
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
const ll mod = 1e9 + 7;
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
bool isPrime(ll n) {if (n <= 1)return false; if (n <= 3)return true; if (n % 2 == 0 || n % 3 == 0)return false; for (ll i = 5; i * i <= n; i += 6) {if (n % i == 0 || n % (i + 2) == 0)return false;} return true;}
ll lcm(ll a, ll b) {return (a / __gcd(a, b)) * b;}
int nXOR(int n) {if (n % 4 == 0)return n; if (n % 4 == 1)return 1; if (n % 4 == 2)return n + 1; return 0;}
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
long double maximumSum(vector<long double>&arr, int d, int n) {
	vector<long double>pref(n);
	pref[0] = arr[0];
	for (int i = 1; i < n; i++)pref[i] = pref[i - 1] + arr[i];
	long double ans = -1e18;
	long double minSoFar = 0;
	for (int right = d - 1; right < n; right++) {
		long double bestSubarrayendingHere = pref[right] - minSoFar;
		minSoFar = min(minSoFar, pref[right - d + 1]);
		ans = max(ans, bestSubarrayendingHere);
	}
	return ans;
}
bool f(double x, vector<long double>&a, int d, int n) {
	vector<long double>transformed(n);
	for (int i = 0; i < n; i++)transformed[i] = a[i] - x;

	return (maximumSum(transformed, d, n) >= 0);
}

pi anySubarrayWithPositiveSum(vector<long double>&arr, int d, int n) {
	vector<long double>pref(n);
	pref[0] = arr[0];
	for (int i = 1; i < n; i++)pref[i] = pref[i - 1] + arr[i];
	long double ans = -1e18;
	long double minSoFar = 0;
	int leftidx = -1;
	int right;
	for (right = d - 1; right < n; right++) {
		long double bestSubarrayendingHere = pref[right] - minSoFar;

		ans = max(ans, bestSubarrayendingHere);
		if (ans >= 0)return make_pair(leftidx + 1, right);

		if (minSoFar > pref[right - d + 1]) {
			minSoFar = pref[right - d + 1];
			leftidx = right - d + 1;
		}

	}
	return { -10, -10};
}

pi bestSubarray(double x, vector<long double>&a, int d, int n) {
	vector<long double>transformed(n);
	for (int i = 0; i < n; i++)transformed[i] = a[i] - x;

	return anySubarrayWithPositiveSum(transformed, d, n);
}

void solve()
{
	int n, d;
	cin >> n >> d;

	vector<long double>a(n);
	for (auto &i : a)cin >> i;

	long double low = 0, high = 100;

	for (int i = 0; i < 100; i++) {
		long double mid = low + (high - low) / 2;
		if (f(mid, a, d, n)) {
			low = mid;
		}
		else high = mid;
	}
	pi ans = bestSubarray(low, a, d, n);
	cout << ans.first + 1 << " " << ans.second + 1 << nl;
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