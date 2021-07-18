#include<bits/stdc++.h>
using namespace std;
class Graph{
private:
	int V;
	list<pair<int,int>> *connect;
public:
	Graph(int v){
		V = v;
		connect = new list<pair<int,int>>[V+1];
	}
	void addEdge(int X,int Y,int cost){
			connect[X].push_back({Y,cost});
			connect[Y].push_back({X,cost});
	}
	pair<int,int> dfsCalculate(int src,map<int,bool>& isVisited){
		pair<int,int> currReturn;
		currReturn.first = currReturn.second = 0;
		cout<<"Source: "<<src<<"\n";
		isVisited[src] = true;
		for(auto tvl:connect[src]){
			if(!isVisited[tvl.first]){
			pair<int,int> temp = dfsCalculate(tvl.first,isVisited);
			currReturn.second+=temp.second;
			int ans  = 2*min(temp.second,V-temp.second)*tvl.second;
			currReturn.first+=ans+temp.first;
		}
		}
		cout<<src<<" "<<currReturn.first<<"\n";
		currReturn.second+=1;
		return currReturn;
	}
	int MaxiMumTvl(int src){
		 map<int,bool> isVisted;
		 for(int i =1;i<=V;i++)
		 	isVisted[i] = false;
		pair<int,int> ans = dfsCalculate(src,isVisted);
		return ans.first;
	}
	void display(){
		for(int i =0;i<=V;i++){
			for(auto x:connect[i]){
				cout<<x.first<<" "<<x.second<<"\n";
			}
		}
	}
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	Graph g(4);
	g.addEdge(1,2,3);
	g.addEdge(2,3,2);
	g.addEdge(4,3,2);
	g.display();
	cout<<"\n";
	cout<<g.MaxiMumTvl(1);
	return 0;
}