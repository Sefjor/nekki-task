//Программа прошла много попыток сделать перемножение матриц самостоятельно.
#include <iostream>
#include "Eigen/Core"
#include "Eigen/Dense"
#include <vector>
using namespace std;
using namespace Eigen;

const int sz = 8;

Matrix<long double, sz, sz> A;
Matrix<long double, sz, 1> B;
Matrix<long double, 8, 1> C;
array<double, 8> basegateP {0.09, 0.1, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16} ;
array<double, 8> basecolorP;
array<double, 8> samecolorQ;
int main()

{
	cout << "использовать базовые условия? y/n" << endl;
	char p;
	cin >> p;
	if (p != 'y') {
	cout << "введите Pик-Руф через enter" << endl;
	for (int i = 0; i < 8; i++ )
	cin >> basegateP[i];
	cout << "введите Qик,ик-Qуф,уф через enter" << endl;
	for (int i = 0; i < 8; i++ )
	cin >> samecolorQ[i];
	for (int i = 0; i < 8; i++ )
		basecolorP[i] = basegateP[i] * samecolorQ[i] + basegateP[7-i] * (1 - samecolorQ[7-i]);
	}
	else
       for (int i = 0; i < 8; i++ )
	basecolorP[7-i] = basegateP[i];

	for (int i = 0; i < 8; i++ )
		for (int j = 0; j < 8; j++ )
			if (i == j)
			A(j, i) = basegateP[i] * -7;
			else
			A(j, i) = basegateP[i];


for (int i = 0; i < 8; i++ )
	B(i,0) = basecolorP[i] - basegateP[i];
C = A.colPivHouseholderQr().solve(B);
cout << "Новые шансы Qик,ик-Qуф,уф" << endl;
for (int i = 0; i < 8; i++ )
	cout << 1-C(i,0)*7 << " ";
cout << endl;
cout << "Новые шансы Qик,xx!=ик.. ..Qуф,xx!=уф" << endl;
for (int i = 0; i < 8; i++ )
	cout << C(i,0) << " ";
cout << endl;
return 0;
}
