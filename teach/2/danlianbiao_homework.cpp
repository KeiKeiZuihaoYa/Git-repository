#include <bits/stdc++.h>
using namespace std;

// 单链表定义
typedef struct
{
    string a;
    double b;
} ElemType;

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
}

// 后插法插入
Statue InsertList_Hou(Node *&L, ElemType e)
{
}

// 取值
Statue GetList(Node *L, int i, ElemType &e) // 把第 i 个元素的值赋给 e
{
}

// 插入(任意位置)
Statue InsertList_Ren(Node *&L, int i, ElemType e) // 第 i 个位置
{
}

// 删除
Statue DeleteList(Node *&L, int i, ElemType &e) // 第 i 个位置 删除, 并且第i个位置元素赋给 e
{
}

// 修改
Statue ModifyList(Node *&L, int i, ElemType e) // 第 i 个位置 修改, 并且第i个位置元素赋给 e
{
}

signed main()
{
    Node *L;
    ElemType e;

    InitList(L);
    InsertList_Hou(L, {"0hhhhhhxy", 11.22});
    InsertList_Hou(L, {"1hhhhhhxy", 11.22});
    InsertList_Ren(L, 1, {"2hhhhhhxy", 11.22});
    GetList(L, 1, e);
    cout << e.a << " " << e.b << endl;
    ModifyList(L, 1, {"3hhhhhhxy", 11.22});
    cout << e.a << " " << e.b << endl;
    DeleteList(L, 1, e);
    GetList(L, 1, e);
    cout << e.a << " " << e.b << endl;

    return 0;
}