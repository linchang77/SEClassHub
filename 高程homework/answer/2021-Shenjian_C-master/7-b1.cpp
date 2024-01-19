/* 1953609 ��� ���͢ */
#define _CRT_SECURE_NO_WARNINGS		//ʹ����VS��Ϊunsafe�ĺ���
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <conio.h>	//��getch����˲���Ҫ֧��Linux
#include <string.h>	//Dev/CB��strlen��Ҫ
using namespace std;
#define minute_sec 60
#define hour_sec 3600
#define day_sec 86400
#define normal_year 31536000
#define run_year 31622400
#define normal_month 2592000
struct tj_time {
	int tj_year;	//��ʾ���
	int tj_month;	//��ʾ��(1-12)
	int tj_day;	//��ʾ��(1-28/29/30/31)
	int tj_hour;	//��ʾСʱ(0-23)
	int tj_minute;	//��ʾ��(0-59)
	int tj_second;	//��ʾ��(0-59)
};

/* �����ڴ˶���������Ҫ�ĺ��� */
int cal_runyear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else
		return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�������ʾ���ȴ��س���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void wait_for_enter(const char* const prompt = NULL)
{
	if ((prompt == NULL) || (strlen(prompt) == 0)) //˼��һ�£�||���������������ܷ񻥻�
		cout << endl << "���س�������";
	else
		cout << endl << prompt << "�����س�������";

	while (_getch() != '\r')
		;
	cout << endl << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����ϵͳ��ת��������������ֵת��Ϊ�뱾�����ƵĽṹ�岢���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void system_time_output(const time_t year)  //time_t�ı�����64λ�޷�������
{
	struct tm* tt;	//struct tm Ϊϵͳ����Ľṹ��

	tt = localtime(&year);	//localtimeΪϵͳ����

	/* tm_*** Ϊstruct tm�еĳ�Ա���ͱ����struct tj_time��������ݲ���ȫ���ϣ����庬���Լ������������ */
	cout << setfill('0') << setw(4) << tt->tm_year + 1900 << '-'
		<< setw(2) << tt->tm_mon + 1 << '-'
		<< setw(2) << tt->tm_mday << ' '
		<< setw(2) << tt->tm_hour << ':'
		<< setw(2) << tt->tm_min << ':'
		<< setw(2) << tt->tm_sec << endl;

	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��Զ���ת������������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void tj_time_output(const struct tj_time* const tp)
{
	/* ʵ���Զ���ṹ������������ʽ��system_time_output��ͬ */
	cout << setfill('0') << setw(4) << tp->tj_year << '-'
		<< setw(2) << tp->tj_month << '-'
		<< setw(2) << tp->tj_day << ' '
		<< setw(2) << tp->tj_hour << ':'
		<< setw(2) << tp->tj_minute << ':'
		<< setw(2) << tp->tj_second << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��Զ���ת������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
struct tj_time* tj_time_convert(int year)
{
	static struct tj_time result;	//���徲̬�ֲ���������׼��

	/* ʵ�ֹ��̿�ʼ�������������Ӧ�Ķ��弰ִ����伴�� */
	int month_sec[13] = { 0,2678400,2419200,2678400,2592000,2678400,2592000,2678400, 2678400,2592000,2678400,2592000,2678400 };
	int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	result = {1970,1,1,8,0,0};
	while (year >= normal_year)
	{
		if (cal_runyear(result.tj_year))
		{
			year -= run_year;
			result.tj_year++;
		}
		else
		{
			year -= normal_year;
			result.tj_year++;
		}
	}
	if (cal_runyear(result.tj_year))
	{
		month_sec[2] += 86400;
		month[2]++;
	}
	for (int i = 1; i < 12; i++)
	{
		if (year < month_sec[i])
			break;
		else
		{
			year -= month_sec[i];
			result.tj_month++;
		}
		if (result.tj_month > 12)
		{
			result.tj_month -= 12;
			result.tj_year++;
		}
	}
	while (year >= day_sec)
	{
		year -= day_sec;
		result.tj_day++;
		if (result.tj_day > month[result.tj_month])
		{
			result.tj_day -= month[result.tj_month];
			result.tj_month++;
		}
		if (result.tj_month > 12)
		{
			result.tj_month -= 12;
			result.tj_year++;
		}
	}
	while (year >= hour_sec)
	{
		year -= hour_sec;
		result.tj_hour++;
		if (result.tj_hour >= 24)
		{
			result.tj_hour -= 24;
			result.tj_day++;
		}
		if (result.tj_day > month[result.tj_month])
		{
			result.tj_day -= month[result.tj_month];
			result.tj_month++;
		}
		if (result.tj_month > 12)
		{
			result.tj_month -= 12;
			result.tj_year++;
		}
	}
	while (year >= minute_sec)
	{
		year -= minute_sec;
		result.tj_minute++;
		if (result.tj_minute >= 60)
		{
			result.tj_minute -= 60;
			result.tj_hour++;
		}
		if (result.tj_hour >= 24)
		{
			result.tj_hour -= 24;
			result.tj_day++;
		}
		if (result.tj_day > month[result.tj_month])
		{
			result.tj_day -= month[result.tj_month];
			result.tj_month++;
		}
		if (result.tj_month > 12)
		{
			result.tj_month -= 12;
			result.tj_year++;
		}
	}
	result.tj_second = year;
	/* ʵ�ֹ��̽��� */

	return &result;	//ע�⣬���ص��Ǿ�̬�ֲ������ĵ�ַ������䲻׼��
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	int read_time;
	struct tj_time* tp;

	for (;;) {
		cin >> read_time; //��Ϊ���������ض��򣬴˴������κ���ʾ

		/* ��������<0���˳�ѭ�� */
		if (cin.good() == 0 || read_time < 0)
			break;

		cout << "����             : " << read_time << endl;
		cout << "ϵͳת���Ľ��   : ";
		system_time_output(read_time);

		cout << "�Զ���ת���Ľ�� : ";
		tp = tj_time_convert(read_time);
		tj_time_output(tp);

		wait_for_enter();
	}

	if (1) {
		struct tj_time* tp;
		int t = (int)time(0);		//ϵͳ������ȡ��ǰϵͳʱ�䣨��1970-01-01 00:00:00��ʼ��������

		cout << "��ǰϵͳʱ��     : " << t << endl;
		cout << "ϵͳת���Ľ��   : ";
		system_time_output(t);

		cout << "�Զ���ת���Ľ�� : ";
		tp = tj_time_convert(t);
		tj_time_output(tp);

		wait_for_enter();
	}

	return 0;
}
