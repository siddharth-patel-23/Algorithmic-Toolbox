#include <bits/stdc++.h>
using namespace std;

struct kn
{
    double v;
    double w;
    double dv;
};

bool cmp(kn k1, kn k2)
{
    return k1.dv>k2.dv;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, w, i;
	cin>>n>>w;
	vector<kn> v(n);
	for (i=0;i<n;i++)
	{
	    cin>>v[i].v>>v[i].w;
	    v[i].dv=v[i].v/v[i].w;
	}
	sort(v.begin(), v.end(), cmp);
	i=0;
	double ans=0;
	while (w>0 and i<n)
	{
	    if (v[i].w<=w)
	    {
	        w-=v[i].w;
	        ans+=v[i].v;
	        i++;
	    }
	    else
	    {
	        ans+=w*v[i].dv;
	        w=0;
	    }
	}
	cout<<fixed<<setprecision(4)<<ans;
	return 0;
}
