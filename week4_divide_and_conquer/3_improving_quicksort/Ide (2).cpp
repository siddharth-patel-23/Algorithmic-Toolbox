#include <bits/stdc++.h>
using namespace std;

vector<int> partition(vector<int> &v, int l, int r)
{
    vector<int> rt(2);
    int sz=r-l+1;
    vector<int> tmp(sz);
    int cmp=v[l];
    int tr1=l, tr2=0;
    while(tr1<=r && tr2<sz)
    {
        if (v[tr1]<cmp) tmp[tr2]=v[tr1], tr2++;
        tr1++;
    }
    rt[0]=tr2+l;
    tr1=l;
    while(tr1<=r && tr2<sz)
    {
        if (v[tr1]==cmp) tmp[tr2]=v[tr1], tr2++;
        tr1++;
    }
    rt[1]=tr2+l-1;
    tr1=l;
    while(tr1<=r && tr2<sz)
    {
        if (v[tr1]>cmp) tmp[tr2]=v[tr1], tr2++;
        tr1++;
    }
    for (tr1=0;tr1<sz;tr1++) v[tr1+l]=tmp[tr1];
    
    return rt;
}

void qSort(vector<int> &v, int l, int r)
{
    if (l>=r) return;
    vector<int> m;
    int k=l+rand()%(r-l+1);
    swap(v[l], v[k]);
    m=partition(v, l, r);
    qSort(v, l, m[0]-1);
    qSort(v, m[1]+1, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, i, ip, ans=0;
	cin>>n;
	vector<int> v(n);
	for (i=0;i<n;i++) cin>>v[i];
	qSort(v, 0, n-1);
	for (i=0;i<n;i++) cout<<v[i]<<" ";
	return 0;
}
