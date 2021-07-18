#include<bits/stdc++.h>
using namespace std;
class Graph{
private:

	map<int,list<int>> AdjList;

public:

	void addEdge(int X,int Y){

		AdjList[X].push_back(Y);

		AdjList[Y].push_back(X);

	}

	bool DFScheckingForCyclic(int src,map<int,bool>& visited,int parent){

		visited[src] = true;
		bool currNbr = false;
		for(auto nbr:AdjList[src]){

			if(visited[nbr] && nbr!=parent){
				cout<<src<<" "<<nbr<<"\n";
					currNbr = true;
					break;
			}
			else if(!visited[nbr]){
				currNbr =currNbr || DFScheckingForCyclic(nbr,visited,src);
			}
		}
		return currNbr;
	}

	bool isCyclic(int src){

		map<int,bool> visited;

		for(auto x:AdjList)
			visited[x.first] = false;

		return DFScheckingForCyclic(src,visited,src);
	}
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	Graph g;

	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,1);

	cout<<g.isCyclic(1)<<"\n";

	return 0;
}