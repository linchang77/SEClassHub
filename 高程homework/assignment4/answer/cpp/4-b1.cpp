/*2250420 �� �¾�*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
/***************************************************************************
  �������ƣ�daxie 
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch(num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
		}
}
int main()
{   double a;
    int flag_of_zero=0;
    cout << "������[0-100��)֮�������:" << endl;
    cin >> a;
	int a1 = (int)(a/10);//�������ʮλ֮ǰ����ȡ���� 
	int b1 = a1 / 100000000;//ʮ�� 
	int b2 = a1 / 10000000 % 10;//�� 
	int b3 = a1 / 1000000 % 10;//ǧ�� 
	int b4 = a1 / 100000 % 10;//���� 
	int b5 = a1 / 10000 % 10;//ʮ�� 
	int b6 = a1 / 1000 % 10;//�� 
	int b7 = a1 / 100 % 10;//ǧ 
	int b8 = a1 / 10 % 10;//�� 
	int b9 = a1 % 10;//ʮ 
	int a2 = round((a/10-a1)*1000);
	int b10 = a2 / 100 % 10;//Բ 
	int b11 = a2 / 10 % 10;//�� 
	int b12 = a2  % 10;//��
//ȡ��ÿһλ������

    cout<<"��д�����:"<<endl;  
 
	switch(b1)
	{
		case 1:
			daxie(1,1);
			cout<<"ʰ";
			break; 
		case 2:
			daxie(2,flag_of_zero);
		    cout<<"ʰ";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"ʰ";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"ʰ";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"ʰ";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"ʰ";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"ʰ";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"ʰ";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"ʰ";
			break;
	}
	switch(b2)
	{
		case 1:
			daxie(1,flag_of_zero);
			cout<<"��"; 
			break; 
		case 2:
			daxie(2,flag_of_zero);
		    cout<<"��";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"��";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"��";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"��";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"��";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"��";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"��";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"��";
			break;
		case 0:
			if(b1==0&&b2==0)
			;
			else
			cout<<"��";
			break; 
	}
	switch(b3)
	{
		case 1:
			daxie(1,flag_of_zero);
			cout<<"Ǫ"; 
			break; 
		case 2:
			daxie(2,flag_of_zero);
		    cout<<"Ǫ";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"Ǫ";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"Ǫ";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"Ǫ";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"Ǫ";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"Ǫ";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"Ǫ";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"Ǫ";
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
			cout<<"��"; 
			break;
		case 2:
			daxie(2,flag_of_zero);
		    cout<<"��";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"��";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"��";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"��";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"��";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"��";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"��";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"��";
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
		        cout<<"ʰ";
			    break;
			} 
			else
			{
				daxie(1,flag_of_zero);
				cout<<"ʰ";
			    break;
			 } 
		case 2:
			daxie(2,flag_of_zero);
		    cout<<"ʰ";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"ʰ";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"ʰ";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"ʰ";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"ʰ";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"ʰ";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"ʰ";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"ʰ";
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0)
	        break;
		    if(b6!=0) 
		    {
		        cout<<"��";
		        break; 
		    } 
	}
	switch(b6)
	{
		case 1:
			daxie(1,flag_of_zero);
			cout<<"��"; 
			break;
		case 2:
			daxie(2,flag_of_zero);
		    cout<<"��";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"��";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"��";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"��";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"��";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"��";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"��";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"��";
			break;
		case 0:
		    if(b3==0&&b4==0&&b5==0&&b6==0)
	        ;
		    else
			cout<<"��";
			
	}
		switch(b7)
	{
		case 1:
			daxie(1,flag_of_zero);
			cout<<"Ǫ"; 
			break;
		case 2:
			daxie(2,flag_of_zero);
		    cout<<"Ǫ";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"Ǫ";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"Ǫ";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"Ǫ";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"Ǫ";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"Ǫ";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"Ǫ";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"Ǫ";
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
			cout<<"��"; 
			break;
		case 2:
			daxie(2,flag_of_zero);
		    cout<<"��";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"��";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"��";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"��";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"��";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"��";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"��";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"��";
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
				cout<<"ʰ";
			    break;
		case 2:	 
			daxie(2,flag_of_zero);
		    cout<<"ʰ";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"ʰ";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"ʰ";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"ʰ";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"ʰ";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"ʰ";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"ʰ";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"ʰ";
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0)
	        break;
		    if(b10!=0) 
		    {
		        cout<<"��";
		        break; 
		    } 
	}
	switch(b10)
	{
		case 1:
			daxie(1,flag_of_zero);
			cout<<"Բ"; 
			break;
		case 2:
			daxie(2,flag_of_zero);
		    cout<<"Բ";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"Բ";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"Բ";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"Բ";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"Բ";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"Բ";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"Բ";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"Բ";
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0&&b9==0)
	        break;
		    else
			cout<<"Բ"; 
	}
	switch(b11)
	{
		case 1:
			daxie(1,flag_of_zero);
			cout<<"��"; 
			break;
		case 2:
			daxie(2,flag_of_zero);
		    cout<<"��";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"��";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"��";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"��";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"��";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"��";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"��";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"��";
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
			cout<<"��"; 
			break;
		case 2:
			daxie(2,flag_of_zero);
		    cout<<"��";
			break; 
		case 3:
			daxie(3,flag_of_zero);
			cout<<"��";
			break;
		case 4:
			daxie(4,flag_of_zero);
			cout<<"��";
			break;
		case 5:
			daxie(5,flag_of_zero);
			cout<<"��";
			break;
		case 6:
			daxie(6,flag_of_zero);
			cout<<"��";
			break;
		case 7:
			daxie(7,flag_of_zero);
			cout<<"��";
			break;
		case 8:
			daxie(8,flag_of_zero);
			cout<<"��";
			break;
		case 9:
			daxie(9,flag_of_zero);
			cout<<"��";
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0&&b9==0&&b10==0&&b11==0)
		    {
		    	daxie(0,1);
				cout<<"Բ"; 
		    	break;
			} 		 
	}
		if(b12==0)
	    cout<<"��"; 
	    cout<<endl;  
	return 0;
}

