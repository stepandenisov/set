#include "Set.h"
#define menu "1)�������� �������\n2)������� �������\n3)��������� ������� ��������\n4)������� ��������� �� �����\n0)�����\n"
int main()
{
	setlocale(LC_ALL, "Russian");
	Set s;
	unsigned choice = 1;
	int value;
	while (choice)
	{
		cout << menu;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "������� �������� ��� ����������: ";
			cin >> value;
			(s.insert(int(value))) ? cout << "�������� ������� ���������" << endl : cout << "�������� ��� ����" << endl;
			break;
		case 2:
			cout << "������� �������� ��� ��������: ";
			cin >> value;
			(s.erase(int(value))) ? cout << "�������� ������� �������" << endl : cout << "�������� ��� � ���������" << endl;
			break;
		case 3:
			cout << "������� �������� ��� ��������: ";
			cin >> value;
			(s.find(int(value))) ? cout << "�������� ����" << endl : cout << "�������� ���" << endl;
			break;
		case 4:
			cout << "���������:\n";
			cout << s;
			cout << endl;
			break;
		case 0:
			cout << "���������� � ������ ����������?\n1)��\n2)���" << endl;
			cin >> value;
			if (value == 1)
			{
				choice = 1;
				s.clear();
				break;
			}
			else
			{
				choice = 0;
				break;
			}
		}
	} 
	return 0;
}