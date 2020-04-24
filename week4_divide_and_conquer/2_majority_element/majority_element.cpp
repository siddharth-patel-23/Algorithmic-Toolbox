#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, i, ip, ans=0;
	cin>>n;
	vector<int> v(n);
	for (i=0;i<n;i++) cin>>v[i];
	sort(v.begin(), v.end());
	i=0;
	while(i<n)
	{
	    int cmp=v[i];
	    int cnt=1;
	    i++;
	    while(i<n && cmp==v[i])
	    cnt++, i++;
	    if (cnt>n/2) ans++;
	}
	cout<<ans;
	return 0;
}
