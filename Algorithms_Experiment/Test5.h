#pragma once
#include"Base.h"


//定点数量最大个数
#define MAX_VERTEX_NUM 20

typedef int InfoType ;
typedef char VertexType;
typedef int ElemType;
bool visited[MAX_VERTEX_NUM];  //访问标志数组


//队列的结构
//队列的基本操作 
typedef struct QueueNode {
    ElemType data;
    struct QueueNode* next;
}Squeue, * queue;
typedef struct {
    queue front, rear;
}Queue, * LinkQueue;


//图的结构
typedef struct ArcNode {  //相当于边关系区块
    ElemType  adjvex;  //相当于 V1-V2 中储存V2
    struct ArcNode* nextarc;  //指向下一条弧的指针
    InfoType info;   //权值
}ArcNode;
typedef struct VNode {
    VertexType  data;   // 结点值
    ArcNode* firstarc;
} VNode, AdjList[MAX_VERTEX_NUM];
typedef struct {
    AdjList vertices;
    int vexnum, arcnum;//图的当前顶点数和弧数
    int kind;  //类型
}ALGraph;

//队列的操作
void initQueue(LinkQueue Q);
bool QueueisEmpty(LinkQueue Q);
void EnQueue(LinkQueue Q, ElemType x);
bool DeQueue(LinkQueue Q, ElemType &x);
//图的操作
Status Test5(void);
Status CreateGraph(ALGraph& G);
Status CreatDG(ALGraph& G);
Status CreatUDG(ALGraph& G);
int LocateVex(ALGraph G, char v);  //返回结点下标
Status ShowGraph(ALGraph& G);
Status ShowUDG(ALGraph& G);  //无向图的邻接表输出
Status ShowDG(ALGraph& G);  //有向图的邻接表输出
Status Depth_First_Search(ALGraph& G);  //深度优先搜索
Status Broadth_First_Search(ALGraph& G);  //广度优先搜索
Status DFS(ALGraph& G, int i);
int FirstAdjVex(ALGraph& G, int i);
int NextAdjVex(ALGraph& T, int v, int w);
Status Test5(void) {
    ALGraph G;
    CreateGraph(G);
    ShowGraph(G);
    Depth_First_Search(G);
    Broadth_First_Search(G);
    return TRUE;
}
Status CreateGraph(ALGraph& G) {
    printf("请输入您要创建图的类型\n0代表无向图  1代表有向图");
    printf("\n---->");
    scanf("%d", &G.kind);
    switch (G.kind) {
    case 0:return CreatUDG(G);  //构造无向图
    case 1:return CreatDG(G);  //构造有向图
    default:return ERROR;
    }
    return TRUE;
}

Status CreatUDG(ALGraph& G) {  //无向图
    printf("请输入顶点数 -->");
    scanf("%d", &G.vexnum);
    printf("请输入图边数 -->");
    scanf("%d", &G.arcnum);

    printf("请按顺序插入顶点信息\n");
    for (int i = 0; i < G.vexnum; ++i) {  //初始化顶点
        getchar();
        scanf("%c", &G.vertices[i].data);
        G.vertices[i].firstarc = NULL;
    }
    printf("请输入边的信息\n");
    for (int k = 0; k < G.arcnum; k++) {  //边个数
        char v1, v2;
        getchar();
        scanf("%c%c", &v1, &v2);
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);

        //对i行进行区块插入
        ArcNode* Temp1 = (ArcNode*)malloc(sizeof(ArcNode));
        Temp1->info = 0;
        Temp1->adjvex = j;
        Temp1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = Temp1;

        //对j行区块插入
        ArcNode* Temp2 = (ArcNode*)malloc(sizeof(ArcNode));
        Temp2->info = 0;
        Temp2->adjvex = i;
        Temp2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = Temp2;

    }

    return TRUE;
}
Status CreatDG(ALGraph& G) {  //有向图
    printf("请输入顶点数 -->");
    scanf("%d", &G.vexnum);
    printf("请输入图边数 -->");
    scanf("%d", &G.arcnum);

    printf("请按顺序插入顶点信息\n");
    for (int i = 0; i < G.vexnum; ++i) {  //初始化顶点
        getchar();
        scanf("%c", &G.vertices[i].data);
        G.vertices[i].firstarc = NULL;
    }
    printf("请输入边的信息\n");
    for (int k = 0; k < G.arcnum; k++) {  //边个数
        char v1, v2;
        getchar();
        scanf("%c%c", &v1, &v2);
        int i = LocateVex(G, v1);

        //对i行进行区块插入
        ArcNode* Temp1 = (ArcNode*)malloc(sizeof(ArcNode));
        Temp1->info = 0;
        Temp1->adjvex = LocateVex(G, v2);
        Temp1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = Temp1;
    }
    return TRUE;
}
int LocateVex(ALGraph G, char v) {
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data == v)
            return i;
    }
    return -1;
}

Status ShowGraph(ALGraph& G) {
    switch (G.kind) {
    case 0:return ShowUDG(G);  //构造无向图
    case 1:return ShowDG(G);  //构造有向图
    default:return ERROR;
    }
}

Status ShowUDG(ALGraph& G) {  //无向图的邻接表输出
    printf("该无向图邻接表输出结果如下\n");
    ArcNode* Temp;
    for (int i = 0; i < G.vexnum; i++) {  //每行顶点分开输出
        printf("%c: ", G.vertices[i].data);
        for (Temp = G.vertices[i].firstarc; Temp; Temp = Temp->nextarc)
            printf(" --->%c", G.vertices[Temp->adjvex].data);
        printf("\n");
    }
    return TRUE;
}
Status ShowDG(ALGraph& G) { //有向图的邻接表输出
    printf("该有向图邻接表输出结果如下\n");
    ArcNode* Temp;
    for (int i = 0; i < G.vexnum; i++) {  //每行顶点分开输出
        printf("%c: ", G.vertices[i].data);
        for (Temp = G.vertices[i].firstarc; Temp; Temp = Temp->nextarc)
            printf(" --->%c", G.vertices[Temp->adjvex].data);
        printf("\n");
    }
    return TRUE;
}

Status Depth_First_Search(ALGraph& G) {
    if (G.kind == 1) {
        printf("该深度优先搜索仅适用于无向图!\n");
        return FALSE;
    }

    printf("深度优先搜索结果如下\n");
    for (int i = 0; i < G.vexnum; i++) visited[i] = FALSE;  //标志位清空
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) DFS(G, i);
    }
    printf("\n");
    return TRUE;
}
Status Broadth_First_Search(ALGraph& G) {
    if (G.kind == 1) {
        printf("该广度优先搜索仅适用于无向图!\n");
        return FALSE;
    }
    printf("广度优先搜索结果如下\n");
    for (int i = 0; i < G.vexnum; ++i) visited[i] = FALSE;
    LinkQueue Q = (LinkQueue)malloc(sizeof(queue));
    initQueue(Q);
    for(int i = 0;i<G.vexnum;++i)
        if (!visited[i]) {
            visited[i] = TRUE;
            printf("%c ", G.vertices[i].data);
            EnQueue(Q, i);
            while (!QueueisEmpty(Q)) {
                int u ;
                DeQueue(Q, u);
                for (int w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w)) {
                    if (!visited[w]) {
                        visited[w] = TRUE;
                        printf("%c ", G.vertices[w].data);
                        EnQueue(Q, w);
                    }
                }
            }
        }         
    return TRUE;
}
Status DFS(ALGraph& G,int i) {
	visited[i] = TRUE;
    printf("%c ", G.vertices[i].data);
    for (int w = FirstAdjVex(G, i); w >= 0; w = NextAdjVex(G, i, w)) {  //FirstAdjvex检查所有的邻节点
        if (!visited[w]) DFS(G, w);
    }
    return TRUE;
}
int FirstAdjVex(ALGraph& G, int i) {
    return G.vertices[i].firstarc->adjvex;  
}
int NextAdjVex(ALGraph& T, int v, int w){
    ArcNode* p;
    p = T.vertices[v].firstarc;
    while (p->adjvex != w) { p = p->nextarc; }
    //找到对应行区块的后一个元素
    p = p->nextarc;
    if (p != NULL) return p->adjvex;
    else return -1;
}
void initQueue(LinkQueue Q) {
    Q->front = Q->rear = (queue)malloc(sizeof(Squeue));
    Q->front->next = NULL;
}
bool QueueisEmpty(LinkQueue Q) {
    if (Q->front == Q->rear) return true;
    else return false;
}
void EnQueue(LinkQueue Q, ElemType x) {
    queue s = (queue)malloc(sizeof(Squeue));
    s->data = x;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
}
bool DeQueue(LinkQueue Q,ElemType &x) {
    if (Q->front == Q->rear) return false;
    queue p = Q->front->next;
    x = p->data;
    Q->front->next = p->next;
    if (Q->rear == p) Q->rear = Q->front;
    free(p);
    return true;
}
