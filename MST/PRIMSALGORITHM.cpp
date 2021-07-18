#include<bits/stdc++.h>
using namespace std;
class graph{
 int vertex;
 list<pair<int,int>> *l;
public:
	graph(int v){
		vertex = v;
		l = new list<pair<int,int>>[v];
	}
	void addEdge(int x,int y,int wgt){
		l[x].push_back({y,wgt});
		l[y].push_back({x,wgt});
	}

	int prims(int src){
		bool visited[vertex];
		for(int i =0;i<vertex;i++)
			visited[i] = false;
		// taking min heap
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > Q;
		Q.push({0,src});

		int ans = 0;

		while(!Q.empty()){

			auto valPair = Q.top(); 
			Q.pop();

			int wgt  = valPair.first;
			int currVertex = valPair.second;

			visited[currVertex] = true;

			for(auto nbr:l[currVertex]){

				int connectingWgt = nbr.first;
				int connectingVertex = nbr.second;

				if(visited[connectingVertex]==false){
					ans+=connectingWgt;
					visited[connectingVertex] = true;
					Q.push({connectingWgt,connectingVertex});
				
				}
			
			}
		}
		return ans;
	}
};
int main(){
	

	
	return 0;
}