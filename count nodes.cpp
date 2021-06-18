// CPP code to find number of nodes
// in subtree of each node
#include <bits/stdc++.h>
using namespace std;

const int N = 9;

// variables used to store data globally
int count1[N] = {0};

// adjacency list representation of tree
vector<int> adj[N];

// function to calculate no. of nodes in a subtree
void numberOfNodes(int s, int e)
{
	//vector<int>::iterator u;
	count1[s] = 1;
	for (int g: adj[s]) {
		
		// condition to omit reverse path
		// path from children to parent
		if (g == e)
			continue;
		
		// recursive call for DFS
		numberOfNodes(g, s);
		
		// update count[] value of parent using
		// its children
		count1[s] += count1[g];
	}
}

// function to add edges in graph
void addEdge(int a, int b)
{
	adj[a].push_back(b);
	adj[b].push_back(a);
}

// function to print result
void printNumberOfNodes()
{
	for (int i = 1; i < N; i++) {
		cout << "\nNodes in subtree of " << i;
		cout << ": " << count1[i]-1;
	}
}

// driver function
int main()
{
	// insertion of nodes in graph
	addEdge(1, 2);
	addEdge(1, 4);
	addEdge(1, 5);
	addEdge(2, 6);
	addEdge(4, 3);
	addEdge(4, 7);
    //addEdge(7, 8);

    // call to perform dfs calculation
	// making 1 as root of tree
	numberOfNodes(1, 0);
	
	// print result
	printNumberOfNodes();
	return 0;
}
