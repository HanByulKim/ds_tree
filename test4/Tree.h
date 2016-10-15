#pragma once
#include <iostream>
#include "Node.h"

template <typename T>
class Tree{
public:
	Tree(){	}

	Node<T>* root;

	void preorder(Node<T>* itr){
		if (isEmpty(itr)) return;
		std::cout << itr->n << " "; // visit
		preorder(itr->left);
		preorder(itr->right);
	}
	void postorder(Node<T>* itr){
		if (isEmpty(itr)) return;
		postorder(itr->left);
		postorder(itr->right);
		std::cout << itr->n << " ";
	}
	void inorder(Node<T>* itr){
		if (isEmpty(itr->left) && isEmpty(itr->right)) // if leaf?
			std::cout << itr->n << " ";
		else{
			inorder(itr->left);
			inorder(itr->right);
		}
	}
	Node<T>* find(T x){
		return find(x, root);
	}
	Node<T>* find(T x, Node<T>* t){
		if (t == NULL) return NULL;
		else if (x < t->n) find(x, t->left);
		else if (x > t->n) find(x, t->right);
		else return t;
	}
	Node<T>* findMin(){
		return findMin(root);
	}
	Node<T>* findMin(Node<T>* t){
		if (t == NULL) return NULL;
		else if (t->left == NULL) return t;
		else return findMin(t->left);
	}
	Node<T>* findMax(){
		return findMax(root);
	}
	Node<T>* findMax(Node<T>* t){
		if (t == NULL) return NULL;
		else if (t->right == NULL) return t;
		else return findMax(t->right);
	}
 
	bool isEmpty(Node<T>* idx){ return !idx; }
};