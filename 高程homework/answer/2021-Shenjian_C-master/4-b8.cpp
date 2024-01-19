/*1953609 ��� ���͢*/
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�����������hanoi�ж���һ����̬�ֲ�����
   3������������������������ʼ/Ŀ�����ĺ���������������ʹ��ѭ�������������
   4����������ú������У���main�в���������κ���ʽ��ѭ����while��do-while��for��if-goto��
      ���������main�н��У���main���������ѭ��
   --------------------------------------------------------------------- */

   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
               3��������һ����̬�ֲ�����
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static int sum = 1;
    if (n == 1)
    {
        cout << setiosflags(ios::right) << setw(5) << sum << ":" << setw(3) << n << "# " << src << "-->" << dst << endl;
        sum++;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        cout << setiosflags(ios::right) << setw(5) << sum << ":" << setw(3) << n << "# " << src << "-->" << dst << endl;
        sum++;
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����������(��������뺯��)�����õݹ麯��
***************************************************************************/
int main()
{
    int n;
    while (1)
    {
        cout << "�����뺺ŵ���Ĳ�����1-16��" << endl;
        cin >> n;
        if (!cin.good() || n > 16 || n < 1)
        {
            cin.clear();
            cin.ignore(2147483647, '\n');
            continue;
        }
        else
        {
            cin.clear();
            cin.ignore(2147483647, '\n');
            break;
        }
    }
    char start, end;
    while (1)
    {
        cout << "��������ʼ����A-C��" << endl;
        cin >> start;
        if (!cin.good() || start > 99 || start < 65 || (start < 97 && start>67))
        {
            cin.clear();
            cin.ignore(2147483647, '\n');
            continue;
        }
        else
        {
            if (start > 96)
                start -= 32;
            cin.clear();
            cin.ignore(2147483647, '\n');
            break;
        }
    }
    while (1)
    {
        cout << "������Ŀ������A-C��" << endl;
        cin >> end;
        if (!cin.good() || end > 99 || end < 65 || (end < 97 && end>67))
        {
            cin.clear();
            cin.ignore(2147483647, '\n');
            continue;
        }
        else if (end > 96)
        {
            end -= 32;
            if (end == start)
            {
                cout << "Ŀ����(" << start << ")" << "��������ʼ��(" << end << ")��ͬ" << endl;
                continue;
            }
        }
        else
        {
            if (end == start)
            {
                cout << "Ŀ����(" << start << ")" << "��������ʼ��(" << end << ")��ͬ" << endl;
                continue;
            }
        }
        cin.clear();
        cin.ignore(2147483647, '\n');
        break;
    }
    char tmp = '0';
    if ((start == 65 && end == 66) || (end == 65 && start == 66))
        tmp = 'C';
    else if ((start == 65 && end == 67) || (end == 65 && start == 67))
        tmp = 'B';
    else if ((start == 66 && end == 67) || (end == 66 && start == 67))
        tmp = 'A';
    cout << "�ƶ�����Ϊ:" << endl;
    hanoi(n, start, tmp, end);
    return 0;
}
