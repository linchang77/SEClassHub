/*2250420 软工 陈君*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
/***************************************************************************
  函数名称：daxie 
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch(num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
		}
}
int main()
{   double a;
    int flag_of_zero=0;
    cout << "请输入[0-100亿)之间的数字:" << endl;
    cin >> a;
	int a1 = (int)(a/10);//将这个数十位之前的数取出来 
	int b1 = a1 / 100000000;//十亿 
	int b2 = a1 / 10000000 % 10;//亿 
	int b3 = a1 / 1000000 % 10;//千万 
	int b4 = a1 / 100000 % 10;//百万 
	int b5 = a1 / 10000 % 10;//十万 
	int b6 = a1 / 1000 % 10;//万 
	int b7 = a1 / 100 % 10;//千 
	int b8 = a1 / 10 % 10;//百 
	int b9 = a1 % 10;//十 
	int a2 = round((a/10-a1)*1000);
	int b10 = a2 / 100 % 10;//圆 
	int b11 = a2 / 10 % 10;//角 
	int b12 = a2  % 10;//分
//取出每一位的数字

    cout<<"大写结果是:"<<endl;  
 
	switch(b1)
	{
		case 1:
			daxie(1,1);
			cout<<"拾";
			break; 
		case 2:
			daxie(2,flag_of_zero);
		    cout<<"拾";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"拾";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"拾";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"拾";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"拾";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"拾";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"拾";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"拾";
			break;
	}
	switch(b2)
	{
		case 1:
			daxie(1,flag_of_zero);
			cout<<"亿"; 
			break; 
		case 2:
			daxie(2,flag_of_zero);
		    cout<<"亿";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"亿";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"亿";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"亿";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"亿";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"亿";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"亿";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"亿";
			break;
		case 0:
			if(b1==0&&b2==0)
			;
			else
			cout<<"亿";
			break; 
	}
	switch(b3)
	{
		case 1:
			daxie(1,flag_of_zero);
			cout<<"仟"; 
			break; 
		case 2:
			daxie(2,flag_of_zero);
		    cout<<"仟";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"仟";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"仟";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"仟";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"仟";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"仟";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"仟";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"仟";
			break;
		case 0:
		if(b1==0&&b2==0)
		    break;
		if(b4!=0) 
		{
			daxie(0,1);
		    break; 
		} 
	}
	switch(b4)
	{
		case 1:
			daxie(1,flag_of_zero);
			cout<<"佰"; 
			break;
		case 2:
			daxie(2,flag_of_zero);
		    cout<<"佰";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"佰";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"佰";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"佰";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"佰";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"佰";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"佰";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"佰";
			break;
		case 0:
		if(b1==0&&b2==0&&b3==0)
	        break;
		if(b5!=0) 
		{
		daxie(0,1);
		break; 
		}
	}
	switch(b5)
	{
		case 1:
			if(b4==0&&b1==0&&b2==0&&b3==0)
			{
		        cout<<"拾";
			    break;
			} 
			else
			{
				daxie(1,flag_of_zero);
				cout<<"拾";
			    break;
			 } 
		case 2:
			daxie(2,flag_of_zero);
		    cout<<"拾";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"拾";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"拾";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"拾";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"拾";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"拾";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"拾";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"拾";
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0)
	        break;
		    if(b6!=0) 
		    {
		        cout<<"零";
		        break; 
		    } 
	}
	switch(b6)
	{
		case 1:
			daxie(1,flag_of_zero);
			cout<<"万"; 
			break;
		case 2:
			daxie(2,flag_of_zero);
		    cout<<"万";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"万";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"万";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"万";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"万";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"万";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"万";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"万";
			break;
		case 0:
		    if(b3==0&&b4==0&&b5==0&&b6==0)
	        ;
		    else
			cout<<"万";
			
	}
		switch(b7)
	{
		case 1:
			daxie(1,flag_of_zero);
			cout<<"仟"; 
			break;
		case 2:
			daxie(2,flag_of_zero);
		    cout<<"仟";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"仟";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"仟";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"仟";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"仟";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"仟";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"仟";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"仟";
			break;
		case 0:
		if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0)
		    break;
		if(b8!=0) 
		{
			daxie(0,1); 
		    break; 
		}
	}
	switch(b8)
	{
		case 1:
			daxie(1,flag_of_zero);
			cout<<"佰"; 
			break;
		case 2:
			daxie(2,flag_of_zero);
		    cout<<"佰";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"佰";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"佰";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"佰";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"佰";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"佰";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"佰";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"佰";
			break;
		case 0:
		if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0)
	        break;
		if(b9!=0) 
		{
		daxie(0,1);
		break; 
		}
	}
	switch(b9)
	{
		case 1:
				daxie(1,flag_of_zero);
				cout<<"拾";
			    break;
		case 2:	 
			daxie(2,flag_of_zero);
		    cout<<"拾";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"拾";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"拾";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"拾";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"拾";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"拾";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"拾";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"拾";
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0)
	        break;
		    if(b10!=0) 
		    {
		        cout<<"零";
		        break; 
		    } 
	}
	switch(b10)
	{
		case 1:
			daxie(1,flag_of_zero);
			cout<<"圆"; 
			break;
		case 2:
			daxie(2,flag_of_zero);
		    cout<<"圆";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"圆";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"圆";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"圆";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"圆";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"圆";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"圆";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"圆";
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0&&b9==0)
	        break;
		    else
			cout<<"圆"; 
	}
	switch(b11)
	{
		case 1:
			daxie(1,flag_of_zero);
			cout<<"角"; 
			break;
		case 2:
			daxie(2,flag_of_zero);
		    cout<<"角";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"角";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"角";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"角";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"角";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"角";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"角";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"角";
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0&&b9==0&&b10==0)
	        break;
		    if(b12!=0)
		    daxie(0,1);		 
	}
	switch(b12)
	{
		case 1:
			daxie(1,flag_of_zero);
			cout<<"分"; 
			break;
		case 2:
			daxie(2,flag_of_zero);
		    cout<<"分";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"分";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"分";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"分";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"分";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"分";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"分";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"分";
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0&&b9==0&&b10==0&&b11==0)
		    {
		    	daxie(0,1);
				cout<<"圆"; 
		    	break;
			} 		 
	}
		if(b12==0)
	    cout<<"整"; 
	    cout<<endl;  
	return 0;
}

