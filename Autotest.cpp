#include "Autotest.h";

int Autotest() {
	int n = 2;
	Comp* v1 = (Comp*)malloc(sizeof(Comp) * n), *v2 = (Comp*)malloc(sizeof(Comp) * n);
	for (int i = 0; i < n; i++) {
		v1[i].Im = i;
		v2[i].Im = -i;
		v1[i].Rl = i;
		v2[i].Rl = i;
	}
	CVector w1(v1, n), w2(v2, n);
	CVector minus = w1 - w2, plus = w1 + w2;

	if ((w1 * w1).Im != 0 || minus.Out(1).Rl != 0 || plus.Out(1).Im != 0)
		return 0;
	return 1;

}