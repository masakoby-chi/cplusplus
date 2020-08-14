#include <opencv2/opencv.hpp>
#include <vector>

#pragma once

namespace kb
{
	//	同じ画像サイズの画像を縦横に並べて、１枚の大きな画像にする関数
	void arrange_matN(std::vector<cv::Mat>& vec_mat, cv::Mat& matV, int num_width=-1);
};
