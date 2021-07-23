#include<stdio.h>
#include<stdlib.h>



int main()
{
	char *p = "abcde";
	char *left = p;
	char *right = p+4;
	char t = *left;
	*left=*right;
	*right = t;
	
	
	printf("left =%s,right =%s,p =%s\n",left,right,p);

	system("pause");
	return 0;
} 
