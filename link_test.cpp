#include"my_link.h"
template<typename T>
void test_case1(T arry[],int ilen)
{
	printf("begin test case...\n");
	struct node<T> * root = build_link(arry,ilen);
	print(root);
	struct node<T> * s = link_sort_bubble(root);
	printf("sort result:\n");
	print(s);
	struct node<T> * reverse_link  = link_reverse(s);
	printf("reversed  result:\n");
	print(reverse_link);
	free(reverse_link);
	printf("end test case!\n");
	printf("----------------\n");
}
void test_case2()
{
	printf("please input node data count:\n");
	int icount = 0;
	scanf("%d",&icount);
	printf("node count:%d\n",icount);
	int *arry = new int[icount];
	for(int i=0;i<icount;i++)
		scanf("%d",&arry[i]);
	
	struct node<int> * root = build_link(arry,icount);
	print(root);
	struct node<int> * s = link_sort_bubble(root);
	printf("sort result:\n");
	print(s);
}
int main(int,char*[])
{
	{
		int arrt_int[] = {1,46,2,3,11,4,5};
		test_case1(arrt_int,sizeof(arrt_int)/sizeof(int));
	}
	{
		int arrt_int[] = {122,46,23,1,34,5};
		test_case1(arrt_int,sizeof(arrt_int)/sizeof(int));
	}
	{
		int arrt_int[] = {33,2,1,12};
		test_case1(arrt_int,sizeof(arrt_int)/sizeof(int));
	}
	{
		int arrt_int[] = {5,6,2,1};
		test_case1(arrt_int,sizeof(arrt_int)/sizeof(int));
	}
	while(1)
	{
		test_case2();
	}
	return 0;
	double arry_d[] = {3.21};
	test_case1(arry_d,sizeof(arry_d)/sizeof(double));
	float arrt_f[] = {21.9,234,0.1,23.97,33.21,0,343,3.12};
	test_case1(arrt_f,sizeof(arrt_f)/sizeof(float));
	return 0;
}
