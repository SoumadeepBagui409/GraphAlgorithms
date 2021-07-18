#include<bits/stdc++.h>
using namespace std;
class graph{
	int vertex;
	list<pair<int,int>> l;
public:
	graph(int v){
		vertex = v;
	}
	void addEdge(int x,int y){
		l.push_back({x,y});
	}

	int findSet(int src,int parent[]){
		if(parent[src]==-1)
			return src;
		//path compression
		return parent[i] = findSet(parent[src],parent);
	}
	void union_set(int s1,int s2,int parent[]){
		int parentSet1 = findSet(s1,parent);
		int parentSet2 = findSet(s2,parent);
		if(parentSet1!=parentSet2){
			parent[parentSet2] = parentSet1;
		}
	}
	bool CycleDetect(){
		int parent[vertex];
		
		for(int i =0;i<vertex;i++)
			parent[i] = -1;

		for(auto Edge:l){
			int set1 = Edge.first;
			int set2 = Edge.second;
			int prntset1 = findSet(set1,parent);
			int prntset2 = findSet(set2,parent);

			if(prntset1!=prntset2){
				union_set(prntset1,prntset2,parent);
			}
			else{
				return true;
			}
		}

		return false;
	}
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,0);
	cout<<g.CycleDetect();
	return 0;
}