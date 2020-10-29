#include<iostream>
#define int long long
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif

	int n, m, x, y;
	cin >> n >> m >> x >> y;
	int s = 0;
	int e = n;
	int ans = -1;
	while(s<=e)
	{
		int mid = s + ((e-s)/2);
		if (mid*x <= m + ((n - mid)*y))
		{
			ans = mid;
			s = mid + 1;
		}
		else 
			e = mid - 1;
	}
    cout << ans;
	return 0;
}