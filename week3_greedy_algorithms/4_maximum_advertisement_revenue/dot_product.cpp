#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long int n, i;
	cin>>n;
	vector<long long int> a(n), b(n);
	for (i=0;i<n;i++) cin>>a[i];
	for (i=0;i<n;i++) cin>>b[i];
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	long long int ans=0;
	for (i=0;i<n;i++)
	ans+=(a[i]*b[i]);
	
	cout<<ans;
	return 0;
}
