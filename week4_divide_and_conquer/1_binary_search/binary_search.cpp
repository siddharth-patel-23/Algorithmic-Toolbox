#include <bits/stdc++.h>
using namespace std;

int bs(int key, int l ,int r, vector<int> &v)
{
    if (l>r)
        return -1;
    int m=(l+r)/2;
    if (v[m]==key) return m;
    if (v[m]>key) 
        return bs(key, l, m-1, v);
    return bs(key, m+1, r, v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, i, ip;
	cin>>n;
	vector<int> v(n);
	for (i=0;i<n;i++) cin>>v[i];
	cin>>m;
	for (i=0;i<m;i++)
	{
	    cin>>ip;
	    cout<<bs(ip, 0, n-1, v)<<" ";
	}
	return 0;
}
