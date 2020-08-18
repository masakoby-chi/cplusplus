
#include <string>
#include <vector>

#pragma once

namespace kb
{
	//-----------------------------------------------------------------------------------
	//	std::string --> unicode
	void string2wchar(std::string iStr, wchar_t* oBuf1, int cnt1);
	//	unicode --> std::string
	void wchar2string(const wchar_t* oBuf1, std::string& oStr1);


	//	���������؂蕶����p���ĕ�������
	int split_string(
		const std::string& strL1, 
		char delim, 
		std::vector<std::string>& v_str1
	);

	//	�p�X�����A�f�B���N�g�����ƃt�@�C�����ɕ�������
	void split_path(std::string& path, std::string& dirname, std::string& filename);
	void split_path(std::string& path, std::string& dirname, std::string& filetitle, std::string& fileext);

};

