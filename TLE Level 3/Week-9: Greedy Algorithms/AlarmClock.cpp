#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define nl '\n'
#ifdef Rakib_18
#include "debug.hpp"
#else
#define debug(...)
#endif

#undef int
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int >, rb_tree_tag, tree_order_statistics_node_update>pbds;

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void RakibOne8()
{
	int n, m, k;
	cin >> n >> m >> k;

	pbds st;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		st.insert(x);
	}

	int ans = 0;
	for (auto it = st.begin(); it != st.end();) {
		int x = *it;

		int time = x + m;

		int left = st.order_of_key(x);
		int right = st.order_of_key(time);

		int alarms = right - left;
		int remove = max(0LL, (alarms - k) + 1);

		debug(x, left, right, alarms, remove);
		while (!st.empty() && remove--) {
			int val = *st.find_by_order(right - 1);
			debug(val, x);
			if (val >= x) {
				st.erase(val);
				ans++;
				right--;
			}
		}
		it = st.upper_bound(x);
		debug(ans);
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