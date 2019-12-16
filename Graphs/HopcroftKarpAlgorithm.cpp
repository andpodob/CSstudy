#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#pragma GCC target ("avx2")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimization("O3")
using namespace std;
struct vertex {
	int id;
	int color;
	int match;
	vector<int> adj;
};
bool DFScoloring(vector<vertex>& Graph) {
	vector<bool> visited(Graph.size(), false);
	for (int i = 0; i < Graph.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			Graph[i].color = 1;
			stack<int> S;
			S.push(i);
			while (!S.empty()) {
				int v = S.top();
				S.pop();
				visited[v] = true;
				for (int j = 0; j < Graph[v].adj.size(); j++) {
					if (Graph[Graph[v].adj[j]].color == Graph[v].color) {
						return false;
					}
					else {
						Graph[Graph[v].adj[j]].color = (Graph[v].color + 1) % 2;
					}
					if (!visited[Graph[v].adj[j]]) {
						S.push(Graph[v].adj[j]);
					}
				}
			}
		}
	}
	return true;
}
bool HopcroftKarpBFS(vector<vertex> Graph, int NIL, vector<int>& dist) {
	queue<int> Q;
	for (int i = 0; i < Graph.size() - 1; i++) {
		if (Graph[i].color == 0) {
			if (Graph[i].match == NIL) {
				dist[i] = 0;
				Q.push(i);
			}
			else {
				dist[i] = 2 * Graph.size();
			}
		}
	}
	dist[NIL] = 2 * Graph.size();
	while (!Q.empty()) {
		int v = Q.front();
		Q.pop();
		if (dist[v] < dist[NIL]) {
			for (int i = 0; i < Graph[v].adj.size(); i++) {
				if (dist[Graph[Graph[v].adj[i]].match] == 2 * Graph.size()) {
					dist[Graph[Graph[v].adj[i]].match] = dist[v] + 1;
					Q.push(Graph[Graph[v].adj[i]].match);
				}
			}
		}
	}
	return dist[NIL] != 2 * Graph.size();
}
bool HopcroftKarpDFS(int v, int NIL, vector<vertex>& Graph, vector<int>& dist) {
	if (v != NIL) {
		for (int i = 0; i < Graph[v].adj.size(); i++) {
			if (dist[Graph[Graph[v].adj[i]].match] == dist[v] + 1) {
				if (HopcroftKarpDFS(Graph[Graph[v].adj[i]].match, NIL, Graph, dist)) {
					Graph[Graph[v].adj[i]].match = v;
					Graph[v].match = Graph[v].adj[i];
					return true;
				}
			}
		}
		dist[v] = 2 * Graph.size();
		return false;
	}
	return true;
}
int HopcroftKarp(vector<vertex>& Graph) {
	int NIL = Graph.size();
	Graph.push_back({ NIL,-1,-1 });
	for (int i = 0; i < Graph.size() - 1; i++) {
		if (Graph[i].color != -1) {
			Graph[i].match = NIL;
		}
	}
	vector<int> dist(Graph.size(), -1);
	int res = 0;
	while (HopcroftKarpBFS(Graph, NIL, dist)) {
		for (int i = 0; i < Graph.size() - 1; i++) {
			if (Graph[i].color == 0 && Graph[i].match == NIL) {
				if (HopcroftKarpDFS(i, NIL, Graph, dist)) {
					res++;
				}
			}
		}
	}
	Graph.pop_back();
	return res;
}