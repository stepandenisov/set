#include "Set.h"
#define menu "1)�������� �������\n2)������� �������\n3)��������� ������� ��������\n4)������� ��������� �� �����\n0)�����\n"
int main()
{
	setlocale(LC_ALL, "Russian");
	Set s;
	unsigned choice = 1;
	double value;
	while (choice)
	{
		cout << menu;
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "������� �������� ��� ����������: ";
			cin >> value;
			(s.insert(int(value))) ? cout << "�������� " << int(value)<< " ������� ���������" << endl : cout << "�������� " << int(value)<< " ��� ����" << endl;
			break;
		case 2:
			system("cls");
			cout << "������� �������� ��� ��������: ";
			cin >> value;
			(s.erase(int(value))) ? cout << "�������� " << int(value) << " ������� �������" << endl : cout << "�������� " << int(value) << " ��� � ���������" << endl;
			break;
		case 3:
			system("cls");
			cout << "������� �������� ��� ��������: ";
			cin >> value;
			(s.find(int(value))) ? cout << "�������� " << int(value) << " ����" << endl : cout << "�������� " << int(value) << " ���" << endl;
			break;
		case 4:
			system("cls");
			cout << "���������:\n";
			cout << s;
			cout << endl;
			break;
		case 0:
			system("cls");
			cout << "���������� � ������ ����������?\n1)��\n2)���" << endl;
			cin >> value;
			if (value == 1)
			{
				choice = 1;
				s.clear();
				system("cls");
				break;
			}
			else
			{
				choice = 0;
				system("cls");
				break;
			}
		}
	} 
	return 0;
}

