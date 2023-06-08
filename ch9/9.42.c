/*9.42-9.43 Trie 树插入删除和查找*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAXLEN 20
typedef struct tree {
	int exist;
	char s[MAXLEN];
}tree;
tree s[MAXLEN];
int result[MAXLEN];
int main()
{
	int op;
	int i = 0;
	int k;
	char temp[MAXLEN];
	int count = 0;
	while (scanf("%d %s",&op,temp) != EOF)
	{
		if (op == 1) {
			strcpy(s[i].s, temp);
			s[i].exist = 1;
			i++;
		}
		else if (op == 2) {
			for (k = 0; k < MAXLEN; k++) {
				if (strcmp(s[k].s, temp)==0)
					s[k].exist = 0;
			}
		}
		else if (op == 3) {
			for (k = 0; k < MAXLEN; k++) {
				if (strcmp(s[k].s, temp)==0 && s[k].exist == 1)
					result[count] = 1;
			}
			count++;
		}
	}
	for (i = 0; i < count; i++) {
		if (result[i] == 1)
			printf("True\n");
		else
			printf("False\n");
	}
	return 0;
}

