#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, i, sum=0, j, k, g, ans;
	cin>>n;
	vector<int> v(n+1);
	v[0]=0;
	for (i=1;i<=n;i++) cin>>v[i], sum+=v[i];
	if (sum%3!=0 || n<3)
	    cout<<0;
	else
	{
	    ans=1;
	    vector<int> tmp;
	    sum/=3;
	    for (g=0;g<3;g++)
	    {
	        vector<bool> vis(n+1, false);
    	    vector<vector<int>> val(n+1, vector<int> (sum+1));
    	    for (i=0;i<=n;i++) val[i][0]=0;
    	    for (j=0;j<=sum;j++) val[0][j]=0;
    	    for (i=1;i<=n;i++)
    	    {
    	        if (vis[i]) continue;
    	        for (j=1;j<=sum;j++)
    	        {
    	            val[i][j]=val[i-1][j];
    	            if (v[i]<=j)
    	            val[i][j]=max(val[i][j], val[i-1][j-v[i]]+v[i]);
    	        }
    	    }
    	    if (val[n][sum]!=sum)
    	    {
    	        ans=0;
    	        break;
    	    }
    	    else
    	    {
    	        i=n; j=sum, k=n;
    	        while(i>0 && k>0)
    	        {
    	            if (val[i][j]==val[i-1][j]) i--;
    	            else
    	            {
    	                if (val[i][j]==val[i-1][j-v[k]]+v[k]) vis[k]=true, i--, j-=v[k], k--;
    	                else k--;
    	            }
    	        }
    	    }
    	    tmp.push_back(0);
    	    for (i=1;i<=n;i++) 
    	    {
    	        if (!vis[i]) tmp.push_back(v[i]);
    	       // else cout<<v[i]<<" ";
    	    }
    	   // cout<<"\n";
    	    v.clear();
    	    v=tmp;
    	    n=tmp.size();
	    }
	    cout<<ans;
	}
	return 0;
}
