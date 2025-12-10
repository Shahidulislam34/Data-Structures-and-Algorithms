#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

#define MAX 100

int timeCounter = 0;
int disc[MAX], low[MAX], parent[MAX];
bool visited[MAX];

struct Edge {
   int u, v;
};

stack<Edge> edgeStack;

// Mapping indexes to letters
char nodes[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

void push(int u, int v) {
   edgeStack.push({u, v});
}

void popUntil(int u, int v) {
   cout << "\nBiconnected Component: ";
   while (!edgeStack.empty()) {
      Edge e = edgeStack.top();
      edgeStack.pop();
      cout << "{" << nodes[e.u] << ", " << nodes[e.v] << "} ";
      if (e.u == u && e.v == v) {
         break;
      }
   }
}

void DFS(vector<int> graph[MAX], int u) {
   visited[u] = true;
   disc[u] = low[u] = ++timeCounter;

   for (int v : graph[u]) {
      if (!visited[v]) {
         parent[v] = u;
         push(u, v);

         DFS(graph, v);

         low[u] = min(low[u], low[v]);

         if (low[v] >= disc[u]) {
            popUntil(u, v);
         }
      } else if (v != parent[u] && disc[v] < disc[u]) {
         low[u] = min(low[u], disc[v]);
         push(u, v);
      }
   }
}

void findBCC(vector<int> graph[MAX], int n) {
   memset(visited, false, sizeof(visited));
   memset(parent, -1, sizeof(parent));
   memset(disc, 0, sizeof(disc));
   memset(low, 0, sizeof(low));

   for (int i = 0; i < n; i++) {
      if (!visited[i]) {
         DFS(graph, i);
      }
   }

   if (!edgeStack.empty()) {
      cout << "\nRemaining Biconnected Component: ";
      while (!edgeStack.empty()) {
         Edge e = edgeStack.top();
         edgeStack.pop();
         cout << "{" << nodes[e.u] << ", " << nodes[e.v] << "} ";
      }
   }
}

int main() {
   int n = 7;
   vector<int> graph[MAX];

   graph[0].push_back(1); graph[1].push_back(0); // A-B
   graph[0].push_back(2); graph[2].push_back(0); // A-C
   graph[1].push_back(3); graph[3].push_back(1); // B-D
   graph[2].push_back(4); graph[4].push_back(2); // C-E
   graph[4].push_back(5); graph[5].push_back(4); // E-F
   graph[4].push_back(6); graph[6].push_back(4); // E-G
   graph[3].push_back(4); graph[4].push_back(3); // D-E

   cout << "Biconnected Components are:\n";
   findBCC(graph, n);

   return 0;
}
