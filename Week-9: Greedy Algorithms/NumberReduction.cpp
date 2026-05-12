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
	string s;
	cin >> s;
	int k;
	cin >> k;

	multiset<pair<int, int>>st;
	vector<int>ans;
	int n = s.size();

	int j = 0;
	int pos = n - k;
	for (int i = 0; i < n - k; i++) {
		while (j < n && n - j >= pos) {
			int x = s[j] - '0';
			st.insert({x, j});
			j++;
		}
		debug(st);
		pos -= 1;
		auto it = st.begin();
		auto value = *it;
		while (i == 0 && value.first == 0) {
			++it;
			value = *it;
		}
		ans.push_back(value.first);

		auto remove = *st.begin();
		while (!st.empty() && remove.second <= value.second) {
			st.erase(st.begin());
			remove = *st.begin();
		}
	}
	for (auto x : ans)cout << x;
	cout << nl;
}
int32_t main()
{
	init_code();
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--)
	{
		RakibOne8();
	}
	return 0;
}