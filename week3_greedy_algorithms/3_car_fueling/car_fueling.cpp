#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int d, m, n, i;
	cin>>d;
	cin>>m;
	cin>>n;
	vector<int> v(n);
	for (i=0;i<n;i++) cin>>v[i];
	v.push_back(d);
	int ans=0;
	int m1=m;
	bool f=false;
	for (i=0;i<=n;i++)
	{
	    if (v[i]>m)
	    {
	        if (i==0)
	        {
	            ans=-1;
	            break;
	        }
	        else
	        {
	            if (v[i-1]>m) 
	            {
	                ans=-1;
	                break;
	            }
	            ans++;
	            m=v[i-1]+m1;
	            
	        }
	    }
	}
	if (v[i-1]>m)
	ans=-1;
	cout<<ans;
	
	
	return 0;
}
