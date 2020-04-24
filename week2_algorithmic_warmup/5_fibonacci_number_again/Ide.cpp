#include <bits/stdc++.h>
using namespace std;

void multiply(long long int a[2][2], long long int b[2][2], long long int m)
{
    long long int tmp[2][2];
    for (int i=0;i<2;i++)
    {
        for (int j=0;j<2;j++)
        {
            tmp[i][j]=0;
            for (int k=0;k<2;k++)
            {
                // tmp[i][j]+=a[i][k]*b[k][j];
                tmp[i][j]+=(a[i][k]*b[k][j])%m;
                tmp[i][i]%=m;
            }
        }
    }
    for (int i=0;i<2;i++)
    {
        for (int j=0;j<2;j++) a[i][j]=tmp[i][j];
    }
}

long long int power(long long int n, long long int m)
{
    if (n==0 || n==1)
    return 1;
    long long int res[2][2]={{1, 0}, {0, 1}};
    long long int a[2][2]={{1, 1}, {1, 0}};
    while(n>0)
    {
        if (n%2==1) multiply(res, a, m);
        multiply(a, a, m);
        n=n/2;
    }
    return res[0][0];
    
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long n, m;
	cin>>n>>m;
	cout<<power(n-1, m);
	
	return 0;
}
