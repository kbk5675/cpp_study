// 다익스트라 구현하기

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct Vertex
{
	int data = 10;
};

vector<vector<int>> adjacent;
vector<pair<int, int>> disConnected;

void CreateGraph()
{
	adjacent = vector<vector<int>>(6, vector<int>(6, -1));

	adjacent[0][1] = 15;
	adjacent[0][3] = 35;
	adjacent[1][0] = 15;
	adjacent[1][2] = 5;
	adjacent[1][3] = 10;
	adjacent[2][5] = 3;
	adjacent[3][4] = 5;
	adjacent[5][4] = 5;
}

void Dijikstra(int here)
{
	struct VertexCost
	{
		int vertex;
		int cost;
	};

	list<VertexCost> discovered;
	vector<int> best(6, INT32_MAX);
	vector<int> parent(6, -1);

	discovered.push_back(VertexCost{ here, 0 });
	best[here] = 0;
	parent[here] = 0;

	while (!discovered.empty())
	{
		list<VertexCost>::iterator bestIt;
		int bestCost = INT32_MAX;

		for (auto it = discovered.begin(); it != discovered.end(); it++)
		{
			if (it->cost < bestCost)
			{
				bestCost = it->cost;
				bestIt = it;
			}
		}

		int cost = bestIt->cost;
		here = bestIt->vertex;
		discovered.erase(bestIt);

		if (best[here] < cost)
			continue;


		for (int there = 0; there < 6; there++)
		{
			if (adjacent[here][there] == -1)
			{
				disConnected.push_back({ here, there });
				continue;
			}
			

			int nextCost = best[here] + adjacent[here][there];
			if (nextCost >= best[there])
				continue;
			
			cout << "vertex :" << here << " to " << "vertex :" << there << "가중치 : " << nextCost << '\n';

			discovered.push_back(VertexCost{ there, nextCost });
			best[there] = there;
			parent[there] = here;
		}
	}


}

int main()
{
	CreateGraph();

	for (int i = 0; i < 6; i++)
	{
		Dijikstra(i);
	}
	
	// 연결되지 않은 친구들
	for (int i = 0; i < disConnected.size(); i++)
	{
		cout << disConnected[i].first << " to " << disConnected[i].second << " not to connected\n";
	}


	return 0;
}