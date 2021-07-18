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
	void bfs(T src){
		map<T,int> visited;
		queue<T> tvl;
		tvl.push(src);
		visited[src] = 1;
		cout<<src<<"\n";
		while(!tvl.empty()){
			T node = tvl.front();
			tvl.pop();
			for(auto nbr:list[node]){
				if(!visited[nbr]){
					cout<<nbr<<"->";
					tvl.push(nbr);
					visited[nbr] = 1;
				}
			}
			cout<<"\n";
		}
		cout<<"\n";	
	}
};
int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
	#ifndef ONLINE_JUDGE
	freopen("C:/Users/AAA/Desktop/graph/graphtraversal/input.txt","r",stdin);
	freopen("C:/Users/AAA/Desktop/graph/graphtraversal/output.txt","w",stdout);
	#endif
	graph<int> g;
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(0,3);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.bfs(0);
	return 0;
}