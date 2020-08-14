#include "kb_mat.h"

double kb::dotproduct(double* v1, double* v2, int num)
{
	double sum = 0;
	for (int i = 0; i < num; i++) {
		sum += v1[i] * v2[i];
	}
	return sum;
}

void kb::crossproduct(double* p1, double* p2, double* p_out)
{
	p_out[0] = p1[1] * p2[2] - p1[2] * p2[1];
	p_out[1] = p1[2] * p2[0] - p1[0] * p2[2];
	p_out[2] = p1[0] * p2[1] - p1[1] * p2[0];
}
