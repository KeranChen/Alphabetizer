#include <iostream>
#include <string>

#include "StringBST.h"

using namespace std;

/*
The default constructor takes no parameters and initializes an
            empty binary search tree.  
*/
StringBST::StringBST() {
	BSTroot = NULL;
	nodeCount = 0;
}

/*
constructor takes an array of strings and an
            integer specifying the size of the array as parameters and
            creates a binary search tree with strings inserted in the 
            order in which they appear in the array.
*/
StringBST::StringBST(string input[], int size) {
	for (int i = 0; i < size; i++) {
		
		add(input[i]);
	}
	
	
}


/*
destructor that destroys/deletes/recycles the 
heap-allocated data associated with the current binary search 
tree.
*/
StringBST::~StringBST() {
	postOrderDelete(BSTroot);
	nodeCount = 0;
}

/*
A "print" function that takes no parameters and returns nothing. 
          It prints the binary search tree in order.  For example,
          consider a tree we might draw like this:
*/

void StringBST::print() {
	inOrderPrint(BSTroot);
	std::cout << "\n";
}

/*
A "contains" function that takes a string as a parameter, and
          returns a boolean.  It will search the binary search tree, and
          if it finds the query returns true, otherwise it will return
          false.
*/
bool StringBST::contains(string input) {
	std::cout << input
			  << " ";
	return contains(BSTroot, input);
}

/*
"add" function that takes an element (string) and adds it
          to the binary search tree in the correct location based on
          the behavior of binary search trees.  It does not return
          anything.  Your tree should be able to handle adding
          duplicate elements.  In the example tree above Horse, Swan,
          Deer, and Llama were all added multiple times.  The number
          that follows them indicates how many times (Deer has been
          added 4 times).
*/

void StringBST::add(string input) {
	//TreeNode *tmp = BSTroot;
	BSTroot = insert(BSTroot, input);
	//postOrderDelete(tmp);
	nodeCount++;
}

/*
"size" function that takes no parameters and returns an
          integer value that is the number of strings in the binary 
          search tree. This function should take duplicates into account.
          (The "size" of the tree below is 14.)
*/
int StringBST::size() {
	return nodeCount;
}

/*
"isEmpty" function that takes no parameters and returns a
          boolean value that is true if this specific instance of the
          StringBST class is empty and false otherwise.
*/
bool StringBST::isEmpty() {
	return nodeCount == 0;
}

/*
"clear" function that takes no parameters and has a void
          return type.  It makes the current binary search tree into 
          an empty binary search tree
*/

void StringBST::clear() {
	postOrderDelete(BSTroot);
	BSTroot = NULL;
	nodeCount = 0;
}

/*
"remove" function that takes a target (string) as a parameter
          and returns a boolean.  It will find the target and then proceed
          to remove one instance of it from the tree.  The boolean
          returned reflects whether or not the function was able to find
          and remove the target.  For example if we removed "Swan" from
          the example tree above, we would still have 2 instances of
          "Swan" in the resulting tree.  However if we removed "Bison"
          from the tree we would no longer have any instances of "Bison"
          in the tree. If we removed "Bird" then the remove function
          should return "false", and NOT throw an exception.
      
*/
bool StringBST::remove(string target) {
	if (!isEmpty()) {
			TreeNode *pre = NULL;
			if(remove(BSTroot, pre, target, true)) {
				nodeCount--;
				return true;
			} else {
				return false;
			}
		
	} else {
		return false;
	}
}

/*
"getMin" function that takes no parameters and returns a
          string.  It returns the left most (smallest) string in the
          binary search tree.  If the tree is empty it throws a C++
          "runtime_error" exception with the message "empty_tree".
*/

string StringBST::getMin() {
	if (isEmpty()) {
		throw runtime_error("empty_tree");
	} else {
		return getMin(BSTroot);
	}
}

/*
getMax" function that takes no parameters and returns a
          string.  It returns the right most (largest) string in the
          binary search tree.  If the tree is empty it throws a C++
          "runtime_error" exception with the message "empty_tree".
*/
string StringBST::getMax() {
	if (isEmpty()) {
		throw runtime_error("empty_tree");
	} else {
		return getMax(BSTroot);
	}
}

/*
"removeMin" function that takes no parameters and returns 
          nothing.  It removes the left most (smallest) string in the 
          binary search tree.  Similarly to "remove", "removeMin" only 
          removes one instance of the left most string. If the tree is
          empty it throws a C++ "runtime_error" exception with the
          message "empty_tree".
*/

void StringBST::removeMin() {
	string target = getMin();
	remove(target);
	return;
}

/*
"removeMax" function that takes no parameters and returns 
          nothing.  It removes the right most (largest) string in the 
          binary search tree.  Similarly to "remove", "removeMax" only 
          removes one instance of the right most string. If the tree is
          empty it throws a C++ "runtime_error" exception with the
          message "empty_tree".
*/

void StringBST::removeMax() {
	string target = getMax();
	remove(target);
	return;
}




/********************************Private*********************************/
/*
delete the tree in the PostOrder
input: TreeNode root
output: void
do it recursively
*/
void StringBST::postOrderDelete(TreeNode *node) {
	if (node == NULL) {
		return;
	}
	postOrderDelete(node->left);
	postOrderDelete(node->right);
	delete node;
}

/*
create a TreeNode 
input: string the key in the new TreeNode
ouput: a TreeNode with key as the string input
*/
StringBST::TreeNode *StringBST::newTreeNode(string input) {
	TreeNode *newNode = new StringBST::TreeNode();
	newNode->key = input;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->count = 1;
	return newNode;
}

/*
print the BSTtree in inOrder
input: nothing
output: void
*/
void StringBST::inOrderPrint(TreeNode *node) {
	std::cout << "[";
	if (node == NULL) {
		std::cout << "]";
		return ;
	}
	inOrderPrint(node->left);
	std::cout << " "
			  << node->key
			  << " "
			  << node->count
			  << " ";
	inOrderPrint(node->right);
	std::cout << "]";



}

/*
insert a string into the BST
input: string input
output: void
*/
StringBST::TreeNode *StringBST::insert(TreeNode *node, string input) {
	if (node == NULL) {
		return newTreeNode(input);
	}
	if (input == node->key) {
		node->count++;
	} else if (input > node->key) {
		node->right = insert(node->right, input);
	} else {
		node->left = insert(node->left, input);
	}
	return node;
}

/*
check wehter the bst contains this string
input: treenode root, string input
output: boolean
*/
bool StringBST::contains(TreeNode *node, string input) {
	if (node == NULL) {
		return false;
	}
	if (node->key == input) {
		return true;
	}
	if (input > node->key) {
		return contains(node->right, input);
	} else  {
		return contains(node->left, input);
	}
}

/*
remove the target string recursively
input: treeNode root, string target
output: bool
*/
bool StringBST::remove(TreeNode *node, TreeNode *parent, string target, bool left) {
	if (node == NULL) {
		return false;
	}
	if (target > node->key) {
		return remove(node->right, node, target, false);
	} else if (target < node->key) {
		return remove(node->left, node, target, true);
	} else {
		//when target == node->key
		if (node->count > 1) {
			node->count--;
			return true;
		} else {
			//when node->count == 1, we have to delete this node
			if (node->left == NULL && node->right == NULL) {
				TreeNode *tmp = node;
				if (parent == NULL) {
					BSTroot = NULL;
				} else if (left) {
					parent->left = NULL;
				} else {
					parent->right = NULL;
				}
				delete tmp;
				return true;
			} else if (node->left == NULL) {
				TreeNode *tmp = node;
				if (parent == NULL) {
					//means this node is the BSTroot
					BSTroot = node->right;
				}else if (left) {
					parent->left = node->right;
				} else {
					parent->right = node->right;
				}
				delete tmp;
				return true; 
			} else if (node->right == NULL) {
				TreeNode *tmp = node;
				if (parent == NULL) {
					//means this node is the BSTroot
					BSTroot = node->left;
				} else if (left) {
					parent->left = node->left;
				} else {
					parent->right = node->left;
				}
				delete tmp;
				return true;
			} else {
				//if node has 2 children
				node->key = greatestSmaller(node);
				return remove(node->left, node, node->key, true);
			}
		}
	}
	return false;
}

/*
find the greatestSmaller string compared to the string in the given node
input: TreeNode node
output: string
*/
string StringBST::greatestSmaller(TreeNode *node) {
	//since our assumption is we already know the node has a left child
	TreeNode *tmp = node->left;
	while (tmp->right != NULL) {
		tmp = tmp->right;
	}
	return tmp->key;
}


/*
find the smallest string in the BST recursively
input: nothing
output: the smallest string
*/
string StringBST::getMin(TreeNode *node) {
	if (node->left == NULL) {
		return node->key;
	}
	return getMin(node->left);
}


/*
find the largest string in the BST recursively
input: nothing
output: the largest string
*/
string StringBST::getMax(TreeNode *node) {
	
	if (node->right == NULL) {
		return node->key;
	}
	return getMax(node->right);
}





















