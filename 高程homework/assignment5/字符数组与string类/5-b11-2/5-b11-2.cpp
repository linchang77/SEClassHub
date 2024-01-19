/* 软工 2250420 陈君 */
#include <iostream>
#include <string>
#include<cmath> 
//可按需增加需要的头文件
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void daxie(int num, int flag_of_zero, string& result)
{
	if (flag_of_zero && 0 == num)
	{
		result += chnstr[num * 2];
		result += chnstr[num * 2 + 1];
	}
	else if (num >= 1 && num <= 9)
	{
		result += chnstr[num * 2];
		result += chnstr[num * 2 + 1];
	}
}
int main()
{
	/* --允许添加需要的内容 --*/
	double a;
	int flag_of_zero = 0;
	std::cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> a;
	int a1 = (int)(a / 10);//将这个数十位之前的数取出来 
	int b1 = a1 / 100000000;//十亿 
	int b2 = a1 / 10000000 % 10;//亿 
	int b3 = a1 / 1000000 % 10;//千万 
	int b4 = a1 / 100000 % 10;//百万 
	int b5 = a1 / 10000 % 10;//十万 
	int b6 = a1 / 1000 % 10;//万 
	int b7 = a1 / 100 % 10;//千 
	int b8 = a1 / 10 % 10;//百 
	int b9 = a1 % 10;//十 
	int a2 = round((a / 10 - a1) * 1000);
	int b10 = a2 / 100 % 10;//圆 
	int b11 = a2 / 10 % 10;//角 
	int b12 = a2 % 10;//分
	//取出每一位的数字
	cout << "大写结果是:" << endl;
	if (b1 != 0)
	{
		daxie(b1, flag_of_zero, result);
		result += "拾";
	}

	switch (b2)
	{
	case 0:
		if (b1 == 0 && b2 == 0)
			;
		else
			result += "亿";
		break;
	default:
		daxie(b2, flag_of_zero, result);
		result += "亿";
	}
	switch (b3)
	{
	case 0:
		if (b1 == 0 && b2 == 0)
			break;
		if (b4 != 0)
		{
			daxie(0, 1, result);
			break;
		}
		break;
	default:
		daxie(b3, flag_of_zero, result);
		result += "仟";
	}
	switch (b4)
	{
	case 0:
		if (b1 == 0 && b2 == 0 && b3 == 0)
			break;
		if (b5 != 0)
		{
			daxie(0, 1, result);
			break;
		}
		break;
	default:
		daxie(b4, flag_of_zero, result);
		result += "佰";
	}
	switch (b5)
	{
	case 1:
		if (b4 == 0 && b1 == 0 && b2 == 0 && b3 == 0)
		{
			result += "拾";
			break;
		}
		else
		{
			daxie(1, flag_of_zero, result);
			result += "拾";
			break;
		}
		break;
	case 0:
		if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0)
			break;
		if (b6 != 0)
		{
			result += "零";
			break;
		}
		break;
	default:
		daxie(b5, flag_of_zero, result);
		result += "拾";
	}
	switch (b6)
	{
	case 0:
		if (b3 == 0 && b4 == 0 && b5 == 0 && b6 == 0)
			;
		else
			result += "万";
		break;
	default:
		daxie(b6, flag_of_zero, result);
		result += "万";
	}
	switch (b7)
	{
	case 0:
		if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0 && b5 == 0 && b6 == 0)
			break;
		if (b8 != 0)
		{
			daxie(0, 1, result);
			break;
		}
		break;
	default:
		daxie(b7, flag_of_zero, result);
		result += "仟";
	}
	switch (b8)
	{
	case 0:
		if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0 && b5 == 0 && b6 == 0 && b7 == 0)
			break;
		if (b9 != 0)
		{
			daxie(0, 1, result);
			break;
		}
		break;
	default:
		daxie(b8, flag_of_zero, result);
		result += "佰";
	}
	switch (b9)
	{
	case 0:
		if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0 && b5 == 0 && b6 == 0 && b7 == 0 && b8 == 0)
			break;
		if (b10 != 0)
		{
			result += "零";
			break;
		}
		break;
	default:
		daxie(b9, flag_of_zero, result);
		result += "拾";
	}
	switch (b10)
	{
	case 0:
		if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0 && b5 == 0 && b6 == 0 && b7 == 0 && b8 == 0 && b9 == 0)
			break;
		else
			result += "圆";
		break;
	default:
		daxie(b10, flag_of_zero, result);
		result += "圆";
	}
	switch (b11)
	{
	case 0:
		if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0 && b5 == 0 && b6 == 0 && b7 == 0 && b8 == 0 && b9 == 0 && b10 == 0)
			break;
		if (b12 != 0)
			daxie(0, 1, result);
		break;
	default:
		daxie(b11, flag_of_zero, result);
		result += "角";
	}
	switch (b12)
	{
	case 0:
		if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0 && b5 == 0 && b6 == 0 && b7 == 0 && b8 == 0 && b9 == 0 && b10 == 0 && b11 == 0)
		{
			daxie(0, 1, result);
			result += "圆";
			break;
		}
		break;
	default:
		daxie(b12, flag_of_zero, result);
		result += "分";
	}
	if (b12 == 0)
		result += "整";
	cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
	return 0;
}