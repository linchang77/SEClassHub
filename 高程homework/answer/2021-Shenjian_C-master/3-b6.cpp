/*1953609 ��� ���͢*/
#include <iostream>
using namespace std;
int main()
{
    int year, month, day;
    cout << "�������꣬�£���" << endl;
    cin >> year >> month >> day;
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        if (month == 1)
        {
            if (day < 1 || day>31)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day << "��" << endl;
            }
        }
        else if (month == 2)
        {
            if (day < 1 || day>29)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day+31 << "��" << endl;
            }
        }
        else if (month == 3)
        {
            if (day < 1 || day>31)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31+29 << "��" << endl;
            }
        }
        else if (month == 4)
        {
            if (day < 1 || day>30)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 29+31 << "��" << endl;
            }
        }
        else if (month == 5)
        {
            if (day < 1 || day>31)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 29+31+30 << "��" << endl;
            }
        }
        else if (month == 6)
        {
            if (day < 1 || day>30)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 29 + 31 + 30+31 << "��" << endl;
            }
        }
        else if (month == 7)
        {
            if (day < 1 || day>31)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 29 + 31 + 30 + 31+30 << "��" << endl;
            }
        }
        else if (month == 8)
        {
            if (day < 1 || day>31)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 29 + 31 + 30 + 31 + 30 +31<< "��" << endl;
            }
        }
        else if (month == 9)
        {
            if (day < 1 || day>30)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 29 + 31 + 30 + 31 + 30 + 31+31 << "��" << endl;
            }
        }
        else if (month == 10)
        {
            if (day < 1 || day>31)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31+30 << "��" << endl;
            }
        }
        else if (month == 11)
        {
            if (day < 1 || day>30)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30+31 << "��" << endl;
            }
        }
        else if (month == 12)
        {
            if (day < 1 || day>31)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31+30 << "��" << endl;
            }
        }
        else
        {
            cout << "�������-�·ݲ���ȷ" << endl;
        }  
    }
    else
    {
        if (month == 1)
        {
            if (day < 1 || day>31)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day << "��" << endl;
            }
        }
        else if (month == 2)
        {
            if (day < 1 || day>28)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 << "��" << endl;
            }
        }
        else if (month == 3)
        {
            if (day < 1 || day>31)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 28 << "��" << endl;
            }
        }
        else if (month == 4)
        {
            if (day < 1 || day>30)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 28 + 31 << "��" << endl;
            }
        }
        else if (month == 5)
        {
            if (day < 1 || day>31)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 28 + 31 + 30 << "��" << endl;
            }
        }
        else if (month == 6)
        {
            if (day < 1 || day>30)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 28 + 31 + 30 + 31 << "��" << endl;
            }
        }
        else if (month == 7)
        {
            if (day < 1 || day>31)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 28 + 31 + 30 + 31 + 30 << "��" << endl;
            }
        }
        else if (month == 8)
        {
            if (day < 1 || day>31)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 << "��" << endl;
            }
        }
        else if (month == 9)
        {
            if (day < 1 || day>30)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 << "��" << endl;
            }
        }
        else if (month == 10)
        {
            if (day < 1 || day>31)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 << "��" << endl;
            }
        }
        else if (month == 11)
        {
            if (day < 1 || day>30)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 << "��" << endl;
            }
        }
        else if (month == 12)
        {
            if (day < 1 || day>31)
                cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
            else
            {
                cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 << "��" << endl;
            }
        }
        else
        {
        cout << "�������-�·ݲ���ȷ" << endl;
        }
    }
    return 0;
}
