#include<bits/stdc++.h>
#define pii pair<int,int>
#define S second
#define F first
using namespace std;
int n,y,x;
pair<double,pii> arrayofpoints[10005];
vector<pair<double,pii> > pointsvector;

double dis(pair<double,pii> p1 , pair<double,pii> p2)
{
	int a = p1.S.F - p2.S.F;
	int b = p2.S.S - p1.S.S;
	return sqrt(a*a + b*b);
}
int orientation(pair<double,pii> a, pair<double,pii> b, pair<double,pii> c)
{	
	int val = (b.S.S - a.S.S)*(c.S.F - b.S.F) - (b.S.F - a.S.F)*(c.S.S - b.S.S);
	
	if(val == 0)return 0;
	else if(val > 0)return 1;
	else return 2;
}
pair<double,pii> nextToTop(stack<pair<double,pii> > &S)
{
   pair<double,pii> p = S.top();
    S.pop();
   pair<double,pii> res = S.top();
    S.push(p);
    return res;
}
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> x >> y;
		arrayofpoints[i].S.F = x;
		arrayofpoints[i].S.S =  y;
	}
	int lowermost = 1,xcor = arrayofpoints[1].S.F , ycor = arrayofpoints[1].S.S;
	for(int i=1;i<=n;i++)
	{
		if(arrayofpoints[i].S.S < ycor)
		{
			lowermost = i;
			ycor = arrayofpoints[i].S.S;
			xcor = arrayofpoints[i].S.F;
		}
		else if(arrayofpoints[i].S.S == ycor)
		{
			if(arrayofpoints[i].S.F < xcor)
			{
				lowermost = i;
				xcor = arrayofpoints[i].S.F;
			}
		}
	}
	swap(arrayofpoints[1] , arrayofpoints[lowermost]);
	y = arrayofpoints[1].S.S;
	x = arrayofpoints[1].S.F;
	for(int i=2;i<=n;i++)
	{
		arrayofpoints[i].F = (arrayofpoints[i].S.S - y)/(double)(arrayofpoints[i].S.F - x);
	}
	sort(arrayofpoints+2, arrayofpoints + n+1);
	pointsvector.push_back(arrayofpoints[1]);
	for(int i=2;i<=n;i++)
	{
		int maxi = i;
		double maxdis = dis(arrayofpoints[1] , arrayofpoints[i]);
		while(i <=n && arrayofpoints[i].F == arrayofpoints[i+1].F)
		{
			if(maxdis < dis(arrayofpoints[1],arrayofpoints[i]))
			{
				maxi = i;
				maxdis = dis(arrayofpoints[1],arrayofpoints[i]);
			}
			i++;

		}
		pointsvector.push_back(arrayofpoints[i]);
	}

	stack<pair<double,pii> > stackpoints;
	stackpoints.push(pointsvector[0]);
	stackpoints.push(pointsvector[1]);
	stackpoints.push(pointsvector[2]);
	for(int i=3;i<pointsvector.size();i++)
	{
		pair<double,pii> p1 = nextToTop(stackpoints);
		pair<double,pii> p2 = (stackpoints.top());
		pair<double,pii> p3 = pointsvector[i];
	//	cout << orientation(p1 ,p2 , p3) <<endl;
		while(orientation( p1, p2 , p3) != 2)
			{
				stackpoints.pop();
				p1 = nextToTop(stackpoints);
				p2 = stackpoints.top();
			}
		stackpoints.push(pointsvector[i]);
	}
	while(!stackpoints.empty())
	{
		cout <<( stackpoints.top()).S.F << " " << ( stackpoints.top()).S.S << endl;
		stackpoints.pop();
	}


}
/*
Input : 
7
0 3
2 2
1 1 
2 1
3 0
0 0
3 3
Output : 
0 3
3 3
3 0
0 0


Input : 
8
0 3
1 1
2 2
4 4
0 0
1 2 
3 1
3 3
Output : 
0 3
4 4
3 1
0 0

*/
