#include "json.hpp"

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
#include <numeric>

using namespace std;
using namespace nlohmann;

typedef unsigned long long ull;

struct PairHash {
public:
  template <typename T, typename U>
  size_t operator()(const pair<T, U> &x) const
  {
    return hash<T>()(x.first) ^ hash<U>()(x.second);
  }
};

int main()
{
	ull distPoints[] = { 0, 1, 2, 4, 7, 10, 15 };
	
	json j;
	cin >> j;
	
	vector<ull> playerPoints(j["Players"].size(), 0);
	vector<ull> longestChains(j["Players"].size(), 0);
	ull longestMaxChain = 0;
	
	unordered_map<string,ull> colorsToIds;
	ull i = 0;
	for (auto& v : j["Players"])
		colorsToIds.emplace(v["Color"], i++);
		
	unordered_map<string,unordered_map<string,unordered_map<ull,ull>>> nodeConnections;
	unordered_set<string> cityNames;
	for (auto& c : j["Board"]["Connections"])
	{
		string d1 = c["Destination1"]["DestinationName"];
		string d2 = c["Destination2"]["DestinationName"];
		
		auto node1 = nodeConnections[d1].emplace(d2, unordered_map<ull,ull>()).first;
		auto node2 = nodeConnections[d2].emplace(d1, unordered_map<ull,ull>()).first;
		
		cityNames.emplace(d1);
		cityNames.emplace(d2);
		
		auto con1 = c["ConnectionOccupant1"];
		if (con1.is_string())
		{
			auto player = colorsToIds[con1];
			playerPoints[player] += distPoints[(ull)c["Distance"]];
			node1->second.emplace(player, (ull)c["Distance"]);
			node2->second.emplace(player, (ull)c["Distance"]);
		}

		auto con2 = c["ConnectionOccupant2"];
		if (con2.is_string())
		{
			auto player = colorsToIds[con2];
			playerPoints[player] += distPoints[(ull)c["Distance"]];
			node1->second.emplace(player, (ull)c["Distance"]);
			node2->second.emplace(player, (ull)c["Distance"]);
		}
	}
	
	for (auto& p : j["Players"])
	{
		auto player = colorsToIds[p["Color"]];
		
		unordered_map<pair<string,string>,ull,PairHash> distances;
		for (const auto& s1 : cityNames)
			for (const auto& s2 : cityNames)
			{
				ull dist = 1000000000000000ULL;
				
				if (s1 == s2) dist = 0;
				else
				{
					auto it = nodeConnections[s1].find(s2);
					if (it != nodeConnections[s1].end())
						if (it->second.find(player) != it->second.end())
							dist = nodeConnections[s1][s2][player];
				}
				distances.emplace(make_pair(s1, s2), dist);
				distances.emplace(make_pair(s2, s1), dist);
			}
		
		for (const auto& s3 : cityNames)
			for (const auto& s1 : cityNames)
				for (const auto& s2 : cityNames)
					if (distances[make_pair(s1, s2)] > distances[make_pair(s1, s3)] + distances[make_pair(s3, s2)])
						distances[make_pair(s1, s2)] = distances[make_pair(s1, s3)] + distances[make_pair(s3, s2)];
				
		for (const auto& s1 : cityNames)
			for (const auto& s2 : cityNames)
			{
				if (distances[make_pair(s1, s2)] >= 1000000000000000ULL) continue;
				if (longestChains[player] < distances[make_pair(s1, s2)])
					longestChains[player] = distances[make_pair(s1, s2)];
				if (longestMaxChain < longestChains[player])
					longestMaxChain = longestChains[player];
			}
			
		for (auto& r : p["Routes"])
		{
			string d1 = r["Destination1"]["DestinationName"];
			string d2 = r["Destination2"]["DestinationName"];
		
			bool hasDestination = distances[make_pair(d1, d2)] < 1000000000000000ULL;
			
			if (hasDestination) playerPoints[player] += (ull)r["Points"];
			else playerPoints[player] -= (ull)r["Points"];
		}
	}
	
	for (ull i = 0; i < longestChains.size(); i++)
		if (longestChains[i] == longestMaxChain)
			playerPoints[i] += 10;
			
	vector<ull> players(playerPoints.size());
	iota(players.begin(), players.end(), 0);
	
	sort(players.begin(), players.end(), [&](ull i, ull k)
	{
		return playerPoints[i] == playerPoints[k] ?
			j["Players"][i]["Name"] < j["Players"][k]["Name"] :
			playerPoints[i] > playerPoints[k];
	});
	
	for (ull p : players)
	{
		cout << (string)j["Players"][p]["Name"] << ',';
		cout << playerPoints[p] << ',';
		cout << longestChains[p] << endl;
	}
}
