/*
	@brief:邻接矩阵的创建
	@autuor:WavenZ
	@time:2018/10/5
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define INFINITY	65535
#define MAX_VERTEX_NUM 20
typedef enum { DG, DN, UDG, UDN }GraphKind;//{有向图，有向网， 无向图，无向网}
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
Status CreateUDN(MGraph *G)//无向网
{
	int info;
	char x, y, tempc;
	int temp;
	int i, j, k;
	printf("请依次输入顶点数、边数以及是否包含其他信息（0/1）：");
	scanf("%d %d %d", &G->vexnum, &G->arcnum, &info);
	getchar();//读取缓冲区的'\0'
	printf("请依次输入顶点名称：");
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
		printf("请输入第%d条边依附的顶点以及权值:", k + 1);
		scanf("%c %c %d", &x, &y, &temp);
		getchar();
		i = LocateVex(*G, x);
		j = LocateVex(*G, y);
		G->arcs[i][j].adj = temp;
		G->arcs[j][i].adj = G->arcs[i][j].adj;//无向对称
	}
	return 1;
}
Status CreateDN(MGraph *G)//有向网
{
	int info;
	char x, y, tempc;
	int temp;
	int i, j, k;
	printf("请依次输入顶点数、弧数以及是否包含其他信息（0/1）：");
	scanf("%d %d %d", &G->vexnum, &G->arcnum, &info);
	getchar();//读取缓冲区的'\0'
	printf("请依次输入顶点名称：");
	for (i = 0; i < G->vexnum; ++i)
	{
		scanf("%c", &tempc);
		G->vexs[i] = tempc;
	}
	getchar();//读取缓冲区的'\0'
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
		printf("请输入第%d条弧的弧尾、弧头以及权值:", k + 1);
		scanf("%c %c %d", &x, &y, &temp);
		getchar();//读取缓冲区的'\0'
		i = LocateVex(*G, x);
		j = LocateVex(*G, y);
		G->arcs[i][j].adj = temp;
	}
}
Status CreateUDG(MGraph *G)//无向图
{
	int info;
	char x, y, tempc;
	int temp;
	int i, j, k;
	printf("请依次输入顶点数、边数以及是否包含其他信息（0/1）：");
	scanf("%d %d %d", &G->vexnum, &G->arcnum, &info);
	getchar();//读取缓冲区的'\0'
	printf("请依次输入顶点名称：");
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
		printf("请输入第%d条边依附的两个顶点", k + 1);
		scanf("%c %c", &x, &y);
		getchar();
		i = LocateVex(*G, x);
		j = LocateVex(*G, y);
		G->arcs[i][j].adj = 1;
		G->arcs[j][i].adj = G->arcs[i][j].adj;
	}
}
Status CreateDG(MGraph *G)//有向图
{
	int info;
	char x, y, tempc;
	int temp;
	int i, j, k;
	printf("请依次输入顶点数、弧数以及是否包含其他信息（0/1）：");
	scanf("%d %d %d", &G->vexnum, &G->arcnum, &info);
	getchar();
	printf("请依次输入顶点名称：");
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
		printf("请输入第%d条弧依附的弧尾和弧头:", k + 1);
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
	printf("请输入图的类型（1.有向图 2.有向网 3.无向图 4.无向网）：");
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
			else printf("∞\t");

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
