#include "Header.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	int N;
	cout << "������� ���������� �����";
	cin >> N;
	Matrix mat(N);			  //������ ������� � ������� n*(n+1), ��� ��������� ������� ��� ������ b
	//mat.insert();			 //��� ������� ��������� ��������� ������� ������ ������ 
	mat.random(100);		//��������� ������� ��������� �������, � ��� ����� � ������ b
	mat.PRINT();		   //������� ���������� ������� � ������ b
	mat.gaus();			  //����� ������
	mat.PRINT();
	mat.exit();
	mat.proverka();

	system("pause");
}