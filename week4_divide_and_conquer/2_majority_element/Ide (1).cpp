#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int l, int m, int r)
{
    int n=v.size();
    vector<int> v1, v2;
    int i=0, j=0, k=l;
    for (i=l;i<=r;i++)
    {
        if (i<=m) v1.push_back(v[i]);
        else v2.push_back(v[i]);
    }
    
    int n1=v1.size();
    int n2=v2.size();
    i=0, j=0;
    while(i<n1 && j<n2)
    {
        if (v1[i]<v2[j])
        {
            v[k]=v1[i];
            i++;
            k++;
        }
        else
        {
            v[k]=v2[j];
            j++;
            k++;
        }
    }
    while(i<n1) v[k]=v1[i], i++, k++;
    while(j<n2) v[k]=v2[j], j++, k++;
    
}

void mSort(vector<int> &v, int l, int r)
{
    if (l>=r) return;
    int m=(l+r)/2;
    mSort(v, l, m);
    mSort(v, m+1, r);
    merge(v, l, m, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, i, ip, ans=0;
	cin>>n;
	vector<int> v(n);
	for (i=0;i<n;i++) cin>>v[i];
	mSort(v, 0, n-1);
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
