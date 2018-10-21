#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define	NO 0
#define	YES 1
#define	MAXLINE 1000

int main()
{
	FILE *fpin;	FILE *fpout;
	char line[1000];
	char *ptr;	int strlng[100];	int max_cnt;	int cnt;	int flag;	int i;	i = 0;	flag = NO;	max_cnt = 0;	fpin = fopen("test.txt", "rt");	if (fpin == NULL)		return 1;	fpout = fopen("result.txt", "wt");	if (fpout == NULL)		return 1;	while (!feof(fpin))
	{
		ptr = fgets(line, 1000, fpin);
		cnt = 0;

		if (ptr == NULL)
			break;

		while (*ptr != '\0')
		{
			if ((*ptr < 'A' || *ptr > 'Z') && (*ptr < 'a' || *ptr > 'z'))
			{
				if (flag)
					cnt++;

				flag = NO;
			}
			else
				flag = YES;

			ptr++;
		}

		if (cnt > max_cnt)
			max_cnt = cnt;

		strlng[i] = cnt;
		i++;
	}

	rewind(fpin);

	i = 0;
	while (!feof(fpin))
	{
		ptr = fgets(line, 1000, fpin);

		if (strlng[i] < max_cnt)
			fputs(line, fpout);
		else
			fprintf(fpout, "\n");

		i++;
	}

	fclose(fpin);
	fclose(fpout);
	return 0;
}


	