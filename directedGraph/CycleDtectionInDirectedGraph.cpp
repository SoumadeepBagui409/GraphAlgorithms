#include<bits/stdc++.h>
using namespace std;
class graph{
private:
	list<int> *l;
	int v;
public:
	graph(int v){
		this->v = v;
		l = new list<int>[v];
	}

	void addEdge(int x,int y){
		l[x].push_back(y);
	}

	bool DetectingCycle(int src,bool* path,bool* visited){

		path[src] = visited[src] = true;

		for(auto nbr:l[src]){
			if(path[nbr] == true)
				return true;
			else if(!visited[nbr]){
				bool futureCycleDetecting = DetectingCycle(nbr,path,visited);
				if(futureCycleDetecting)
					return true;
			}
		}

		path[src] = false;

		return false;
	}

	bool CyclicDtection(){

		bool visited[v];
		bool path[v];
		
		for(int i =0;i<v;i++){
			path[i] = false;
			visited[i] = false;
		}


		return DetectingCycle(0,path,visited);
	}
};
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	graph g(3);

	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,2);

	cout<<g.CyclicDtection()<<"\n";
	return 0;
}