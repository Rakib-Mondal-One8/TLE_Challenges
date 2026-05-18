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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	int answer = 0;
	for (int i = 0; i < (k + 1) / 2; i++) {
		vector<int>f(26);
		for (int j = 0; j < n; j += k) {
			f[s[j + i] - 'a']++;
			if (j + i != j + k - 1 - i)f[s[j + k - 1 - i] - 'a']++;
		}
		answer += (accumulate(f.begin(), f.end(), 0) - *max_element(f.begin(), f.end()));
	}
	cout << answer << nl;
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