#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() : root{ nullptr }
{
}


BinarySearchTree::BinarySearchTree(const BinarySearchTree& rhs) : root{ nullptr }
{
	root = clone(rhs.root);
}


BinarySearchTree::BinarySearchTree(BinarySearchTree&& rhs) : root{ rhs.root }
{
	rhs.root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	makeEmpty();
}

const int& BinarySearchTree::findMin() const
{
	if (isEmpty())
		return -1;
	return findMin(root)->element;
}


const int& BinarySearchTree::findMax() const
{
	if (isEmpty())
		return -1;
	return findMax(root)->element;
}

bool BinarySearchTree::contains(const int& x) const
{
	return contains(x, root);
}

bool BinarySearchTree::isEmpty() const
{
	return root == nullptr;
}

void BinarySearchTree::printTree() const
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	else
		printTree(root);
}

void BinarySearchTree::makeEmpty()
{
	makeEmpty(root);
}


void BinarySearchTree::insert(const int& x)
{
	insert(x, root);
}

void BinarySearchTree::insert(int&& x)
{
	insert(std::move(x), root);
}

void BinarySearchTree::remove(const int& x)
{
	remove(x, root);
}

void BinarySearchTree::preOrderTraversal()
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	preOrderTraversal(root);
}

void BinarySearchTree::inOrderTraversal()
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	inOrderTraversal(root);
}

void BinarySearchTree::postOrderTraversal()
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	postOrderTraversal(root);
}

void BinarySearchTree::levelOrderTraversal()
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	levelOrderTraversal(root);
}

int BinarySearchTree::internalPathlength()
{
	/*
	if (root != nullptr) {
		return internalPathlength(root, 0, 1);
	}
	else {
		cout << "Error: Root is a nullptr." << endl;
		return -1;
	}*/
	if (isEmpty())
		cout << "Empty tree" << endl;
	return internalPathlength(root, 0);
}

int BinarySearchTree::countNodes()
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	return countNodes(root);
}

bool BinarySearchTree::minimalHeight()
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	return minimalHeight(root);
}

int BinarySearchTree::numberOfTwigs()
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	return numberOfTwigs(root);
}



void BinarySearchTree::insert(const int& x, BinaryNode*& t)
{
	if (t == nullptr)
		t = new BinaryNode{ x, nullptr, nullptr };
	else if (x < t->element)
		insert(x, t->left);
	else if (t->element < x)
		insert(x, t->right);
	else
		;  // Duplicate; do nothing
}


void BinarySearchTree::insert(int&& x, BinaryNode*& t)
{
	if (t == nullptr)
		t = new BinaryNode{ std::move(x), nullptr, nullptr };
	else if (x < t->element)
		insert(std::move(x), t->left);
	else if (t->element < x)
		insert(std::move(x), t->right);
	else
		;  // Duplicate; do nothing
}

void BinarySearchTree::remove(const int& x, BinaryNode*& t)
{
	if (t == nullptr)
		return;   // Item not found; do nothing
	if (x < t->element)
		remove(x, t->left);
	else if (t->element < x)
		remove(x, t->right);
	else if (t->left != nullptr && t->right != nullptr) // Two children
	{
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else
	{
		BinaryNode* oldNode = t;
		t = (t->left != nullptr) ? t->left : t->right;
		delete oldNode;
	}
}

BinaryNode* BinarySearchTree::findMin(BinaryNode* t) const
{
	if (t == nullptr)
		return nullptr;
	if (t->left == nullptr)
		return t;
	return findMin(t->left);
}

BinaryNode* BinarySearchTree::findMax(BinaryNode* t) const
{
	if (t != nullptr)
		while (t->right != nullptr)
			t = t->right;
	return t;
}

bool BinarySearchTree::contains(const int& x, BinaryNode* t) const
{
	if (t == nullptr)
		return false;
	else if (x < t->element)
		return contains(x, t->left);
	else if (t->element < x)
		return contains(x, t->right);
	else
		return true;    // Match
}

void BinarySearchTree::makeEmpty(BinaryNode*& t)
{
	if (t != nullptr)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = nullptr;
}


void BinarySearchTree::printTree(BinaryNode* t) const
{
	if (t != nullptr)
	{
		printTree(t->left);
		cout << t->element << endl;
		printTree(t->right);
	}
}

BinaryNode* BinarySearchTree::clone(BinaryNode* t) const
{
	if (t == nullptr)
		return nullptr;
	else
		return new BinaryNode{ t->element, clone(t->left), clone(t->right) };
}

void BinarySearchTree::preOrderTraversal(BinaryNode* t) const
{
	if (t != nullptr)
	{
		cout << t->element << endl;
		preOrderTraversal(t->left);
		preOrderTraversal(t->right);
	}
}

void BinarySearchTree::inOrderTraversal(BinaryNode* t) const
{
	if (t != nullptr)
	{
		inOrderTraversal(t->left);
		cout << t->element << endl;
		inOrderTraversal(t->right);
	}
}

void BinarySearchTree::postOrderTraversal(BinaryNode* t) const
{
	if (t != nullptr)
	{
		postOrderTraversal(t->left);
		postOrderTraversal(t->right);
		cout << t->element << endl;
	}
}

void BinarySearchTree::levelOrderTraversal(BinaryNode* t) const
{
	if (t != nullptr)
	{
		int h = height(root);
		std::cout << "Height of the tree is: " << h << std::endl;
		int i;
		for (i = 1; i <= h; i++)
			CurrentLevel(root, i);
	}
}

//Fra Simon
int BinarySearchTree::internalPathlength(BinaryNode* t, int level, int node) const
{
	int nodesL = 0;
	int nodesR = 0;
	if (t != nullptr) {
		if (t->left != nullptr)
			nodesL = 1;
		if (t->right != nullptr)
			nodesR = 1;
		return internalPathlength(t->left, level + 1, nodesL) + internalPathlength(t->right, level + 1, nodesR) + level * node;
	}
	else
		return 0;
}

//Fra nettet
int BinarySearchTree::internalPathlength(BinaryNode* t, int level) const
{
	if (t != nullptr) {
		return (level + internalPathlength(t->right, level + 1) + internalPathlength(t->left, level + 1));
	}
	else
		return 0;
}

int BinarySearchTree::height(BinaryNode* t) const
{
	if (t != nullptr) {
		int lheight = height(t->left);
		int rheight = height(t->right);
		if (lheight > rheight) {
			return(lheight + 1);
		}
		else {
			return(rheight + 1);
		}
	}
	return 0;
}

int BinarySearchTree::countNodes(BinaryNode* t) const
{
	if (t != nullptr) {
		int sum = 0;
		sum += 1;
		sum += countNodes(t->left);
		sum += countNodes(t->right);
		return sum;
	}
	return 0;
}

bool BinarySearchTree::minimalHeight(BinaryNode* t) const
{
	int nodes = countNodes(root);
	int pow2 = 0;
	for (int i = 0; i <= nodes; ++i) {
		if (pow(2, i) > nodes) {
			pow2 = i;
			break;
		}
	}
	int h = height(root);
	std::cout << pow2 << " " << h << std::endl;
	if (pow2 == h) {
		return true;
	}
	return false;
}

int BinarySearchTree::numberOfTwigs(BinaryNode* t) const
{
	int sum = 0;
	if (t != nullptr) {
		if (t->left != nullptr && t->right == nullptr) {
			return 1;
		}
		else if (t->left == nullptr && t->right != nullptr) {
			return 1;
		}
		sum += numberOfTwigs(t->left);
		sum += numberOfTwigs(t->right);
	}
	return sum;
}

void BinarySearchTree::CurrentLevel(BinaryNode* t, int level) const
{
	if (t != nullptr) {
		if (level == 1)
			cout << t->element << endl;
		else if (level > 1) {
			CurrentLevel(t->left, level - 1);
			CurrentLevel(t->right, level - 1);
		}
	}
}

