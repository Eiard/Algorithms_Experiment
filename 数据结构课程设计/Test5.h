#pragma once
#include"Base.h"
#include"Test2.h"  //用到了栈


/*
* 物联11902班 张宜成 201902849
* 该头文件创建于5月28日
*
* Test5.h头文件:
*		包含图的相关函数
*		包含 最小生成树（应用）最短路径（应用） 关键路径（应用） (均未实现) 
*/

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

//-----------------------------------------------------
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
//-----------------------------------------------------
//队列的操作
void initQueue(LinkQueue Q);
bool QueueisEmpty(LinkQueue Q);
void EnQueue(LinkQueue Q, ElemType x);
bool DeQueue(LinkQueue Q, ElemType &x);
//图的操作
Status Test5(void);
Status ShowMeun5(void);

Status CreateGraph(ALGraph& G,int Kind);
Status CreatDG(ALGraph& G);
Status CreatDN(ALGraph& G);
Status CreatUDG(ALGraph& G);
Status CreatUDN(ALGraph& G);

Status ShowGraph(ALGraph& G);
Status ShowDG(ALGraph& G);  //有向图的邻接表输出
Status ShowDN(ALGraph& G);  //有向网的邻接表输出
Status ShowUDG(ALGraph& G);  //无向图的邻接表输出
Status ShowUDN(ALGraph& G);  //无向网的邻接表输出

Status Depth_First_Search(ALGraph& G);  //深度优先搜索
Status Broadth_First_Search(ALGraph& G);  //广度优先搜索
Status DFS(ALGraph& G, int i);
Status TopologicalSort(ALGraph G);
Status FindInDegree(ALGraph G, int indegree[MAX_VERTEX_NUM]);

int LocateVex(ALGraph G, char v);  //返回结点下标
int FirstAdjVex(ALGraph& G, int i);
int NextAdjVex(ALGraph& T, int v, int w);
//-----------------------------------------------------
Status Test5(void) {
    int select;
    ALGraph G;
    while (TRUE) {
        ShowMeun5();
        printf("请选择：");
        scanf("%d", &select);
        system("cls");
        switch (select) {
        case 1: {
            printf("---------创建无向图---------\n");

			if (CreateGraph(G, select - 1)) printf("构造成功!\n");
            else printf("构造失败!\n");

            system("pause");
            system("cls");
            break;
        }
        case 2: {
            printf("---------创建无向网---------\n");

            if (CreateGraph(G, select - 1)) printf("构造成功!\n");
            else printf("构造失败!\n");

            system("pause");
            system("cls");
            break;
        }
        case 3: {
            printf("---------创建有向图---------\n");

            if (CreateGraph(G, select - 1)) printf("构造成功!\n");
            else printf("构造失败!\n");

            system("pause");
            system("cls");
            break;
        }
        case 4: {
            printf("---------创建有向网---------\n");

            if (CreateGraph(G, select - 1)) printf("构造成功!\n");
            else printf("构造失败!\n");

            system("pause");
            system("cls");
            break;
        }
        case 5: {
            printf("---------遍历---------\n");


            printf("邻接表显示如下:\n");
            ShowGraph(G);

            Depth_First_Search(G);
            Broadth_First_Search(G);

            system("pause");
            system("cls");
            break;
        }
        case 6: {
            printf("---------拓扑排序---------\n");

            TopologicalSort(G);

            system("pause");
            system("cls");
            break;
        }
        case 7: {
            printf("---------最小生成树---------\n");

            printf("未实现\n");

            system("pause");
            system("cls");
            return OK;
        }
        case 8: {
            printf("---------最短路径---------\n");

            printf("未实现\n");

            system("pause");
            system("cls");
            return OK;
        }
        case 9: {
            printf("---------关键路径---------\n");

            printf("未实现\n");

            system("pause");
            system("cls");
            return OK;
        }
        case 10: {
            printf("退出成功!\n");
            system("pause");
            system("cls");
            return OK;
        }
        default:
            printf("您输入有误请重新输入!\n");
            system("pause");
            system("cls");
            break;
        }
    }

    return OK;
}
Status ShowMeun5(void) {
    printf("****************图的基本操作及应用******************\n");
    printf("* 1  创建无向图                                    *\n");
    printf("* 2  创建无向网                                    *\n");
    printf("* 3  创建有向图                                    *\n");
    printf("* 4  创建有向网                                    *\n");
    printf("* 5  遍历                                          *\n");
    printf("* 6  拓扑排序                                      *\n");
    printf("* 7  最小生成树（应用）   (未实现)                 *\n");
    printf("* 8  最短路径（应用）     (未实现)                 *\n");
    printf("* 9  关键路径（应用）     (未实现)                 *\n");
    printf("* 10 退出                                          *\n");
    printf("****************************************************\n");
    return OK;
}

Status CreateGraph(ALGraph& G,int Kind) {
    G.kind = Kind;
    switch (Kind) {
    case 0:return CreatUDG(G);  //构造无向图
    case 1:return CreatUDN(G);  //构造无向网
    case 2:return CreatDG(G);  //构造有向图
	case 3:return CreatDN(G);  //构造有向网
    default:return ERROR;
	}
    return OK;
}
Status CreatUDG(ALGraph& G) {  //无向图(边无权值)
    printf("请输入顶点数 -->");
    scanf("%d", &G.vexnum);
    printf("请输入图边数 -->");
    scanf("%d", &G.arcnum);

    printf("请按顺序插入顶点信息(格式)a b c d\n");
    for (int i = 0; i < G.vexnum; ++i) {  //初始化顶点
        getchar();
        scanf("%c", &G.vertices[i].data);
        G.vertices[i].firstarc = NULL;
    }
    printf("请输入边的信息(格式)ab\n");
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

    return OK;
}
Status CreatUDN(ALGraph& G) {  //无向网
    printf("请输入顶点数 -->");
    scanf("%d", &G.vexnum);
    printf("请输入图边数 -->");
    scanf("%d", &G.arcnum);

    printf("请按顺序插入顶点信息(格式)a b c d\n");
    for (int i = 0; i < G.vexnum; ++i) {  //初始化顶点
        getchar();
        scanf("%c", &G.vertices[i].data);
        G.vertices[i].firstarc = NULL;
    }
    printf("请输入边的信息(格式)ab-3\n");
    for (int k = 0; k < G.arcnum; k++) {  //边个数
        char v1, v2;
        int Info;
        getchar();
        scanf("%c%c-%d", &v1, &v2,&Info);
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);

        //对i行进行区块插入
        ArcNode* Temp1 = (ArcNode*)malloc(sizeof(ArcNode));
        Temp1->info = Info;
        Temp1->adjvex = j;
        Temp1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = Temp1;

        //对j行区块插入
        ArcNode* Temp2 = (ArcNode*)malloc(sizeof(ArcNode));
        Temp2->info = Info;
        Temp2->adjvex = i;
        Temp2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = Temp2;

    }

    return OK;
}
Status CreatDG(ALGraph& G) {  //有向图
    printf("请输入顶点数 -->");
    scanf("%d", &G.vexnum);
    printf("请输入图边数 -->");
    scanf("%d", &G.arcnum);

    printf("请按顺序插入顶点信息(格式)a b c d\n");
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
    return OK;
}
Status CreatDN(ALGraph& G) {  //有向网
    printf("请输入顶点数 -->");
    scanf("%d", &G.vexnum);
    printf("请输入图边数 -->");
    scanf("%d", &G.arcnum);

    printf("请按顺序插入顶点信息(格式)a b c d\n");
    for (int i = 0; i < G.vexnum; ++i) {  //初始化顶点
        getchar();
        scanf("%c", &G.vertices[i].data);
        G.vertices[i].firstarc = NULL;
    }
    printf("请输入边的信息(格式)ab-3\n");
    for (int k = 0; k < G.arcnum; k++) {  //边个数
        char v1, v2;
        int Info;
        getchar();
		scanf("%c%c-%d", &v1, &v2, &Info);
        int i = LocateVex(G, v1);

        //对i行进行区块插入
        ArcNode* Temp1 = (ArcNode*)malloc(sizeof(ArcNode));
        Temp1->info = Info;
        Temp1->adjvex = LocateVex(G, v2);
        Temp1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = Temp1;
    }
    return OK;
}



Status ShowGraph(ALGraph& G) {
    switch (G.kind) {
    case 0:return ShowUDG(G);  //输出无向图
    case 1:return ShowUDN(G);  //输出无向网
    case 2:return ShowDG(G);  //输出有向图
    case 3:return ShowDN(G);  //输出有向网
    default:return ERROR;
    }
}
Status ShowUDG(ALGraph& G) {  //无向图的邻接表输出
    printf("该无向图邻接表输出结果如下\n");
    ArcNode* Temp;
    for (int i = 0; i < G.vexnum; i++) {  //每行顶点分开输出
        printf("[%c]: ", G.vertices[i].data);
        for (Temp = G.vertices[i].firstarc; Temp; Temp = Temp->nextarc)
            printf(" --->[%c]", G.vertices[Temp->adjvex].data);
        printf("\n");
    }
    return OK;
}
Status ShowUDN(ALGraph& G) {
    printf("该无向网邻接表输出结果如下\n");
    ArcNode* Temp;
    for (int i = 0; i < G.vexnum; i++) {  //每行顶点分开输出
        printf("[%c]: ", G.vertices[i].data);
        for (Temp = G.vertices[i].firstarc; Temp; Temp = Temp->nextarc)
            printf(" --->[%c|%d]", G.vertices[Temp->adjvex].data, Temp->info);
        printf("\n");
    }
    return OK;
}
Status ShowDG(ALGraph& G) { //有向图的邻接表输出
    printf("该有向图邻接表输出结果如下\n");
    ArcNode* Temp;
    for (int i = 0; i < G.vexnum; i++) {  //每行顶点分开输出
        printf("[%c]: ", G.vertices[i].data);
        for (Temp = G.vertices[i].firstarc; Temp; Temp = Temp->nextarc)
            printf(" --->[%c]", G.vertices[Temp->adjvex].data);
        printf("\n");
    }
    return OK;
}
Status ShowDN(ALGraph& G) {  //有向网
    printf("该有向图邻接表输出结果如下\n");
    ArcNode* Temp;
    for (int i = 0; i < G.vexnum; i++) {  //每行顶点分开输出
        printf("[%c]: ", G.vertices[i].data);
        for (Temp = G.vertices[i].firstarc; Temp; Temp = Temp->nextarc)
            printf(" --->[%c|%d]", G.vertices[Temp->adjvex].data, Temp->info);
        printf("\n");
    }
    return OK;
}

Status Depth_First_Search(ALGraph& G) {
    if (G.kind == 0) printf("无向图深度优先遍历结果如下:\n");
    else if(G.kind==1) printf("无向网深度优先遍历结果如下:\n");
    else if (G.kind == 2) { printf("有向图无法进行深度优先遍历\n"); return ERROR; }
    else if (G.kind == 3) { printf("有向网无法进行深度优先遍历:\n"); return ERROR; }

    printf("深度优先搜索结果如下\n");
    for (int i = 0; i < G.vexnum; i++) visited[i] = FALSE;  //标志位清空
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) DFS(G, i);
    }
    printf("\n");
    return TRUE;
}
Status Broadth_First_Search(ALGraph& G) {

    if (G.kind == 0) printf("无向图广度优先遍历结果如下:\n");
    else if (G.kind == 1) printf("无向网广度优先遍历结果如下:\n");
    else if (G.kind == 2) { printf("有向图无法进行广度优先遍历\n"); return ERROR; }
    else if (G.kind == 3) { printf("有向网无法进行广度优先遍历:\n"); return ERROR; }

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
    printf("\n");
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
Status TopologicalSort(ALGraph G) {
    if (G.kind == 0) {printf("无向图无拓扑序列\n"); return ERROR;}
	else if (G.kind == 1) { printf("无向网无拓扑序列\n"); return ERROR; }
    else if (G.kind == 2) printf("有向图拓扑序列如下:\n");
    else if (G.kind == 3) printf("有向网拓扑序列如下:\n"); 
    int indegree[MAX_VERTEX_NUM];
    FindInDegree(G, indegree);
    SqStack S;
    InitStack(S);
    for (int i = 0; i < G.vexnum; ++i) {
        if (!indegree[i]) Push(S, i);
    }
    int count = 0;
    int i;
    while (!StackEmpty(S)) {
		Pop(S, i);printf("%c ", G.vertices[i].data);count++;
        for (ArcNode* p = G.vertices[i].firstarc; p; p = p->nextarc) {
            int k = p->adjvex;
            if (!(--indegree[k]))Push(S, k);
        }
    }
    if (count < G.vexnum)return ERROR;
    else return OK;
}
Status FindInDegree(ALGraph G, int indegree[MAX_VERTEX_NUM]) {
    //初始化数组，默认初始值全部为0
    for (int i = 0; i < G.vexnum; i++) {
        indegree[i] = 0;
    }
    //遍历邻接表，根据各链表中结点的数据域存储的各顶点位置下标，在indegree数组相应位置+1
    for (int i = 0; i < G.vexnum; i++) {
        ArcNode* p = G.vertices[i].firstarc;
        while (p) {
            indegree[p->adjvex]++;
            p = p->nextarc;
        }
    }
    return OK;
}

int LocateVex(ALGraph G, char v) {
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data == v)
            return i;
    }
    return -1;
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
