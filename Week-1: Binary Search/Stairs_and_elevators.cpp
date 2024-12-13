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
void solve()
{
	ll n, m, cl, ce, v;
	cin >> n >> m >> cl >> ce >> v;

	vector<ll>stair(cl);
	for (auto &i : stair)cin >> i;
	vector<ll>ele(ce);
	for (auto &i : ele)cin >> i;

	ll Q;
	cin >> Q;

	auto left = [&](ll x, vector<ll>&a) {
		ll l = 0, r = a.size() - 1;
		ll ans = a[0];
		while (l <= r) {
			ll mid = l + (r - l) / 2;
			if (a[mid] <= x) {
				ans = a[mid];
				l = mid + 1;
			}
			else r = mid - 1;
		}
		return ans;
	};
	auto right = [&](ll x, vector<ll>&a) {
		ll l = 0, r = a.size() - 1;
		ll ans = a[r];
		while (l <= r) {
			ll mid = l + (r - l) / 2;
			if (a[mid] >= x) {
				ans = a[mid];
				r = mid - 1;
			}
			else l = mid + 1;
		}
		return ans;
	};

	for (int i = 0; i < Q; i++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ll time = LLONG_MAX;
		if (x1 == x2)time = abs(y1 - y2);
		if (!stair.empty()) {
			ll near1 = left(y1, stair);
			ll near2 = right(y1, stair);


			ll curTime = abs(y1 - near1);
			curTime += abs(x1 - x2);
			curTime += abs(y2 - near1);

			time = min(time, curTime);



			curTime = abs(y1 - near2);
			curTime += abs(x1 - x2);
			curTime += abs(y2 - near2);

			time = min(time, curTime);

		}
		if (!ele.empty()) {
			ll near1 = left(y1, ele);
			ll near2 = right(y1, ele);


			ll curTime = abs(y1 - near1);
			ll len = abs(x1 - x2);
			curTime += len / v + (len % v != 0 ? 1 : 0);
			curTime += abs(y2 - near1);

			time = min(time, curTime);



			curTime = abs(y1 - near2);
			len = abs(x1 - x2);
			curTime += len / v + (len % v != 0 ? 1 : 0);
			curTime += abs(y2 - near2);

			time = min(time, curTime);


		}
		cout << time << nl;
	}

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