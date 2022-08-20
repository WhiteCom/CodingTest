#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* left, * right;
};

int left_node = -1, right_node = -1;

/*
( 참고 1 : https://comdolidol-i.tistory.com/280 )
( 참고 2 : https://viyoung.tistory.com/346 )
( 참고 2의 아이디어를 이해하고, 참고 1의 방식을 이용 )
( 트리 순회 자체는 전형적인 inorder 방식 ) 
트리 중위순회시, 가장 오른쪽 노드들을 방문 시, 간선을 2번 방문하지 않는다.
트리 간선수는 (정점 개수 - 1)
( 정점 * 2 - 오른쪽 노드 방문하는 간선들의 개수 )
*/
void Inorder(Node* root, bool flag)
{
	if (!root)
		return;
	
	if (root->data == -1)
		return;

	left_node++;
	Inorder(root->left, false);
	// printf("%d -> ", root->data);
	if (flag)
	{
		right_node++;
		Inorder(root->right, true);
	}
	else
	{
		Inorder(root->right, false);
	}
}


int main()
{
	int nodeNum;
	cin >> nodeNum;

	Node* nodes = new Node[nodeNum];

	// init tree
	for (int i = 0; i < nodeNum; ++i)
	{
		nodes[i].data = i + 1;

		int mid, left, right;

		cin >> mid >> left >> right;
		// left node
		if (left == -1)
			nodes[mid - 1].left = NULL;
		else
			nodes[mid - 1].left = &nodes[left - 1];

		// right node
		if (right == -1)
			nodes[mid - 1].right = NULL;
		else
			nodes[mid - 1].right = &nodes[right - 1];
	}

	Inorder(&nodes[0], true);

	cout << 2 * left_node - right_node << '\n';

	delete nodes;

	return 0;
}