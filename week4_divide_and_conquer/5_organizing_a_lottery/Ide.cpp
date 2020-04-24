#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x;
    int y;
};

bool cmp(Point p1, Point p2)
{
    return p1.x<p2.x;
}

bool cmpl(Point p1, Point p2)
{
    return p1.y<p2.x;
}

bool cmpu(Point p1, Point p2)
{
    return p1.x<p2.y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, i, j;
	cin>>n>>m;
	vector<Point> v1(n);
	vector<Point> v2(m);
	vector<int> ans(m, 0);
	for (i=0;i<n;i++) cin>>v1[i].x>>v1[i].y;
	for (i=0;i<m;i++) cin>>v2[i].x, v2[i].y=i;
	sort(v1.begin(), v1.end(), cmp);
	sort(v2.begin(), v2.end(), cmp);
	int l1, l2, l=0, u=n-1, u1, u2;
	for (i=0;i<m;i++)
	{
	    
	    u1=upper_bound(v1.begin()+l, v1.end(), v2[i], cmp)-v1.begin()+1;
	    if (u1>n-1) u1=n-1;
	    u2=upper_bound(v1.begin()+l, v1.end(), v2[i], cmpu)-v1.begin()+1;
	    if (u2>n-1) u2=n-1;
	    u=max(u1, u2);
	    
	    l1=lower_bound(v1.begin()+l, v1.end(), v2[i], cmp)-v1.begin()-1;
	    if (l1<0) l1=0;
	    l2=lower_bound(v1.begin()+l, v1.end(), v2[i], cmpl)-v1.begin()-1;
	    if (l2<0) l2=0;
	    l=min(l1, l2);
	    
	    for (j=l;j<=u;j++)
	    {
	        if (v1[j].x<=v2[i].x && v2[i].x<=v1[j].y) ans[v2[i].y]++;
	    }
	}
	for (i=0;i<m;i++) cout<<ans[i]<<" "; 
	return 0;
}
