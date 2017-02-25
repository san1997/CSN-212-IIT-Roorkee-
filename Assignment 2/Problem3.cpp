//circular LIS
//problem link : https://www.codechef.com/problems/D2/
//http://ideone.com/mwiHi8
#include <bits/stdc++.h>
using namespace std;
int n,a[30002];
int len(int p)
{
	int dp[30002];
	for(int i=p;i<p+n;i++)
	{
		int maxm = 0;
		for(int j=0;j<i;j++)
		{
			if(a[i] > a[j])
			{
				if(maxm < dp[j])maxm = dp[j];
			}
		}
		dp[i] = maxm+1;
	}
	int maxm = 0;
	for(int i=p;i<p+n;i++)
		if(maxm < dp[i])maxm = dp[i];
	return maxm;
}
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i= 0;i<n;i++)
			{cin >> a[i];a[i+n] = a[i];}
		int ans = 0;
		for(int i=0;i<n;i++)
			{
				int v = len(i);
				if(v > ans)ans = v;
			}
		cout << ans << endl;	
		
	}
	return 0;
}
