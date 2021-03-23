#include <stdio.h>
#include <string.h>
#include <algorithm>

int num[12] = {0,26,325,2600,14950,65780,230230,0,0,0,0};
int n, sum, flag;
char tmp[11], str[11];

void cal(int a,int b,int m)
{
	int i;

	for(i = a; i <= b; i++)
	{
		if(flag)
			return ;
		tmp[n-m] = i+'a'-1;
		if(m==1)
		{
			sum++;
			tmp[n] = '\0';
			if(strcmp(tmp,str)==0)
			{
				flag = 1;
				return ;
			}
			continue;
		}
		cal(i+1,b+1,m-1);
	}
}

int main()
{
	int i;
	char tmp[100];

	while(scanf("%s",str)==1){
	n = strlen(str);
	strcpy(tmp,str);
	std::sort(tmp,tmp+n);
	if(strcmp(str,tmp)!=0)
	{
		puts("0");
		continue;
	}
	for(i = 1; tmp[i]; i++)
	{
		if(tmp[i]==tmp[i-1])
		{
			i = -1;
			break;
		}
	}
	if(i==-1)
	{
		puts("0");
		continue;
	}
	for(i = 0; i < n-1; i++)
		if(str[i]>=str[i+1])
		{
			printf("0\n");
			return 0;
		}
	sum = flag = 0;
	for(i = 1; i < n; i++)
		sum += num[i];
	cal(1,27-n,n);
	printf("%d\n",sum);}
	return 0;
}
