/* bsearch example with strings */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort, bsearch, NULL */
#include <string.h>     /* strcmp */
#include<windows.h>		/* system */

char strvalues[][20] = {"some","example","strings","here"};

int main ()
{
	char * pItem;
	char key[20] = "example";

	/* sort elements in array: */
	qsort (strvalues, 4, 20, (int(*)(const void*,const void*)) strcmp);

	/* search for the key: */
	pItem = (char*) bsearch (key, strvalues, 4, 20, (int(*)(const void*,const void*)) strcmp);

	if (pItem!=NULL)
		printf ("%s is in the array.\n",pItem);
	else
		printf ("%s is not in the array.\n",key);
	system("pause");
	return 0;
}

#if 0
/* bsearch example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* qsort, bsearch, NULL */
#include<windows.h>		/* system  */

int compareints(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int values[] = { 50, 20, 60, 40, 10, 30 };

int main()
{
	int * pItem;
	int key = 41;
	qsort(values, 6, sizeof(int), compareints);
	pItem = (int*)bsearch(&key, values, 6, sizeof(int), compareints);
	if (pItem != NULL)
		printf("%d is in the array.\n", *pItem);
	else
		printf("%d is not in the array.\n", key);


	system("pause");
	return 0;
}
#endif
