#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using pbdms = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#ifdef Rakib_18
#include "DEBUG_TEMPLATE.h"
#else
#define HERE
#define debug(args...)
#endif
const ll mod = 1e9 + 7;
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
    ll n;
    cin >> n;

    vector<pll>a(n);
    for (auto& i : a)cin >> i.first >> i.second;

    ll num = 1, sum = 1, Product = 1;
    for (auto i : a) {
        num = mod_mul(num, i.second + 1, mod);
    }
    for (auto i : a) {
        ll x = expo(i.first, i.second + 1, mod);
        x = mod_sub(x, 1, mod);
        x = mod_div(x, i.first - 1, mod);
        sum = mod_mul(sum, x, mod);
    }
    bool ok = false;
    int position;
    for (int i = 0;i < n;i++) {
        if (a[i].second % 2 == 1) {
            ok = true;
            position = i;
        }
    }

    if (ok) {
        ll outer = 1;
        for (int i = 0;i < n;i++) {
            if (i == position) {
                outer = (outer * (a[i].second + 1) / 2) % (mod - 1);
            }
            else outer = (outer * (a[i].second + 1)) % (mod - 1);
        }
        for (int i = 0;i < n;i++) {
            ll x = expo(a[i].first, a[i].second * outer, mod - 1);
            Product = mod_mul(Product, x, mod);
        }
    }
    else {
        ll outer = 1;
        for (int i = 0;i < n;i++) {
            outer = (outer * (a[i].second + 1)) % (mod - 1);
        }
        for (int i = 0;i < n;i++) {
            ll x = expo(a[i].first, a[i].second * outer, mod - 1);
            Product = mod_mul(Product, x, mod);
        }
    }
    cout << num << " " << sum << " " << Product << nl;
}
int32_t main()
{
    fastio();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}