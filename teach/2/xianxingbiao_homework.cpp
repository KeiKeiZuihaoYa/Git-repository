#include <bits/stdc++.h>
using namespace std;
// 线性表定义
#define Statue int
#define OK 1
#define ERROR -1
#define MAXSIZE 100

typedef struct
{
    string a;
    double b;
} Elemtype;

typedef struct
{
    int length;
    Elemtype *elem; // 数组
} Sqlist;

// 线性表初始化
Statue Initlist(Sqlist &L, int length) // 线性表的长度为 length, 但数组开的时候需要使用最大长度
{
}

// 线性表修改
Statue Modifylist(Sqlist &L, int i, Elemtype e) // 在线性表L中， 修改下标为i的元素为e
{
}

// 线性表插入
Statue Insertlist(Sqlist &L, int i, Elemtype e) // 在线性表L中， 插入下标为i的元素为e
{
}

// 线性表删除
Statue Deletelist(Sqlist &L, int i, Elemtype &e) // 在线性表L中， 删除下标为i的元素， 并返回该元素
{
}

// 线性表查找
Statue LocateElem(Sqlist L, Elemtype e) // 在线性表L中， 是否存在一个元素的值为 e , 返回元素下标
{
}

// 线性表取值
Statue GetElem(Sqlist L, int i, Elemtype &e) // 在线性表L中， 取下标为i的元素, 并保存在e中
{
}

void print(Sqlist L) // 打印线性表
{
    for (int i = 0; i < L.length; i++)
        cout << L.elem[i].a << ' ' << L.elem[i].b << '\n';
}

signed main()
{
    Sqlist L;
    Elemtype e = {"zzzzzaxy", 11.22};

    Initlist(L, 10);
    Modifylist(L, 0, e);
    Insertlist(L, 2, e);
    Deletelist(L, 1, e);
    e.a = "xyzzzzh";
    Modifylist(L, 1, e);
    cout << LocateElem(L, e) << '\n';
    GetElem(L, 0, e);
    cout << e.a << ' ' << e.b << '\n';

    print(L); // 打印

    return 0;
}