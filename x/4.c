/*4-去除C程序中的注释*/

#include <stdio.h>

int main()
{
	int state = 0;//0:正常读取，1：注释内，2：字符串内
	char c;
	while ((c = getchar()) != EOF)
	{
		if (state == 0) {
			if (c == '"') {
				state = 2;
				putchar(c);
			}
			else if (c == '/') {
				char b = c;
				c = getchar();
				if (c == '*')
					state = 1;
				else {
					putchar(b);
					putchar(c);
				}
			}
			else {
				putchar(c);
			}
		}
		else if (state == 1) {
			if (c == '*') {
				char b = c;
				c = getchar();
				if (c == '/')
					state = 0;
			}
		}
		else if (state == 2) {
			if (c == '\\')
			{
				char b = c;
				c = getchar();
				putchar(b);
				putchar(c);
			}
			else if (c == '"') {
				putchar(c);
				state = 0;
			}
			else {
				putchar(c);
			}
		}
	}
	return 0;
}