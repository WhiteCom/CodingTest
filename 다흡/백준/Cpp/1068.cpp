#include <iostream>
#include <vector>

using namespace std;

int DFS(vector< vector<int>>& tree, int node, int target, int& leaf)
{
	if (node == target)
		return -1;

	if (tree[node].size() <= 0)
	{
		leaf++;
		return 0;
	}

	for (int i = 0; i < tree[node].size(); ++i)
	{
		int temp = DFS(tree, tree[node][i], target, leaf);
		if (temp == -1 && tree[node].size() == 1)
			leaf++;
	}

	return 0;
}

int main()
{
	int nodeCount;
	cin >> nodeCount;

	int root = 0;
	vector< vector<int>> tree(nodeCount + 1);
	for (int i = 0; i < nodeCount; ++i)
	{
		int tempNum;
		cin >> tempNum;

		if (tempNum == -1)
			root = i;
		else
			tree[tempNum].push_back(i);
	}

	int target;
	cin >> target;

	int leafCount = 0;
	DFS(tree, root, target, leafCount);

	cout << leafCount << '\n';


	return 0;
}