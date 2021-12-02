//main.cpp

//#include "Autotest.h"
#include "CVector.h"
#include "Autotest.h"


int main(void) {
	setlocale(LC_ALL, "rus");
	
	if (!Autotest()) {
		cout << "Не пройдён автотест" << endl;
		return -1;
	}

	CVector v1, v2;
	cout << "Ваши вектор:" << endl;
	cout << "Первый (";
	for (int i = 0; i < v1.Len_out() - 1; i++)
		cout << "Rl:" << v1.Out(i).Rl <<" Im:" << v1.Out(i).Im << ", ";
	cout << "Rl:" << v1.Out(v1.Len_out() - 1).Rl << " Im:" << v1.Out(v1.Len_out() - 1).Im << ")" << endl;

	cout << "И второй (";
	for (int i = 0; i < v2.Len_out() - 1; i++)
		cout << "Rl:" << v2.Out(i).Rl << " Im:" << v2.Out(i).Im << ", ";
	cout << "Rl:" << v2.Out(v2.Len_out() - 1).Rl << " Im:" << v2.Out(v2.Len_out() - 1).Im << ")" << endl;


	CVector plus = v1 + v2;
	CVector minus = v1 - v2;
	Comp mul = v1 * v2;
	cout << "Сумма векторов: (";
	for (int i = 0; i < plus.Len_out() - 1; i++)
		cout << "Rl:" << plus.Out(i).Rl << " Im:" << plus.Out(i).Im << ", ";
	cout << "Rl:" << plus.Out(plus.Len_out() - 1).Rl << " Im:" << plus.Out(plus.Len_out() - 1).Im << ")" << endl;

	cout << "Разность векторов: (";
	for (int i = 0; i < minus.Len_out() - 1; i++)
		cout << "Rl:" << minus.Out(i).Rl << " Im:" << minus.Out(i).Im << ", ";
	cout << "Rl:" << minus.Out(minus.Len_out() - 1).Rl << " Im:" << minus.Out(minus.Len_out() - 1).Im << ")" << endl;

	cout << "Скалярное умножение равно " << mul.Rl;
	if (mul.Im < 0) 
		cout << " - " << -mul.Im << "i" << endl;
	else if(mul.Im > 0)
		cout << " + " << mul.Im << "i" << endl;
	

	return 0;

}