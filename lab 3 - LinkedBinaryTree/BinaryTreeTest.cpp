#include "LinkedBinaryTree.h"
#include "BinaryTreeIterator.h"

#include <iostream>

using namespace std;


int main() {	

	LinkedBinaryTree<int, BinaryTreeIterator<int>> myTree(10);

	myTree.insertItem(5, myTree.root(), myTree.parent(myTree.root()) );
	myTree.insertItem(15, myTree.root(), myTree.parent(myTree.root()) );
	myTree.insertItem(25, myTree.root(), myTree.parent(myTree.root()) );
	myTree.insertItem(35, myTree.root(), myTree.parent(myTree.root()) );
    

	BinaryTreeIterator<int> iter = myTree.root();
	
	iter.downRight();
	iter.downRight();
	iter.downRight();
	
	cout << (*iter) << endl;

	cout << myTree.depth( iter ) << endl;
	cout << myTree.depthNonRecursive(iter) << endl;
	cout << myTree.depthNonRecursive(iter) << endl;


	cout << endl << endl;
	BinaryTreeIterator<int> tempIter = myTree.treeMinimum(iter);
	cout << tempIter.node() << endl << endl;
	system("PAUSE");
	
}
