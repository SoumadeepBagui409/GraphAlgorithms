#include<bits/stdc++.h>
using namespace std;
class graph{
private:
	int v;
	map<int,vector<int>> lsts;
public:
	graph(int V){
		v=V;
	}
	void addEdge(int x,int y){
		list[x].push_back[y];
		list[y].push_back[y];		
	}
	bool dfsCall(int src,map<int,int>&color,map<int,bool> &visited,int currColor){
		visited[src] = true;
		color[src] = currColor;
		bool ans=true;
		for(auto nbr:list[src]){
			if(!visited[nbr]){
				visited[nbr] = true;
				ans = dfsCall(src,color,visited,3-currColor);
				if(ans == false)
					return false;
			}
			else if(visited[src] && currColor==color[nbr]){
				return false;
			}		
		}
		return true;
	}
	void dfsCall(itn src)
	void TwoSet(int src){
		map<int,int> color;
		map<int,bool> visited;
		for(int i =0;i<V;i++)
			visited[i] = false;
		bool ans = dfsCall(src,color,visited,1);
	}
};
int main(){

	return 0;
}