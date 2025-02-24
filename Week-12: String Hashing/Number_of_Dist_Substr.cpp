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
struct Hashing {
    string s;
    int n;
    int primes;
    vector<ll> hashPrimes = { 1000000009, 100000007 };
    const ll base = 31;
    vector<vector<ll>> hashValues;
    vector<vector<ll>> powersOfBase;
    vector<vector<ll>> inversePowersOfBase;
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
    vector<ll> substringHash(int l, int r) {
        vector<ll> hash(primes);
        for (int i = 0; i < primes; i++) {
            ll val1 = hashValues[i][r];
            ll val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            hash[i] = mod_mul(mod_sub(val1, val2, hashPrimes[i]), inversePowersOfBase[i][l], hashPrimes[i]);
        }
        return hash;
    }
};
void solve()
{
    string s;
    cin >> s;

    set<vector<ll>>unique_subs;

    int n = s.size();
    Hashing hs = Hashing(s);

    for (int i = 0;i < n;i++) {
        for (int j = i;j < n;j++) {
            vector<ll>hash = hs.substringHash(i, j);
            unique_subs.insert(hash);
        }
    }
    debug(unique_subs);
    cout << unique_subs.size() << nl;
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