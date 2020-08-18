#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream> 

#include "kb_mat.h"

void kb::matRotZ(double* mat3x3, double deg)
{
	double radZ = deg * M_PI / 180.0;
	mat3x3[0] = cos(radZ);
	mat3x3[1] = -sin(radZ);
	mat3x3[2] = 0.0;
	mat3x3[3] = sin(radZ);
	mat3x3[4] = cos(radZ);
	mat3x3[5] = 0.0;
	mat3x3[6] = 0.0;
	mat3x3[7] = 0.0;
	mat3x3[8] = 1.0;
}

void kb::matRotX(double* mat3x3, double deg)
{
	double radZ = deg * M_PI / 180.0;
	mat3x3[0] = 1.0;
	mat3x3[1] = 0.0;
	mat3x3[2] = 0.0;
	mat3x3[3] = 0.0;
	mat3x3[4] = cos(radZ);
	mat3x3[5] = -sin(radZ);
	mat3x3[6] = 0.0;
	mat3x3[7] = sin(radZ);
	mat3x3[8] = cos(radZ);
}

void kb::matRotY(double* mat3x3, double deg)
{
	double radZ = deg * M_PI / 180.0;
	mat3x3[0] = cos(radZ);
	mat3x3[1] = 0.0;
	mat3x3[2] = sin(radZ);
	mat3x3[3] = 0.0;
	mat3x3[4] = 1.0;
	mat3x3[5] = 0.0;
	mat3x3[6] = -sin(radZ);
	mat3x3[7] = 0;
	mat3x3[8] = cos(radZ);
}

void kb::matmul_3x3_3x1(double* mat1, double* vec1, double* vec2)
{
	vec2[0] = mat1[0] * vec1[0] + mat1[1] * vec1[1] + mat1[2] * vec1[2];
	vec2[1] = mat1[3] * vec1[0] + mat1[4] * vec1[1] + mat1[5] * vec1[2];
	vec2[2] = mat1[6] * vec1[0] + mat1[7] * vec1[1] + mat1[8] * vec1[2];
}

void kb::matmul_3x3_3x3(double* mat1, double* mat2, double* mat3)
{
	for (int i = 0; i < 3; i++) {
		int k = i * 3;
		mat3[0 + k] = mat2[0] * mat1[0 + k] + mat2[3] * mat1[1 + k] + mat2[6] * mat1[2 + k];
		mat3[1 + k] = mat2[1] * mat1[0 + k] + mat2[4] * mat1[1 + k] + mat2[7] * mat1[2 + k];
		mat3[2 + k] = mat2[2] * mat1[0 + k] + mat2[5] * mat1[1 + k] + mat2[8] * mat1[2 + k];
	}
}

void kb::matRTto4x4(double* matR, double* matT, double* mat4x4)
{
	mat4x4[0] = matR[0];
	mat4x4[1] = matR[1];
	mat4x4[2] = matR[2];
	mat4x4[4] = matR[3];
	mat4x4[5] = matR[4];
	mat4x4[6] = matR[5];
	mat4x4[8] = matR[6];
	mat4x4[9] = matR[7];
	mat4x4[10] = matR[8];

	mat4x4[3] = matT[0];
	mat4x4[7] = matT[1];
	mat4x4[11] = matT[2];
	mat4x4[12] = 0;
	mat4x4[13] = 0;
	mat4x4[14] = 0;
	mat4x4[15] = 1;
}

void kb::mat4x4toRT(double* mat4x4, double* matR, double* matT)
{
	matR[0] = mat4x4[0];
	matR[1] = mat4x4[1];
	matR[2] = mat4x4[2];
	matR[3] = mat4x4[4];
	matR[4] = mat4x4[5];
	matR[5] = mat4x4[6];
	matR[6] = mat4x4[8];
	matR[7] = mat4x4[9];
	matR[8] = mat4x4[10];
	matT[0] = mat4x4[3];
	matT[1] = mat4x4[7];
	matT[2] = mat4x4[11];
}


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

int kb::load_mat(const std::string& path, double* mat, int num)
{
	std::ifstream file(path.c_str());
	if (file.is_open() == false)
		return -1;

	std::string str1;
	for (int i = 0; i < num; i++) {
		file >> str1;
		mat[i] = std::stod(str1);
	}
	return 0;
}

