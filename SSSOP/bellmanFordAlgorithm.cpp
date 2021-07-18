#include<bits/stdc++.h>
using namespace std;
class graph{
	int vertex;
    vector<vector<int>> edges;
public:
	graph(int v){
		vertex = v;
	}
	void addEdge(int X,int Y,int Cost){
		edges.push_back({X,Y,Cost});
	}

	vector<int> bellmanFordAlgorithm(int src){
		// 1. first step Distance array intializing all with infy except for src node

		vector<int> distance(vertex);
		for(int i = 0 ;i<vertex;i++){
			distance[i] = INT_MAX;
		}

		distance[src] = 0;

		// run relaxation process  vetex - 1 times as maximi=um edges can a graph have is vertex - 1		

		for(int i = 0;i<vertex-1;i++){

			for(auto edgePair: edges){
				int first = edgePair[0];
				int second = edgePair[1];
				int cost = edgePair[2];
				// relaxation
				if(distance[first]!=INT_MAX && distance[first] + cost < distance[second]){
					distance[second] = distance[first] + cost;
				}
			}
		}
		// case 2 checking at vth time if change happen negative wght cycle detected
		for(auto edgePair: edges){
				int first = edgePair[0];
				int second = edgePair[1];
				int cost = edgePair[2];
				// relaxation
				if(distance[first]!=INT_MAX && distance[first] + cost < distance[second]){
					cout<<"Negative cycle detected!!!";
					vector<int> nulltype;
					return nulltype;
				}
			}

	return distance;
	}
};

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int vertex,ege;
	cin>>vertex>>ege;
	graph g(vertex);
	while(ege--){
		int x,y,cost;
		cin>>x>>y>>cost;
		g.addEdge(x-1,y-1,cost);
	}
	int src;
	cin>>src;
	vector<int> minDist = g.bellmanFordAlgorithm(src);
	for(int i =1;i<vertex;i++){
		cout<<"From "<<src+1<<" to "<<i+1<<" distance is: "<<minDist[i]<<"\n";
	}
	return 0;
}