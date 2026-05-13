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

	vector<int>a(n + 1);
	int md = 0;
	int x = -1e9;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		x = max(a[i], x);
		if (a[i] < x)md = max(md, x - a[i]);
	}
	cout << ceil(log2(md + 1)) << nl;

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