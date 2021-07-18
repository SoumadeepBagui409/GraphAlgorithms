#include<bits/stdc++.h>
using namespace std;
class DSU{
 int *parent;
 int *rank;
 int vertex;
public:
	DSU(int n){
		vertex = n;
		parent = new int[n];
		rank = new int[n];
		for(int i =0;i<vertex;i++)
		{
			parent[i] = -1;
			rank[i] = 1;
		}
	}
	int find(int src){
		if(parent[src] == -1)
			return src;
		// path compression
		return parent[src] = find(parent[src]);
	}

	void unionofSet(int first,int second){
		// Union by every component count
		int ParentofFirst = find(first);
		int ParentofSecond = find(second);

		if(ParentofSecond!=ParentofFirst){
		if(rank[first]<rank[second]){
			parent[first] = second;
			rank[second]+=rank[first];
		}
		else{
			parent[second]=first;
			rank[first]+=rank[second];
		}
	}
	}
};

class graph{
	vector<vector<int>> edgeList;
	int v;
public:
	graph(int v){
		this->v = v;
	}

	void addEdge(int x,int y,int w){
		edgeList.push_back({w,x,y});
	}

	int KrushkalAlgo(){
		// logic 

		//Intialise a DSU

		DSU connector(v);

		// 1.Sort the Edge on the basis of weight
		sort(edgeList.begin(),edgeList.end());

		// ans = 0;
		int ans = 0;

		// creating a vector to store the edges along with cost
		vector<vector<int>> SelctedEdges;	

		// tvl over the sorted edge

		for(auto edge:edgeList){
			int wgt = edge[0];
			int first = edge[1];
			int second = edge[2];

			int ParentofFirst = connector.find(first);
			int ParentofSecond = connector.find(second);

			if(ParentofSecond!=ParentofFirst){
				SelctedEdges.push_back({min(first,second),max(first,second),wgt});
				connector.unionofSet(ParentofFirst,ParentofSecond);
				ans+=wgt;
			}
		}
		cout<<"Slected edges on the basis of the weight\n";
		for(auto select:SelctedEdges){
			cout<<select[0]<<" "<<select[1]<<" -> "<<select[2]<<"\n";
		}

		sort(SelctedEdges.begin(),SelctedEdges.end());
		
		cout<<"Edges on the basis of the smalles node\n";
		
		for(auto select:SelctedEdges){
			cout<<select[0]<<" "<<select[1]<<" -> "<<select[2]<<"\n";
		}
		cout<<"MST answer: ";
		return ans;
	}
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int vtx,egd;
	cin>>vtx>>egd;
	graph g(vtx);
	while(egd--){
		int x,y,w;
		cin>>x>>y>>w;
		g.addEdge(x-1,y-1,w);
	}
	cout<<g.KrushkalAlgo()<<"\n";
	return 0;	
}