/*2250420 Èí¹¤ ³Â¾ı*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{   double a;
    printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:\n") ;
    scanf("%lf",&a);
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

    printf("´óĞ´½á¹ûÊÇ:\n");
	switch(b1)
	{
		case 1:
			printf("Ê°");
			break; 
		case 2:
		    printf("·¡Ê°");
			break; 
		case 3:
			printf("ÈşÊ°");
			break;
		case 4:
			printf("ËÁÊ°");
			break;
		case 5:
			printf("ÎéÊ°");
			break;
		case 6:
			printf("Â½Ê°");
			break;
		case 7:
			printf("ÆâÊ°");
			break;
		case 8:
			printf("°ÆÊ°");
			break;
		case 9:
			printf("¾ÁÊ°");
			break;
	}
	switch(b2)
	{
		case 1:
			printf("Ò¼ÒÚ");
			break; 
		case 2:
		    printf("·¡ÒÚ");
			break; 
		case 3:
			printf("ÈşÒÚ");
			break;
		case 4:
			printf("ËÁÒÚ");
			break;
		case 5:
			printf("ÎéÒÚ");
			break;
		case 6:
			printf("Â½ÒÚ");
			break;
		case 7:
			printf("ÆâÒÚ");
			break;
		case 8:
			printf("°ÆÒÚ");
			break;
		case 9:
			printf("¾ÁÒÚ");
			break;
		case 0:
			if(b1==0&&b2==0)
			;
			else
			printf("ÒÚ");
			break; 
	}
	switch(b3)
	{
		case 1:
			printf("Ò¼Çª");
			break; 
		case 2:
		    printf("·¡Çª");
			break; 
		case 3:
			printf("ÈşÇª");
			break;
		case 4:
			printf("ËÁÇª");
			break;
		case 5:
			printf("ÎéÇª");
			break;
		case 6:
			printf("Â½Çª");
			break;
		case 7:
			printf("ÆâÇª");
			break;
		case 8:
			printf("°ÆÇª");
			break;
		case 9:
			printf("¾ÁÇª");
			break;
		case 0:
		if(b1==0&&b2==0)
		    break;
		if(b4!=0) 
		{
			printf("Áã");
		    break; 
		} 
	}
	switch(b4)
	{
		case 1:
			printf("Ò¼°Û");
			break; 
		case 2:
		    printf("·¡°Û");
			break; 
		case 3:
			printf("Èş°Û");
			break;
		case 4:
			printf("ËÁ°Û");
			break;
		case 5:
			printf("Îé°Û");
			break;
		case 6:
			printf("Â½°Û");
			break;
		case 7:
			printf("Æâ°Û");
			break;
		case 8:
			printf("°Æ°Û");
			break;
		case 9:
			printf("¾Á°Û");
			break;
		case 0:
		if(b1==0&&b2==0&&b3==0)
	        break;
		if(b5!=0) 
		{
		printf("Áã");
		break; 
		}
	}
	switch(b5)
	{
		case 1:
			if(b4==0&&b1==0&&b2==0&&b3==0)
			{
		        printf("Ê°");
			    break;
			} 
			else
			{
				printf("Ò¼Ê°");
			    break;
			 } 
		case 2:
		    printf("·¡Ê°");
			break; 
		case 3:
			printf("ÈşÊ°");
			break;
		case 4:
			printf("ËÁÊ°");
			break;
		case 5:
			printf("ÎéÊ°");
			break;
		case 6:
			printf("Â½Ê°");
			break;
		case 7:
			printf("ÆâÊ°");
			break;
		case 8:
			printf("°ÆÊ°");
			break;
		case 9:
			printf("¾ÁÊ°");
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0)
	        break;
		    if(b6!=0) 
		    {
		        printf("Áã");
		        break; 
		    } 
	}
	switch(b6)
	{
		case 1:
			printf("Ò¼Íò");
			break;
		case 2:
		    printf("·¡Íò");
			break; 
		case 3:
			printf("ÈşÍò"); 
			break;
		case 4:
			printf("ËÁÍò");
			break;
		case 5:
			printf("ÎéÍò");
			break;
		case 6:
			printf("Â½Íò");
			break;
		case 7:
			printf("ÆâÍò");
			break;
		case 8:
			printf("°ÆÍò");
			break;
		case 9:
			printf("¾ÁÍò");
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0)
	        ;
		    else
			printf("Íò");
			
	}
		switch(b7)
	{
		case 1:
			printf("Ò¼Çª");
			break; 
		case 2:
		    printf("·¡Çª");
			break; 
		case 3:
			printf("ÈşÇª");
			break;
		case 4:
			printf("ËÁÇª");
			break;
		case 5:
			printf("ÎéÇª");
			break;
		case 6:
			printf("Â½Çª");
			break;
		case 7:
			printf("ÆâÇª");
			break;
		case 8:
			printf("°ÆÇª");
			break;
		case 9:
			printf("¾ÁÇª");
			break;
		case 0:
		if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0)
		    break;
		if(b8!=0) 
		{
			printf("Áã");
		    break; 
		}
	}
	switch(b8)
	{
		case 1:
			printf("Ò¼°Û");
			break; 
		case 2:
		    printf("·¡°Û");
			break; 
		case 3:
			printf("Èş°Û");
			break;
		case 4:
			printf("ËÁ°Û");
			break;
		case 5:
			printf("Îé°Û");
			break;
		case 6:
			printf("Â½°Û");
			break;
		case 7:
			printf("Æâ°Û");
			break;
		case 8:
			printf("°Æ°Û");
			break;
		case 9:
			printf("¾Á°Û");
			break;
		case 0:
		if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0)
	        break;
		if(b9!=0) 
		{
		printf("Áã");
		break; 
		}
	}
	switch(b9)
	{
		case 1:
			if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0)
			{
		        printf("Ê°");
			    break;
			} 
			else
			{
				printf("Ò¼Ê°");
			    break;
			 } 
		case 2:
		    printf("·¡Ê°");
			break; 
		case 3:
			printf("ÈşÊ°");
			break;
		case 4:
			printf("ËÁÊ°");
			break;
		case 5:
			printf("ÎéÊ°");
			break;
		case 6:
			printf("Â½Ê°");
			break;
		case 7:
			printf("ÆâÊ°");
			break;
		case 8:
			printf("°ÆÊ°");
			break;
		case 9:
			printf("¾ÁÊ°");
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0)
	        break;
		    if(b10!=0) 
		    {
		        printf("Áã");
		        break; 
		    } 
	}
	switch(b10)
	{
		case 1:
			printf("Ò¼Ô²");
			break; 
		case 2:
		    printf("·¡Ô²");
			break; 
		case 3:
			printf("ÈşÔ²");
			break;
		case 4:
			printf("ËÁÔ²");
			break;
		case 5:
			printf("ÎéÔ²");
			break;
		case 6:
			printf("Â½Ô²");
			break;
		case 7:
			printf("ÆâÔ²");
			break;
		case 8:
			printf("°ÆÔ²");
			break;
		case 9:
			printf("¾ÁÔ²");
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0&&b9==0)
	        break;
		    else
			printf("Ô²"); 
	}
	switch(b11)
	{
		case 1:
			printf("Ò¼½Ç");
			break; 
		case 2:
		    printf("·¡½Ç");
			break; 
		case 3:
			printf("Èş½Ç");
			break;
		case 4:
			printf("ËÁ½Ç");
			break;
		case 5:
			printf("Îé½Ç");
			break;
		case 6:
			printf("Â½½Ç");
			break;
		case 7:
			printf("Æâ½Ç");
			break;
		case 8:
			printf("°Æ½Ç");
			break;
		case 9:
			printf("¾Á½Ç");
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0&&b9==0&&b10==0)
	        break;
		    if(b12!=0)
			printf("Áã"); 		 
	}
	switch(b12)
	{
		case 1:
			printf("Ò¼·Ö");
			break; 
		case 2:
		    printf("·¡·Ö");
			break; 
		case 3:
			printf("Èş·Ö");
			break;
		case 4:
			printf("ËÁ·Ö");
			break;
		case 5:
			printf("Îé·Ö");
			break;
		case 6:
			printf("Â½·Ö");
			break;
		case 7:

			printf("Æâ·Ö");
			break;
		case 8:
			printf("°Æ·Ö");
			break;
		case 9:
			printf("¾Á·Ö");
			break;
		case 0:
		    if(b1==0&&b2==0&&b3==0&&b4==0&&b5==0&&b6==0&&b7==0&&b8==0&&b9==0&&b10==0&&b11==0)
		    {
				printf("ÁãÔ²"); 
		    	break;
			} 		 
	}
		if(b12==0)
	    printf("Õû\n"); 
	return 0;
}

