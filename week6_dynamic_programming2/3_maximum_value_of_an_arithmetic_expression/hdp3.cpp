#include <bits/stdc++.h>
using namespace std;

int mxVal(string s);
int mnVal(string s);

int mxVal(string s)
{
    int l=s.size();
    if (l==1)
    return s[0]-'0';
    int ans=INT_MIN;
    
    for (int i=1;i<l;i+=2)
    {
        int mna=mnVal(s.substr(0, i));
        int mxa=mxVal(s.substr(0, i));
        int mnb=mnVal(s.substr(i+1, l-i-1));
        int mxb=mxVal(s.substr(i+1, l-i-1));
        if (s[i]=='+')
        ans=max(ans, mxa+mxb);
        else if (s[i]=='-')
        {
            ans=max(ans, mxa-mnb);
        }
        else if (s[i]=='*')
        {
            ans=max(ans, max(mna*mxb, max(mna*mnb, max(mxa*mnb, mxa*mxb))));
        }
    }
    return ans;
    
}

int mnVal(string s)
{
    int l=s.size();
    if (l==1)
    return s[0]-'0';
    int ans=INT_MAX;
    
    for (int i=1;i<l;i+=2)
    {
        int mna=mnVal(s.substr(0, i));
        int mxa=mxVal(s.substr(0, i));
        int mnb=mnVal(s.substr(i+1, l-i-1));
        int mxb=mxVal(s.substr(i+1, l-i-1));
        if (s[i]=='+')
        ans=min(ans, mna+mnb);
        else if (s[i]=='-')
        {
            ans=min(ans, mna-mxb);
        }
        else if (s[i]=='*')
        {
            ans=min(ans, min(mna*mxb, min(mna*mnb, min(mxa*mnb, mxa*mxb))));
        }
    }
    return ans;
    
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, i;
	string s;
	cin>>s;
	cout<<mxVal(s);
	return 0;
}
