#include "locale.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double funcAC(double x, double eps, int *i)
{
	int k = 1;
	double x0 = x, x1, t, t1, s = x;
	t = 1.0*(k) / (k + 1);
	t1 = x*x*x;
	x1 = t1*t / (k + 2);

	while (fabs(x1 - x0) >= eps)
	{
		if ((k+1)/2 >= (*i)) { printf("\nstop"); break; }
		s += x1;
		(k) += 2;
		t *= 1.0*(k) / (k + 1);
		t1 *= x*x;
		x0 = x1;
		x1 = t1*t / (k + 2);
	}
	if (((k+1)/2) <= (*i)) (*i) = (k+1)/2;
	else (*i) -= (k+1)/2;

	return 0.5*3.1415926535 - s;
}

double funcLN(double x, double eps, int *i) {

	double lastresult, result;
	int n = 0;
	lastresult = 0;

	do {
		result = lastresult;
		lastresult += (pow(-1, n) * pow(x, n + 1)) / (n + 1);
		n++;
		if (n >= (*i)) { printf("\nstop"); break; }
	} while (fabs(lastresult - result) >= eps);

	if (n <= (*i)) (*i) = n;
	else (*i) -= n;
	return lastresult;
}

double StartPer(double *x, int *iter, double *eps) {
	printf("\n������� �������� X:");
	scanf_s("%lf", x);
	printf("\n������� ���������� ���������:");
	scanf_s("%d", iter);
	printf("\n������� ����������� ������:");
	scanf_s("%lf", eps);
}

double ObnullPer(double *rr, double *x, double *eps, int *itr) {
	(*rr) = 0;
	(*x) = 0;
	(*eps) = 0;
	(*itr) = 0;
}

double funcCOS(double x, double eps, int *itr)
{
	double s, an;
	int n;
	n = 0;
	an = 1;
	s = 0;

	while (fabs(an)>eps)
	{
		s += an;
		if (n>= (*itr)) { printf("kok"); break; }
		n++;
		an *= -x*x / (2.0*n - 1.0) / (2.0*n);
	}
	printf("%d",n);
	if((n != 1) && (n <= (*itr))) (*itr) = n;
		else (*itr) -= (n);
		if (n == 1) (*itr) = n;

	return s;
}
void menu()
{
	printf("\n����_����� �������_������:\n");
	printf("#1. Ln(1+x) \n");
	printf("#2. Arccos(x) \n");
	printf("#3. Sin(x)\n");
	printf("0. �����\n");
	printf("_________________________________________________\n");
	printf("���� �����>>");
}

void main()
{
	setlocale(LC_ALL, "Russian");
	printf("��������� �� ���������� ������� ����� ��� �������\n");
	printf("_____________________________________________");
	int t = 5;

	while (t != 0)
	{
		menu();
		scanf_s("%d", &t);
		switch (t)
		{
		case 1:
		{
			printf("\n������ Ln(1+x)");
			double x;   /* �������� ������� */
			double rr = 0;      /* ��������� ���������� ������� */
			double eps; /* �������� */
			int iter;   /* �������� -- ���������� ��������� */

			printf("\n�������� -1<X<=1:");
			StartPer(&x, &iter, &eps);

			printf("| �������� X |        ln(x + 1)/  t   | ���-�� ��������� |        ln(x + 1)       |\n");

			/* ������ �������� �� ����� ��������� ��������� */
			rr = funcLN(x, eps, &iter);

			printf("|   %5.2f    |    %16.13f    |      %5d       |     %16.13f    |\n", x, rr, iter, log(x + 1));

			printf("\n����� ���������� ��� ���������� ������ ��������: %5d", iter);
			printf("\n������� ����� ������� � ��������� ���������: %16.30f", (log(x + 1) - rr));

			ObnullPer(&rr, &x, &eps, &iter);
			break;
		}
		case 2:
		{
			printf("������ Arccos x");
			double x;   /* �������� ������� */
			double rr = 0;      /* ��������� ���������� ������� */
			double eps; /* �������� */
			int iter;   /* �������� -- ���������� ��������� */
			printf("\n�������� -1<X<1:");

			StartPer(&x, &iter, &eps);
			printf("| �������� X |        Acos(x)/  t   | ���-�� ������ |        Acos(x)          |\n");

			rr = funcAC(x, eps, &iter);
			printf("|   %5.2f    |    %16.13f    |      %5d       |     %16.13f    |\n", x, rr, iter, acos(x));

			printf("\n����� ���������� ��� ���������� ������ ��������: %5d", iter);
			printf("\n������� ����� ������� � ��������� ���������: %16.30f", (acos(x) - rr));
			ObnullPer(&rr, &x, &eps, &iter);
			break;
		}
		case 3:
		{
			printf("������ Cos x");
			double x;   /* �������� ������� */
			double rr = 0;      /* ��������� ���������� ������� */
			double eps; /* �������� */
			int iter;   /* �������� -- ���������� ��������� */
			StartPer(&x, &iter, &eps);
			if (x > 0) while (x > 6.28319) x -= 6.28319;
			if (x < 0) while (x < 6.28319) x += 6.28319;
			printf("| �������� X |        Cos(x)/  t   | ���-�� ������ |        Cos(x)          |\n");

			rr = funcCOS(x, eps, &iter);
			printf("|  %5.6f  |    %16.13f    |      %5d       |     %16.13f    |\n", x, rr, iter, cos(x));

			printf("\n����� ���������� ��� ���������� ������ ��������: %5d", iter);
			printf("\n������� ����� ������� � ��������� ���������: %16.30f", (cos(x) - rr));
			ObnullPer(&rr, &x, &eps, &iter);
			break; }
		}
	}
}