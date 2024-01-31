#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[10][10],stk[10],visit[10],visited[10],i,j,k,n,e,v,top;
	cout<<"Enter the number of vertices in the graph: ";
	cin>>n;
	cout<<"Enter the number of edges in the graph: ";
	cin>>e;
	cout<<"Enter the starting and ending vertex of the edges: ";
	for(k=1;k<=e;k++)
	{
		cin>>i>>j;
		arr[i][j]=1;
	}
	cout<<"Enter the vertex at which depth first search traversal begins: ";
	cin>>v;
	cout<<"After the depth first search traversal: ";
	cout<<v<<" ";
	visited[v]=1;
	k=1;
	while(k<n)
	{
		for(j>=n;j>=1;j--)
		{
			{
				visit[j]=1;
				stk[top]=j;
				top++;
			}
			v=stk[--top];
			cout<<v<<" ";
			k++;
			visit[v]=0;
			visited[v]=1;
		}
	}
	cout<<"\n\n\n";
	return 0;
}
