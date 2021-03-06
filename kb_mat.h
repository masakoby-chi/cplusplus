#pragma once

#include <string>
#include <vector>

namespace kb
{
	//	3x3ñ]sñ
	void matRotX(double* mat3x3, double deg);
	void matRotY(double* mat3x3, double deg);
	void matRotZ(double* mat3x3, double deg);

	//	sñZ
	void matmul_3x3_3x1(double* mat1, double* vec1, double* vec2);
	void matmul_3x3_3x3(double* mat1, double* mat2, double* mat3);


	//	4x4 RTsñ
	//	tsñ
	void mat4x4inverse(double* mat4x4, double* mat4x4_o);
	//	
	void matRTto4x4(double* matR, double* matT, double* mat4x4);
	//	
	void mat4x4toRT(double* mat4x4, double* matR, double* matT);


	//	³xNgÌàÏ
	double dotproduct(double* p1, double* p2, int num);
	//	R³xNgÌOÏ
	void crossproduct(double* p1, double* p2, double* p_out);


	//	Xy[XæØèÌeLXgsñt@CÇÝÝ
	int load_mat(const std::string& path, double* mat, int num);

};
