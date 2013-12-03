#ifndef BINARYTREEITERATOR_H
#define BINARYTREEITERATOR_H


template <typename T>class BinaryTreeNode;  // Forward reference.

template <typename T>
class BinaryTreeIterator { 
public:
    BinaryTreeIterator(BinaryTreeNode<T>* pInitialNode) : 
       m_pCurrent(pInitialNode)
       {}

    T & operator *() { 
		T element = (*m_pCurrent).element();
		return element;	    
    } 
    
	BinaryTreeNode<T> * node() {
		return m_pCurrent;
	}

    
	bool operator ==(BinaryTreeIterator<T> other) const; 
	bool operator !=(BinaryTreeIterator<T> other) const; 
	
	// Iterator movement.
    bool forth();	
	bool downLeft();
    bool downRight();
    bool up();
    
     
private:   	
	BinaryTreeNode<T>* m_pCurrent;         // Pointer to the current node
};

template <typename T>
bool BinaryTreeIterator<T> :: forth() { 	
	bool moved = false;
	BinaryTreeIterator<T> parent = m_pCurrent->parent();
     
     if (parent.node() != 0) {	    
		BinaryTreeIterator<T> rightChild = parent.node()->rightChild();        
        if (rightChild.node() != 0) {
			moved = true;
            m_pCurrent = rightChild.node();
        }
     }   
	 return moved;
}
	
template <typename T>
bool BinaryTreeIterator<T> :: operator ==(const BinaryTreeIterator<T> other) const { 
     return m_pCurrent == other.m_pCurrent;  
}

template <typename T>
bool BinaryTreeIterator<T> :: operator !=(const BinaryTreeIterator<T> other) const {
     return m_pCurrent != other.m_pCurrent;   
}

template <typename T>
bool BinaryTreeIterator<T> :: downLeft() {    
	
	if (m_pCurrent != 0 && m_pCurrent->leftChild() != 0) {
		BinaryTreeIterator<T> iter = m_pCurrent->leftChild();		
		m_pCurrent = iter.node();
		return true;
	}	
	return false;
}

template <typename T>
bool BinaryTreeIterator<T> :: downRight() {     	
	if (m_pCurrent != 0 && m_pCurrent->rightChild() != 0) {
		BinaryTreeIterator<T> iter = m_pCurrent->rightChild();		
		m_pCurrent = iter.node();
		return true;
	}	
	return false;
}

template <typename T>
bool BinaryTreeIterator<T> :: up() {	 
	if (m_pCurrent != 0 && m_pCurrent->parent() != 0) {
		BinaryTreeIterator<T> iter = m_pCurrent->parent();	
		m_pCurrent = iter.node();	
		return true;
	}	
	return false;
}


#include "BinaryTreeNode.h"

#endif 
