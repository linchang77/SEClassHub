/* 1953609 ��� ���͢ */
#include <iostream>
using namespace std;

int judge(char* str)
{
    for (char* h = str, *t = str + strlen(str) - 2; h < t; h++, t--)
    {
        if (*h != *t)
        {
            cout << "no" << endl;
            return 1;
        }
    }
    return 0;
}
int main()
{
    char str[81];
    cout << "������һ������С��80���ַ��������Ĵ���" << endl;
    fgets(str, 80,stdin);
    int tag = -1;
    tag = judge(str);
    if (tag != 1)
        cout << "yes" << endl;
    return 0;
}