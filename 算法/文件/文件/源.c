#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char ch;
	if (fp = fopen("cad.txt", "w")) = NULL)
	{
		printf("Failure to open cad.txt");
		exit(0);
	}
	ch = getchar();
	while (ch != '\n')
	{
		fputc(ch, fp);
		ch = getchar();
	}
	fclose(fp);
	return 0;
}