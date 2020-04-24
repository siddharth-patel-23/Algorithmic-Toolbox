#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int n, k=0, cnt=1, i;
    cin>>n;
    vector<int> ans;
    while(n>0)
    {
        if (n>=cnt)
        {
            n-=cnt;
            if (n<=cnt)
            {
                cnt+=n;
                ans.push_back(cnt);
                n=0;
            }
            else
            ans.push_back(cnt), cnt++;
        }
        k++;
    }
    cout<<k<<"\n";
    for (i=0;i<ans.size();i++) cout<<ans[i]<<" ";
	return 0;
}
