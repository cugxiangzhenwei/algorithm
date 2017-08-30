#include"blance_sort_tree.h"
void test_case1()
{
	struct node<int> * root = NULL;
	bool btaller = false;
	insert(root,1,btaller);
	breadth_print(root);

	insert(root,2,btaller);
	breadth_print(root);

	insert(root,3,btaller);
	breadth_print(root);

	insert(root,4,btaller);
	breadth_print(root);

	insert(root,5,btaller);
	breadth_print(root);

	insert(root,6,btaller);
	breadth_print(root);

	insert(root,7,btaller);
	breadth_print(root);

	insert(root,10,btaller);
	breadth_print(root);

	insert(root,9,btaller);
	breadth_print(root);
}
int main(int,char *[])
{
	test_case1();
	return 0;
}
