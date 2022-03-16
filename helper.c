// function for qsort (doubles)
int dcompare(const void * a, const void * b) {

	if (*(double *) a < *(double *) b) return -1;
	else if (*(double *) a > *(double *) b) return 1;
	else return 0;
}