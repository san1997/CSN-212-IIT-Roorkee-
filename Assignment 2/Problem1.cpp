//Zigzag
// problem link : https://community.topcoder.com/stat?c=problem_statement&pm=1259
//http://ideone.com/SLPNgE
#include <iostream>
using namespace std;
int n,a[100005], up[100005],down[100005];
int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i=0;i<n;i++)
			cin >> a[i];
		up[0] = 1;
		down[0] = 1;
		
		for(int i=1;i<n;i++)
		{
			int upmax =0,downmax=0;
			for(int j=0;j<i;j++)
			{
				if(a[j] < a[i])
				{
					if(down[j] > downmax)downmax = down[j];
				}
				if(a[j] > a[i])
				{
					if(up[j] > upmax)upmax = up[j];
				}
			}
			up[i] = downmax+1;
			down[i] = upmax +1 ;
		}
		int maxl = 0;
		for(int i=0;i<n;i++)
		{
			if(up[i] > maxl)maxl= up[i];
			if(down[i] > maxl) maxl = down[i];
		}
		cout << maxl << endl;
		
	}
	return 0;
}
