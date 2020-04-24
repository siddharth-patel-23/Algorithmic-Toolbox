#include <bits/stdc++.h>
using namespace std;

struct cd
{
    int a;
    int b;
};

bool cmp(cd c1, cd c2)
{
    if (c1.a==c2.a) return c1.b<c2.b;
    return c1.a<c2.a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, i;
	cin>>n;
	vector<cd> v(n);
	vector<int> ans;
	for (i=0;i<n;i++)
	{
	    cin>>v[i].a>>v[i].b;
	}
	sort(v.begin(), v.end(), cmp);
	
	int m=1;
	int cp=v[0].b;
	for (i=1;i<n;i++)
	{
	    if (v[i].a<=cp)
	    {
	        cp=min(v[i].b, cp);
	    }
	    else
	    {
	        ans.push_back(cp);
	        cp=v[i].b;
	        m++;
	    }
	}
	ans.push_back(cp);
	cout<<m<<"\n";
	for (i=0;i<ans.size();i++)
	{
	    cout<<ans[i]<<" ";
	}
	
	return 0;
}
