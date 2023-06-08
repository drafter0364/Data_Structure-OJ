/*9.31-二叉排序树*/
#include <stdio.h>
#define MAXLEN 20

void checkleft(int k,int value);
void checkright(int k, int value);
int val[MAXLEN];
int left[MAXLEN];
int right[MAXLEN];
int result = 1;
int main()
{

	int c;
	int i = 0;
	while(scanf("%d %d %d\n", &val[i], &left[i], &right[i])!=EOF)
		i++;

	int num = i;
	for (i = 0; i < num; i++) {
		if (left[i] != -1 && val[i] < val[left[i]] || right[i] != -1 && val[i] > val[right[i]])
		{
			result = 0;
			printf("0");
			return 0;
		}
	}

	for (i = 0; i < num; i++)
	{
		checkleft(left[i], val[i]);
		checkright(right[i], val[i]);
	}
	printf("%d", result);

	return 0;
	
}

void checkleft(int k, int value) {
	if (k == -1)
		return;
	else if (k != -1 && val[k] > value)
		result = 0;
	if (left[k] != -1) {
		if (val[left[k]] > value)
			result = 0;
		else
			checkleft(left[k], value);
	}
	if (right[k] != -1) {
		if (val[right[k]] > value)
			result = 0;
		else
			checkleft(right[k], value);
	}

}
void checkright(int k, int value) {
	if (k == -1)
		return;
	else if (k != -1 && val[k] < value)
		result = 0;
	if (left[k] != -1) {
		if (val[left[k]] < value)
			result = 0;
		else
			checkright(left[k], value);
	}
	if (right[k] != -1) {
		if (val[right[k]] < value)
			result = 0;
		else
			checkright(right[k], value);
	}
}