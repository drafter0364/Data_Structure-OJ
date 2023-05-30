/*7.25-判断有向图是否存在回路*/
#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 30
int exist[MAXLEN];
int innum[MAXLEN];
int loop(int s[], int fst[], int lst[], int vexnum, int edgenum);
int If_in_zero(int innum[], int number);
int main()
{
	int vexnum;
	int edgenum;
	scanf("%d", &vexnum);
	getchar();
	char c;
	int elem;
	int s[MAXLEN];
	int fst[MAXLEN];
	int lst[MAXLEN];

	int i = 0;
	do
	{
		scanf("%d", &elem);
		s[i++] = elem;
	} while ((c = getchar()) != '\n');
	edgenum = i - 1;
	i = 0;
	do
	{
		scanf("%d", &elem);
		fst[i++] = elem;
	} while ((c = getchar()) != '\n');
	i = 0;
	do
	{
		scanf("%d", &elem);
		lst[i++] = elem;
	} while ((c = getchar()) != '\n ' && c != EOF);

	for (i = 0; i < MAXLEN; i++)
	{
		innum[i] = 0;
		exist[i] = 1;
	}

	int output;
	output = loop(s, fst, lst, vexnum, edgenum);
	printf("%s", (output) ? "yes" : "no");
	return 0;
}

int loop(int s[], int fst[], int lst[], int vexnum, int edgenum)
{

	innum[0] = 0;
	int i;
	int vex;
	for (i = 1; i <= edgenum; i++)
	{
		vex = s[i];
		innum[vex]++;
	}
	int result;
	int first;
	int last;
	while ((result = If_in_zero(innum, vexnum)))
	{
		first = fst[result];
		last = lst[result] - 1;
		exist[result] = 0;
		if (first > last)
			continue;
		else
		{
			for (i = first; i <= last; i++)
			{
				vex = s[i];
				innum[vex]--;
			}
		}
	}
	for (i = 1; i <= vexnum; i++)
		if (exist[i] == 1)
			return 1;
	return 0;
}
int If_in_zero(int innum[], int number)
{
	int i;
	for (i = 1; i <= number; i++)
		if (innum[i] == 0 && exist[i] == 1)
			return i;
	return 0;
}