#pragma once

#include <vector>
#include <string>
#include "iostream"
#include <functional>
#include<algorithm>

using namespace std;

class AVLTree
{
	struct Node
	{
		string e;
		Node* l;
		Node* r;
		int h;

		Node(string e) : e(e), l(nullptr), r(nullptr), h(0) {}


		static int height(Node* n) { return n == nullptr ? -1 : n->h; }

		void updateH()
		{
			h = max(Node::height(l), Node::height(r)) + 1;
		}
	};


	Node* root;
	int lenght;

	//function<R(T)> key;

	//Compra strings mayor o menor

	bool EsNumero(string s) {
		int cont = 1;
		for (char e : s) {

			if (!(e >= 48 && e <= 57)) {

				return 0; break;
			}

		}
		return 1;

	}

	bool ComparaStrings(string a, string b) {

		if (EsNumero(a)) {
			int num1, num2;

			num1 = atoi(a.c_str());
			num2 = atoi(b.c_str());

			return (num2 > num1);
		}
		else {
			int numen = a.size();
			if (b.size() < numen) numen = b.size();

			for (int i = 0; i < numen; i++) {

				if (a[i] > b[i]) { return 0; break; }
				else if (a[i] < b[i]) { return 1; break; }
				else if (a[i] == b[i]) { continue; }

			}
			if (b.size() <= a.size()) return 0;
			else { return 1; }


		}


	}


	void destroy(Node* n)
	{
		if (n != nullptr)
		{
			destroy(n->l);
			destroy(n->r);
			delete n;
		}
	}

	void rotAB(Node*& n)
	{
		Node* aux = n->l;
		n->l = aux->r;
		n->updateH();
		aux->r = n;
		n = aux;
		n->updateH();
	}
	void rotBA(Node*& n)
	{
		Node* aux = n->r;
		n->r = aux->l;
		n->updateH();
		aux->l = n;
		n = aux;
		n->updateH();
	}
	void add(Node*& n, string e)
	{
		if (n == nullptr)
		{
			n = new Node(e);
			return;
		}
		else if (ComparaStrings(e,n->e))
		{
			add(n->l, e);
		}
		else
		{

			add(n->r, e);
		}

		balance(n);
	}

	void balance(Node*& n)
	{
		int delta = Node::height(n->l) - Node::height(n->r);

		if (delta < -1)
		{
			if (Node::height(n->r->l) > Node::height(n->r->r))
			{
				rotAB(n->r);
			}
			rotBA(n);
		}
		else if (delta > 1)
		{
			if (Node::height(n->l->r) > Node::height(n->l->l))
			{
				rotAB(n->l);
			}
			rotAB(n);
		}
	}
public:

	AVLTree() : root(nullptr), lenght(0) {}
	~AVLTree() { destroy(root); }

	int Lenght() { return lenght; }
	int Height() { return Node::height(root); }

	void Add(string e)
	{
		add(root, e);
		++lenght;
	}

};
