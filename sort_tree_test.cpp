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
int main(int,char*[])
{
	bool bcontinue = true;
	while(bcontinue)
	{
		bcontinue = test_case1();
	}
	printf("exit test!\n");
}
