#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int m;
	cin>>m;
	int a=m/10;
	int b=(m-a*10)/5;
	int c=m-a*10-b*5;;
	cout<<a+b+c;
	return 0;
}
