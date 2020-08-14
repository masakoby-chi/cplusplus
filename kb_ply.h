//
//	plyファイル
//

#include <string>
#include <vector>

#pragma once

namespace kb
{
	//	メッシュとして保存
	int save_mesh_as_ply(
		std::string& path,
		std::vector<float>& vec_pos,
		std::vector<int>& vec_idx);

	int load_mesh_as_ply(
		std::string& path,
		std::vector<float>& vec_pos,
		std::vector<float>& vec_nv,
		std::vector<int>& vec_idx);

};
