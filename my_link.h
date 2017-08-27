#include<stdio.h>
#include<typeinfo>
#include<string.h>
template< typename T>
struct node
{
	node * next;
	T data;
};
template<typename T>
void print(struct node<T> *link)
{
	char sz_format[10] = {0};
	if(typeid(T) == typeid(int) || typeid(T) == typeid(long))
		strcpy(sz_format,"%d \t");
	else if(typeid(T) == typeid(float))
		strcpy(sz_format,"%f \t");
	else if(typeid(T) == typeid(double))
		strcpy(sz_format,"%f \t");
	while(link)
	{
		printf(sz_format,link->data);
		link = link->next;
	}
	printf("\n");
}
template<typename T>
void free(struct node<T> *link)
{
	while(link)
	{
		struct node<T> *p = link;
		link = link->next;
		delete p;
	}
}

template<typename T>
int link_size(struct node<T> *link)
{
	int si = 0;
	while(link)
	{
		link = link->next;
		si++;
	}
	return si;
}

template<typename T>
struct node<T> * link_reverse(struct node<T> *link)
{
	struct node<T> *n = NULL;
	struct node<T> *last = link;
	while(link)
	{
		struct node<T> *p = link->next;
		link->next = n;
		n = link;
		link = p;
		if(link!=NULL)
			last = link;
	}
	return last;
}
template<typename T>
node<T> * build_link(T arry[],int ilen)
{
	if(ilen ==0) return NULL;
	struct node<T> * root = new node<T>;
	root->data = arry[0];
	root->next = NULL;
	struct node<T> * now = root;
	for(int i = 1; i<ilen; i++)
	{
		struct node<T> * n = new node<T>;
		n->next = NULL;
		n->data = arry[i];
		now->next = n;
		now = n;
	}
	return root;
}
template<typename T>
void link_sort_select(struct node<T> *link)
{
	struct node<T> * p = link;
	while(p)
	{
		struct node<T> * min = p;
		struct node<T> * q = p->next;
		while(q)
		{
			if(min->data > q->data)
				min = q;
			q = q->next;
		}
		if(p != min)
		{
			T t = p->data;
			p->data = min->data;
			min->data = t;
		}
		p = p->next;
	}
}

template<typename T>
node<T> * link_sort_select_v2(struct node<T> *link)
{
	struct node<T> * p = link;
	struct node<T> * p_prev = NULL;
	struct node<T> * root = NULL;
	while(p)
	{
		struct node<T> * min = p;
		struct node<T> * q_prev = p;
		struct node<T> * q = p->next;
		struct node<T> * min_prev = NULL;
		while(q)
		{
			if(min->data > q->data)
			{
				min_prev = q_prev; 
				min = q;
			}
			q_prev = q;
			q = q->next;
		}
		if(p != min && min_prev!=NULL)
		{
			if(p_prev)
				p_prev->next = min;
			min_prev->next = p;
			{
				struct node<T> * mn= min->next;
				min->next = p->next;	
				p->next = mn;
			}	
			p = min;
			min = NULL;
		}
		if(NULL == root)
			root = p;

		p_prev = p;
		p = p->next;
	}
	return root;
}

template<typename T>
node<T> * link_sort_bubble(struct node<T> *link)
{
	struct node<T> * header  = link;
	struct node<T> * tail = NULL;
	while(header && header->next!=tail)
	{
		struct node<T> * prev = NULL;
		struct node<T> * p = header;
		while(p!=tail && p->next!=tail)
		{
			struct node<T> * q = p->next;
			if(p->data > q->data)
			{
				struct node<T> * qn = q->next;
				q->next = p;	
				if(prev)
					prev->next = q;
				else
					header = q;
				p->next = qn;
				prev = q;
			}
			else
			{
				prev = p;
				p = p->next;
			}
		}
		tail = p;
	}
	link = header;
	return link;
}

