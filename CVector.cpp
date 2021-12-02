//CVector.cpp

#include "CVector.h"




CVector::CVector() {
	cout << "Введите длину:";
	cin >> len;
	vec = (Comp*)malloc(sizeof(Comp) * len);
	for (int i = 0; i < len; i++) {
		cout << "Rl[" << i << "]:";
		cin >> vec[i].Rl;
		cout << "Im[" << i << "]:";
		cin >> vec[i].Im;
	}
}

CVector::CVector(Comp* input, int new_len) {
	vec = input;
	len = new_len;
}

CVector::CVector(const CVector& imp) {
	len = imp.len;
	vec = (Comp*)malloc(sizeof(Comp) * len);
	for (int i = 0; i < len; i++)
		vec[i] = imp.vec[i];
}

void CVector::Add(CVector imp) {
	if (len != imp.len) {
		cout << "Векторы должны быть одинаковой длины" << endl;
		return;
	}
	for (int i = 0; i < len; i++) {
		vec[i].Rl += imp.vec[i].Rl;
		vec[i].Im += imp.vec[i].Im;
	}
}

void CVector::UnAdd(CVector imp) {
	if (len != imp.len) {
		cout << "Векторы должны быть одинаковой длины" << endl;
		return;
	}
	for (int i = 0; i < len; i++) {
		vec[i].Rl -= imp.vec[i].Rl;
		vec[i].Im -= imp.vec[i].Im;
	}
}

int CVector::Len_out() {
	return len;
}

Comp CVector::Scal_Mul(CVector imp) {
	if (len != imp.len) {
		cout << "Векторы должны быть одинаковой длины" << endl;
		Comp er;
		er.Im = 0;
		er.Rl = 0;
		return er;
	}
	Comp S;
	S.Im = 0;
	S.Rl = 0;
	for (int i = 0; i < _len; i++) {
		S.Rl += vec[i].Rl * imp.vec[i].Rl + vec[i].Im * imp.vec[i].Im;
		S.Im += -vec[i].Rl * imp.vec[i].Im + vec[i].Im * imp.vec[i].Rl;
	}
	return S;
}

Comp CVector::Out(int which) {
	return vec[which];
}

const CVector operator+(const CVector& left, const CVector& right) {
	CVector newV(left);
	newV.Add(right);
	return newV;
}

const CVector operator-(const CVector& left, const CVector& right) {
	CVector newV(left);
	newV.UnAdd(right);
	return newV;
}

Comp operator*(CVector& left, const CVector& right) {
	return left.Scal_Mul(right);
}

CVector::~CVector() {
	free(vec);
}



