/*10.43-计数排序*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#define MAXSIZE 100//待排顺序表最大长度
int c[MAXSIZE];
int a[MAXSIZE];
int main()
{
	int i = 0;
	int tmp;
	while (scanf("%d",&tmp)!=EOF)
	{
		a[i] = tmp;
		i++;
	}
	int count = i;
	int j;
	for (j = 0; j < count; j++) {
		for (i = 0; i < count; i++) {
			if (i != j && a[i] < a[j])
				c[j]++;
		}
	}
	for (j = 0; j < count; j++) {
		printf("%d ", c[j]);
	}
	return 0;
}
