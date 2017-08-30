#include<stdio.h>
#include<typeinfo>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;
enum Blance_Factor_type
{
	BF_LG = 1,
	BF_EQ = 0,
	BF_RG = -1
};
template<typename T>
struct node
{
	node * left;
	node * right;
	T data;
	int bf;
};
template<typename T>
void print_data(T & data,int bf)
{
	char sz_format[20] = {0};
	if(typeid(T) == typeid(int) || typeid(T) == typeid(long))
		strcpy(sz_format,"%d(bd:%d)  ");
	else if(typeid(T) == typeid(float))
		strcpy(sz_format,"%f(bd:%d)  ");
	else if(typeid(T) == typeid(double))
		strcpy(sz_format,"%f(bd:%d)  ");
	else if(typeid(T) == typeid(char))
		strcpy(sz_format,"%c(bd:%d)  ");
	printf(sz_format,data,bf);
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
		print_data(t->data,t->bf);
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
			print_data(t->data,t->bf);
			t = t->right;
		}
	}
	printf("\n");
}
template<typename T>
void swap_data(T & t1 ,T & t2)
{
	T t = t1;
	t1 = t2;
	t2 = t;
}
template<typename T>
void rote_to_left(struct node<T> *  &p)
{
	struct node<T> * R = p->right;
	if(R->left!=NULL)
	{
		swap_data(R->data,R->left->data);
		struct node<T> * t = R->right;
		R->right= R->left;
		R->left = t;
		R->bf = 0 - R-> bf;
	}
	p->right = R->left;
	R->left = p;
	R->bf +=1;
	p = R;
	if(p->left->left==NULL && p->left->right==NULL)
		p->left->bf = 0;
	else if(p->left->left!=NULL && p->left->right!=NULL)
		p->left->bf = p->left->left->bf - p->left->right->bf;
	else if(p->left->left!=NULL && p->left->right ==NULL)
			p->left->bf = 1;
	else
		p->left->bf = -1;
}
template<typename T>
void rote_to_right(struct node<T> *  &p)
{
	struct node<T> * L = p->left;
	p->left = L->right;
	L->right = p;		
	L->bf -=1;
	p = L;
	if(p->right->left==NULL && p->right->right==NULL)
		p->right->bf = 0;
	if(p->right->left!=NULL && p->right->right!=NULL)
		p->right->bf = p->right->left->bf - p->right->right->bf;	
	else if(p->right->left!=NULL && p->right->right ==NULL)
			p->right->bf = 1;
	else
		p->right->bf = -1;
}
template<typename T>
bool insert(struct node<T> * & root, const T & data,bool & btaller)
{
	if(root ==NULL)
	{
		struct node<T> * p = new struct node<T>;
		p->left = p->right = NULL;
		p->data = data;
		p->bf = 0;
		root = p;		
		btaller = true;
		return true;
	}

	if(data < root->data)
	{
		bool b = insert(root->left,data,btaller);
		if(!b) 
		{
			btaller = false;
			return false;
		}
		if(btaller)
		{
			root->bf +=1;
			switch(root->bf -1)
			{
				case BF_LG:
				{
					rote_to_right(root);
				}
				case BF_RG:
				{
					printf("should't come here:%d,%s\n",__LINE__,__FUNCTION__);
					rote_to_left(root);
					btaller = false;
				}
			}
			return true;
		}
	}
	else if(data > root->data)
	{
		bool b = insert(root->right,data,btaller);
		if(!b) 
		{
			btaller = false;
			return false;
		}
		if(btaller)
		{
			root->bf -=1;
			switch(root->bf + 1)
			{
				case BF_LG:
				{
					printf("should't come here:%d,%s\n",__LINE__,__FUNCTION__);
					rote_to_right(root);
				}
				case BF_RG:
				{
					rote_to_left(root);
					btaller = false;
				}
			}
			return true;
		}
	}

	 // data == root->data
	btaller = false;
	return false;	
}
