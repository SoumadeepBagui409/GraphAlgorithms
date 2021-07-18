#include<bits/stdc++.h>
using namespace std;
//Directed Graph or undirectionalx	
class graph{
int v;
unordered_map<string,vector<pair<string,int>>> list;
public:
	void addEdge(string x,string y,bool bidir,int dist){
		list[x].push_back({y,dist});
		if(bidir == true){
			list[y].push_back({x,dist});
		}
	}
	void print(){
		for(auto p: list){
			string startingCity = p.first;
			vector<pair<string,int>> connectedCity = p.second;
			cout<<"Starting City: "<<startingCity<<"->";
			for(auto nbr:connectedCity){
				cout<<nbr.first<<" with a distance of "<<nbr.second<<",";
			}
				cout<<endl;
		}
	}
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
		graph g;
		g.addEdge("a","b",true,20);
		g.addEdge("b","c",true,40);
		g.addEdge("c","a",false,100);
		g.print();

	return 0;
}