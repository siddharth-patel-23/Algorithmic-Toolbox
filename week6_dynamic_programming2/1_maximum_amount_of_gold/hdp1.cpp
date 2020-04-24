#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int w, n, i, W;
	cin>>W>>n;
	vector<int> v(n+1);
	v[0]=0;
	for (i=1;i<=n;i++) cin>>v[i];
// 	int mat[W+1][n+1];
	vector<vector<int>> mat(W+1, vector<int> (n+1));
	for (w=0;w<=W;w++) mat[w][0]=0;
	for (i=0;i<=n;i++) mat[0][i]=0;
	
	for (i=1;i<=n;i++)
	{
	    for (w=1;w<=W;w++)
	    {
	        mat[w][i]=mat[w][i-1];
	        if (v[i]<=w)
	        {
	            if (mat[w][i]<mat[w-v[i]][i-1]+v[i])
	            mat[w][i]=mat[w-v[i]][i-1]+v[i];
	        }
	    }
	}
	
// 	for (i=0;i<=n;i++)
// 	    {for (w=0;w<=W;w++) cout<<mat[w][i]<<" ";
// 	    cout<<"\n";}
	
	cout<<mat[W][n];
	return 0;
}
