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
    while(l<r)
    {
        int k=l+rand()%(r-l+1);
        swap(v[l], v[k]);
        int m=partition(v, l, r);
        if ((m-l)<(r-m))
        {
            qSort(v, l, m-1);
            l=m+1;
        }
        else
        {
            qSort(v, m+1, r);
            r=m-1;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, i;
	cin>>n;
	vector<int> v(n);
	for (i=0;i<n;i++) cin>>v[i];
	qSort(v, 0, n-1);
	for (i=0;i<n;i++) cout<<v[i]<<" ";
	return 0;
}
