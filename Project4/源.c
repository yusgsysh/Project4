
#pragma warning(disable : 4996)
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct
{
	int sno;
	char sname[8];
	int score;
}student;
typedef struct node
{
	student data;
	struct node* next;
}linklist;
linklist* createlist()
{
	linklist* head = (linklist*)malloc(sizeof(linklist));
	linklist* r = head, * p;
	int x = 0;
	while (x == 0)
	{
		printf("������ѧ�š��������ɼ����ûس�����:\n");
		p = (linklist*)malloc(sizeof(linklist));
		scanf("%d", &p->data.sno);
		scanf("%s", &p->data.sname);
		scanf("%d", &p->data.score);
		r->next = p;
		r = p;
		printf("��������ѧ����Ϣ�밴0\n");
		scanf("%d", &x);
	}
	r->next = NULL;
	return head;
}
void bianli(linklist* head)
{
	linklist* q = head->next;
	printf("ѧ�� ����    �ɼ�");
	printf("\n");
	while (q)
	{
		printf("%d    %s  %d", q->data.sno, q->data.sname, q->data.score);
		printf("\n");
		q = q->next;
	}
}
void charu(linklist* head)
{
	linklist* p, * r;
	p = (linklist*)malloc(sizeof(linklist));
	printf("��������ѧ����Ϣ");
	scanf("%d %s %d", &p->data.sno, &p->data.sname, &p->data.score);
	while (head->next)
	{
		head = head->next;
	}
	r = head;
	r->next = p;
	r = p;
	r->next = NULL;
}
void shanchu(linklist* head, int i)
{
	linklist* p, * q;
	p = head;
	for (int j = 1; j <= i - 1; j++) {
		p = p->next;
	}
	q = p->next;
	p->next = p->next->next;
	free(q);
}
int main()
{
	linklist* head = createlist();
	printf("��ѡ��Ҫ���еĲ�����������ţ�\n1�����ѧ������\n2�������µ�ѧ����Ϣ\n3��ɾ��ѧ����Ϣ\n");
	int x, y;
	scanf("%d", &x);
	while (x == 1 || x == 2 || x == 3)
	{
		if (x == 1)
		{
			bianli(head);
		}
		else if (x == 2)
		{
			charu(head);
		}
		else if (x == 3)
		{
			printf("������Ҫɾ��ѧ����ѧ��\n");
			scanf("%d", &y);
			shanchu(head, y);
		}
		printf("��ѡ��Ҫ���еĲ�����������ţ�\n1�����ѧ������\n2�������µ�ѧ����Ϣ\n3��ɾ��ѧ����Ϣ\n");
		scanf("%d", &x);
	}
	return 0;
}