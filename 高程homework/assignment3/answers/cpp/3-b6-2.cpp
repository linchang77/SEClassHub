/*2250420 Èí¹¤ ³Â¾ı*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

int main()
{   double a;
    cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:" << endl;
    cin >> a;
	int a1 = (int)(a/10);//½«Õâ¸öÊıÊ®Î»Ö®Ç°µÄÊıÈ¡³öÀ´ 
	int b1 = a1 / 100000000;//Ê®ÒÚ 
	int b2 = a1 / 10000000 % 10;//ÒÚ 
	int b3 = a1 / 1000000 % 10;//Ç§Íò 
	int b4 = a1 / 100000 % 10;//°ÙÍò 
	int b5 = a1 / 10000 % 10;//Ê®Íò 
	int b6 = a1 / 1000 % 10;//Íò 
	int b7 = a1 / 100 % 10;//Ç§ 
	int b8 = a1 / 10 % 10;//°Ù 
	int b9 = a1 % 10;//Ê® 
	int a2 = round((a/10-a1)*1000);
	int b10 = a2 / 100 % 10;//Ô² 
	int b11 = a2 / 10 % 10;//½Ç 
	int b12 = a2  % 10;//·Ö
//È¡³öÃ¿Ò»Î»µÄÊı×Ö

    cout<<"´óĞ´½á¹ûÊÇ:"<<endl;  
 
	switch(b1)
	{
		case 1:
			cout<<"Ê°";
			break; 
		case 2:
		    cout<<"·¡Ê°";
			break; 
		case 3:
			cout<<"ÈşÊ°";
			break;
		case 4:
			cout<<"ËÁÊ°";
			break;
		case 5:
			cout<<"ÎéÊ°";
			break;
		case 6:
			cout<<"Â½Ê°";
			break;
		case 7:
			cout<<"ÆâÊ°";
			break;
		case 8:
			cout<<"°ÆÊ°";
			break;
		case 9:
			cout<<"¾ÁÊ°";
			break;
	}
	switch(b2)
	{
		case 1:
			cout<<"Ò¼ÒÚ"; 
			break; 
		case 2:
		    cout<<"·¡ÒÚ";
			break; 
		case 3:
			cout<<"ÈşÒÚ";
			break;
		case 4:
			cout<<"ËÁÒÚ";
			break;
		case 5:
			cout<<"ÎéÒÚ";
			break;
		case 6:
			cout<<"Â½ÒÚ";
			break;
		case 7:
			cout<<"ÆâÒÚ";
			break;
		case 8:
			cout<<"°ÆÒÚ";
			break;
		case 9:
			cout<<"¾ÁÒÚ";
			break;
		case 0:
			if(b1==0&&b2==0)
			;
			else
			cout<<"ÒÚ";
			break; 
	}
	switch(b3)
	{
		case 1:
			cout<<"Ò¼Çª";
			break; 
		case 2:
		    cout<<"·¡Çª";
			break; 
		case 3:
			cout<<"ÈşÇª";
			break;
		case 4:
			cout<<"ËÁÇª";
			break;
		case 5:
			cout<<"ÎéÇª";
			break;
		case 6:
			cout<<"Â½Çª";
			break;
		case 7:
			cout<<"ÆâÇª";
			break;
		case 8:
			cout<<"°ÆÇª";
			break;
		case 9:
			cout<<"¾ÁÇª";
			break;
		case 0:
		if(b1==0&&b2==0)
		    break;
		if(b4!=0) 
		{
			cout<<"Áã";
		    break; 
		} 
	}
	switch(b4)
	{
		case 1:
			cout<<"Ò¼°Û";
			break; 
		case 2:
		    cout<<"·¡°Û";
			break; 
		case 3:
			cout<<"Èş°Û";
			break;
		case 4:
			cout<<"ËÁ°Û";
			break;
		case 5:
			cout<<"Îé°Û";
			break;
		case 6:
			cout<<"Â½°Û";
			break;
		case 7:
			cout<<"Æâ°Û";
			break;
		case 8:
			cout<<"°Æ°Û";
			break;
		case 9:
			cout<<"¾Á°Û";
			break;
		case 0:
		if(b1==0&&b2==0&&b3==0)
	        break;
		if(b5!=0) 
		{
		cout<<"Áã";
		break; 
		}
	}
	switch(b5)
	{
		case 1:
			if(b4==0&&b1==0&&b2==0&&b3==0)
			{
		        cout<<"Ê°";
			    break;
			} 
			else
			{
				cout<<"Ò¼Ê°";
			    break;
			 } 
		case 2:
		    cout<<"·¡Ê°";
			break; 
		case 3:
			cout<<"ÈşÊ°";
			break;
		case 4:
			cout<<"ËÁÊ°";
			break;
		case 5:
			cout<<"ÎéÊ°";
			break;
		case 6:
			cout<<"Â½Ê°";
			break;
		case 7:
			cout<<"ÆâÊ°";
			break;
		case 8:
			cout<<"°ÆÊ°";
			break;
		case 9:
			cout<<"¾ÁÊ°";
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0)
	        break;
		    if(b6!=0) 
		    {
		        cout<<"Áã";
		        break; 
		    } 
	}
	switch(b6)
	{
		case 1:
			cout<<"Ò¼Íò";
			break;
		case 2:
		    cout<<"Ò¼Íò";
			break; 
		case 3:
			cout<<"ÈşÍò";
			break;
		case 4:
			cout<<"ËÁÍò";
			break;
		case 5:
			cout<<"ÎéÍò";
			break;
		case 6:
			cout<<"Â½Íò";
			break;
		case 7:
			cout<<"ÆâÍò";
			break;
		case 8:
			cout<<"°ÆÍò";
			break;
		case 9:
			cout<<"¾ÁÍò";
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0)
	        ;
		    else
			cout<<"Íò";
			
	}
		switch(b7)
	{
		case 1:
			cout<<"Ò¼Çª";
			break; 
		case 2:
		    cout<<"·¡Çª";
			break; 
		case 3:
			cout<<"ÈşÇª";
			break;
		case 4:
			cout<<"ËÁÇª";
			break;
		case 5:
			cout<<"ÎéÇª";
			break;
		case 6:
			cout<<"Â½Çª";
			break;
		case 7:
			cout<<"ÆâÇª";
			break;
		case 8:
			cout<<"°ÆÇª";
			break;
		case 9:
			cout<<"¾ÁÇª";
			break;
		case 0:
		if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0)
		    break;
		if(b8!=0) 
		{
			cout<<"Áã";
		    break; 
		}
	}
	switch(b8)
	{
		case 1:
			cout<<"Ò¼°Û";
			break; 
		case 2:
		    cout<<"·¡°Û";
			break; 
		case 3:
			cout<<"Èş°Û";
			break;
		case 4:
			cout<<"ËÁ°Û";
			break;
		case 5:
			cout<<"Îé°Û";
			break;
		case 6:
			cout<<"Â½°Û";
			break;
		case 7:
			cout<<"Æâ°Û";
			break;
		case 8:
			cout<<"°Æ°Û";
			break;
		case 9:
			cout<<"¾Á°Û";
			break;
		case 0:
		if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0)
	        break;
		if(b9!=0) 
		{
		cout<<"Áã";
		break; 
		}
	}
	switch(b9)
	{
		case 1:
			if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0)
			{
		        cout<<"Ê°";
			    break;
			} 
			else
			{
				cout<<"Ò¼Ê°";
			    break;
			 } 
		case 2:
		    cout<<"·¡Ê°";
			break; 
		case 3:
			cout<<"ÈşÊ°";
			break;
		case 4:
			cout<<"ËÁÊ°";
			break;
		case 5:
			cout<<"ÎéÊ°";
			break;
		case 6:
			cout<<"Â½Ê°";
			break;
		case 7:
			cout<<"ÆâÊ°";
			break;
		case 8:
			cout<<"°ÆÊ°";
			break;
		case 9:
			cout<<"¾ÁÊ°";
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0)
	        break;
		    if(b10!=0) 
		    {
		        cout<<"Áã";
		        break; 
		    } 
	}
	switch(b10)
	{
		case 1:
			cout<<"Ò¼Ô²";
			break; 
		case 2:
		    cout<<"·¡Ô²";
			break; 
		case 3:
			cout<<"ÈşÔ²";
			break;
		case 4:
			cout<<"ËÁÔ²";
			break;
		case 5:
			cout<<"ÎéÔ²";
			break;
		case 6:
			cout<<"Â½Ô²";
			break;
		case 7:
			cout<<"ÆâÔ²";
			break;
		case 8:
			cout<<"°ÆÔ²";
			break;
		case 9:
			cout<<"¾ÁÔ²";
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0&&b9==0)
	        break;
		    else
			cout<<"Ô²"; 
	}
	switch(b11)
	{
		case 1:
			cout<<"Ò¼½Ç";
			break; 
		case 2:
		    cout<<"·¡½Ç";
			break; 
		case 3:
			cout<<"Èş½Ç";
			break;
		case 4:
			cout<<"ËÁ½Ç";
			break;
		case 5:
			cout<<"Îé½Ç";
			break;
		case 6:
			cout<<"Â½½Ç";
			break;
		case 7:
			cout<<"Æâ½Ç";
			break;
		case 8:
			cout<<"°Æ½Ç";
			break;
		case 9:
			cout<<"¾Á½Ç";
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0&&b9==0&&b10==0)
	        break;
		    if(b12!=0)
		    cout<<"Áã"; 		 
	}
	switch(b12)
	{
		case 1:
			cout<<"Ò¼·Ö";
			break; 
		case 2:
		    cout<<"·¡·Ö";
			break; 
		case 3:
			cout<<"Èş·Ö";
			break;
		case 4:
			cout<<"ËÁ·Ö";
			break;
		case 5:
			cout<<"Îé·Ö";
			break;
		case 6:
			cout<<"Â½·Ö";
			break;
		case 7:
			cout<<"Æâ·Ö";
			break;
		case 8:
			cout<<"°Æ·Ö";
			break;
		case 9:
			cout<<"¾Á·Ö";
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0&&b9==0&&b10==0&&b11==0)
		    {
		    	cout<<"ÁãÔ²"; 
		    	break;
			} 		 
	}
		if(b12==0)
	    cout<<"Õû"; 
	    cout<<endl; 
	return 0;
}

