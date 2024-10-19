int n, m;
int nxt[N];
string s, p;

void get_Next(string s, int ne[]) // 这个函数对字符串s进行预处理得到next数组
{
    int j = 0;
    ne[0] = 0; // 初始化
    for (int i = 1; i < s.size(); i++)
    { // i指针指向的是后缀末尾，j指针指向的是前缀末尾
        while (j > 0 && s[i] != s[j])
            j = ne[j - 1]; // 前后缀不相同，去找j前一位的最长相等前后缀
        if (s[i] == s[j])
            j++;   // 前后缀相同，j指针后移
        ne[i] = j; // 更新next数组
    }
}
