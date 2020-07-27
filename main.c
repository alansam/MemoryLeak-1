#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int a;
	int c;
	double b;
	long long int d;
} MYSTRUCT;

#define COUNT 4
#define MAX_SIZE 24

int main()
{
	MYSTRUCT *p, *q;
	void* v;

	printf("size of MYSTRUCT = %d\n", sizeof(MYSTRUCT));
	
	p = (MYSTRUCT*)calloc(COUNT, MAX_SIZE);

	for(int i = 0; i < COUNT; i++)
	{
		p[i].a = i;
		p[i].b = 10000000000.0 + i;
		p[i].c = i * 20;
		p[i].d = 4294967296 + i;
	}

	q = p;
	printf("[0] values:\na is %d\nb is %d\nc is %d\nd is %lld", q->a, q->b, q->c, q->d);
	printf("\n[0] values:\na is %d\nb is %d\nc is %d\nd is %lld", &q->a, &q->b, &q->c, &q->d);
	
	q = p + 3;
	printf("\n[3] values:\na is %d\nb is %d\nc is %d\nd is %lld", q->a, q->b, q->c, q->d);
	printf("\n[3] values:\na is %d\nb is %d\nc is %d\nd is %lld", &q->a, &q->b, &q->c, &q->d);

	v = p + 3;	
	printf("\n[3] values:\na is %d\nb is %d\nc is %d\nd is %lld", q->a, q->b, q->c, q->d);
	printf("\n[3] values:\na is %d\nb is %d\nc is %d\nd is %lld", &q->a, &q->b, &q->c, &q->d);

  free(p);
  printf("\n all free \n\n");

	return 0;
}
