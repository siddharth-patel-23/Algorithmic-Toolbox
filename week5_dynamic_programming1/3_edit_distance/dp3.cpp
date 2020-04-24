#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s1, s2;
	int i, j, n1, n2;
	cin>>s1>>s2;
	n1=s1.size();
	n2=s2.size();
	s1=" "+s1;
	s2=" "+s2;
	int mat[n1+1][n2+1];
	for (i=0;i<=n1;i++) mat[i][0]=i;
	for (j=0;j<=n2;j++) mat[0][j]=j;
	for (i=1;i<=n1;i++)
	{
	    for (j=1;j<=n2;j++)
	    {
	        int cmp=mat[i-1][j-1];
	        if (s1[i]!=s2[j]) cmp++;
	        mat[i][j]=min(cmp, min(mat[i][j-1]+1, mat[i-1][j]+1));
	        
	    }
	}
	cout<<mat[n1][n2];
	return 0;
}
