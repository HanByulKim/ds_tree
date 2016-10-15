#pragma once
#include <iostream>
#include "Node.h"

template <typename T>
class Tree{
public:
	Tree(){	}


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
	void insert(T x){ insert(x, root) }
	void insert(T x, Node<T>* t){
		if (t == NULL)
			t = new Node<T>(x);
		else if (x < t->n) insert(x, t->left);
		else if (x > t->n) insert(x, t->right);
		else throw std::out_of_range;
	}
	void remove(T x){
		remove(x, root);
	}
	void remove(T x, Node<T>* t){
		Node<T>* target = find(x, t);
		
		if (target == NULL) return NULL;
		else if (target->left == NULL && target->right == NULL) delete target; // is leaf
		else if (target->left != NULL && target->right != NULL){
			target->n = findMin(target->right)->n;
			remove(target->n, target->right);
		}
		else{
			Node<T>* old = target;
			target = (t->left != NULL) ? t->left : t->right;
			delete old;
		}
	}
 
	bool isEmpty(Node<T>* idx){ return !idx; }
private:
	Node<T>* root;
};