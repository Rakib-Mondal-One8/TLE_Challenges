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
	int n;
	cin >> n;

	map<int, vector<int>>mp;
	vector<int>a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mp[a[i]].push_back(i);
	}

	set<pair<int, int>>st;
	for (auto x : mp) {
		vector<int>idx = x.second;
		for (int i = 1; i < idx.size(); i++) {
			st.insert({idx[i - 1], idx[i]});
		}
	}

	vector<pair<int, int>>ans(1);
	ans[0] = {0, 0};
	for (auto pairs : st) {
		auto prev = ans.back();
		if (pairs.first >= prev.first && pairs.second <= prev.second) {
			ans.pop_back();
			ans.push_back(pairs);
		}
		if (pairs.first > prev.second) {
			ans.push_back(pairs);
		}
	}
	debug(ans);
	int m = ans.size();
	if (m == 1) {
		cout << -1 << nl;
		return;
	}
	ans[m - 1].second = n;

	cout << m - 1 << nl;
	for (int i = 1; i < m; i++) {
		cout << ans[i - 1].second + 1 << " " << ans[i].second << nl;
	}

}
int32_t main()
{
	init_code();
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	// cin >> t;
	while (t--)
	{
		RakibOne8();
	}
	return 0;
}