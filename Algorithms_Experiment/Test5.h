#pragma once
#include"Base.h"


//��������������
#define MAX_VERTEX_NUM 20

typedef int InfoType ;
typedef char VertexType;
typedef int ElemType;
bool visited[MAX_VERTEX_NUM];  //���ʱ�־����


//���еĽṹ
//���еĻ������� 
typedef struct QueueNode {
    ElemType data;
    struct QueueNode* next;
}Squeue, * queue;
typedef struct {
    queue front, rear;
}Queue, * LinkQueue;


//ͼ�Ľṹ
typedef struct ArcNode {  //�൱�ڱ߹�ϵ����
    ElemType  adjvex;  //�൱�� V1-V2 �д���V2
    struct ArcNode* nextarc;  //ָ����һ������ָ��
    InfoType info;   //Ȩֵ
}ArcNode;
typedef struct VNode {
    VertexType  data;   // ���ֵ
    ArcNode* firstarc;
} VNode, AdjList[MAX_VERTEX_NUM];
typedef struct {
    AdjList vertices;
    int vexnum, arcnum;//ͼ�ĵ�ǰ�������ͻ���
    int kind;  //����
}ALGraph;

//���еĲ���
void initQueue(LinkQueue Q);
bool QueueisEmpty(LinkQueue Q);
void EnQueue(LinkQueue Q, ElemType x);
bool DeQueue(LinkQueue Q, ElemType &x);
//ͼ�Ĳ���
Status Test5(void);
Status CreateGraph(ALGraph& G);
Status CreatDG(ALGraph& G);
Status CreatUDG(ALGraph& G);
int LocateVex(ALGraph G, char v);  //���ؽ���±�
Status ShowGraph(ALGraph& G);
Status ShowUDG(ALGraph& G);  //����ͼ���ڽӱ����
Status ShowDG(ALGraph& G);  //����ͼ���ڽӱ����
Status Depth_First_Search(ALGraph& G);  //�����������
Status Broadth_First_Search(ALGraph& G);  //�����������
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
    printf("��������Ҫ����ͼ������\n0��������ͼ  1��������ͼ");
    printf("\n---->");
    scanf("%d", &G.kind);
    switch (G.kind) {
    case 0:return CreatUDG(G);  //��������ͼ
    case 1:return CreatDG(G);  //��������ͼ
    default:return ERROR;
    }
    return TRUE;
}

Status CreatUDG(ALGraph& G) {  //����ͼ
    printf("�����붥���� -->");
    scanf("%d", &G.vexnum);
    printf("������ͼ���� -->");
    scanf("%d", &G.arcnum);

    printf("�밴˳����붥����Ϣ\n");
    for (int i = 0; i < G.vexnum; ++i) {  //��ʼ������
        getchar();
        scanf("%c", &G.vertices[i].data);
        G.vertices[i].firstarc = NULL;
    }
    printf("������ߵ���Ϣ\n");
    for (int k = 0; k < G.arcnum; k++) {  //�߸���
        char v1, v2;
        getchar();
        scanf("%c%c", &v1, &v2);
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);

        //��i�н����������
        ArcNode* Temp1 = (ArcNode*)malloc(sizeof(ArcNode));
        Temp1->info = 0;
        Temp1->adjvex = j;
        Temp1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = Temp1;

        //��j���������
        ArcNode* Temp2 = (ArcNode*)malloc(sizeof(ArcNode));
        Temp2->info = 0;
        Temp2->adjvex = i;
        Temp2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = Temp2;

    }

    return TRUE;
}
Status CreatDG(ALGraph& G) {  //����ͼ
    printf("�����붥���� -->");
    scanf("%d", &G.vexnum);
    printf("������ͼ���� -->");
    scanf("%d", &G.arcnum);

    printf("�밴˳����붥����Ϣ\n");
    for (int i = 0; i < G.vexnum; ++i) {  //��ʼ������
        getchar();
        scanf("%c", &G.vertices[i].data);
        G.vertices[i].firstarc = NULL;
    }
    printf("������ߵ���Ϣ\n");
    for (int k = 0; k < G.arcnum; k++) {  //�߸���
        char v1, v2;
        getchar();
        scanf("%c%c", &v1, &v2);
        int i = LocateVex(G, v1);

        //��i�н����������
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
    case 0:return ShowUDG(G);  //��������ͼ
    case 1:return ShowDG(G);  //��������ͼ
    default:return ERROR;
    }
}

Status ShowUDG(ALGraph& G) {  //����ͼ���ڽӱ����
    printf("������ͼ�ڽӱ�����������\n");
    ArcNode* Temp;
    for (int i = 0; i < G.vexnum; i++) {  //ÿ�ж���ֿ����
        printf("%c: ", G.vertices[i].data);
        for (Temp = G.vertices[i].firstarc; Temp; Temp = Temp->nextarc)
            printf(" --->%c", G.vertices[Temp->adjvex].data);
        printf("\n");
    }
    return TRUE;
}
Status ShowDG(ALGraph& G) { //����ͼ���ڽӱ����
    printf("������ͼ�ڽӱ�����������\n");
    ArcNode* Temp;
    for (int i = 0; i < G.vexnum; i++) {  //ÿ�ж���ֿ����
        printf("%c: ", G.vertices[i].data);
        for (Temp = G.vertices[i].firstarc; Temp; Temp = Temp->nextarc)
            printf(" --->%c", G.vertices[Temp->adjvex].data);
        printf("\n");
    }
    return TRUE;
}

Status Depth_First_Search(ALGraph& G) {
    if (G.kind == 1) {
        printf("�������������������������ͼ!\n");
        return FALSE;
    }

    printf("������������������\n");
    for (int i = 0; i < G.vexnum; i++) visited[i] = FALSE;  //��־λ���
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) DFS(G, i);
    }
    printf("\n");
    return TRUE;
}
Status Broadth_First_Search(ALGraph& G) {
    if (G.kind == 1) {
        printf("�ù����������������������ͼ!\n");
        return FALSE;
    }
    printf("������������������\n");
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
    for (int w = FirstAdjVex(G, i); w >= 0; w = NextAdjVex(G, i, w)) {  //FirstAdjvex������е��ڽڵ�
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
    //�ҵ���Ӧ������ĺ�һ��Ԫ��
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
