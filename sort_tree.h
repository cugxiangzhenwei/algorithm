#include<stdio.h>
#include<typeinfo>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;
template<typename T>
struct node
{
	node * left;
	node * right;
	T data;
};
template<typename T>
void print_data(T & data)
{
	char sz_format[10] = {0};
	if(typeid(T) == typeid(int) || typeid(T) == typeid(long))
		strcpy(sz_format,"%d \t");
	else if(typeid(T) == typeid(float))
		strcpy(sz_format,"%f \t");
	else if(typeid(T) == typeid(double))
		strcpy(sz_format,"%f \t");
	else if(typeid(T) == typeid(char))
		strcpy(sz_format,"%c \t");
	printf(sz_format,data);
}
template<typename T>
void mid_print(struct node<T> *t)
{
	if(t==NULL) return;
	printf("mid loop print result:\n");
	std::stack<struct node<T> *> s;
	while(t||!s.empty())
	{
		while(t)
		{
			s.push(t);
			t = t->left;
		}
		if(!s.empty())
		{
			t = s.top();
			s.pop();
			print_data(t->data);
			t = t->right;
		}
	}
	printf("\n");
}
template<typename T>
node<T> * insert(struct node<T> * root,T data)
{
	if(root==NULL)
	{
		root = new struct node<T>;
		root->left  = NULL;
		root->right = NULL;
		root->data = data;
		return root;
	}
	struct node<T> * p = root;
	struct node<T> * parent = root;
	while(p)
	{
		if(p->data > data)
		{
			parent = p;
			p = p->left;
		}
		else if(p->data < data)
		{
			parent = p;
			p = p->right;	
		}
		else
			break;

	}
	if(p) return p;
	struct node<T> * n = new struct node<T>;
	n->left  = NULL;
	n->right = NULL;
	n->data = data;
	if(parent->data > data)
		parent->left = n;
	else if(parent->data < data)
		parent->right = n;
	return n;
}

template<typename  T >
void free_tree(struct node<T> * &root)
{
	std::stack<struct node<T> *> s;
	s.push(root);
	while(!s.empty())
	{
		struct node<T> * n = s.top();
		s.pop();
		struct node<T> * l = n->left;
		struct node<T> * r = n->right;
		delete n;
		n = NULL;
		if(r)
			s.push(r);
		if(l)
			s.push(l);
	}
	root  = NULL;
}
template<typename T >
int count(struct node<T> * root)
{
	int icount = 0;
	queue< struct node<T> *> s;
	s.push(root);
	while(!s.empty())
	{
		struct node<T> * t = s.front();
		s.pop();
		icount ++;
		if(t->left)
			s.push(t->left);
		if(t->right)
			s.push(t->right);
	}
	return icount;
}
