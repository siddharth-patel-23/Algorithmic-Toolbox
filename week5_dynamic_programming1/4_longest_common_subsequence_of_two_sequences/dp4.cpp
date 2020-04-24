#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n1, n2, i, j;
	cin>>n1;
	vector<int> v1(n1+1);
	for (i=1;i<=n1;i++) cin>>v1[i];
	cin>>n2;
	vector<int> v2(n2+1);
	for (i=1;i<=n2;i++) cin>>v2[i];
	v1[0]=v2[0]=0;
	int mat[n1+1][n2+1];
	for (i=0;i<=n1;i++) mat[i][0]=0;
	for (j=0;j<=n2;j++) mat[0][j]=0;
	for (i=1;i<=n1;i++)
	{
	    for (j=1;j<=n2;j++)
	    {
	        int cmp=mat[i-1][j-1];
	        if (v1[i]==v2[j]) cmp++;
	        mat[i][j]=max(cmp, max(mat[i][j-1], mat[i-1][j]));
	    }
	}
	cout<<mat[n1][n2];
	return 0;
}
