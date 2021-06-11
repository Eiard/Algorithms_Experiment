#pragma once
#include"Base.h"
#include"Test2.h"  //�õ���ջ


/*
* ����11902�� ���˳� 201902849
* ��ͷ�ļ�������5��28��
*
* Test5.hͷ�ļ�:
*		����ͼ����غ���
*		���� ��С��������Ӧ�ã����·����Ӧ�ã� �ؼ�·����Ӧ�ã� (��δʵ��) 
*/

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

//-----------------------------------------------------
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
//-----------------------------------------------------
//���еĲ���
void initQueue(LinkQueue Q);
bool QueueisEmpty(LinkQueue Q);
void EnQueue(LinkQueue Q, ElemType x);
bool DeQueue(LinkQueue Q, ElemType &x);
//ͼ�Ĳ���
Status Test5(void);
Status ShowMeun5(void);

Status CreateGraph(ALGraph& G,int Kind);
Status CreatDG(ALGraph& G);
Status CreatDN(ALGraph& G);
Status CreatUDG(ALGraph& G);
Status CreatUDN(ALGraph& G);

Status ShowGraph(ALGraph& G);
Status ShowDG(ALGraph& G);  //����ͼ���ڽӱ����
Status ShowDN(ALGraph& G);  //���������ڽӱ����
Status ShowUDG(ALGraph& G);  //����ͼ���ڽӱ����
Status ShowUDN(ALGraph& G);  //���������ڽӱ����

Status Depth_First_Search(ALGraph& G);  //�����������
Status Broadth_First_Search(ALGraph& G);  //�����������
Status DFS(ALGraph& G, int i);
Status TopologicalSort(ALGraph G);
Status FindInDegree(ALGraph G, int indegree[MAX_VERTEX_NUM]);

int LocateVex(ALGraph G, char v);  //���ؽ���±�
int FirstAdjVex(ALGraph& G, int i);
int NextAdjVex(ALGraph& T, int v, int w);
//-----------------------------------------------------
Status Test5(void) {
    int select;
    ALGraph G;
    while (TRUE) {
        ShowMeun5();
        printf("��ѡ��");
        scanf("%d", &select);
        system("cls");
        switch (select) {
        case 1: {
            printf("---------��������ͼ---------\n");

			if (CreateGraph(G, select - 1)) printf("����ɹ�!\n");
            else printf("����ʧ��!\n");

            system("pause");
            system("cls");
            break;
        }
        case 2: {
            printf("---------����������---------\n");

            if (CreateGraph(G, select - 1)) printf("����ɹ�!\n");
            else printf("����ʧ��!\n");

            system("pause");
            system("cls");
            break;
        }
        case 3: {
            printf("---------��������ͼ---------\n");

            if (CreateGraph(G, select - 1)) printf("����ɹ�!\n");
            else printf("����ʧ��!\n");

            system("pause");
            system("cls");
            break;
        }
        case 4: {
            printf("---------����������---------\n");

            if (CreateGraph(G, select - 1)) printf("����ɹ�!\n");
            else printf("����ʧ��!\n");

            system("pause");
            system("cls");
            break;
        }
        case 5: {
            printf("---------����---------\n");


            printf("�ڽӱ���ʾ����:\n");
            ShowGraph(G);

            Depth_First_Search(G);
            Broadth_First_Search(G);

            system("pause");
            system("cls");
            break;
        }
        case 6: {
            printf("---------��������---------\n");

            TopologicalSort(G);

            system("pause");
            system("cls");
            break;
        }
        case 7: {
            printf("---------��С������---------\n");

            printf("δʵ��\n");

            system("pause");
            system("cls");
            return OK;
        }
        case 8: {
            printf("---------���·��---------\n");

            printf("δʵ��\n");

            system("pause");
            system("cls");
            return OK;
        }
        case 9: {
            printf("---------�ؼ�·��---------\n");

            printf("δʵ��\n");

            system("pause");
            system("cls");
            return OK;
        }
        case 10: {
            printf("�˳��ɹ�!\n");
            system("pause");
            system("cls");
            return OK;
        }
        default:
            printf("��������������������!\n");
            system("pause");
            system("cls");
            break;
        }
    }

    return OK;
}
Status ShowMeun5(void) {
    printf("****************ͼ�Ļ���������Ӧ��******************\n");
    printf("* 1  ��������ͼ                                    *\n");
    printf("* 2  ����������                                    *\n");
    printf("* 3  ��������ͼ                                    *\n");
    printf("* 4  ����������                                    *\n");
    printf("* 5  ����                                          *\n");
    printf("* 6  ��������                                      *\n");
    printf("* 7  ��С��������Ӧ�ã�   (δʵ��)                 *\n");
    printf("* 8  ���·����Ӧ�ã�     (δʵ��)                 *\n");
    printf("* 9  �ؼ�·����Ӧ�ã�     (δʵ��)                 *\n");
    printf("* 10 �˳�                                          *\n");
    printf("****************************************************\n");
    return OK;
}

Status CreateGraph(ALGraph& G,int Kind) {
    G.kind = Kind;
    switch (Kind) {
    case 0:return CreatUDG(G);  //��������ͼ
    case 1:return CreatUDN(G);  //����������
    case 2:return CreatDG(G);  //��������ͼ
	case 3:return CreatDN(G);  //����������
    default:return ERROR;
	}
    return OK;
}
Status CreatUDG(ALGraph& G) {  //����ͼ(����Ȩֵ)
    printf("�����붥���� -->");
    scanf("%d", &G.vexnum);
    printf("������ͼ���� -->");
    scanf("%d", &G.arcnum);

    printf("�밴˳����붥����Ϣ(��ʽ)a b c d\n");
    for (int i = 0; i < G.vexnum; ++i) {  //��ʼ������
        getchar();
        scanf("%c", &G.vertices[i].data);
        G.vertices[i].firstarc = NULL;
    }
    printf("������ߵ���Ϣ(��ʽ)ab\n");
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

    return OK;
}
Status CreatUDN(ALGraph& G) {  //������
    printf("�����붥���� -->");
    scanf("%d", &G.vexnum);
    printf("������ͼ���� -->");
    scanf("%d", &G.arcnum);

    printf("�밴˳����붥����Ϣ(��ʽ)a b c d\n");
    for (int i = 0; i < G.vexnum; ++i) {  //��ʼ������
        getchar();
        scanf("%c", &G.vertices[i].data);
        G.vertices[i].firstarc = NULL;
    }
    printf("������ߵ���Ϣ(��ʽ)ab-3\n");
    for (int k = 0; k < G.arcnum; k++) {  //�߸���
        char v1, v2;
        int Info;
        getchar();
        scanf("%c%c-%d", &v1, &v2,&Info);
        int i = LocateVex(G, v1);
        int j = LocateVex(G, v2);

        //��i�н����������
        ArcNode* Temp1 = (ArcNode*)malloc(sizeof(ArcNode));
        Temp1->info = Info;
        Temp1->adjvex = j;
        Temp1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = Temp1;

        //��j���������
        ArcNode* Temp2 = (ArcNode*)malloc(sizeof(ArcNode));
        Temp2->info = Info;
        Temp2->adjvex = i;
        Temp2->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = Temp2;

    }

    return OK;
}
Status CreatDG(ALGraph& G) {  //����ͼ
    printf("�����붥���� -->");
    scanf("%d", &G.vexnum);
    printf("������ͼ���� -->");
    scanf("%d", &G.arcnum);

    printf("�밴˳����붥����Ϣ(��ʽ)a b c d\n");
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
    return OK;
}
Status CreatDN(ALGraph& G) {  //������
    printf("�����붥���� -->");
    scanf("%d", &G.vexnum);
    printf("������ͼ���� -->");
    scanf("%d", &G.arcnum);

    printf("�밴˳����붥����Ϣ(��ʽ)a b c d\n");
    for (int i = 0; i < G.vexnum; ++i) {  //��ʼ������
        getchar();
        scanf("%c", &G.vertices[i].data);
        G.vertices[i].firstarc = NULL;
    }
    printf("������ߵ���Ϣ(��ʽ)ab-3\n");
    for (int k = 0; k < G.arcnum; k++) {  //�߸���
        char v1, v2;
        int Info;
        getchar();
		scanf("%c%c-%d", &v1, &v2, &Info);
        int i = LocateVex(G, v1);

        //��i�н����������
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
    case 0:return ShowUDG(G);  //�������ͼ
    case 1:return ShowUDN(G);  //���������
    case 2:return ShowDG(G);  //�������ͼ
    case 3:return ShowDN(G);  //���������
    default:return ERROR;
    }
}
Status ShowUDG(ALGraph& G) {  //����ͼ���ڽӱ����
    printf("������ͼ�ڽӱ�����������\n");
    ArcNode* Temp;
    for (int i = 0; i < G.vexnum; i++) {  //ÿ�ж���ֿ����
        printf("[%c]: ", G.vertices[i].data);
        for (Temp = G.vertices[i].firstarc; Temp; Temp = Temp->nextarc)
            printf(" --->[%c]", G.vertices[Temp->adjvex].data);
        printf("\n");
    }
    return OK;
}
Status ShowUDN(ALGraph& G) {
    printf("���������ڽӱ�����������\n");
    ArcNode* Temp;
    for (int i = 0; i < G.vexnum; i++) {  //ÿ�ж���ֿ����
        printf("[%c]: ", G.vertices[i].data);
        for (Temp = G.vertices[i].firstarc; Temp; Temp = Temp->nextarc)
            printf(" --->[%c|%d]", G.vertices[Temp->adjvex].data, Temp->info);
        printf("\n");
    }
    return OK;
}
Status ShowDG(ALGraph& G) { //����ͼ���ڽӱ����
    printf("������ͼ�ڽӱ�����������\n");
    ArcNode* Temp;
    for (int i = 0; i < G.vexnum; i++) {  //ÿ�ж���ֿ����
        printf("[%c]: ", G.vertices[i].data);
        for (Temp = G.vertices[i].firstarc; Temp; Temp = Temp->nextarc)
            printf(" --->[%c]", G.vertices[Temp->adjvex].data);
        printf("\n");
    }
    return OK;
}
Status ShowDN(ALGraph& G) {  //������
    printf("������ͼ�ڽӱ�����������\n");
    ArcNode* Temp;
    for (int i = 0; i < G.vexnum; i++) {  //ÿ�ж���ֿ����
        printf("[%c]: ", G.vertices[i].data);
        for (Temp = G.vertices[i].firstarc; Temp; Temp = Temp->nextarc)
            printf(" --->[%c|%d]", G.vertices[Temp->adjvex].data, Temp->info);
        printf("\n");
    }
    return OK;
}

Status Depth_First_Search(ALGraph& G) {
    if (G.kind == 0) printf("����ͼ������ȱ����������:\n");
    else if(G.kind==1) printf("������������ȱ����������:\n");
    else if (G.kind == 2) { printf("����ͼ�޷�����������ȱ���\n"); return ERROR; }
    else if (G.kind == 3) { printf("�������޷�����������ȱ���:\n"); return ERROR; }

    printf("������������������\n");
    for (int i = 0; i < G.vexnum; i++) visited[i] = FALSE;  //��־λ���
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) DFS(G, i);
    }
    printf("\n");
    return TRUE;
}
Status Broadth_First_Search(ALGraph& G) {

    if (G.kind == 0) printf("����ͼ������ȱ����������:\n");
    else if (G.kind == 1) printf("������������ȱ����������:\n");
    else if (G.kind == 2) { printf("����ͼ�޷����й�����ȱ���\n"); return ERROR; }
    else if (G.kind == 3) { printf("�������޷����й�����ȱ���:\n"); return ERROR; }

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
    printf("\n");
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
Status TopologicalSort(ALGraph G) {
    if (G.kind == 0) {printf("����ͼ����������\n"); return ERROR;}
	else if (G.kind == 1) { printf("����������������\n"); return ERROR; }
    else if (G.kind == 2) printf("����ͼ������������:\n");
    else if (G.kind == 3) printf("������������������:\n"); 
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
    //��ʼ�����飬Ĭ�ϳ�ʼֵȫ��Ϊ0
    for (int i = 0; i < G.vexnum; i++) {
        indegree[i] = 0;
    }
    //�����ڽӱ����ݸ������н���������洢�ĸ�����λ���±꣬��indegree������Ӧλ��+1
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
