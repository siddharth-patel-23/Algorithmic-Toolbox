#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
    if (a<=9 && b<=9)
    {
        return a>b;
    }
    else if (a<=9 && b>9 && b<=99)
    {
        int tmp=b/10;
        if (a==tmp) return a>(b%10);
        return a>tmp;
    }
    else if (a<=9 && b>99)
    {
        int tmp1=b/10;
        int tmp2=b/100;
        if (a==tmp2) 
        {
            if (a==(tmp1%10))
            return a>(b%10);
            return a>(tmp1%10);
        }
        return a>tmp2;
    }
    else if (a<=99 && a>9 && b<=9)
    {
        int tmp=a/10;
        if (tmp==b)
        return (a%10)>b;
        return tmp>b;
    }
    else if (a<=99 && a>9 && b>9 && b<=99)
    {
        return a>b;
    }
    else if (a<=99 && a>9 && b>99)
    {
        int tmpa=a/10;
        int tmpb1=b/10;
        int tmpb2=b/100;
        if (tmpa==tmpb2)
        {
            if (a%10==tmpb1%10)
            return tmpa>(b%10);
            return (a%10)>(tmpb1%10);
        }
        return tmpa>tmpb2;
    }
    else if (a>99 && b<=9)
    {
        int tmp1=a/10;
        int tmp2=a/100;
        if (b==tmp2) 
        {
            if (b==(tmp1%10))
            return (a%10)>b;
            return (tmp1%10)>b;
        }
        return tmp2>b;
    }
    else if (a>99 && b>9 && b<=99)
    {
        int tmpb=b/10;
        int tmpa1=a/10;
        int tmpa2=a/100;
        if (tmpb==tmpa2)
        {
            if (b%10==tmpa1%10)
            return (a%10)>tmpb;
            return (tmpa1%10)>(b%10);
        }
        return tmpa2>tmpb;
    }
    
    if ((a!=1000 && b!=1000) || a==b)
    return a>b;
    if (a==1000) return (a/1000)>(b/100);
    return (a/100)>(b/1000);
    
    
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, i;
	cin>>n;
	vector<int> v(n);
	for (i=0;i<n;i++) cin>>v[i];
	sort(v.begin(), v.end(), cmp);
	for (i=0;i<n;i++) cout<<v[i];
	return 0;
}
