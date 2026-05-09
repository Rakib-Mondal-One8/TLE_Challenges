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

	vector<int>pos;
	int op = s.size() / 2, cl = s.size() / 2;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')--op;
		if (s[i] == ')')--cl;
		if (s[i] == '?')pos.push_back(i);
	}

	for (int i = 0; i < pos.size(); i++) {
		if (i < op) {
			s[pos[i]] = '(';
		}
		else s[pos[i]] = ')';
	}

	bool ok = true;
	auto checkRBS = [&](string s) {
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(')cnt++;
			else cnt--;

			if (cnt < 0)return false;
		}
		return cnt == 0;
	};
	if (op > 0 && cl > 0) {
		swap(s[pos[op - 1]], s[pos[op]]);
		if (checkRBS(s))ok = false;
	}

	cout << ((ok) ? "YES" : "NO") << nl;
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