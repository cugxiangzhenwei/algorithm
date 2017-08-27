#include<stdio.h>
#include<typeinfo>
#include<string.h>
#include<stack>
#include<map>
#include<queue>
using namespace std;
template< typename T>
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
void prev_print(struct node<T> *t)
{
	if(t==NULL) return;

	printf("prev loop print result:\n");
	std::stack<struct node<T> *> s;
	s.push(t);
	while(!s.empty())
	{
		struct node<T> * n = s.top();
		s.pop();
		print_data(n->data);
		if(n->right)
			s.push(n->right);
		if(n->left)
			s.push(n->left);
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
void post_print(struct node<T> *t)
{
	if(t==NULL) return;
	printf("post loop print result:\n");
	std::stack<struct node<T> *> s;
	std::map<struct node<T>*,bool> m;
	while(t || !s.empty())
	{
		while(t)
		{
			s.push(t);
			t = t->left;
		}	
		if(!s.empty())
		{
			t = s.top();	
			if(m[t] == false)
			{
				m[t] = true;
				t = t->right;
			}		
			else
			{
				print_data(t->data);
				s.pop();
				t = NULL;
			}	
		}
	}
	printf("\n");
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
void insert_tree(struct node<T> * root,T data)
{
	struct node<T> * tn = new struct node<T>;
	tn->data = data;
	tn->left = NULL;
	tn->right = NULL;	
	queue< struct node<T> *> s;
	s.push(root);
	while(!s.empty())
	{
		struct node<T> * t = s.front();
		s.pop();
		if(t->left == NULL)
		{
			t->left = tn;
			break;
		}
		else if(t->right ==NULL)
		{
			t->right = tn;
			break;
		}
		else
		{
			s.push(t->left);
			s.push(t->right);
		}

	}
}
template<typename T>
void create_tree(T arry[],struct node<T> * &root,int ilen)
{
	if(ilen <=0) return;
	struct node<T> ** ta = new struct node<T> *[ilen];
	for(int i=0;i<ilen;i++)
	{
		struct node<T> * pt = new struct node<T>;
		struct node<T> & t = *pt;
		ta[i] = pt;
		t.left = NULL;
		t.right = NULL;
		t.data = arry[i];
	}
	int im = ilen/2 -1;
	int i = 0;
	for(i=0;i< im; i++)
	{
		ta[i]->left  = ta[2*i+1];
		ta[i]->right = ta[2*i+2];	
	}
	if(2*i+1 <ilen)
		ta[i]->left = ta[2*i+1];
	if(2*i+2 <ilen)
		ta[i]->right = ta[2*i+2];
	root = *ta;
	delete[]ta;
	ta = NULL;
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
