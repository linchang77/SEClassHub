/*2250420 �� �¾�*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

int main()
{   double a;
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
			cout<<"ʰ";
			break; 
		case 2:
		    cout<<"��ʰ";
			break; 
		case 3:
			cout<<"��ʰ";
			break;
		case 4:
			cout<<"��ʰ";
			break;
		case 5:
			cout<<"��ʰ";
			break;
		case 6:
			cout<<"½ʰ";
			break;
		case 7:
			cout<<"��ʰ";
			break;
		case 8:
			cout<<"��ʰ";
			break;
		case 9:
			cout<<"��ʰ";
			break;
	}
	switch(b2)
	{
		case 1:
			cout<<"Ҽ��"; 
			break; 
		case 2:
		    cout<<"����";
			break; 
		case 3:
			cout<<"����";
			break;
		case 4:
			cout<<"����";
			break;
		case 5:
			cout<<"����";
			break;
		case 6:
			cout<<"½��";
			break;
		case 7:
			cout<<"����";
			break;
		case 8:
			cout<<"����";
			break;
		case 9:
			cout<<"����";
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
			cout<<"ҼǪ";
			break; 
		case 2:
		    cout<<"��Ǫ";
			break; 
		case 3:
			cout<<"��Ǫ";
			break;
		case 4:
			cout<<"��Ǫ";
			break;
		case 5:
			cout<<"��Ǫ";
			break;
		case 6:
			cout<<"½Ǫ";
			break;
		case 7:
			cout<<"��Ǫ";
			break;
		case 8:
			cout<<"��Ǫ";
			break;
		case 9:
			cout<<"��Ǫ";
			break;
		case 0:
		if(b1==0&&b2==0)
		    break;
		if(b4!=0) 
		{
			cout<<"��";
		    break; 
		} 
	}
	switch(b4)
	{
		case 1:
			cout<<"Ҽ��";
			break; 
		case 2:
		    cout<<"����";
			break; 
		case 3:
			cout<<"����";
			break;
		case 4:
			cout<<"����";
			break;
		case 5:
			cout<<"���";
			break;
		case 6:
			cout<<"½��";
			break;
		case 7:
			cout<<"���";
			break;
		case 8:
			cout<<"�ư�";
			break;
		case 9:
			cout<<"����";
			break;
		case 0:
		if(b1==0&&b2==0&&b3==0)
	        break;
		if(b5!=0) 
		{
		cout<<"��";
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
				cout<<"Ҽʰ";
			    break;
			 } 
		case 2:
		    cout<<"��ʰ";
			break; 
		case 3:
			cout<<"��ʰ";
			break;
		case 4:
			cout<<"��ʰ";
			break;
		case 5:
			cout<<"��ʰ";
			break;
		case 6:
			cout<<"½ʰ";
			break;
		case 7:
			cout<<"��ʰ";
			break;
		case 8:
			cout<<"��ʰ";
			break;
		case 9:
			cout<<"��ʰ";
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
			cout<<"Ҽ��";
			break;
		case 2:
		    cout<<"Ҽ��";
			break; 
		case 3:
			cout<<"����";
			break;
		case 4:
			cout<<"����";
			break;
		case 5:
			cout<<"����";
			break;
		case 6:
			cout<<"½��";
			break;
		case 7:
			cout<<"����";
			break;
		case 8:
			cout<<"����";
			break;
		case 9:
			cout<<"����";
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0)
	        ;
		    else
			cout<<"��";
			
	}
		switch(b7)
	{
		case 1:
			cout<<"ҼǪ";
			break; 
		case 2:
		    cout<<"��Ǫ";
			break; 
		case 3:
			cout<<"��Ǫ";
			break;
		case 4:
			cout<<"��Ǫ";
			break;
		case 5:
			cout<<"��Ǫ";
			break;
		case 6:
			cout<<"½Ǫ";
			break;
		case 7:
			cout<<"��Ǫ";
			break;
		case 8:
			cout<<"��Ǫ";
			break;
		case 9:
			cout<<"��Ǫ";
			break;
		case 0:
		if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0)
		    break;
		if(b8!=0) 
		{
			cout<<"��";
		    break; 
		}
	}
	switch(b8)
	{
		case 1:
			cout<<"Ҽ��";
			break; 
		case 2:
		    cout<<"����";
			break; 
		case 3:
			cout<<"����";
			break;
		case 4:
			cout<<"����";
			break;
		case 5:
			cout<<"���";
			break;
		case 6:
			cout<<"½��";
			break;
		case 7:
			cout<<"���";
			break;
		case 8:
			cout<<"�ư�";
			break;
		case 9:
			cout<<"����";
			break;
		case 0:
		if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0)
	        break;
		if(b9!=0) 
		{
		cout<<"��";
		break; 
		}
	}
	switch(b9)
	{
		case 1:
			if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0)
			{
		        cout<<"ʰ";
			    break;
			} 
			else
			{
				cout<<"Ҽʰ";
			    break;
			 } 
		case 2:
		    cout<<"��ʰ";
			break; 
		case 3:
			cout<<"��ʰ";
			break;
		case 4:
			cout<<"��ʰ";
			break;
		case 5:
			cout<<"��ʰ";
			break;
		case 6:
			cout<<"½ʰ";
			break;
		case 7:
			cout<<"��ʰ";
			break;
		case 8:
			cout<<"��ʰ";
			break;
		case 9:
			cout<<"��ʰ";
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
			cout<<"ҼԲ";
			break; 
		case 2:
		    cout<<"��Բ";
			break; 
		case 3:
			cout<<"��Բ";
			break;
		case 4:
			cout<<"��Բ";
			break;
		case 5:
			cout<<"��Բ";
			break;
		case 6:
			cout<<"½Բ";
			break;
		case 7:
			cout<<"��Բ";
			break;
		case 8:
			cout<<"��Բ";
			break;
		case 9:
			cout<<"��Բ";
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
			cout<<"Ҽ��";
			break; 
		case 2:
		    cout<<"����";
			break; 
		case 3:
			cout<<"����";
			break;
		case 4:
			cout<<"����";
			break;
		case 5:
			cout<<"���";
			break;
		case 6:
			cout<<"½��";
			break;
		case 7:
			cout<<"���";
			break;
		case 8:
			cout<<"�ƽ�";
			break;
		case 9:
			cout<<"����";
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0&&b9==0&&b10==0)
	        break;
		    if(b12!=0)
		    cout<<"��"; 		 
	}
	switch(b12)
	{
		case 1:
			cout<<"Ҽ��";
			break; 
		case 2:
		    cout<<"����";
			break; 
		case 3:
			cout<<"����";
			break;
		case 4:
			cout<<"����";
			break;
		case 5:
			cout<<"���";
			break;
		case 6:
			cout<<"½��";
			break;
		case 7:
			cout<<"���";
			break;
		case 8:
			cout<<"�Ʒ�";
			break;
		case 9:
			cout<<"����";
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0&&b9==0&&b10==0&&b11==0)
		    {
		    	cout<<"��Բ"; 
		    	break;
			} 		 
	}
		if(b12==0)
	    cout<<"��"; 
	    cout<<endl; 
	return 0;
}

