#pragma once
#include <iostream>
template<typename T>
class Node{
public:
	Node(){}
	Node(T data) : n(data), left(NULL), right(NULL){}
	Node(T data, Node* lt, Node* rt) : n(data), left(lt), right(rt){}

	T n;
	Node* left;
	Node* right;
	int height;
};