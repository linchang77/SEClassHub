/*1953609 ��� ���͢*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
int main()
{
    int fifty=0,twenty=0,ten=0,five=0,one=0,five_jiao=0,jiao=0,five_fen=0,two_fen=0,fen=0;
    double change;
    cout << "����������ֵ��" << endl;
    cin >> change;
    const int change1 = static_cast<int>(change/10);
    int shi = change1 % 10;
    int ge = static_cast<int>(floor((change / 10.0 - floor(change / 10)) * 10 + 1e-7));
    int horn= static_cast<int>(round((change - floor(change)) * 100)) / 10 % 10;
    int cent = static_cast<int>(round((change - floor(change)) * 100)) % 10;
    if (shi >= 5)
    {
        fifty += 1;
        shi -= 5;
    }
    if (shi >= 2)
    {
        twenty += 1;
        shi -= 2;
    }
    if (shi >= 2)
    {
        twenty += 1;
        shi -= 2;
    }
    if (shi >= 1)
    {
        ten += 1;
        shi -= 1;
    }
    if (ge >= 5)
    {
        five += 1;
        ge -= 5;
    }
    if (ge >= 1)
    {
        one += 1;
        ge -= 1;
    }
    if (ge >= 1)
    {
        one += 1;
        ge -= 1;
    }
    if (ge >= 1)
    {
        one += 1;
        ge -= 1;
    }
    if (ge >= 1)
    {
        one += 1;
        ge -= 1;
    }
    if (horn >= 5)
    {
        five_jiao += 1;
        horn -= 5;
    }
    if (horn >= 1)
    {
        jiao += 1;
        horn -= 1;
    }
    if (horn >= 1)
    {
        jiao += 1;
        horn -= 1;
    }
    if (horn >= 1)
    {
        jiao += 1;
        horn -= 1;
    }
    if (horn >= 1)
    {
        jiao += 1;
        horn -= 1;
    }
    if (cent >= 5)
    {
        five_fen += 1;
        cent -= 5;
    }
    if (cent >= 2)
    {
        two_fen += 1;
        cent -= 2;
    }
    if (cent >= 2)
    {
        two_fen += 1;
        cent -= 2;
    }
    if (cent >= 1)
    {
        fen += 1;
        cent -= 1;
    }
    const int sum = fifty + twenty + ten + five + one + five_jiao + jiao + five_fen + two_fen + fen;
    cout << "��" << sum << "�����㣬�������£�"<<endl;
    if (fifty > 0)
        cout << setw(5) << setiosflags(ios::left) << "50Ԫ" << "��" << fifty << "��" << endl;
    if (twenty > 0)
        cout << setw(5) << setiosflags(ios::left) << "20Ԫ" << "��" << twenty << "��" << endl;
    if (ten > 0)
        cout << setw(5) << setiosflags(ios::left) << "10Ԫ" << "��" << ten << "��" << endl;
    if (five > 0)
        cout << setw(5) << setiosflags(ios::left) << "5Ԫ" << "��" << five << "��" << endl;
    if (one > 0)
        cout << setw(5) << setiosflags(ios::left) << "1Ԫ" << "��" << one << "��" << endl;
    if (five_jiao > 0)
        cout << setw(5) << setiosflags(ios::left) << "5��" << "��" << five_jiao << "��" << endl;
    if (jiao > 0)
        cout << setw(5) << setiosflags(ios::left) << "1��" << "��" << jiao << "��" << endl;
    if (five_fen > 0)
        cout << setw(5) << setiosflags(ios::left) << "5��" << "��" << five_fen << "��" << endl;
    if (two_fen > 0)
        cout << setw(5) << setiosflags(ios::left) << "2��" << "��" << two_fen << "��" << endl;
    if (fen > 0)
        cout << setw(5) << setiosflags(ios::left) << "1��" << "��" << fen << "��" << endl;
    return 0;
}
