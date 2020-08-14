
#include <string>
#include <vector>

#pragma once

namespace kb
{
	//
	int split_string(
		const std::string& strL1, 
		char delim, 
		std::vector<std::string>& v_str1
	);

	//
	void split_path(std::string& path, std::string& dirname, std::string& filename);
	void split_path(std::string& path, std::string& dirname, std::string& filetitle, std::string& fileext);

};

