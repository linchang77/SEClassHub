/*1953609 ��� ���͢*/
#include <iostream>
using namespace std;

int main()
{
    const int month1[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    const int month2[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
    int year, month, day;
    int tag = 0;
    cout << "�������꣬�£���" << endl;
    cin >> year >> month >> day;
    const int day2 = day;
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        if (month == 1)
        {
            if (day < 1 || day>31)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if (month == 2)
        {
            if (day < 1 || day>29)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if (month == 3)
        {
            if (day < 1 || day>31)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if (month == 4)
        {
            if (day < 1 || day>30)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if (month == 5)
        {
            if (day < 1 || day>31)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if (month == 6)
        {
            if (day < 1 || day>30)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if (month == 7)
        {
            if (day < 1 || day>31)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if (month == 8)
        {
            if (day < 1 || day>31)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if (month == 9)
        {
            if (day < 1 || day>30)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if (month == 10)
        {
            if (day < 1 || day>31)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if (month == 11)
        {
            if (day < 1 || day>30)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if (month == 12)
        {
            if (day < 1 || day>31)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if(month<1||month>12)
        {
            tag = 1;
            cout << "�������-�·ݲ���ȷ" << endl;
        }
        if(tag==0)
        {
            for (int i = 0; i < month-1; i++)
                day += month2[i];
            cout << year << "-" << month << "-" << day2 << "��" << year << "��ĵ�" << day << "��" << endl;
        }
    }
    else
    {
        if (month == 1)
        {
            if (day < 1 || day>31)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if (month == 2)
        {
            if (day < 1 || day>28)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if (month == 3)
        {
            if (day < 1 || day>31)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if (month == 4)
        {
            if (day < 1 || day>30)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if (month == 5)
        {
            if (day < 1 || day>31)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if (month == 6)
        {
            if (day < 1 || day>30)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if (month == 7)
        {
            if (day < 1 || day>31)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if (month == 8)
        {
            if (day < 1 || day>31)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if (month == 9)
        {
            if (day < 1 || day>30)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if (month == 10)
        {
            if (day < 1 || day>31)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if (month == 11)
        {
            if (day < 1 || day>30)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if (month == 12)
        {
            if (day < 1 || day>31)
            {
                tag = 1;
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            }
        }
        else if (month < 1 || month>12)
        {
            tag = 1;
            cout << "�������-�·ݲ���ȷ" << endl;
        }
        if(tag==0)
        {
            for (int i = 0; i < month-1; i++)
                day += month1[i];
            cout << year << "-" << month << "-" << day2 << "��" << year << "��ĵ�" << day << "��" << endl;
        }
    }
    return 0;
}


