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
int N = 1e7 + 1;
vector<bool> isprime(N + 1, 1);
vector<int> smallestprime(N + 1);

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
void calc() // O(Nlog(logN)) N->10^7
{
    for (int i = 2; i < N; i++) smallestprime[i] = i;
    for (int i = 2; i < N; i++)
    {
        if (smallestprime[i] == i)
        {
            for (ll j = i * 1ll * i; j < N; j += i)
            {
                if (j == smallestprime[j]) smallestprime[j] = i;
            }
        }
    }
}

void solve() {

    calc();
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    map<int, int> numerator, denominator, minpower;

    for (int i = 0; i < n; i++) //n*log(a[i])
    {
        int x = a[i];
        while (x > 1) // log(a[i])
        {
            int p = smallestprime[x], cnt = 0;

            while (x % p == 0)
            {
                cnt++;
                x /= p;
            }
            numerator[p] += cnt;
        }
    }
    for (int i = 0; i < m; i++) //m*log(b[i])
    {
        int x = b[i];
        while (x > 1)
        {
            int p = smallestprime[x], cnt = 0;

            while (x % p == 0)
            {
                cnt++;
                x /= p;
            }
            denominator[p] += cnt;
        }
    }
    for (auto it : numerator) //O(100)
    {
        minpower[it.first] = min(it.second, denominator[it.first]);
    }
    numerator = denominator = minpower;
    for (int i = 0; i < n; i++) //n*log(a[i])
    {
        int x = a[i];
        while (x > 1)
        {
            int p = smallestprime[x], cnt = 0;

            while (x % p == 0)
            {
                cnt++;
                x /= p;
            }
            cnt = min(cnt, numerator[p]);
            numerator[p] -= cnt;
            a[i] /= binpow(p, cnt); //log(cnt)
        }
    }
    for (int i = 0; i < m; i++) //m*log(b[i])
    {
        int x = b[i];
        while (x > 1)
        {
            int p = smallestprime[x], cnt = 0;

            while (x % p == 0)
            {
                cnt++;
                x /= p;
            }
            cnt = min(cnt, denominator[p]);
            denominator[p] -= cnt;
            b[i] /= binpow(p, cnt); //log(cnt)
        }
    }
    cout << a.size() << " " << b.size() << endl;
    for (auto it : a) cout << it << " ";
    cout << endl;
    for (auto it : b) cout << it << " ";
    cout << endl;
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