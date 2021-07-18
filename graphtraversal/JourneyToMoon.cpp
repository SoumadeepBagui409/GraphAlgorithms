#include<bits/stdc++.h>
using namespace std;
template<typename T>
class graph{
private:
	map<T,vector<T>> AdjList;
public:
	void addEdge(T a,T b){
		AdjList[a].push_back(b);
		AdjList[b].push_back(a);
	}
	int dfsAllNode(T src,map<T,bool>& visited){
		int ans = 0;
		visited[src] = true;
		for(auto nbr: AdjList[src]){
			if(!visited[nbr]){
				ans += 1+dfsAllNode(nbr,visited);
			}
		}
		return ans;
	}
	int ConnectedComponent(){
		map<T,bool> visited;
		map<int,int> graphNode;
		for(auto nbr:AdjList){
			visited[nbr.first] = false;			
		}
		int cnt = 1;
		int countTotalNodes = 0;
		for(auto tvl : AdjList){
			if(!visited[tvl.first]){
				graphNode[cnt] = 1 + dfsAllNode(tvl.first,visited);
				countTotalNodes+=graphNode[cnt];
				cnt++;
			}
		}
		for(auto tvl:graphNode)
		{
			cout<<"Component number: "<<tvl.first<<" have total "<<tvl.second<<" nodes\n";
		}
		cout<<"Total node are "<< countTotalNodes<<"\n";
		int answer = countTotalNodes*(countTotalNodes-1)/2;
		for(auto allComponentNodes: graphNode){
			if(allComponentNodes.second>=2){
				answer-=(allComponentNodes.second)*(allComponentNodes.second-1)/2;
			}
		}
		return answer;
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

	g.addEdge(7,8);
	g.addEdge(8,9);
	g.addEdge(9,7);
	
	cout<<g.ConnectedComponent()<<"\n";
	return 0;
}