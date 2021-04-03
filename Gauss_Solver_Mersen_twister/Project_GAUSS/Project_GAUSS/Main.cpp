#include <iostream>
#include "Solver.h"
#include "header.h"

#define RANDOM 100
void menu() {
	cout << "�������� ����� ������� ��������� ��� ����������:" << endl;
	cout << "������� 1, ���� �� ������ ������ ������� � � ������ b ��������������." << endl;
	cout << "������� 2, ���� �� ������ ��������� ������� � � ������ b ��������� �������." << endl;
	cout << "�����:";
}

int  main()
{
	ERRORS W;
	setlocale(LC_ALL, "Russian");
	int R = NULL;
	int t = NULL;
	menu();
	cin >> t;
	if ((t == 0)||((t!=1)&&(t!=2)))
	{
			W = ERROR_INSERT;
			cout << "SYSTEM DOW{"<<W<<"}||ERROR_INSERT||T=0 or T!=1 or T!=2" << endl;
			system("pause");
			exit(W);
	}

	switch (t)
	{
		case 1:
		{
			Solver SOLV;
			SOLV.PrintM(1);
			SOLV.Gauss();
			SOLV.PrintM(2);
			SOLV.PrintX();
			SOLV.Check();
			cout << endl;
			cout << "��������: A*x=" << endl;
			SOLV.PrintB();
			break;
		}
		case 2:
		{
			cout << "������� ������� �������:";
			cin >> R;

			if (R < 0)
			{
				W = ERROR_INSERT_SIZES;
				cout << "SYSTEM DOWN{" << W << "}||ERROR_INSERT_SIZE||size<0 " << endl;
				system("pause");
				exit(W);
			}

			matrix A(R, R, RANDOM);
			vector x(R), b(R, RANDOM);
			Solver SOLV(A, x, b);
			SOLV.PrintM(1);
			SOLV.Gauss();
			SOLV.PrintM(2);
			SOLV.PrintX();
			SOLV.Check();
			cout << endl;
			cout << "��������: A*x=" << endl;
			SOLV.PrintB();
			break;
		}
	}
	system("Pause");
	return 0;
}