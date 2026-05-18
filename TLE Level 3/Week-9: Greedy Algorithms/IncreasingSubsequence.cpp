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

	vector<int>a(n);
	for (auto &x : a)cin >> x;

	debug(a);

	int left = 0, right = n - 1, past = 0;
	string answer = "";

	while (left <= right) {
		if (a[left] < a[right]) {
			if (a[left] > past)past = a[left], left++, answer += 'L';
			else if (a[right] > past)past = a[right], right--, answer += 'R';
			else break;
		}
		else if (a[right] < a[left]) {
			if (a[right] > past)past = a[right], right--, answer += 'R';
			else if (a[left] > past)past = a[left], left++, answer += 'L';
			else break;
		}
		else {
			if (a[left] <= past)break;
			int newLeft = left + 1, newRight = right - 1;
			while (newLeft <= right && a[newLeft] > a[newLeft - 1])newLeft++;
			while (newRight >= left && a[newRight] > a[newRight + 1])newRight--;

			if ((newLeft - left) >= (right - newRight))answer += string((newLeft - left), 'L');
			else answer += string((right - newRight), 'R');
			break;
		}
	}
	cout << answer.size() << nl;
	cout << answer << nl;
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