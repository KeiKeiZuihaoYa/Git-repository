// 线性表定义
typedef struct
{
    int a;
    double b;
} Elemtype;

typedef struct
{
    int length;
    Elemtype *elem; // 数组
} Sqlist;

#define Statue int
#define OK 1
#define ERROR -1
#define MAXSIZE 100
// 线性表初始化
Statue Initlist(Sqlist &L)
{
    // 申请内存空间存放元素（数组）
    L.elem = (Elemtype *)malloc(MAXSIZE * sizeof(Elemtype));
    // C++ Java
    L.elem = new Elemtype[MAXSIZE];
    if (!L.elem)
        return ERROR;
    L.length = MAXSIZE;
    return OK;
}

// 线性表取值
Statue Getelem(Sqlist L, int i, Elemtype &e) // L 是 线性表， i 是 下标， e 是 线性表下标为i的元素
{
    if (i >= L.length) // 元素下标从0开始
        return ERROR;
    e = L.elem[i];
    return OK;
}

// 查找
Statue LocateElem(Sqlist L, Elemtype e) // 在线性表L中， 是否存在一个元素的值为 e , 返回元素下标
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)
            return i;
    }
    return L.length; // STL 中的 end()
}

// 插入
Statue InsElem(Sqlist &L, int i, Elemtype e) // 在线性表L中， 插入元素e， 下标为i
{
    if (i >= L.length)
        return ERROR;

    // 把插入位置后面的元素都往后移一位
    for (int j = L.length; j > i; j--)
    {
        L.elem[j] = L.elem[j - 1];
    }
    L.elem[i] = e;
    L.length++;
    return OK;
}

// 删除
Statue DelElem(Sqlist &L, int i) // 在线性表L中， 删除下标为i的元素
{
    if (i >= L.length)
        return ERROR;

    // 把插入位置后面的元素都往后移一位
    for (int j = i; j < L.length; j++)
    {
        L.elem[j] = L.elem[j + 1];
    }
    L.length--;
    return OK;
}

// 修改
Statue ModElem(Sqlist &L, int i, Elemtype e) // 在线性表L中， 修改下标为i的元素为e
{
    if (i >= L.length)
        return ERROR;

    L.elem[i] = e;
    return OK;
}
