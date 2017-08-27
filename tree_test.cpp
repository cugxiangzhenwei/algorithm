#include"my_tree.h"
bool test_case2()
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
	create_tree(arry,root,icount);
	printf("tree node count:%d\n",count(root));
	delete []arry;
	arry = NULL;
	breadth_print(root);
	prev_print(root);
	mid_print(root);
	post_print(root);
	free_tree(root);
	return true;
}
void test_case1()
{
	{
		int arry[] = {1,2,3,4,5,6,7};
		struct node<int> * root = NULL;
		int ilen = sizeof(arry)/sizeof(int);
		create_tree(arry,root,ilen);
		printf("tree node count:%d\n",count(root));
		breadth_print(root);
		prev_print(root);
		mid_print(root);
		post_print(root);
		printf("begin insert data:\n");
		insert_tree(root,8);
		printf("after insert data:\n");
		breadth_print(root);
		prev_print(root);
		mid_print(root);
		post_print(root);
		free_tree(root);
		printf("\n");
	}
	{
		char arry[] = {'A','B','C','D','E','F','G','H'};
		struct node<char> * root = NULL;
		int ilen = sizeof(arry)/sizeof(char);
		create_tree(arry,root,ilen);
		breadth_print(root);
		prev_print(root);
		mid_print(root);
		post_print(root);
		free_tree(root);
		printf("\n");
	}
}

int main(int,char *[])
{
	bool bcontinue = true;
	while(bcontinue)
	{
		bcontinue = test_case2();
	}
	printf("exit test!\n");
	return 0;
}
