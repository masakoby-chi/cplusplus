//
//	ply�t�@�C��
//

#include <string>
#include <vector>

#pragma once

namespace kb
{
	//	���b�V���Ƃ��ĕۑ�
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
