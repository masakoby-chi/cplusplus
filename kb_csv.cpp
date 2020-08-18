#include "kb_csv.h"
#include <fstream> 
#include <sstream>

int kb::load_space(std::string& path, std::vector<std::vector<std::string>>& vv)
{
	// �t�@�C�����J��
	std::ifstream f1(path);
	if (!f1.is_open())
	{
		return -1;
	}


	while (1) {
		//
		std::string strL1;
		std::getline(f1, strL1);

		//	�f�[�^
		std::istringstream stream(strL1);

		std::vector<std::string> v1;
		int k = 0;

		//1�s�̂����A������ƃR���}�𕪊�����
		while (1) {
			std::string token;
			std::getline(stream, token, ' ');
			size_t n1 = token.length();
			if (n1 == 0) {
			}
			else {
				k++;
				v1.push_back(token);
			}
			if (stream.eof() != false)
				break;
		}

		if (k > 0) {
			vv.push_back(v1);
		}

		if (f1.eof() == true)
			break;

	}

	return 0;
}

int kb::load_csv(std::string& path, std::vector<std::vector<std::string>>& vv)
{
	// �t�@�C�����J��
	std::ifstream f1(path);
	if (!f1.is_open())
		return -1;


	while (1) {
		//
		std::string strL1;
		std::getline(f1, strL1);

		//	�f�[�^
		std::istringstream stream(strL1);

		std::vector<std::string> v1;
		int k = 0;

		//1�s�̂����A������ƃR���}�𕪊�����
		while (1) {
			std::string token;
			std::getline(stream, token, ',');
			size_t n1 = token.length();
			if (n1 == 0) {
			}
			else {
				k++;
				v1.push_back(token);
			}
			if (stream.eof() != false)
				break;
		}

		if (k > 0) {
			vv.push_back(v1);
		}

		if (f1.eof() == true)
			break;

	}

	return 0;
}
