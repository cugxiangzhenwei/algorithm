#include<stdio.h>
int add_recu(int i,int j)
{
	int a = i^j;
	int b = i&j; 
	if(b==0)
		return a;
	return add_recu(a,b<<1);
}
int add(int i,int j)
{
	int a = i^j;
	int b = i&j;
	while(b!=0)
	{
		i = a;
		j = b<<1;
		a = i^j;
		b = i&j;
	}
	return a;
}
int multip(int a,int b)
{
	if(b==1)
		return a;
	else if(b==0)
		return 0;
	else if(b ==2)
		return a<<1;
	return add(multip(a,add(b,-1)),a);
}
int main(int,char *[])
{
	{
		int s = add(3,6);
		printf("3+6=%d\n",s);
	}
	{
		int s = add(3,7);
		printf("3+7=%d\n",s);
	}
	{
		int s = add(9,11);
		printf("9+11=%d\n",s);
	}
	{
		int m = multip(9,5);
		printf("9 *5 =%d\n",m);
	}
	{
		int m = multip(8,7);
		printf("8 *7 =%d\n",m);
	}
	{
		int m = multip(10000,998);
		printf("10000 *998 =%d\n",m);
	}
	{
		int m = add(7,-3);
		printf("7 -3 =%d\n",m);
	}
	{
		int m = add(7,-4);
		printf("7 -4 =%d\n",m);
	}
	return 0;
}

