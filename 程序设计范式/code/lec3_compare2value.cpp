#include <stdlib.h>
#include <iostream>

using namespace std;

int compare(const void *arg1, const void *arg2);

int main()
{
    const int max_size = 10;
    int num[max_size];
    int n;
// �ӱ�׼�����豸����������ͬʱ�ۼ����������
// ֱ��������Ƿ���������Ϊֹ
    for(n = 0; cin>>num[n]; n++)
        qsort(num, n, sizeof(int), compare);
    
    for(int i = 0; i < n; i++)
        cout<<num[i]<<"\n"; 
        
    system("pause");
    return 0;  
}

int compare(const void *arg1, const void *arg2)
{
    return (*(int*)arg1<*(int*)arg2)?-1:(*(int*)arg1>*(int*)arg2)?1:0;
}    

