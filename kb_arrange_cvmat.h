#include <opencv2/opencv.hpp>
#include <vector>

#pragma once

namespace kb
{
	//	�����摜�T�C�Y�̉摜���c���ɕ��ׂāA�P���̑傫�ȉ摜�ɂ���֐�
	void arrange_matN(std::vector<cv::Mat>& vec_mat, cv::Mat& matV, int num_width=-1);
};
