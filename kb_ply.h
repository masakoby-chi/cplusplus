//
//	ply�t�@�C��
//

#include <string>
#include <vector>

#pragma once

namespace kb
{
	//	�R�����_�Q�Ƃ��ĕۑ�
	int save_as_ply(
		std::string& path,
		std::vector<float>& v_pt,
		std::vector<unsigned char>& vcolor);
	//	�R�����_�Q�Ƃ��ĕۑ�
	int save_as_ply(
		std::string& path,
		std::vector<float>& v_pt);

	//	���b�V���Ƃ��ĕۑ�
	int save_mesh_as_ply(
		std::string& path,
		std::vector<float>& vec_pos,
		std::vector<int>& vec_idx);

	//	���b�V���Ƃ��ēǂݍ���
	int load_mesh_as_ply(
		std::string& path,
		std::vector<float>& vec_pos,
		std::vector<float>& vec_nv,
		std::vector<int>& vec_idx);

};
