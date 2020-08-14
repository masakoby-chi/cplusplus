//
//	plyファイル
//

#include <string>
#include <vector>

#pragma once

namespace kb
{
	//	３次元点群として保存
	int save_as_ply(
		std::string& path,
		std::vector<float>& v_pt,
		std::vector<unsigned char>& vcolor);
	//	３次元点群として保存
	int save_as_ply(
		std::string& path,
		std::vector<float>& v_pt);

	//	メッシュとして保存
	int save_mesh_as_ply(
		std::string& path,
		std::vector<float>& vec_pos,
		std::vector<int>& vec_idx);

	//	メッシュとして読み込む
	int load_mesh_as_ply(
		std::string& path,
		std::vector<float>& vec_pos,
		std::vector<float>& vec_nv,
		std::vector<int>& vec_idx);

};
