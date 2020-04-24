#include <bits/stdc++.h>
using namespace std;

void multiply(long long int a[2][2], long long int b[2][2])
{
    long long int tmp[2][2];
    long long int m=10;
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

long long int power(long long int n)
{

    if (n<=2)
    return n;
    long long int res[2][2]={{1, 0}, {0, 1}};
    long long int a[2][2]={{1, 1}, {1, 0}};
    while(n>0)
    {
        if (n%2==1) multiply(res, a);
        multiply(a, a);
        n=n/2;
    }
    return (res[0][0])%10;
    
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long n;
	cin>>n;
	cout<<power(n);
	
	return 0;
}
