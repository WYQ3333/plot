#include<stdio.h>
#include<Windows.h>

void  SetPos(int x, int y)
{
	COORD pos = { 0 };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = x; pos.Y = y;
	SetConsoleCursorPosition(handle, pos);//�ѹ�궨λ��������Ҫ��λ����
}


int main()
{
	//���ô��ڴ�С
	system("mode con cols=100 lines=30");
	int i = 2;
	int num1[100] = { 0 };
	char c;
	while ((c = getchar()) != EOF)
	{
		//ȷ���������ַ�Ϊ��д��Сд��ĸ�����������ַ�
		if ((c != ' ') && (c != '\t') && (c != '\n')&&((c>=65&&c<=90)||(c>=97&&c<=122)))
		{
			num1[i]++;
		}
		else
		{
			i+=2;
		}
	}
	for (i = 0; i < 100; i +=2)
	{
		int j = 0;
		for (j = 20; j >(20 - num1[i]); j--)
		{
			SetPos(i, j);
			printf("��");
		}
	}
	SetPos(50, 20);
	system("pause");
	return 0;
}