/* 学号 姓名 班级 */

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int index = 0;
    if (str == NULL)
        return 0;
    while (*str!='\0')
    {
        str++;
        index++;
    }
    return index;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strcat(char* s1, const char* s2)
{
    if (s1 == NULL)
        return NULL;
    if (s2 == NULL)
        return s1;
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = s1 + tj_strlen(s1);
    for (; *s2 != '\0'; s2++, p++)
    {
        *p = *s2;
    }
    *p = '\0';
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strncat(char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL)
        return NULL;
    if (s2 == NULL)
        return s1;
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = s1 + tj_strlen(s1);
    int count = 0;
    for (; *s2 != '\0'&&count<len; s2++, p++)
    {
        *p = *s2;
        count++;
    }
    *p = '\0';
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strcpy(char* s1, const char* s2)
{
    if (s1 == NULL)
        return NULL;
    if (s2 == NULL)
    {
        *s1 = '\0';
        return s1;
    }
    
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = s1;
    while (*s2 != '\0')
    {
        *p = *s2;
        p++;
        s2++;
   }
    *p= '\0';
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strncpy(char* s1, const char* s2, const int len)
{
    if (s1 == NULL)
        return NULL;
    if (s2 == NULL)
        return s1;

    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = s1;
    int count = 0;
    while (*s2 != '\0'&&count<len)
    {
        *p = *s2;
        p++;
        s2++;
        count++;
    }
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char* s1, const char* s2)
{
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 1;
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    while (1)
    {
        if (*s1 != *s2)
            return *s1 - *s2;
        if (*s1 == '\0' || *s2 == '\0')
            break;
        s1++;
        s2++;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char* s1, const char* s2)
{
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 1;
   /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    while (1)
    {
        if (*s1 != *s2)
        {
            char news1;
            char news2;
            if (*s1 <= 'Z' && *s1 >= 'A')
            {
                news1 = *s1 + 32;
                if (news1 != *s2)
                    return news1 - *s2;
            }
            else if (*s2 <= 'Z' && *s2 >= 'A')
            {
                news2 = *s2 + 32;
                if (news2 != *s1)
                    return *s1 - news2;
            }
            else
                return *s1 - *s2;
        }
        if (*s1 == '\0' || *s2 == '\0')
            break;
        s1++;
        s2++;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 1;
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int count = 0;
    while (count<len)
    {
        if (*s1 != *s2)
            return *s1 - *s2;
        if (*s1 == '\0' || *s2 == '\0')
            break;
        s1++;
        s2++;
        count++;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char* s1, const char* s2, const int len)
{
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 1;
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int count = 0;
    while (count < len)
    {
        if (*s1 != *s2)
        {
            char news1;
            char news2;
            if (*s1 <= 'Z' && *s1 >= 'A')
            {
                news1 = *s1 + 32;
                if (news1 != *s2)
                    return news1 - *s2;
            }
            else if (*s2 <= 'Z' && *s2 >= 'A')
            {
                news2 = *s2 + 32;
                if (news2 != *s1)
                    return *s1 - news2;
            }
            else
                return *s1 - *s2;
        }
        if (*s1 == '\0' || *s2 == '\0')
            break;
        s1++;
        s2++;
        count++;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strupr(char* str)
{
    if (str == NULL)
        return NULL;
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = str;
    while (*str != '\0')
    {
        if (*str <= 'z' && *str >= 'a')
            *str -= 32;
        str++;
    }
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strlwr(char* str)
{
    if (str == NULL)
        return NULL;
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p = str;
    while (*str != '\0')
    {
        if (*str <= 'Z' && *str >= 'A')
            *str += 32;
        str++;
    }
    return p;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char* str, const char ch)
{
    if (str == NULL)
        return 0;
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int count = 1;
    while (*str != '\0')
    {
        if (*str == ch)
            return count;
        count++;
        ++str;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char* str, const char* substr)
{
    if (str == NULL||substr==NULL)
        return 0;
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int tag = 0;
    int count = 1;
    while (*str != '\0')
    {
        int subcount = 0;
        if (*str == *substr)
        {
            while (*substr != '\0')
            {
                if (*str != *substr)
                {
                    tag = 1;
                    break;
                }
                substr++;
                str++;
                subcount++;
            }
            if (tag == 0)
                return count;
            tag = 0;
            str = str - subcount;
            substr = substr - subcount;
        }

        count++;
        str++;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char* str, const char ch)
{
    if (str == NULL)
        return 0;
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int count = 1;
    int lastcount=0;
    while (*str != '\0')
    {
        if (*str == ch)
            lastcount = count;
        count++;
        ++str;
    }
    return lastcount;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char* str, const char* substr)
{
    if (str == NULL || substr == NULL)
        return 0;
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int tag = 0;
    int count = 1;
    int lastcount = 0;
    while (*str != '\0')
    {
        int subcount = 0;
        if (*str == *substr)
        {
            while (*substr != '\0')
            {
                if (*str != *substr)
                {
                    tag = 1;
                    break;
                }
                substr++;
                str++;
                subcount++;
            }
            if (tag == 0)
                lastcount = count;
            tag = 0;
            str = str - subcount;
            substr = substr - subcount;
        }

        count++;
        str++;
    }
    return lastcount;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strrev(char* str)
{
    if (str == NULL)
        return NULL;
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p1 = str;
    char* p2 = str+tj_strlen(str)-1;
    while (p1 <= p2)
    {
        char temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        p1++;
        p2--;
    }
    return str;
}