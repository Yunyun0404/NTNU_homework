#include "myvector.h"

int main() {
	sVector *a = myvector_init();
	sVector *b = myvector_init();
	sVector *c = myvector_init();

	myvector_set(a, 1, 1, 1);
	myvector_set(b, 1, 2, 0);

	myvector_print(a, 1);
	myvector_print(b, 1);

	myvector_print(a, 2);
	myvector_print(b, 2);

	double x, y, Tx = 3.1415926, Ty = 4.7227;
	int32_t res = myvector_cvp(&x, &y, &Tx, &Ty, a, b);
	
	// myvector_print(c, 1);
	// myvector_print(c, 2);
	printf("%d, %g %g\n", res, x, y);

	free(a);
	free(b);
	free(c);
	return 0;
}