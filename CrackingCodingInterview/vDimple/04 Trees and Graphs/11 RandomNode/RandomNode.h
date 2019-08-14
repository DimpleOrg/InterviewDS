#pragma once
#include<iostream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<vector>
#include<time.h>

template<typename T>
struct treeNode_02
{
	T data;
	std::shared_ptr<treeNode_02<T>> left;
	std::shared_ptr<treeNode_02<T>> right;
};

template<typename T>
class BTree_02
{
private:
	std::shared_ptr<treeNode_02<T>> root;
	std::queue<std::shared_ptr<treeNode_02<T>>> q;
	std::unordered_map<std::shared_ptr<treeNode_02<T>>, int> umap;
	std::vector<std::shared_ptr<treeNode_02<T>>> vec;

	std::shared_ptr<treeNode_02<T>> getNode(std::shared_ptr<treeNode_02<T>> root, T src, std::shared_ptr<treeNode_02<T>>& res);
	void insertNodeHelper(T val);
	void deleteNode(std::shared_ptr<treeNode_02<T>> root, std::shared_ptr<treeNode_02<T>> node, T val);
	void print(std::shared_ptr<treeNode_02<T>> root);
	void removeLastNodeFromQ();
	void makeLastNOdeNullInTree(std::shared_ptr<treeNode_02<T>> root, std::shared_ptr<treeNode_02<T>>& parent);

public:
	BTree_02()
	{
		srand(time(0));
	}
	void insertNode(T val);
	std::shared_ptr<treeNode_02<T>> getNode(T src);		//same as find node function
	void print();

	void deleteNode(T val)
	{
		deleteNode(root, root, val);
	}
	
	std::shared_ptr<treeNode_02<T>> getRandomNode();
};

template<typename T>
inline void BTree_02<T>::insertNode(T val)
{
	if (!root)
	{
		root = make_shared<treeNode_02<T>>();
		root->data = val;
		root->left = nullptr;
		root->right = nullptr;
		q.push(root);
		vec.push_back(root);
		umap.insert({ root,vec.size() - 1 });
	}
	else
		insertNodeHelper(val);
}

template<typename T>
inline void BTree_02<T>::insertNodeHelper(T val)
{
	auto node = q.front();
	if (node->left == nullptr)
	{
		node->left = make_shared<treeNode_02<T>>();
		node->left->data = val;
		q.push(node->left);
		vec.push_back(node->left);
		umap.insert({ node->left,vec.size() - 1 });
	}

	else if (node->right == nullptr)
	{
		node->right = make_shared<treeNode_02<T>>();
		node->right->data = val;
		q.pop();
		q.push(node->right);
		vec.push_back(node->right);
		umap.insert({ node->right,vec.size() - 1 });
	}
}

template<typename T>
inline void BTree_02<T>::makeLastNOdeNullInTree(std::shared_ptr<treeNode_02<T>> root, std::shared_ptr<treeNode_02<T>>& parent)
{
	if (!root->left && !root->right)
		return;

	if (root->left)
	{
		parent = root;
		makeLastNOdeNullInTree(root->left, parent);
	}

	if (root->right)
	{
		parent = root;
		makeLastNOdeNullInTree(root->right, parent);
	}
		
}

template<typename T>
inline void BTree_02<T>::deleteNode(std::shared_ptr<treeNode_02<T>> root, std::shared_ptr<treeNode_02<T>> node, T val)
{	
	if (!node)
		return; 

	if (node->data == val)
	{
		//Make lastNode NULL in tree
		std::shared_ptr<treeNode_02<T>> parent;
		//parent = root;
		makeLastNOdeNullInTree(root, parent);

		int index = 0;
		//index=umap[node];

		if (!parent->right)
		{
			node->data = parent->left->data;
			index = umap[parent->left];
			umap.erase(parent->left);
			parent->left = nullptr;
		}
		else
		{
			node->data = parent->right->data;
			index = umap[parent->right];
			umap.erase(parent->right);
			parent->right = nullptr;
		}

		////deleting in tree
		//std::shared_ptr<treeNode_02<T>> lastNode = q.back();
		//removeLastNodeFromQ();
		//node->data = lastNode->data;
		//lastNode = nullptr;		//Although address of lastNode in queue and tree is same, lastNode is not becoming null in tree

		//deleting in map and vector
		
		if (index != (vec.size() - 1))
		{
			std::swap(vec[index], vec[vec.size() - 1]);
			umap[vec[index]] = index;
		}
		
		vec.pop_back();
	}
	else
	{
		deleteNode(root, node->left, val);
		deleteNode(root, node->right, val);
	}
}

template<typename T>
inline void BTree_02<T>::removeLastNodeFromQ()
{
	//taking help of two stacks to remove last element from Queue
	std::stack<std::shared_ptr<treeNode_02<T>>> tempStack1, tempStack2;
	while (!q.empty())
	{
		tempStack1.push(q.front());
		q.pop();
	}
	tempStack1.pop();

	while (!tempStack1.empty())
	{
		tempStack2.push(tempStack1.top());
		tempStack1.pop();
	}

	while (!tempStack2.empty())
	{
		q.push(tempStack2.top());
		tempStack2.pop();
	}
}

template<typename T>
inline std::shared_ptr<treeNode_02<T>> BTree_02<T>::getRandomNode()
{
	int rn;
	int len = vec.size();
	
	if (len > 0)
		rn = (rand() % len)+1;
	
	//std::cout << "\nrandom index rand():\t"<<rn<<std::endl;

	//rn = rn % len;

	return vec[rn-1];
}

template<typename T>
inline std::shared_ptr<treeNode_02<T>> BTree_02<T>::getNode(std::shared_ptr<treeNode_02<T>> root, T src, std::shared_ptr<treeNode_02<T>>& res)
{
	if (!root) return nullptr;

	auto val1 = getNode(root->left, src, res);
	if (val1) return val1;

	if (root->data == src)
		res = root;

	auto val2 = getNode(root->right, src, res);
	if (val2) return val2;

	return res;
}

template<typename T>
inline std::shared_ptr<treeNode_02<T>> BTree_02<T>::getNode(T src)
{
	if (!root || root->data == src)
		return root;
	else
	{
		std::shared_ptr<treeNode_02<T>> res;
		return getNode(root, src, res);
	}
}

template<typename T>
inline void BTree_02<T>::print()
{
	print(root);
}

template<typename T>
inline void BTree_02<T>::print(std::shared_ptr<treeNode_02<T>> root)
{
	if (!root)
		return;
	std::cout << "\t" << root->data;
	print(root->left);
	print(root->right);
}



