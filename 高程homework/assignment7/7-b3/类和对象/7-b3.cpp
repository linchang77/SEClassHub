/* 2250420 �� �¾� */
#include <iostream>
using namespace std;

/* 1�����������κ����͵�ȫ�ֱ������������������궨���
   2������������κ���ʽ��ȫ�ֺ���
*/

/* --- ����Ķ��岹������ --- */
class Days {
private:
	int year;
	int month;
	int day;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա

	/* ������Բ�����Ҫ�����Ա�����Ķ��壨���ṩ����磬���������������Ա�������ã��������Ϊ˽�У��������ޣ��������壩 */

public:
	int calc_days();     //�����ǵ���ĵڼ���
	Days(int a, int b,int c);
	/* ������Բ���������Ҫ�����Ա�����Ķ���(����ʵ��)���������ޣ��������� */

};


/* --- �˴��������Ա����������ʵ�� --- */
Days::Days(int a,int b,int c)
{
	year = a;
	month = b;
	day = c;
}
int Days::calc_days()
{
	bool leap_year = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	if (leap_year)
	{
		switch (month)
		{
		case 1:
			if (day <= 0 || day > 31)
			{
				return -1;
			}
			return day ;
			break;
		case 2:
			if (day <= 0 || day > 29)
			{
				return -1;
			}
			return day + 31 ;
			break;
		case 3:
			if (day <= 0 || day > 31)
			{
				return -1;
			}
			return day + 31 + 29 ;
			break;
		case 4:
			if (day <= 0 || day > 30)
			{
				return -1;
			}
			return day + 31 + 29 + 31 ;
			break;
		case 5:
			if (day <= 0 || day > 31)
			{
				return -1;
			}
			return day + 31 + 29 + 31 + 30 ;
			break;
		case 6:
			if (day <= 0 || day > 30)
			{
				return -1;
			}
			return day + 31 + 29 + 31 + 30 + 31 ;
			break;
		case 7:
			if (day <= 0 || day > 31)
			{
				return -1;
			}
			return day + 31 + 29 + 31 + 30 + 31 + 30 ;
			break;
		case 8:
			if (day <= 0 || day > 31)
			{
				return -1;
			}
			return day + 31 + 29 + 31 + 30 + 31 + 30 + 31 ;
			break;
		case 9:
			if (day <= 0 || day > 30)
			{
				return -1;
			}
			return day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31  ;
			break;
		case 10:
			if (day <= 0 || day > 31)
			{
				return -1;
			}
			return day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30  ;
			break;
		case 11:
			if (day <= 0 || day > 30)
			{
				return -1;
			}
			return day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31  ;
			break;
		case 12:
			if (day <= 0 || day > 31)
			{
				return -1;
			}
			return day + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30  ;
			break;
		default:
			return -1;
		}
	}
	else
	{
		switch (month)
		{
		case 1:
			if (day <= 0 || day > 31)
			{
				return -1;
			}
			return day ;
			break;
		case 2:
			if (day <= 0 || day > 28)
			{
				return -1;
			}
			return day + 31 ;
			break;
		case 3:
			if (day <= 0 || day > 31)
			{
				return -1;
			}
			return day + 31 + 28 ;
			break;
		case 4:
			if (day <= 0 || day > 30)
			{
				return -1;
			}
			return day + 31 + 28 + 31 ;
			break;
		case 5:
			if (day <= 0 || day > 31)
			{
				return -1;
			}
			return day + 31 + 28 + 31 + 30;
			break;
		case 6:
			if (day <= 0 || day > 30)
			{
				return -1;
			}
			return day + 31 + 28 + 31 + 30 + 31 ;
		case 7:
			if (day <= 0 || day > 31)
			{
				return -1;
			}
			return day + 31 + 28 + 31 + 30 + 31 + 30;
		case 8:
			if (day <= 0 || day > 31)
			{
				return -1;
			}
			return day + 31 + 28 + 31 + 30 + 31 + 30 + 31;
		case 9:
			if (day <= 0 || day > 30)
			{
				return -1;
			}
			return day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 ;
		case 10:
			if (day <= 0 || day > 31)
			{
				return -1;
			}
			return day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 ;
		case 11:
			if (day <= 0 || day > 30)
			{
				return -1;
			}
			return day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
		case 12:
			if (day <= 0 || day > 31)
			{
				return -1;
			}
			return day + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
		default:
			return -1;
		}
	}
	return -1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2020, 3, 18);
		cout << "Ӧ�����78�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 3, 18);
		cout << "Ӧ�����77�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 12, 31);
		cout << "Ӧ�����366��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 12, 31);
		cout << "Ӧ�����365��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 2, 29);
		cout << "Ӧ�����60�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 2, 29);
		cout << "Ӧ�����-1�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	return 0;
}