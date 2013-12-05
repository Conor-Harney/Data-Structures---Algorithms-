#include "LinkedBinaryTree.h"
#include "BinaryTreeIterator.h"

#include <iostream>
#include <stack>

using namespace std;

template <typename Iterator>
void binaryPreorder(Iterator position);
template <typename Iterator>
void nonRecursiveBinaryPreorder(Iterator position);



int main() {	

	LinkedBinaryTree<int, BinaryTreeIterator<int>> myTree(10);

	myTree.insertItem(5, myTree.root(), myTree.parent(myTree.root()) );
	myTree.insertItem(15, myTree.root(), myTree.parent(myTree.root()) );
	myTree.insertItem(25, myTree.root(), myTree.parent(myTree.root()) );
	myTree.insertItem(35, myTree.root(), myTree.parent(myTree.root()) );
    //10, 5, 15, 25, 35

	BinaryTreeIterator<int> iter2 = myTree.root();
	binaryPreorder(iter2);

	system("PAUSE");
	iter2 = myTree.root();
	nonRecursiveBinaryPreorder(iter2);
	system("PAUSE");
	iter2 = myTree.root();
	cout << myTree.getHeight(iter2) << endl;
	system("PAUSE");
}


/*
// cout << pNode->element
template <typename T, typename Iterator>
void binaryPreorder( Iterator position){
	if ( position.node() != 0) {
		T t_node = *position.node();
		T root = *position.node();
		bool loopFinished = false;
		cout 
			<< "ROOT = " 
			<< t_node.element()
			<< endl;



		while(loopFinished == false){
			if(t_node.leftChild() != 0){
				while(t_node.leftChild() != 0){ 
					cout << t_node.leftChild().node() << endl; 
					t_node = *t_node.leftChild();
					t_node = t_node;
				}
				break;
			}
			else if (t_node.parent().node()->rightChild().node() != t_node){ 
				t_node = *t_node.parent().node()->rightChild();
				cout << t_node.node() << endl;
				break;
			}
			else{
				while(t_node == t_node.parent().node()->rightChild().node()){ 
					t_node = t_node.parent().node();
					if(t_node == root.node()){ 
						loopFinished = true;	
						break;
					}
				}
				t_node = t_node.parent().node()->rightChild().node(); 
				cout << t_node << endl;
				break;
			}
		}
		

		//
		//cout root
		//=>
		//	if while node left child != null: cout node left child; node = node left child				;break;
		//	else if node's parents right child != node: node = node's parents right child; cout node	;break;
		//	else:while node == parents right child: node = node parent; if node == root:{ loop finished;	;break;}								
		//	node = nodes parent's right child; cout node												;break;
		//<=
		//

	}
}

*/








template <typename Iterator>
void binaryPreorder( Iterator position){
	/*Algorithm binaryPreorder(bt, n):
	    perform the "visit" action for node n
	    if n is an internal node {
		   {recursively traverse left subtree}
		   binaryPreorder(bt,bt.leftChild(n))	
		   {recursively traverse right subtree}
		   binaryPreorder(bt,bt.rightChild(n))	
      }
*/
	if(position.node() != 0){
		cout << position.node()->element() << endl;
	}
	if(position.node()->leftChild() != 0){
		Iterator iter = position.node()->leftChild();
		binaryPreorder(iter);
	}
	if(position.node()->rightChild() != 0){
		Iterator iter = position.node()->rightChild();
		binaryPreorder(iter);
	}
	
}

template <typename Iterator>
void nonRecursiveBinaryPreorder(Iterator position){
/*	create an empty stack
// current node is a parameter to this algorithm (usually the root
// node)
while the stack is not empty OR the current node is not NULL {
	1. while the current node is not null {
		1.1 push the current node onto the stack
		1.2 let the current node = the left child of the current node
	}
	2. if the current node is null {
		2.1 let the current node = the node on top of the stack
		2.2 pop the stack
		2.3 visit the current node
		2.4 let the current node = the right child of the current node
}*/
	stack<BinaryTreeIterator<int>> stack1;
	Iterator currentNode = position.node();
	while(stack1.empty() == false || currentNode != 0){
		while(currentNode != 0){
			stack1.push(currentNode);
			currentNode = currentNode.node()->leftChild();
		}
		if(currentNode == 0){
			currentNode = stack1.top();
			stack1.pop();
			cout << currentNode.node()->element() << endl;
			currentNode = currentNode.node()->rightChild();
		}
	}
}

