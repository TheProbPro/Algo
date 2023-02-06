#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include <algorithm>
using namespace std;

class BinaryNode
{
public:
	int element;
	BinaryNode* left;
	BinaryNode* right;

	BinaryNode(const int& theElement, BinaryNode* lt, BinaryNode* rt)
		: element{ theElement }, left{ lt }, right{ rt } { }

	BinaryNode(int&& theElement, BinaryNode* lt, BinaryNode* rt)
		: element{ std::move(theElement) }, left{ lt }, right{ rt } { }
};


class BinarySearchTree
{
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& rhs);
	BinarySearchTree(BinarySearchTree&& rhs);
	~BinarySearchTree();

	const int& findMin() const;
	const int& findMax() const;
	bool contains(const int& x) const;
	bool isEmpty() const;
	void printTree() const;

	void makeEmpty();
	void insert(const int& x);
	void insert(int&& x);
	void remove(const int& x);

	// Pre-order-, in-order-, post-order- and level order traversal
	void preOrderTraversal();
	void inOrderTraversal();
	void postOrderTraversal();
	void levelOrderTraversal();
	// Internal pathlength of Binary tree
	int internalPathlength();
	int countNodes();
	bool minimalHeight();

	//Eksamen 2023
	int numberOfTwigs();


private:
	BinaryNode* root;

	void insert(const int& x, BinaryNode*& t);
	void insert(int&& x, BinaryNode*& t);
	void remove(const int& x, BinaryNode*& t);
	BinaryNode* findMin(BinaryNode* t) const;
	BinaryNode* findMax(BinaryNode* t) const;

	bool contains(const int& x, BinaryNode* t) const;

	void makeEmpty(BinaryNode*& t);
	void printTree(BinaryNode* t) const;
	BinaryNode* clone(BinaryNode* t) const;


	// Pre-order-, in-order-, post-order- and level order traversal
	void preOrderTraversal(BinaryNode* t) const;
	void inOrderTraversal(BinaryNode* t) const;
	void postOrderTraversal(BinaryNode* t) const;
	void levelOrderTraversal(BinaryNode* t) const;
	// Internal pathlength of Binary tree
	int internalPathlength(BinaryNode* t, int level, int node) const;
	int internalPathlength(BinaryNode* t, int level) const;

	//Used for levelorder traversal
	int height(BinaryNode* t) const;
	void CurrentLevel(BinaryNode* t, int level) const;
	int countNodes(BinaryNode* t) const;
	bool minimalHeight(BinaryNode* t) const;

	//Eksamen 2023
	int numberOfTwigs(BinaryNode* t) const;
};

#endif
