#pragma once

#include <string>
#include <vector>

namespace kb
{
	//	3x3回転行列
	void matRotX(double* mat3x3, double deg);
	void matRotY(double* mat3x3, double deg);
	void matRotZ(double* mat3x3, double deg);

	//	行列演算
	void matmul_3x3_3x1(double* mat1, double* vec1, double* vec2);
	void matmul_3x3_3x3(double* mat1, double* mat2, double* mat3);


	//	4x4 RT行列
	//	逆行列
	void mat4x4inverse(double* mat4x4, double* mat4x4_o);
	//	
	void matRTto4x4(double* matR, double* matT, double* mat4x4);
	//	
	void mat4x4toRT(double* mat4x4, double* matR, double* matT);


	//	ｎ次元ベクトルの内積
	double dotproduct(double* p1, double* p2, int num);
	//	３次元ベクトルの外積
	void crossproduct(double* p1, double* p2, double* p_out);


	//	スペース区切りのテキスト行列ファイル読み込み
	int load_mat(const std::string& path, double* mat, int num);

};
