#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;


vector<vector<int>> adjacent; // 인접 행렬

void CreateGraph()
{
	adjacent = vector<vector<int>>(6, vector<int>(6, -1));

	adjacent[0][1] = 15;
	adjacent[0][3] = 35;
	adjacent[1][0] = 15;
	adjacent[1][2] = 5;
	adjacent[1][3] = 10;
	adjacent[3][4] = 5;
	adjacent[5][4] = 5;
}

void Dijikstra(int start)
{
	struct VertexCost
	{
		int vertex;
		int cost;
	};

	list<VertexCost> discovered;
	vector<int> best(6, INT32_MAX);
	vector<int> parent(6, -1);

	discovered.push_back(VertexCost{ start, 0 });
	best[start] = 0;
	parent[start] = 0;

	while (discovered.empty() == false)
	{
		int bestCost = INT32_MAX;

		// 최소거리인 vertex 찾아내기
		list<VertexCost>::iterator bestIt;
		for (auto it = discovered.begin(); it != discovered.end(); it++)
		{
			// 
			if (it->cost < bestCost)
			{
				bestCost = it->cost;
				bestIt = it;
			}
		}

		// 최소거리 index의 가중치로 초기화 및 출발vertex도 초기화
		int cost = bestIt->cost;
		start = bestIt->vertex;
		// 방문했으니 삭제.
		discovered.erase(bestIt);

		if (best[start] < cost)
			continue;

		for (int there = 0; there < 6; there++)
		{
			// 연결되지 않았으면 스킵.
			if (adjacent[start][there] == -1)
				continue;

			// 더 좋은 경로를 과거에 찾았으면 스킵.
			int nextCost = best[start] + adjacent[start][there];
			if (nextCost >= best[there])
				continue;

			discovered.push_back(VertexCost{ there, nextCost });
			best[there] = nextCost;
			parent[there] = start;
		}
	}
}


int main()
{	
	CreateGraph();
	Dijikstra(0);

	return 0;
}