
#ifndef STRINGBST_H
#define STRINGBST_H

#include <string>
using std::string;


class StringBST {
public:
	StringBST();
	StringBST(string input[], int size);
	~StringBST();
	void print();
	bool contains(string input);
	void add(string input);
	int size();
	bool isEmpty();
	void clear();
	bool remove(string target);
	string getMin();
	string getMax();
	void removeMin();
	void removeMax();
	
private:
	struct TreeNode {
		string key;
		int count;
		TreeNode *left;
		TreeNode *right;
	};
	TreeNode *BSTroot;
	int nodeCount;
	TreeNode *newTreeNode(string input);
	void postOrderDelete(TreeNode *node);
	void inOrderPrint(TreeNode *node);
	TreeNode *insert(TreeNode *node, string input);
	bool contains(TreeNode *node, string input);
	bool remove(TreeNode *node, TreeNode *parent, string target, bool left);
	string greatestSmaller(TreeNode *node);
	string getMin(TreeNode *node);
	string getMax(TreeNode *node);





};
#endif