/* 1953609 ��� ���͢ */
#include <iostream>
#include<math.h>
using namespace std;

unsigned int trans(char* str, int len)
{
    unsigned int res = 0;
    int length = len;
    char* p = str;
    for (int i = 0; i < length; i++,p++,len--)
    {
        res += (*p - '0') * (unsigned int)(pow(2, len-1));
    }
    return res;
}
int main()
{
    char str[33];
    cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
    cin >> str;
    unsigned int res = 0;
    int len = strlen(str);
    res = trans(str, len);
    cout << res << endl;
    return 0;
}
