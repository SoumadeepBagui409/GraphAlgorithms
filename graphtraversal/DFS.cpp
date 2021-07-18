#include<bits/stdc++.h>
using namespace std;
//Directed Graph or undirectionalx	
template<typename T>
class graph{
map<T,vector<T>> list;
public:
	void addEdge(T x,T y){
		list[x].push_back(y);
		list[y].push_back(x);
	}
	void DFS_Travel(T src,map<T,bool>& visited){
		cout<<src<<" ";
		visited[src] = true;
		for(T nbr:list[src]){
			if(!visited[nbr]){
				DFS_Travel(nbr,visited);
			}
		}
	}
	void DFS(T src){
		map<T,bool> visited;
		for(auto x:list){
			visited[x.first] = false;
		}
		DFS_Travel(src,visited);
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
	g.addEdge(0,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.DFS(0);
	return 0;
}