#include<bits/stdc++.h>
using namespace std;
template<typename T>
class graph{
map<T,list<T,int>> AdjList;
public:
	void AddEdge(T X,T Y,int Cost){
		AdjList[X].push_back({Y,Cost});
		AdjList[Y].push_back({X,Cost});
	} 	
	int dijkstraAlgo(T src,T dest){
		map<T,int> dist;

		for(auto tvl:AdjList){
			dist[tvl.first] = INT_MAX;
		}

		dist[src] = 0;
		set<pair<int,T>> Curr_Cost_Eff_Path;

		Curr_Cost_Eff_Path.insert({0,src});

		int ans = 0;

		while(Curr_Cost_Eff_Path.size()!=0){
			
			auto CurrPair = *(Curr_Cost_Eff_Path.begin());
    	
			int CurrCost = CurrPair.first;
			T CurrNode = CurrPair.second;


			for(auto tvl:AdjList[CurrNode]){
				if( CurrCost + tvl.first < dist[tvl.second]){
					auto finder = Curr_Cost_Eff_Path.find({dist[tvl.second],tvl.first});
					if(finder !=Curr_Cost_Eff_Path.end()){
						Curr_Cost_Eff_Path.erase(finder);
					}
					dist[tvl.second] =CurrCost+tvl.first;
					
					Curr_Cost_Eff_Path.insert({dist[tvl.second],tvl.second});
				}
			}			
			Curr_Cost_Eff_Path.erase(Curr_Cost_Eff_Path.begin());			
		}
		return dist[dest];
	}

};
int main(){
	return 0;
}