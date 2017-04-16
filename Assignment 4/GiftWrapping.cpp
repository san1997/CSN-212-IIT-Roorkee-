

#include<bits/stdc++.h>
#define F first 
#define S second
#define pii pair<int,int>
using namespace std;
int x,y,n;
pii arrayofpoints[10005];
vector<int> order;
int orientation(pii a, pii b, pii c)
{	
	int val = (b.S - a.S)*(c.F - b.F) - (b.F - a.F)*(c.S - b.S);
	if(val == 0)return 0;
	else if(val > 0)return 1;
	else return 2;
}
int main()
{	
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> x >> y;
		arrayofpoints[i].F = x;
		arrayofpoints[i].S = y;
	}
	int leftmost = 1;int xcor = arrayofpoints[1].F;
	for(int i=1;i<=n;i++)
	{
		if(arrayofpoints[i].F < xcor)
		{
			leftmost = i;
			xcor = arrayofpoints[i].F;
		}
	}
	int p = leftmost;
	int next ;
	do{
		order.push_back(p);
		next = (p)%n + 1;
		for(int i=1;i<=n;i++)
		{
			if(orientation(arrayofpoints[p] , arrayofpoints[i] , arrayofpoints[next]) == 2)
				next = i;
		}
		p = next;
	}while(p != leftmost);
	for(int i=0;i < order.size();i++)
		{
			int cur = order[i];
			cout << arrayofpoints[cur].F << " " << arrayofpoints[cur].S << endl;
		}


}
/*
7
0 3
2 2
1 1 
2 1
3 0
0 0
3 3
*/
