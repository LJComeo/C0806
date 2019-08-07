#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define N 9
#define OVERFLOW 0
#define OK 1
int keyW[N] = { 4, 7, 5, 9, 3, 2, 6, 1, 8 };

typedef struct LNode
{
	int keyword;
	struct LNode *next;
}LNode,*LinkList;

void Joseph(LinkList p, int m, int x)
{
	LinkList q;
	int i;
	if (x == 0)
		return;
	q = p;
	m %= x;
	if (m == 0)
		m = x;
	for (i = 1; i <= m; i++)
	{
		p = q;
		q = p->next;
	}
	p->next = q->next;
	i = q->keyword;
	printf("%d ", q->keyword);
	free(q);
	Joseph(p, i, x - 1);
}

int main()
{
	int i, m;
	LinkList Lhead, p, q;
	Lhead = (LinkList)malloc(sizeof(LNode));
	if (!Lhead)
		return OVERFLOW;
	Lhead->keyword = keyW[0];
	Lhead->next = NULL;
	p = Lhead;
	for (i = 1; i < 9; i++)
	{
		if (!(q = (LinkList)malloc(sizeof(LNode))))
			return OVERFLOW;
		q->keyword = keyW[i];
		p->next = q;
		p = q;
	}
	p->next = Lhead;
	printf("请输入第一次计数值m: \n");
	scanf("%d", &m);
	printf("输出的数列是: \n");
	Joseph(p, m, N);
	return OK;
	system("pause");
	return 0;
}