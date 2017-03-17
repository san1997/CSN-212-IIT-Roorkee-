#include<bits/stdc++.h>
#define F first
#define S second
#define int_maxm 2147483640
#define mod 1000000007
#define ll long long int
#define pll pair<ll,ll>
#define endl '\n'
using namespace std;
int vertices,edges,x,y,w;
vector<int> graph[100003];
vector<int> weight[100003];
int dp[100003];
int main()
{	
	cin >> vertices >> edges ;// Input the number of vertices and edges in the graph
	for(int i=0;i<edges ;i++)
	{
		cin >> x >> y >> w; // path x -> y with weight w
		graph[x].push_back(y);
		weight[x].push_back(w);
	}
	dp[1] = 0;
	for(int i=2;i<=vertices;i++)
		dp[i] = int_maxm; // Intialising the distance array

	//This loop is for iteratting over n-1 vertices
	for(int i=1;i<vertices;i++)
	{
		//This and inside loop is to iterate over all the edges 
		for(int j=1;j<=vertices;j++)
		{
			for(int k=0;k<graph[j].size();k++)
			{
				int current = graph[j][k];
				int currnetweight = weight[j][k];
				//relaxation step
				dp[current] = min(dp[current],dp[j] + currnetweight);
			}
		}
	}
	bool negcycle = 0;
	for(int i=1;i<=vertices;i++)
	{
		for(int j=0;j<graph[i].size();j++)
		{
			int current = graph[i][j];
			int currnetweight = weight[i][j];
			if(dp[current] > dp[i] + currnetweight)negcycle = 1;
		}
	}
	if(negcycle)
	{
		cout << "This graph contains a negative cycle." << endl;
		return 0;
	}
	for(int i=1;i<=vertices;i++)
		cout << dp[i] << " ";
}
/*
Input : 
5 8
1 2 -1
1 3 4
2 3 3
2 4 2
2 5 2
4 3 5
4 2 1
5 4 -3
Output : 
0 -1 2 -2 1
*/
