#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>


using namespace std;
#define _len 3

struct Comp {
	double Rl;
	double Im;
};

class CVector {
private:
	int len;
	Comp *vec;
public:
	CVector();
	CVector(const CVector& name);
	CVector(Comp* input, int new_len);
	void Add(CVector imp);
	void UnAdd(CVector imp);
	Comp Scal_Mul(CVector imp);
	Comp Out(int wich);
	int Len_out();
	friend const CVector operator+(const CVector& left, const CVector& right);
	friend const CVector operator-(const CVector& left, const CVector& right);
	friend Comp operator*(CVector& left, const CVector& right);
	~CVector();
};




#endif



