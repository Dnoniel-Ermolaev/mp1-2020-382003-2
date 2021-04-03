#include "Matrix.h"

class Solver
{
	int i, j, m;
	int size=NULL;
	double aa, bb;
	double t1, t2, a;
	ERRORS W;
	matrix A;
	vector x, b;
	matrix tA;
	vector tb;
	matrix copyA = A;
	vector copyb = b;
public:
	Solver(const matrix& A, const vector& x, const vector& b); //���������� ��� ��������� ������,�������� ��� ������� ������ ������.
	Solver();//��������������� ���� �����, ���� ������ �����
	void Gauss();
	void PrintM( int t); 
	void PrintX();
	void PrintB();
	void Check();
}; 
