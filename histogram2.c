#include <stdio.h>

#define SIZE 26 /* 26 letters in the alphabet */
#define OFFSET_UPPER 65
#define OFFSET_LOWER 97
/* print histogram of frequencies of different characters */
main()
{
	int c, i, j, k, max;
	int arr[SIZE];

	for (i = 0; i < SIZE; ++i)
	{
		arr[i] = 0;
	}
	
	while ((c = getchar()) != EOF)
	{
		/* it's a lowercase */
		if ((c - OFFSET_UPPER) >= SIZE && (c - OFFSET_LOWER) < SIZE)
		{
			++arr[c - OFFSET_LOWER];
		}
		/* it's an uppercase */
		else if ((c - OFFSET_UPPER) < SIZE)
		{
			++arr[c - OFFSET_UPPER];
		}
	}
	/* find max */
	max = arr[0];
	for (i = 1; i < SIZE; ++i)
	{
		if (max < arr[i])
		{
			max = arr[i];	
		}
	}
	/* print histogram */
	printf("\n\n");
	k = max;
	for (i = 0; i < max; ++i, --k)
	{
		for (j = 0; j < SIZE; ++j) 
		{
			if (arr[j] >= k)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	for (i = 0; i < SIZE; ++i)
	{
		printf("-");
	}
	printf("\n");
	for (i = 0; i < SIZE; ++i)
	{
		printf("%c", i + OFFSET_UPPER);
	}
	printf("\n\tCHARACTERS\n");
}
