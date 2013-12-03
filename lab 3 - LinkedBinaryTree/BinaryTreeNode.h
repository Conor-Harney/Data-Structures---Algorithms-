#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H


// Forward references.
template <typename T>class Container;
template <typename T>class BinaryTreeIterator;

template <typename T>
class BinaryTreeNode {

public:    
    // Constructor
    BinaryTreeNode(T element, Container<T>* pContainer=0, 
             BinaryTreeNode<T>* pParent=0); 
         
    // Generic Position functions
    virtual T element () const;
    virtual Container<T>* container() const;    
    virtual void setElement(T element);
    
    // TreeNode specific functions
    // Manipulators
    void setParent(BinaryTreeNode<T>* pParent); 
    void setLeftChild(BinaryTreeNode<T>* pLeft); 
    void setRightChild(BinaryTreeNode<T>* pRight); 
    
    // Accessors    
    BinaryTreeIterator<T> parent() const;
    BinaryTreeIterator<T> leftChild() const;
    BinaryTreeIterator<T> rightChild() const;        
    
private:    
    
    T d_element;    
    BinaryTreeNode<T>* m_pParent;
    BinaryTreeNode<T>* m_pLeftChild;
    BinaryTreeNode<T>* m_pRightChild;
    Container<T>* m_pContainer;           
};

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(T element, Container<T>* pContainer, 
       BinaryTreeNode<T>* pParent) :
       d_element(element), 
       m_pContainer(pContainer), 
       m_pParent(pParent),
       m_pLeftChild(0),
       m_pRightChild(0)
       {} 

template <typename T>
T BinaryTreeNode<T>::element() const {
    return d_element;    
}

template <typename T>
Container<T>* BinaryTreeNode<T>::container() const {
    return m_pContainer;   
}

template <typename T>
void BinaryTreeNode<T>::setElement(T element) {
   d_element = element;
}

template <typename T>
void BinaryTreeNode<T>::setParent(BinaryTreeNode<T>* pParent) {
   m_pParent = pParent;
}

template <typename T>
void BinaryTreeNode<T>::setLeftChild(BinaryTreeNode<T>* pLeftChild) {
   m_pLeftChild = pLeftChild;
}

template <typename T>
void BinaryTreeNode<T>::setRightChild(BinaryTreeNode<T>* pRightChild) {
   m_pRightChild = pRightChild;
}

template <typename T>
BinaryTreeIterator<T> BinaryTreeNode<T>::parent() const {
   return BinaryTreeIterator<T>(m_pParent);
}

template <typename T>
BinaryTreeIterator<T> BinaryTreeNode<T>::leftChild() const {
   return BinaryTreeIterator<T>(m_pLeftChild);
}

template <typename T>
BinaryTreeIterator<T> BinaryTreeNode<T>::rightChild() const {
   return BinaryTreeIterator<T>(m_pRightChild);   
}

#include "BinaryTreeIterator.h"
#endif

