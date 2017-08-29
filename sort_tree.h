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
void breadth_print(struct node<T> * root)
{
	printf("breadth loop result:\n");
	if(!root) return;

	queue<struct node<T> *> qu;
	qu.push(root);
	while(!qu.empty())
	{
		struct node<T> * t = qu.front();
		qu.pop();
		print_data(t->data);
		if(t->left)
			qu.push(t->left);
		if(t->right)
			qu.push(t->right);
	}
	printf("\n");
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
	if(root==NULL) return;
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
	if(root==NULL) return 0;

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
template<typename T>
node<T> * find(struct node<T> * root, const T & data)
{
	struct node<T> * p = root;
	while(p)
	{
		if(p->data == data)
			break;
		else if(p->data > data)
			p = p->left;
		else if(p->data < data)
			p = p->right;	
	}
	return p;
}
template<typename T>
bool exist(struct node<T> * root,const T & data)
{
	return find(root,data)!=NULL;
}
template<typename T>
node<T> * find_min(struct node<T> * root,struct node<T> * & min_parent)
{
	struct node<T> * p = root;
	while(p)
	{
		if(p->left ==NULL)
			break;
		else
		{
			min_parent = p;
			p = p->left;
		}
	}		
	return p;
}
template<typename T>
node<T> * find_max(struct node<T> * root,struct node<T> * & max_parent)
{
	struct node<T> * p = root;
	while(p)
	{
		if(p->right ==NULL)
			break;
		else
		{
			max_parent = p;
			p = p->right;
		}
	}		
	return p;
}
template<typename T>
node<T> * remove(struct node<T> * root,const T & data)
{
	if(data < root->data)
		root->left = remove(root->left,data);	
	else if(data > root->data)
		root->right = remove(root->right,data);	
	else
	{
		if(root->left!=NULL && root->right!=NULL)
		{
			struct node<T> * min_parent = root;
			struct node<T> * tmin = find_min(root->right,min_parent);
			root->data = tmin->data;
			struct node<T> * p = remove(tmin,tmin->data);
			if(p==NULL)
			{
				min_parent->right = NULL;
				if(root !=min_parent)
					min_parent->left = NULL;
			}
			else if(min_parent == p)
				p->right = p;
			else
				min_parent->left = p;
			return root;

		}
		else if(root->left!=NULL && root->right==NULL)
		{
			struct node<T> * p = root->left;
			delete root;
			return p;
		}
		else if(root->right!=NULL && root->left == NULL)
		{
			struct node<T> * p = root->right;
			delete root;
			return p;
		}
		else
		{
			free_tree(root);
			return NULL;
		}
	}
	return root;
}
