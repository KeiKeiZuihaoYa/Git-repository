// 单链表定义
typedef int ElemType;

typedef struct
{
    ElemType data;
    struct Node *next = NULL;
} Node;

#define Statue int
#define OK 1
#define ERROR -1
#define MAXSIZE 100

// 单链表初始化
Statue InitList(Node *&L)
{
    L = (Node *)malloc(sizeof(Node));
    if (L == NULL)
        return ERROR;
    return OK;
}

// 后插法插入
Statue InsertList_Hou(Node *&L, ElemType e)
{
    Node *p = L;

    // 循环到最后一个节点
    while (p->next != NULL)
    {
        p = p->next;
    }
    Node *s = (Node *)malloc(sizeof(Node));
    s->data = e;
    s->next = NULL;
    p->next = s;
    return OK;
}

// 取值
Statue GetList(Node *L, int i, ElemType &e) // 把第 i 个元素的值赋给 e
{
    Node *p = L;
    int j = 0;
    while (p != NULL && j < i) // 循环到第 i 个节点
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return ERROR;
    e = p->data;
    return OK;
}

// 插入(任意位置)
Statue InsertList_Ren(Node *&L, int i, ElemType e) // 第 i 个位置
{
    Node *p = L;
    int j = 0;
    while (p != NULL && j < i - 1) // 循环到第 i - 1 个节点
    {
        p = p->next;
        j++;
    }
    if (p == NULL) // 如果这个单链表没有第 i 个节点
        return ERROR;
    Node *s = (Node *)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

// 删除
Statue DeleteList(Node *&L, int i, ElemType &e) // 第 i 个位置 删除, 并且第i个位置元素赋给 e
{
    Node *p = L;
    int j = 0;
    while (p != NULL && j < i - 1) // 循环到第 i - 1 个节点
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return ERROR;
    Node *q = p->next; // q 就是 第 i个节点
    p->next = q->next;
    e = q->data;
    delete q;
    return OK;
}

// 修改
Statue ModifyList(Node *&L, int i, ElemType e) // 第 i 个位置 修改, 并且第i个位置元素赋给 e
{
    Node *p = L;
    int j = 0;
    while (p != NULL && j < i) // 循环到第 i 个节点
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return ERROR;
    p->data = e;
    return OK;
}
