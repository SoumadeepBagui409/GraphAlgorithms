#include<bits/stdc++.h>
using namespace std;
// Undirected Graph
class graph{
int v;
list<int> *l;
public:
	graph(int v){
		this->v = v;
		l = new list<int>[v];
	}
	void addEdge(int x,int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void printAdjlist(){
		for(int i =0;i<v;i++){
			cout<<"Vertex "<<i<<"->";
			for(auto nbr:l[i]){
				cout<<nbr<<",";
			}
			cout<<"\n";
		}
	}
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(2,3);
	g.addEdge(2,1);
	g.printAdjlist();
	return 0;
}