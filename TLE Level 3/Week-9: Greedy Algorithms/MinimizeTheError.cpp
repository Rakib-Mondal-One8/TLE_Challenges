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
void RakibOne8()
{
	int n, k1, k2;
	cin >> n >> k1 >> k2;

	vector<int>a(n), b(n);
	for (auto &x : a)cin >> x;
	for (auto &x : b)cin >> x;

	priority_queue<int>pq;

	for (int i = 0; i < n; i++) {
		pq.push(abs(a[i] - b[i]));
	}

	for (int i = 0; i < k1 + k2; i++) {
		int element = pq.top();
		pq.pop();
		pq.push(abs(element - 1));
	}

	int ans = 0;
	while (!pq.empty()) {
		ans += pq.top() * pq.top();
		pq.pop();
	}
	cout << ans << nl;
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
