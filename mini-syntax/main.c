#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mini.y.h"

int main(int argc, char *argv[]) 
{
	if(argc!=2 || argv[1][strlen(argv[1])-1]!='m') 
	{
		printf("usage: %s name.m\n", argv[0]);
		exit(0);
	}			

	if(freopen(argv[1], "r", stdin)==NULL)
	{
		printf("open %s failed\n", argv[1]);
		exit(0);
	}	

	yyparse();
	return 0;
}
