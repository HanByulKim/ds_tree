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
		if (isEmpty(itr)) return;

	}
	bool isEmpty(Node<T>* idx){ return !idx; }
};