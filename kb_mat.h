#pragma once


namespace kb
{
	//	ｎ次元ベクトルの内積
	double dotproduct(double* p1, double* p2, int num);
	//	３次元ベクトルの外積
	void crossproduct(double* p1, double* p2, double* p_out);

};
