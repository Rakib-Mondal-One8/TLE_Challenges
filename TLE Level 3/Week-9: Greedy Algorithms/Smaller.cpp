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
bool go(vector<int>&track1, vector<int>&track2) {
	int s1Min = INT_MAX, s1Max = INT_MIN, s2Max = INT_MIN;
	int len1 = 0, len2 = 0;
	for (int i = 0; i < 26; i++) {

		if (track1[i] > 0) {
			s1Min = min(s1Min, i);
			s1Max = max(s1Max, i);
		}
		if (track2[i] > 0)s2Max = max(s2Max, i);
		len1 += track1[i];
		len2 += track2[i];
	}

	if (s1Min < s2Max)return true;
	else if (s1Min > s2Max)return false;
	else if (s1Max > s2Max)return false;
	else if (len1 < len2)return true;
	else return false;
}
void RakibOne8()
{
	int q;
	cin >> q;

	vector<int>track1(26), track2(26);
	track1[0]++;
	track2[0]++;
	for (int i = 1; i <= q; i++) {
		int op, k;
		string s;
		cin >> op >> k >> s;
		for (auto c : s) {
			if (op == 1)track1[c - 'a'] += k;
			else track2[c - 'a'] += k;
		}
		if (go(track1, track2))cout << "YES" << nl;
		else cout << "NO" << nl;
	}

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