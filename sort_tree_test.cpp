#include<stdio.h>
#include"sort_tree.h"
bool test_case1()
{
	printf("please input node data count:\n");
	int icount = 0;
	scanf("%d",&icount);
	printf("node count:%d\n",icount);
	if(icount<1) return false;

	int *arry = new int[icount];
	for(int i=0;i<icount;i++)
		scanf("%d",&arry[i]);

	struct node<int> * root = NULL;
	root = insert(root,arry[0]);
	for(int i=1;i<icount;i++)
		insert(root,arry[i]);

	delete []arry;
	arry = NULL;
	mid_print(root);
	free_tree(root);
	return true;
}
void test_case2()
{
	int arry[] = {6,2,8,1,5,3,4};
	int icount = sizeof(arry)/sizeof(int);
	struct node<int> * root = NULL;
	root = insert(root,arry[0]);
	for(int i=1;i<icount;i++)
		insert(root,arry[i]);

	breadth_print(root);
	mid_print(root);

	remove(root,4);
	breadth_print(root);
	mid_print(root);

	remove(root,2);
	breadth_print(root);
	mid_print(root);
	free_tree(root);
}
void test_case3()
{
	int arry[] = {6,2,8,1,5,3,4};
	int icount = sizeof(arry)/sizeof(int);
	struct node<int> * root = NULL;
	root = insert(root,arry[0]);
	for(int i=1;i<icount;i++)
		insert(root,arry[i]);

	breadth_print(root);
	mid_print(root);
	while(count(root)>0)
	{
		printf("input data will removed :\n");
		int data = 0;
		scanf("%d",&data);
	    root = remove(root,data);
		printf("after remove data:%d\n",data);
		breadth_print(root);
		mid_print(root);
	}
}
void test_case4()
{
	int arry[] = {3,1,5,4};
	int icount = sizeof(arry)/sizeof(int);
	struct node<int> * root = NULL;
	root = insert(root,arry[0]);
	for(int i=1;i<icount;i++)
		insert(root,arry[i]);

	breadth_print(root);
	mid_print(root);
	while(count(root)>0)
	{
		printf("input data will removed :\n");
		int data = 0;
		scanf("%d",&data);
	    root = remove(root,data);
		printf("after remove data:%d\n",data);
		breadth_print(root);
		mid_print(root);
	}
}
void test_case5()
{
	int arry[] = {4,1,5};
	int icount = sizeof(arry)/sizeof(int);
	struct node<int> * root = NULL;
	root = insert(root,arry[0]);
	for(int i=1;i<icount;i++)
		insert(root,arry[i]);

	breadth_print(root);
	mid_print(root);
	while(count(root)>0)
	{
		printf("input data will removed :\n");
		int data = 0;
		scanf("%d",&data);
	    root = remove(root,data);
		printf("after remove data:%d\n",data);
		breadth_print(root);
		mid_print(root);
	}
}
int main(int,char*[])
{
	test_case5();
	test_case4();
	test_case3();
	test_case2();
	bool bcontinue = true;
	while(bcontinue)
	{
		bcontinue = test_case1();
	}
	printf("exit test!\n");
}
