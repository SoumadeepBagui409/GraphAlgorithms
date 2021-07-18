#include<bits/stdc++.h>
using namespace std;
//Directed Graph or undirectionalx	
template<typename T>
class graph{
map<T,vector<T>> list;
public:
	void addEdge(T a,T b){
		list[a].push_back(b);
		list[b].push_back(a);
	}
	int ssspUsingBFS(T src,T target){
		map<T,int> dist;
		for(auto all:list){
			dist[all.first] = INT_MAX;
		}
		dist[src] = 0;
		queue<int> BFS;
		BFS.push(src);
		while(!BFS.empty()){
			T parent = BFS.front();
			BFS.pop();
			for(auto children:list[parent])
			{
					// this if condition checks that
					// is the child node visited or
					// not
					if(dist[children] == INT_MAX){
							dist[children] = dist[parent] +1;
							BFS.push(children);
					}
			}
		}
		return dist[target];
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
	cout<<g.ssspUsingBFS(0,5);
	return 0;
}