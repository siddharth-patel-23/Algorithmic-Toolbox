#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, i, ans=0;
	cin>>n;
	if (n==1 || n==3 || n==4) ans=1;
	else if (n==2) ans=2;
	else
	{
	    vector<int> v(n+1);
	    v[0]=0;
	    v[1]=v[3]=v[4]=1;
	    v[2]=2;
	    for (i=5;i<=n;i++)
	    {
	        v[i]=min(v[i-1]+1, min(v[i-3]+1, v[i-4]+1));
	    }
	    ans=v[n];
	}
	cout<<ans;
	return 0;
}
