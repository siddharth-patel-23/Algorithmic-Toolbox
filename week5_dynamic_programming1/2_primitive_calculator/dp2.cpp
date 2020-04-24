#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, i;
	cin>>n;
	vector<int> v(n+1);
	if (n==1) cout<<0<<"\n"<<1;
	else if (n==2) cout<<1<<"\n"<<"1 2";
	else if (n==3) cout<<1<<"\n"<<"1 3";
	else
	{
	    vector<int> v(n+1);
	    vector<int> ans;
	    v[0]=0;
	    v[1]=0;
	    v[2]=1;
	    v[3]=1;
	    for (i=4;i<=n;i++)
	    {
	        int c2=INT_MAX-1, c3=INT_MAX-1;
	        if (i%2==0) c2=v[i/2];
	        if (i%3==0) c3=v[i/3];
	        v[i]=min(v[i-1]+1, min(c2+1, c3+1));
	    }
	    cout<<v[n]<<"\n";
	    i=n;
	    while(i!=1)
	    {
	        if (v[i]==v[i-1]+1) ans.push_back(i-1), i--;
	        else if (i%2==0 and v[i]==v[i/2]+1) ans.push_back(i/2), i/=2;
	        else if (i%3==0 and v[i]==v[i/3]+1) ans.push_back(i/3), i/=3;
	    }
	    for (i=ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";
	    cout<<n;
	}
	return 0;
}
