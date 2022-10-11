// 다익스트라 구현하기

#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<vector<int>> adjacent;

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

	discovered.push_back({ here,0 });
	best[here] = 0;
	parent[here] = 0;

	while (discovered.empty() == false)
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
		{
			continue;
		}

		for (int there = 0; there < 6; there++)
		{
			if (adjacent[here][there] == -1)
			{
				continue;
			}

			int nextCost = best[here] + adjacent[here][there];
			if (nextCost >= best[there])
			{
				continue;
			}

			cout << "Vertex : " << here << " To " << there << " 의 가중치 : " << nextCost << '\n';

			discovered.push_back({ there, nextCost });
			best[there] = nextCost;
			parent[there] = here;
		}
		
	}


}

int main()
{
	CreateGraph();
	Dijikstra(0);


	return 0;
}
