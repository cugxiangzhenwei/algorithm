#include<stdio.h>
#include<stack>
#include<math.h>
using namespace std;
void convert_10_to_binary(int num,char out[])
{
	stack<int> s;
	int quo = 0;
	int rem = 0;
	do
	{
		quo = num/2;
		rem = num%2;
		s.push(rem);
		num = quo;
	}while(quo!=0);
	
	int i = 0; 
	while(!s.empty())
	{
		out[i++] = '0' + s.top(); 
		s.pop();
	}
	out[i] = '\0';
}
int convet_binary_to_10(char input[])
{
	int ilen  = 0;
	while(input[ilen]!='\0')
		ilen++;

	printf("%s len = %d\n",input,ilen);
	int num = 0;
	for(int i = ilen-1; i >=0; i-- )
		num = num + pow(2,i) *(input[ilen-i-1]-'0'); 
	return num;
}
void test_case1()
{
	char out[20]={0};
	int num = 9;
	convert_10_to_binary(num,out);
	int iout = convet_binary_to_10(out);
	printf("%d convert result:%s,convert to 10 system:%d\n",num,out,iout);
}
void test_case2()
{
	printf("input num for convert:\n");
	int num = 0;
	scanf("%d",&num);
	char out[20]={0};
	convert_10_to_binary(num,out);
	int iout = convet_binary_to_10(out);
	printf("%d convert result:%s,convert to 10 system:%d\n",num,out,iout);
}
int main(int,char *[])
{
	test_case1();
	while(1)
	{
		test_case2();
	}
	return 0;
}
