#include "kb_string.h"
#include <iostream>
#include <sstream>

int kb::split_string(const std::string& strL1, char delim, std::vector<std::string>& v_str1)
{
	//	�f�[�^
	std::istringstream stream(strL1);
	int k = 0;

	//1�s�̂����A�������(�R���})�𕪊�����
	while (1) {
		std::string token;
		std::getline(stream, token, delim);// '_');
		size_t n1 = token.length();
		if (n1 == 0) {
		}
		else {
			k++;
			v_str1.push_back(token);
		}
		if (stream.eof() != false)
			break;
	}
	return k;
}
