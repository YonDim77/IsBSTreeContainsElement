#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

class Node
{
public:
	Node(int value, Node* left, Node* right)
	{
		this->value = value;
		this->left = left;
		this->right = right;
	}

	int getValue() const
	{
		return value;
	}

	Node* getLeft() const
	{
		return left;
	}

	Node* getRight() const
	{
		return right;
	}

	void printNode() const 
	{
		if (this == nullptr) 
			return;
	
	    cout << getValue() << " ";
		left->printNode();
		right->printNode();	
	}

private:
	int value;
	Node* left;
	Node* right;
};

class BinarySearchTree
{
public:
	static bool contains(const Node& root, int value)
	{
		if (&root == nullptr) return false;

		if (root.getValue() == value)
			return true;
		else
		{
			if (contains(*(root.getLeft()), value))
				return true;
			if (contains(*(root.getRight()), value))
				return true;
		}
		
	}
};

#ifndef RunTests
int main()
{
	Node n1(1, NULL, NULL);
	Node n3(3, NULL, NULL);
	Node n2(2, &n1, &n3);

	if (BinarySearchTree::contains(n2, 3)) cout << "True" << endl;
	else  cout << "False" << endl;
	
	n2.printNode();

}
#endif