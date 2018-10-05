/*
	@brief:�ڽӾ���Ĵ���
	@autuor:WavenZ
	@time:2018/10/5
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define INFINITY	65535
#define MAX_VERTEX_NUM 20
typedef enum { DG, DN, UDG, UDN }GraphKind;//{����ͼ���������� ����ͼ��������}
typedef struct ArcCell {
	int adj;
	int *info;
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {
	char vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum, arcnum;
	GraphKind kind;
}MGraph;

int LocateVex(MGraph G, char vex)
{
	for (int i = 0; i < G.vexnum; ++i)
	{
		if (G.vexs[i] == vex) return i;
	}
	return -1;
}
typedef int Status;
Status CreateUDN(MGraph *G)//������
{
	int info;
	char x, y, tempc;
	int temp;
	int i, j, k;
	printf("���������붥�����������Լ��Ƿ����������Ϣ��0/1����");
	scanf("%d %d %d", &G->vexnum, &G->arcnum, &info);
	getchar();//��ȡ��������'\0'
	printf("���������붥�����ƣ�");
	for (i = 0; i < G->vexnum; ++i) {
		scanf("%c", &tempc);
		G->vexs[i] = tempc;
	}
	getchar();
	for (i = 0; i < G->vexnum; ++i)
	{
		for (j = 0; j < G->vexnum; ++j)
		{
			G->arcs[i][j].adj = INFINITY;
			G->arcs[i][j].info = 0;
		}
	}
	for (k = 0; k < G->arcnum; ++k)
	{
		printf("�������%d���������Ķ����Լ�Ȩֵ:", k + 1);
		scanf("%c %c %d", &x, &y, &temp);
		getchar();
		i = LocateVex(*G, x);
		j = LocateVex(*G, y);
		G->arcs[i][j].adj = temp;
		G->arcs[j][i].adj = G->arcs[i][j].adj;//����Գ�
	}
	return 1;
}
Status CreateDN(MGraph *G)//������
{
	int info;
	char x, y, tempc;
	int temp;
	int i, j, k;
	printf("���������붥�����������Լ��Ƿ����������Ϣ��0/1����");
	scanf("%d %d %d", &G->vexnum, &G->arcnum, &info);
	getchar();//��ȡ��������'\0'
	printf("���������붥�����ƣ�");
	for (i = 0; i < G->vexnum; ++i)
	{
		scanf("%c", &tempc);
		G->vexs[i] = tempc;
	}
	getchar();//��ȡ��������'\0'
	for (i = 0; i < G->vexnum; ++i)
	{
		for (j = 0; j < G->vexnum; ++j)
		{
			G->arcs[i][j].adj = INFINITY;
			G->arcs[i][j].info = 0;
		}
	}
	for (k = 0; k < G->arcnum; ++k)
	{
		printf("�������%d�����Ļ�β����ͷ�Լ�Ȩֵ:", k + 1);
		scanf("%c %c %d", &x, &y, &temp);
		getchar();//��ȡ��������'\0'
		i = LocateVex(*G, x);
		j = LocateVex(*G, y);
		G->arcs[i][j].adj = temp;
	}
}
Status CreateUDG(MGraph *G)//����ͼ
{
	int info;
	char x, y, tempc;
	int temp;
	int i, j, k;
	printf("���������붥�����������Լ��Ƿ����������Ϣ��0/1����");
	scanf("%d %d %d", &G->vexnum, &G->arcnum, &info);
	getchar();//��ȡ��������'\0'
	printf("���������붥�����ƣ�");
	for (i = 0; i < G->vexnum; ++i) {
		scanf("%c", &tempc);
		G->vexs[i] = tempc;
	}
	getchar();
	for (i = 0; i < G->vexnum; ++i)
	{
		for (j = 0; j < G->vexnum; ++j)
		{
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = 0;
		}
	}
	for (k = 0; k < G->arcnum; ++k)
	{
		printf("�������%d������������������", k + 1);
		scanf("%c %c", &x, &y);
		getchar();
		i = LocateVex(*G, x);
		j = LocateVex(*G, y);
		G->arcs[i][j].adj = 1;
		G->arcs[j][i].adj = G->arcs[i][j].adj;
	}
}
Status CreateDG(MGraph *G)//����ͼ
{
	int info;
	char x, y, tempc;
	int temp;
	int i, j, k;
	printf("���������붥�����������Լ��Ƿ����������Ϣ��0/1����");
	scanf("%d %d %d", &G->vexnum, &G->arcnum, &info);
	getchar();
	printf("���������붥�����ƣ�");
	for (i = 0; i < G->vexnum; ++i)
	{
		scanf("%c", &tempc);
		G->vexs[i] = tempc;
	}
	getchar();
	for (i = 0; i < G->vexnum; ++i)
	{
		for (j = 0; j < G->vexnum; ++j)
		{
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = 0;
		}
	}
	for (k = 0; k < G->arcnum; ++k)
	{
		printf("�������%d���������Ļ�β�ͻ�ͷ:", k + 1);
		scanf("%c %c", &x, &y);
		getchar();
		i = LocateVex(*G, x);
		j = LocateVex(*G, y);
		G->arcs[i][j].adj = 1;
	}
}


Status CreateGraph(MGraph *G)
{
	int temp;
	printf("������ͼ�����ͣ�1.����ͼ 2.������ 3.����ͼ 4.����������");
	scanf("%d", &temp);
	switch (temp)
	{
	case 1:
	{
		G->kind = DG;
		return CreateDG(G);
	}
	case 2:
	{
		G->kind = DN;
		return CreateDN(G);
	}
	case 3:
	{
		G->kind = UDG;
		return CreateUDG(G);
	}
	case 4:
	{
		G->kind = UDN;
		return CreateUDN(G);
	}
	default:return 0;
	}
}
Status printGraph(MGraph G)
{
	int i, j;
	for (i = 0; i < G.vexnum; ++i)
	{
		for (j = 0; j < G.vexnum; ++j)
		{
			if (G.arcs[i][j].adj != INFINITY)printf("%d\t", G.arcs[i][j].adj);
			else printf("��\t");

		}
		printf("\n");
	}
}


int main(void)
{
	MGraph mgraph;
	CreateGraph(&mgraph);
	printGraph(mgraph);
	system("pause");
	return 0;
}
