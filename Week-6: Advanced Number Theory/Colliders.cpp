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
int maxN = 1e5 + 7;
vector<pair<int, int>> primeFactorization(int x, vector<int>& spf) {
    vector<pair<int, int>>ans;
    while (x != 1) {
        int prime = spf[x];
        int cnt = 0;
        while (x % prime == 0) {
            cnt++;
            x /= prime;
        }
        ans.push_back({ prime,cnt });
    }
    return ans;
}
vector<int>ShortestPrimeFactor(int maxN) {
    vector<bool>Prime(maxN, true);
    vector<int>spf(maxN, 1e9);

    for (ll i = 2; i < maxN;i++) {
        if (Prime[i]) {
            spf[i] = i;
            for (ll j = i * i;j < maxN;j += i) {
                Prime[j] = false;
                spf[j] = min(spf[j], (int)i);
            }
        }
    }
    return spf;
}
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int>spf = ShortestPrimeFactor(maxN);
    set<int>s;
    set<int>collider;
    vector<int>occupied(1e5 + 7, 0);

    for (int i = 0;i < m;i++) {
        char sign;
        int x;
        cin >> sign >> x;
        debug(sign, x);
        if (sign == '+') {
            if (collider.find(x) != collider.end()) {
                cout << "Already on" << nl;
                continue;
            }
            vector<pi>factors = primeFactorization(x, spf);
            bool ok = false;
            int belongs;
            for (auto e : factors) {
                if (occupied[e.first] != 0) {
                    ok = true;
                    belongs = occupied[e.first];
                    break;
                }
            }
            if (ok) {
                cout << "Conflict with " << belongs << nl;
                continue;
            }
            for (auto e : factors)occupied[e.first] = x;
            collider.insert(x);
            cout << "Success" << nl;
        }
        else {
            if (collider.find(x) != collider.end()) {
                vector<pi>factors = primeFactorization(x, spf);
                for (auto e : factors)occupied[e.first] = 0;
                collider.erase(x);
                cout << "Success" << nl;
            }
            else {
                cout << "Already off" << nl;
            }
        }
    }

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