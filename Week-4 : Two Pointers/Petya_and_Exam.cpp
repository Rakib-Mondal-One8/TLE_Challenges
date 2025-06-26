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
    ll n, t, a, b;
    cin >> n >> t >> a >> b;
    vector<pair<ll, ll>> v;
    vector<int> hard(n);
    int cntA = 0, cntB = 0;
    for (int i = 0; i < n; i++) {
        cin >> hard[i];
        if (hard[i]) {
            cntB++;
        }
        else {
            cntA++;
        }
    }
    for (int i = 0; i < n; i++) {
        ll time;
        cin >> time;
        v.push_back({ time, hard[i] });
    }
    v.push_back({ t + 1, 0 });
    sort(v.begin(), v.end());
    ll cnt1 = 0, cnt2 = 0;
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ll need = cnt1 * a + cnt2 * b;
        ll has = v[i].first - 1 - need;
        if (has >= 0) {
            ll canA = min((cntA - cnt1), has / a);
            has -= canA * a;
            ll canB = min((cntB - cnt2), has / b);
            ans = max(ans, cnt1 + cnt2 + canA + canB);
        }
        int l = i;
        while (l < v.size() && v[l].first == v[i].first) {
            if (v[l].second) {
                cnt2++;
            }
            else {
                cnt1++;
            }
            l++;
        }
        i = l - 1;
    }
    cout << ans << "\n";
}
int32_t main()
{
    fastio();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}