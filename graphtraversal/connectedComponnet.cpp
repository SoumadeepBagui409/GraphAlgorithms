#include<bits/stdc++.h>
using namespace std;
template<typename T>
class graph{
	map<T,vector<T>> list;
public:
	void addEdge(T x,T y){
		list[x].push_back(y);
		list[y].push_back(x);
	}
	void dfs_helper(T src,map<T,bool>& visited){
		visited[src] = true;
		cout<<src<<"->";

		for(auto nbr:list[src]){
			if(!visited[nbr]){
				dfs_helper(nbr,visited);
			}
		}
	}
	void connectedComponent(){
		map<T,bool> visited;
		for(auto startingPoint:list){
			visited[startingPoint.first] = false;
		}
		int cnt = 1;
		for(auto startingPoint:list){
			T currPoint = startingPoint.first;
			if(!visited[currPoint]){
				cout<<" component Number: "<<cnt<<":";
				dfs_helper(currPoint,visited);
				cnt++;
				cout<<"\n";
			}
		}
	}
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	graph<int> g;
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,0);

	g.addEdge(4,5);
	g.addEdge(5,6);
	g.addEdge(6,4);

	g.addEdge(7,7);
	

	g.connectedComponent();
	return 0;
}