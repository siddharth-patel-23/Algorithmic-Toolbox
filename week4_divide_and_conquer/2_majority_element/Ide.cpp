#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int l, int r)
{
    int cmp=v[l];
    int j=l;
    for (int i=l+1;i<=r;i++)
    {
        if (v[i]<=cmp)
        {
            j++;
            swap(v[j], v[i]);
        }
    }
    swap(v[l], v[j]);
    return j;
}

void qSort(vector<int> &v, int l, int r)
{
    if (l>=r) return;
    
    int k=l+rand()%(r-l+1);
    swap(v[l], v[k]);
    int m=partition(v, l, r);
    qSort(v, l, m-1);
    qSort(v, m+1, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, i, ip, ans=0;
	cin>>n;
	vector<int> v(n);
	for (i=0;i<n;i++) cin>>v[i];
	qSort(v, 0, n-1);
	i=0;
	while(i<n)
	{
	    int cmp=v[i];
	    int cnt=1;
	    i++;
	    while(i<n && cmp==v[i])
	    cnt++, i++;
	    if (cnt>n/2)
	    {
	        ans++;
	        break;
	    }
	}
	cout<<ans;
	return 0;
}
