#include <bits/stdc++.h>
using namespace std;

long long int mxVal(string s);
long long int mnVal(string s);

long long int mxVal(string s, int l, int r, vector<vector<long long int>> vmn, vector<vector<long long int>> vmx)
{
    
    long long int sz=r-l+1;
    long long int ans=LLONG_MIN;
    
    for (int i=l+1;i<l+sz;i+=2)
    {
        // cout<<s[i]<<" ";
        long long int mna=vmn[l/2][(i-1)/2]; // mnVal(s.substr(0, i)); 
        long long int mxa=vmx[l/2][(i-1)/2]; // mxVal(s.substr(0, i)); 
        long long int mnb=vmn[(i+1)/2][r/2]; // mnVal(s.substr(i+1, l-i-1)); 
        long long int mxb=vmx[(i+1)/2][r/2]; // mxVal(s.substr(i+1, l-i-1)); 
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
    // cout<<" mx\n";
    return ans;
    
}

int mnVal(string s, int l, int r, vector<vector<long long int>> vmn, vector<vector<long long int>> vmx)
{
    long long int sz=r-l+1;
    long long int ans=LLONG_MAX;
    
    for (int i=l+1;i<l+sz;i+=2)
    {
        // cout<<s[i]<<" ";
        long long int mna=vmn[l/2][(i-1)/2]; // mnVal(s.substr(0, i)); 
        long long int mxa=vmx[l/2][(i-1)/2]; // mxVal(s.substr(0, i)); 
        long long int mnb=vmn[(i+1)/2][r/2]; // mnVal(s.substr(i+1, l-i-1)); 
        long long int mxb=vmx[(i+1)/2][r/2]; // mxVal(s.substr(i+1, l-i-1));
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
    // cout<<" mn\n";
    return ans;
    
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long int n, i, j, k;
	string s;
	cin>>s;
	n=((s.size()-1)/2)+1;
	vector<vector<long long int>> vmn(n, vector<long long int> (n, 0));
	vector<vector<long long int>> vmx(n, vector<long long int> (n, 0));
	
	for (i=0;i<n;i++) vmn[i][i]=s[2*i]-'0', vmx[i][i]=s[2*i]-'0';

	
	
	for (k=1;k<n;k++)
	{
	    for (i=0;i<n-k;i++)
	    {
	        j=i+k;
	        
            vmx[i][j]=mxVal(s, 2*i, 2*j, vmn, vmx);
	        vmn[i][j]=mnVal(s, 2*i, 2*j, vmn, vmx);
	        
	       // cout<<i<<" "<<j<<"\n";
	    }
	}
// 	for (i=0;i<n;i++)
// 	{
// 	    for (j=0;j<n;j++) cout<<vmx[i][j]<<" ";
// 	    cout<<"\n";
// 	}cout<<"\n";
// 	for (i=0;i<n;i++)
// 	{
// 	    for (j=0;j<n;j++) cout<<vmn[i][j]<<" ";
// 	    cout<<"\n";
// 	}
	
	cout<<vmx[0][n-1];
	return 0;
}
