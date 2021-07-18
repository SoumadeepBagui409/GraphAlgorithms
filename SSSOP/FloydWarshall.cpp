#include<bits/stdc++.h>
#define INFY 1000000
using namespace std;
class graph{
int vertex;
vector<vector<int>> matrix;
private:
	graph(int v){
		vertex = v;
		vector<int> temp;
		for(int i =0;i<vertex;i++)
			temp.push_back(INFY);
		for(int i =0;i<vertex;i++)
			matrix.push_back(temp);
	}
	void AddEdge(int x,int y,int cost,bool bidir){
			matrix[x][y] = cost;
			if(bidir)
				matrix[y][x] = cost;
	}
	vector<vector<int>> floydWarshall(){

		for(int k =0;k<vertex;k++){

			for(int i =0;i<vertex;i++)
				for(int j=0;j<vertex;j++)
					matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
		}
		return matrix;
	}
};
int main(){

	return 0;
}