#include "kb_arrange_cvmat.h"

void kb::arrange_matN(std::vector<cv::Mat>& vec_mat, cv::Mat& matV, int num_width)
{
	int num = vec_mat.size();
	if (num <= 0)
		return;

	cv::Size sz = vec_mat[0].size();
	if (sz.width <= 0 || sz.height <= 0)
		return;

	//@c‰¡‚É”z’u‚·‚é‰æ‘œ”‚ðÝ’è‚·‚é
	int nx = num, ny = 1;
	if (num_width <= 0) {
		for (int d = 1; d <= num; d++) {
			int n1 = num / d;
			int a1 = num % d;

			if (a1 > 0) {
				n1++;
			}

			int n2 = d;

			int w = sz.width * n1;
			int h = sz.height * n2;
			if (w < h) {
				nx = n1;
				ny = n2;
				break;
			}
		}

		int det_y = num % nx;
		ny = num / nx;
		if (det_y > 0) {
			ny++;
		}
	}
	else {
		nx = num_width;
		int det_y = num % nx;
		ny = num / nx;
		if (det_y > 0) {
			ny++;
		}
	}


	cv::Size sz2(nx * sz.width, ny * sz.height);

	int kk = 0;
	cv::Mat matOv(sz2, CV_8UC3);
	for (int k = 0; k < num; k++) {
		if (vec_mat[k].empty() == true)
			continue;

		cv::Mat mat3;
		int dp = vec_mat[k].depth();
		int ch = vec_mat[k].channels();
		if (ch == 1) {
			cv::cvtColor(vec_mat[k], mat3, cv::COLOR_GRAY2BGR);
		}
		else {
			mat3 = vec_mat[k];
		}
		cv::Size sz3 = mat3.size();

		cv::Mat mat4;
		if (sz != sz3) {
			cv::resize(mat3, mat4, sz, 0.0, 0.0, cv::INTER_CUBIC);
		}
		else {
			mat4 = mat3;
		}


		int ii = kk % nx;
		int jj = kk / nx;
		int x0 = ii * sz2.width / nx;
		int y0 = jj * sz2.height / ny;

		mat3.copyTo(matOv(cv::Rect(x0, y0, sz.width, sz.height)));
		kk++;
	}
	matV = matOv;
}
